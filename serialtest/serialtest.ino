void setup() {
  pinMode(0, OUTPUT);
  Serial.begin(19200);
}

void loop() {
  int n = 0;
  while(Serial.available()) {
    String a;
    a= Serial.readString();// read the incoming data as string
    delay(1000);
    Serial.println(sum(a));
  }
}

int sum(String a){
  int sum;
  for (int i = 0; a.length(); i++){
    sum += a[i];
  }
  return sum;
}
