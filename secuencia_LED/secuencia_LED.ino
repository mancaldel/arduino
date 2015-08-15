int LED = 13;

int ROJO_1 = 2;
int ROJO_2 = 4;
int ROJO_3 = 7;

int AMARILLO = 8;
int VERDE = 12;

int BUZZ = 9;
long freq = 100;
int veces = 0;
//int control;
boolean r1_s = false, r2_s = false, r3_s = false, a_s = false, v_s = false;

void setup()
{
  pinMode(LED,OUTPUT);
  int LED_s = 0;
  
  pinMode(ROJO_1,OUTPUT);
  pinMode(ROJO_2,OUTPUT);
  pinMode(ROJO_3,OUTPUT);
  
  pinMode(AMARILLO,OUTPUT);
  pinMode(VERDE,OUTPUT);
  
  pinMode(BUZZ, OUTPUT);
  
//  control = 0;
}

void loop()
{
  delay(0);
  int my_delay = 50;
//  while (my_delay < 200)
//  {
    digitalWrite(LED,HIGH);
    delay(my_delay);
    digitalWrite(LED,LOW);
    delay(my_delay);
    //my_delay = my_delay + 100;
//  }
  
  secuencia();
  
}








boolean cambia(int COLOR, boolean estado)
{
  if (estado == false)
  {
    digitalWrite(COLOR,HIGH);
    return true;
  }
  else
  {
    digitalWrite(COLOR,LOW);
    return false;
  }  
}


void secuencia()
{

  veces = veces+1;
  for(int control = 1; control < 32; control++)
  {
    
    r1_s = cambia(ROJO_1, r1_s);
    
    buzz(BUZZ, freq, 50);
    if (veces%2==0){
    freq -= 10;
    }else{
    freq += 10;
    }
    
    if (control % 2 == 0){
      r2_s = cambia(ROJO_2, r2_s);
    }
    
    if (control%4 == 0){
      r3_s = cambia(ROJO_3, r3_s);
    }
    
    if (control%8 == 0){
      a_s = cambia(AMARILLO, a_s);
    }
    
    if (control%16 == 0){
      v_s = cambia(VERDE, v_s);
    }
    delay(10);
  }
}


void buzz(int targetPin, long frequency, long time_buzz){
  
 long delayValue =  1000000/frequency/2;
 
 long numCycles = frequency * time_buzz / 1000;
 
 for (long i=0; i<numCycles; i++){
   digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait againf or the calculated delay value
 }
  
  
  
}
