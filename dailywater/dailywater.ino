int pumpPin = 5;
long pumpMilliliter = 600;
long pumpSpeedMilliliterPerSecond = 30;
long days = 7;

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  // LOW is on. High is off;
  digitalWrite(pumpPin, HIGH);
  delay(10000);
  digitalWrite(pumpPin, LOW);
  Serial.println("Water on");
  long waitTime = (pumpMilliliter / pumpSpeedMilliliterPerSecond) * 1000;
  Serial.println("Waiting " + String(waitTime / 1000) + " seconds");
  delay(waitTime);
  digitalWrite(pumpPin, HIGH);
  Serial.println("Water off");
  long waitingMilliseconds = (days * 86400000);
  delay(waitingMilliseconds);
}
