void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
long DO = 261.626, RE = 293.665, MI = 329.628, FA = 349.228, SOL = 391.995, LA = 440, SI = 493.883, DO2 = 523.251;



}

void loop() {

long DO = 261.626, RE = 293.665, MI = 329.628, FA = 349.228, SOL = 391.995, LA = 440, SI = 493.883, DO2 = 523.251;

  
  buzz(9,DO,100);
  delay(100);
  buzz(9,DO,100);
  delay(100);
  buzz(9,SOL,100);
  delay(100);
  buzz(9,SOL,100);  
  delay(100);
    buzz(9,LA,100);
  delay(100);
  buzz(9,LA,100);
  delay(100);
  buzz(9,SOL,200);  
  delay(100);
    buzz(9,FA,100);
  delay(100);
  buzz(9,FA,100);
  delay(100);
  buzz(9,MI,100);  
  delay(100);
  buzz(9,MI,100);  
  delay(100);
  buzz(9,RE,100);  
  delay(100);
  buzz(9,RE,100);  
  delay(100);
  buzz(9,DO,200);  
  delay(100);
  
  
  buzz(9,SOL,100);  
  delay(100);
  buzz(9,SOL,100);  
  delay(100);
  
  
  buzz(9,FA,100);  
  delay(100);
  buzz(9,FA,100);  
  delay(100);
  
  
  buzz(9,MI,100);  
  delay(100);
  buzz(9,MI,100);  
  delay(100);
  
  
  buzz(9,RE,200);  
  delay(100);
  
  
  
  
  // put your main code here, to run repeatedly:

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
