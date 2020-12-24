const int trigger_pin_increase = 6;
const int echo_pin_increase = 7;
const int trigger_pin_decrease = 9;
const int echo_pin_decrease = 10;


int distance_increase, distance_decrease;
int duration_increase, duration_decrease;


void setup() {

    pinMode(trigger_pin_increase, OUTPUT);
    pinMode(trigger_pin_decrease, OUTPUT);
    pinMode(echo_pin_increase, INPUT);
    pinMode(echo_pin_decrease, INPUT);
    Serial.begin(9600); 
}

void loop() {

    // clean pins
    digitalWrite(trigger_pin_increase, LOW);
    digitalWrite(trigger_pin_decrease, LOW);
    delayMicroseconds(2);

    // generate ultrasound wave
    digitalWrite(trigger_pin_increase, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin_increase, LOW);
    duration_increase = pulseIn(echo_pin_increase, HIGH);  // microseconds from the sensor to object wave and return
    
    digitalWrite(trigger_pin_decrease, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin_decrease, LOW);
    duration_decrease = pulseIn(echo_pin_decrease, HIGH);
    
    distance_increase = duration_increase* 0.034/2; // sound speed = 340 m/s --> 0.034 cm/ms and divided by two to take only the time of returning wave
    distance_decrease = duration_decrease* 0.034/2;

    // if(distance<=10){Serial.print("decrease volume \n");}
    // else{Serial.print("nothing to do\n");}

    Serial.print(distance_decrease);
    Serial.print(",");
    Serial.print(distance_increase);


    delay(100);
   
}
