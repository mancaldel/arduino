// Buzzer example function for the CEM-1203 buzzer (Sparkfun's part #COM-07950).
// by Rob Faludi
// http://www.faludi.com

//void setup() {
//  // put your setup code here, to run once:
//pinMode(9, OUTPUT);
//pinMode(13, OUTPUT);
//analogWrite(13, 0);
// // beep(50);
////  beep(50);
////  beep(50);
//  delay(1000);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//beep(2); 
//}
//
//
//
//void beep(unsigned char delayms){
//  for(int i=1;i=250;i+=10){
//      analogWrite(9, i);      // Almost any value can be used except 0 and 255
//                           // experiment to get the best tone
//      delay(delayms);          // wait for a delayms ms
//      analogWrite(9, 0);       // 0 turns it off
//      delay(delayms);          // wait for a delayms ms   
//  }
//}  





//////////////////////////////////////////////////////////////////////////////////////



void setup() {
  pinMode(9, OUTPUT); // set a pin for buzzer output
  pinMode(13, OUTPUT);
  digitalWrite(13,0);
}

void loop() {
  for(int i=100; i<3400; i+=100){
    buzz(9, i, 30); // buzz the buzzer on pin 4 at 2500Hz for 500 milliseconds
    delay(100); // wait a bit between buzzes
  }
  for(int i=3600; i>100; i-=100){
    buzz(9, i, 30); // buzz the buzzer on pin 4 at 2500Hz for 500 milliseconds
    delay(100); // wait a bit between buzzes
  }
}


void buzz(int targetPin, long frequency, long length) {
  long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to 
  //// get the total number of cycles to produce
 for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait againf or the calculated delay value
  }
}

