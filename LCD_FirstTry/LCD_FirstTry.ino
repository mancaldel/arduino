/*    MY FIRST TRY WITH LCD HD87044

LCD:
  A ---- 220 ----- 5V
  K ---- gnd
  
  VSS ---- gnd
  VDD ---- 5V
  V0 ---- POT10k  ---- 0 & 5 V
  
  RS (white) ---- pin
  RW ---- gnd
  E (brown) ---- pin
  
  D4 (green)  ---- pin
  D5 (grey) ---- pin
  D6 (purple) ---- pin
  D7 (yellow) ----pin
  
  
  THERMISTOR:
    AREF is connected to 3.3V (actually 3.29V)
    measurement ---- A0
    
*/


// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
int lcdRS =9;
int lcdE =8;
int lcd4 =4, lcd5=5, lcd6=6, lcd7=7;
LiquidCrystal mylcd(lcdRS, lcdE, lcd4, lcd5, lcd6, lcd7);

int ledPin = 13;

#define V_ref 3.29
int therm = 0;
//pinMode(ledPin,OUTPUT);


    // Set the time for the CountDown:
int timeRem[3] = {0, 0, 0};
    // Make an array for the last 5 Temperature values:
float tempArray[5] = {0,0,0,0,0};
float elapsedSeconds = 0;
bool stopCount = false;


  // Declarating the function for the termistor usage and countDown:
float temperature(int reading, float tempArray[]);
int countDown(int time[]);
void showTime(LiquidCrystal lcd, int time[]);

/*
            S E T     U P     O F     T H E     B O A R D
*/

void setup() {
    // Set the Analog Voltage Reference to external (must be connected to 3.3V):
  analogReference(EXTERNAL);
    // Turn off on-board LED
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  
    // set up the LCD's number of columns and rows:
  mylcd.begin(16,2);
    // Print a message to the LCD.
  mylcd.print("Hola holita!!");
  delay(1000);
  
}


/*
        M A I N     L O O P
*/
void loop() {
//  mylcd.clear();
  printf("%03d", 7);
    // Go to first line, first column:
  mylcd.setCursor(0,0);
    // Print the remaining time:
  mylcd.print("T.Rem - ");
  if (stopCount == false){
    showTime(mylcd, timeRem);
    countDown(timeRem);
  } else{
    mylcd.print(" BOOM !!");
  }
  
  //delay(100);
    // Go to the second line, first column.  
  mylcd.setCursor(0,1);
  //mylcd.noAutoscroll();
    // Print temperature:
  float newTemp = temperature(therm, tempArray);
  mylcd.print("Temp: ");
  mylcd.print(newTemp);
  delay(100);
//  mylcd.print(" ");
//  mylcd.print(millis()/1000);
}



/*
      F U N C T I O N     D E F I N I T I O N
*/

float temperature(int reading, float tempArray[]){
  
  float tVolt = V_ref * (analogRead(reading)) / 1023;

  float R = tVolt / ( (V_ref - tVolt) / 4570 );
  float lnRr = log(R/4700);
  float steinhart = 3.354016E-3 + 2.569850E-4*lnRr + 2.620131E-6*pow(lnRr,2) + 6.383091E-8*pow(lnRr,3);
  
//  int B = 
//  float rRef = 4700 * exp(-B/tRef)
//  float temp = tVolt *
  for (int i = 0; i<4; i++){
    tempArray[i] = tempArray[i+1];
  }
  tempArray[4] =  1/steinhart - 273;
  //tempArray[i] = 1/steinhart - 273;
  float tempsArray = 0;
  for (int i = 0; i<5; i++){
    tempsArray = tempsArray + tempArray[i];    
  }
  
  return tempsArray/5;
  
}



int countDown(int time[]){
  
  int seconds = millis()/1000;
  if (elapsedSeconds - seconds < 0){
    elapsedSeconds = millis()/1000;
    time[2] = time[2] + 1;
  }
//  int seconds = millis() / 1000;
//  int newSeconds = time[2] + seconds;
//  time[2]=newSeconds;
//  mylcd.print(seconds);
//  delay(500);

  if (time[2] == 60 && stopCount==false){
    time[2] = 00;
    time[1] = time[1] + 1;
  }
  if (time[1] == 60 && stopCount==false){
    time[1] = 00;
    time[0] = time[0] + 1;
  }
  if (time[0]<0 && stopCount==false){ // && time[1]<0 && time[2]<0
    stopCount = true;
    return 1;
  }else{
    return 0;
  }
  
}



void showTime(LiquidCrystal lcd, int time[]){
  if(time[0]<10){mylcd.print(0);}
  lcd.print(time[0]);
  lcd.print(":");
  if(time[1]<10){mylcd.print(0);}
  lcd.print(time[1]);
  lcd.print(":");
  if(time[2]<10){mylcd.print(0);}
  lcd.print(time[2]);
}

