int LED = 13;
int my_delay = 10;

void setup()
{
  pinMode(LED,OUTPUT);
}

void loop()
{
  digitalWrite(LED,HIGH);
  delay(my_delay);
  digitalWrite(LED,LOW);
  delay(my_delay);
  my_delay = my_delay * 1.5;
}
