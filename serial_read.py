import serial
import re
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume

# the code related with volune control is got from
# https://techoverflow.net/2020/04/04/how-to-set-windows-audio-volume-using-python/

# serial port definition
ser = serial.Serial('COM3', baudrate=9600, timeout=0.1)

# Get default audio device using PyCAW
devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(
    IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))

while(True):

    measures = ser.readline().decode('ascii')

    y = re.findall(r'[0-9]+', measures)  # regular expression which unpacks meassures

    try:  # if serial shows more than two measures data is not correct and the program miss that lectures
        assert len(y) == 2
    except:
        print('connection corrumpted')
        continue
    # print(y)

    decrease_distance, increase_distance = int(y[0]), int(y[1])

    if decrease_distance<10:
        # Get current volume
        currentVolumeDb = volume.GetMasterVolumeLevel()
        print('volumne:', currentVolumeDb)

        if currentVolumeDb < -63:
            print('minimum volume')
            continue

        volume.SetMasterVolumeLevel(currentVolumeDb - 1.0, None)
    elif increase_distance < 10:
        # Get current volume
        currentVolumeDb = volume.GetMasterVolumeLevel()
        print('volumne:', currentVolumeDb)

        if currentVolumeDb > -1:
            print('maximum volume')
            continue

        volume.SetMasterVolumeLevel(currentVolumeDb + 1, None)


