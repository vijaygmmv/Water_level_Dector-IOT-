#define BLYNK_TEMPLATE_ID "TMPL3v39NOrJl"
#define BLYNK_TEMPLATE_NAME "distance tester"
#define BLYNK_AUTH_TOKEN "579YuoWbsyWKHJZmgo-i2DP5RtXBrL_O"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NewPing.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial
#define trig D6
#define echo D7
#define BUZZER_PIN 14  // GPIO D5
#define LED 15           // GPIO D8
#define MIN_DISTANCE_PERCENTAGE 10
#define MAX_DISTANCE_PERCENTAGE 80

char ssid[] = "VIJAY";
char pass[] = "1234567889";

Adafruit_SSD1306 display(128, 64, &Wire, -1); // Initialize OLED display

long tankDepth = 15.5;
long Percentage = 0;

void waterLevel() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Blynk.virtualWrite(V3, String(cm));
  Serial.println(cm);
  double level = tankDepth - cm;
  if (level > 0) {
    Percentage = ((level / tankDepth)) * 100;
    Serial.println(Percentage);
    Blynk.virtualWrite(V0, Percentage);
  } else {
    Serial.print("wrong");
    Blynk.virtualWrite(V0, 0);
  }
}

BLYNK_WRITE(V2) {
  Percentage = param.asLong(); // Get the percentage value from Blynk
}

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED, OUTPUT);
  delay(100);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;) ; // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();
}

void loop() {
  Blynk.run();
  waterLevel();

  // Update OLED display with the percentage value
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("    WATER   LEVEL");
  display.println("  -----------------");
  display.setTextSize(4);
  display.setCursor(35, 27);
  display.print(Percentage);
  display.println("%");
  display.display();

// Control Buzzer and LED based on Distance Percentage
  if (Percentage < MIN_DISTANCE_PERCENTAGE || Percentage > MAX_DISTANCE_PERCENTAGE) {
    // less than 10% or more than 30% Buzzer on
    digitalWrite(BUZZER_PIN, HIGH); // Turn on the buzzer

  } else {
    digitalWrite(BUZZER_PIN, LOW); // Turn off the buzzer
  }


  // For LED Setup
  if (Percentage < MIN_DISTANCE_PERCENTAGE ){   // low water level < 10% LED on
    digitalWrite(LED,HIGH);
  }
  else if (Percentage > MAX_DISTANCE_PERCENTAGE){
    digitalWrite(LED,LOW);
  }
  else{
    digitalWrite(LED,LOW);
  }
  delay(1000);
}

