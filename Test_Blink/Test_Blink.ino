void setup()  {
  pinMode(1, OUTPUT);
}

void loop()
{
  for (int i=0; i<1024; i++){
    digitalWrite(1, HIGH);
    delay(i);
    digitalWrite(1, LOW);
    delay(i);
}
  for (int i=500; i>1025; i--){
    digitalWrite(1, HIGH);
    delay(i);
    digitalWrite(1, LOW);
    delay(i);
  }
}
