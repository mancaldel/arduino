    int trig_HC = 2;
    int echo_HC = 8;
    int read_HC = 0;// digitalRead(echo_HC);
    int ledPin = 13;
    int distance = 0;
    int buzzerPin = 4;
    
    // Functions declaration
    int HC_SR04();
    void lightUP(int dist, int ledRange);
    void soundUP(int targetPin, int dist);
//    void buzz(int targetPin, long frequency, long time_buzz);

    


void setup() {  // put your setup code here, to run once:
    // Serial connection
    Serial.begin (9600);
    
    // Output signal to HC-SR4
    pinMode(trig_HC,OUTPUT);
    // Input signal from HC-SR4
    pinMode(echo_HC,INPUT);
  
    // Output signal to LED
    pinMode(ledPin,OUTPUT);
}


// ----------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------
//                                            M A I N     F U N C T I O N
// ----------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------
void loop() {  // put your main code here, to run repeatedly:
    
//    digitalWrite(trig_HC,LOW);
//    delayMicroseconds(3);
//    digitalWrite(trig_HC,HIGH);
//    delayMicroseconds(10);
//    digitalWrite(trig_HC,LOW);
//    
//    read_HC = digitalRead(echo_HC);
//    digitalWrite (led,!read_HC);
//    
//    delay(5);
  
  
    distance = HC_SR04();

    
    
//    Communicate with the computer...
  if (distance >= 1500 || distance <= 70){
    Serial.println("Out of range");
    noTone(buzzerPin);
  } else {
    lightUP(distance, 100);
    soundUP(buzzerPin, distance);
//    Serial.print(distance);
//    Serial.println(" mm");
  }
  delay(250);
  
}



// ----------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------
//                                      O T H E R     F U N C T I O N S
// ----------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------
int HC_SR04(){
    // Reset previous measurements
   // unsigned long dist;
//    bool control = false;
//    int dist = 0;
    
//    while (dist > 300 & dist <=0){
        digitalWrite(trig_HC,LOW);
        delayMicroseconds(3);
        // Send 10us pulse to HC-SR04
        digitalWrite(trig_HC,HIGH);
        delayMicroseconds(10);
        digitalWrite(trig_HC,LOW);
        
        // Time echo signal with timeout 10us
        unsigned long echo_time = pulseIn(echo_HC,HIGH);
        // Calculate distance in mm as: (sound speed 340m/s = 340*1000 mm/s)
    //    int dist = echo_time*340*1000/2;
        int dist = echo_time/5.8;
//        if (dist<4000 & dist>0){
//            control = true;
//        }
//    }
//    Serial.print(dist);
    
    return dist;
        
    // We should always listen to HC-SR04
    // IN SETUP we have: digitalRead(echo_HC);
}


void lightUP(int dist, int ledRange=100){
    if (dist <= ledRange){
        digitalWrite(ledPin,HIGH);
    }else{
        digitalWrite(ledPin,LOW);
    }
  
}


void soundUP(int targetPin, int dist){
    dist = dist/50;
    int freq = dist * 12500 + 100; // distance in mm ==> 1m=1000mm ==> 20kHz
    tone(targetPin, 440);
    
}


//void buzz(int targetPin, long frequency, long time_buzz){
//  
//   long delayValue =  1000000/frequency/2;
// 
//   long numCycles = frequency * time_buzz / 1000;
// 
//   for (long i=0; i<numCycles; i++){
//      digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
//      delayMicroseconds(delayValue); // wait for the calculated delay value
//      digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
//      delayMicroseconds(delayValue); // wait againf or the calculated delay value
//    }
//    
//}
