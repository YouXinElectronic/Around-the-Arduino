int Relay = 3;

void setup() {
  pinMode(Relay, OUTPUT);     //Set Pin3 as output
}
void loop() {
  digitalWrite(Relay, HIGH);   //Turn on relay
  delay(2000);
  digitalWrite(Relay, LOW);    //Turn off relay
  delay(2000);
}
