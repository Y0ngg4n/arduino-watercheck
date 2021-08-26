int moisturePin = A0;
int pumpPin = 5;
int waitTimeInMinutes = 1;
int pumpTimeInMilliseconds = 500;
int airValue = 920;
int waterValue = 836;
int minPercentage = 15;
int messureCount = 10;

// After Tests we found out that the moisture sensor maps between the values 274 and 676.
// So we decided to use 600 as our dry status
// and  400 as our wet status

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  // Wait for waitTimeInMinutes to check again
  Serial.println("Stopping Pump");
  digitalWrite(pumpPin, LOW);
  //delay(waitTimeInMinutes * 6000);
  
  Serial.println("#########");
  int values[10];
  for(int i = 0; i < messureCount; i++){
    values[i] = analogRead(moisturePin);
    //Serial.println(values[i]);
    delay(1000);
  }
  int median = 0;
  for(int i = 0; i < messureCount; i++){
    median = median + values[i];
  }
  median = median / messureCount;
  
  int percentage = map(median, airValue, waterValue, 0, 100);
  Serial.println("Percentage: " + String(percentage) + "%");

  Serial.println("Current Moisture: " + String(median));

  if(percentage > minPercentage){
    Serial.println("Moisture is too low");
    //Serial.println("Starting Pump");
    //digitalWrite(pumpPin, HIGH);
    delay(pumpTimeInMilliseconds);
    //digitalWrite(pumpPin, LOW);
    //Serial.println("Stopping Pump");
  }else{
    Serial.println("Moisture is just right");
  }
}
