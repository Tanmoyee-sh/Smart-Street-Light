#define ECHOPIN 6
#define TRIGPIN 7
#define LDRPin A2
#define LEDPin 8
#include <LiquidCrystal.h>          


int distance = 0;
int LIGHT = 10;
float duration=0;
float distance_cm=0;
float distance_inch=0;

//int sensorValue = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LDRPin, INPUT);
  pinMode(LEDPin, OUTPUT);


  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Your speed is: ");
}

void loop() {
  measure_distance();
  int LDRValue = analogRead(LDRPin);
  if (distance_cm < 10 && LDRValue > LIGHT )
  {
    digitalWrite(LEDPin, HIGH);
    delay(150);
  }
  else
  {
    digitalWrite(LEDPin, LOW);
  }

}

void measure_distance() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);
  duration = pulseIn(ECHOPIN, HIGH); // return 0 if no high pulse in 1sec. duration is in miliseconds
 
  distance_cm=(duration/29)/2;
  Serial.print(distance_cm);
  Serial.println("cm");
  delay(500);
  float speed;
 
  if (distance_cm <= 100)
  {
    unsigned long currentTime = millis();
    static unsigned long previousTime = 0;
    if (previousTime == 0)
    {
      previousTime =  currentTime;
      return;
    }

    float timelapsed = ( currentTime -  previousTime)/1000.0;
    speed = (distance_cm - 100)/timelapsed;
    previousTime =  currentTime;

    Serial.print(speed);
    Serial.println("km/h");
  }
  delay(100);

  lcd.setCursor(0, 1);
  lcd.print(speed);
  delay(100);
}
