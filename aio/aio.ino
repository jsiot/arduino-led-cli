const int LED = 13;
String ledStatus;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  if (Serial.available()) {
    ledStatus = Serial.readString();
    if (ledStatus.equalsIgnoreCase("ON")) {
      digitalWrite(LED, HIGH);
      Serial.write("1");
      delay(1000);
    } else if (ledStatus.equalsIgnoreCase("OFF")) {
      digitalWrite(LED, LOW);
      Serial.write("0");
      delay(1000);
    } else {
      Serial.write("z");
    }
  }


}
