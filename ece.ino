#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define PIR_PIN 14
#define BUZZER_PIN 27

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  dht.begin();

  // SDA = 21, SCL = 22
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true);
  }

  display.clearDisplay();
  display.display();

  Serial.println("Smart Home Sensor Started");
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int motion = digitalRead(PIR_PIN);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");

  display.setCursor(0, 20);
  display.print("Hum: ");
  display.print(hum);
  display.println(" %");

  display.setCursor(0, 40);

  if (motion == HIGH) {
    display.println("MOTION ALERT!");
    tone(BUZZER_PIN, 1000);
  }
  else {
    display.println("System Normal");
    noTone(BUZZER_PIN);
  }

  display.display();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C  ");  

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  ");

  if (motion == HIGH) {
    Serial.println("Motion: Detected");
  } else {
    Serial.println("Motion: None");
  }

  delay(1000);
}
