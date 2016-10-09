#include <LiquidCrystal.h>
#include <DHT.h>;

#define DHTPIN 13
#define DHTTYPE DHT22
#define LCDBrightnessPin 10

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:

  pinMode(LCDBrightnessPin, OUTPUT);
  analogWrite(LCDBrightnessPin, 100);

  Serial.begin(115200);
  dht.begin();

  lcd.begin(16,2);
  lcd.print("Temp:");
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C ");

  lcd.setCursor(11, 0);
  lcd.print("     ");
  lcd.setCursor(11, 0);
  lcd.print(temperature);
  
  lcd.setCursor(11, 1);
  lcd.print("     ");
  lcd.setCursor(11, 1);
  lcd.print(humidity);

  
}
