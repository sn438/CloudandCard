void setup() {
  pinMode(0, OUTPUT);
  Serial.begin(19200);
}

void loop() {
  while(Serial.available()) {
    String a;
    a= Serial.readString();// read the incoming data as string

    Serial.println(a);

  }
}
