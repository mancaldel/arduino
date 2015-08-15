int LED = 13;

void setup()
{
  pinMode(LED,OUTPUT);
}

void loop()
{
  int my_delay = 50;
  while (my_delay < 500)
  {
    digitalWrite(LED,HIGH);
    delay(my_delay);
    digitalWrite(LED,LOW);
    delay(my_delay);
    my_delay = my_delay + 50;
  }
}
