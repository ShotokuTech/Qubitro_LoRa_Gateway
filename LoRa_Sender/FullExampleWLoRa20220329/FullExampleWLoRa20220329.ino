#include <M5Stack.h>
#include <TinyGPS++.h>
#include <M5LoRa.h>
#include "Adafruit_Sensor.h"
#include <Adafruit_BMP280.h>
#include "UNIT_ENV.h"

SHT3X sht30;
Adafruit_BMP280 bme;

static const uint32_t GPSBaud = 9600;
String out;
int i;
float tmp = 0.0;
float hum = 0.0;
float pressure = 0.0;

TinyGPSPlus gps;
HardwareSerial ss(2);

void setup()
{
  M5.begin();
  M5.Lcd.setTextSize(2);
  ss.begin(GPSBaud, SERIAL_8N1, 16, 17);
  M5.Power.begin();
  Wire.begin();
  M5.Lcd.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    M5.Lcd.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setSignalBandwidth(125000);
  LoRa.setTxPower(17, 1);
  LoRa.setSyncWord(0x69);
  LoRa.setSpreadingFactor(7);
  LoRa.setCodingRate4(5);
  LoRa.setPreambleLength(8);
  LoRa.disableCrc();
  M5.Lcd.println("LoRa init succeeded.");
}

void loop()
{
  while (!bme.begin(0x76)){
    M5.Lcd.println("Could not find a valid BMP280 sensor, check wiring!");
  }
  pressure = bme.readPressure();
  sht30.get();
  tmp = sht30.cTemp;
  hum = sht30.humidity;
  M5.Lcd.setCursor(10, 120);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.println(out);
  LoRa.beginPacket();
  LoRa.print(out);
  LoRa.endPacket();
  smartDelay(1000);
  if (millis() > 5000 && gps.charsProcessed() < 10)
    M5.Lcd.println(F("No GPS data received: check wiring"));
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
String str = "";
char buff[12];
      str = str + ",";
      str = str + gps.time.hour();
      str = str + ":";
      str = str + gps.time.minute();
      str = str + ":";      
      str = str + gps.time.second();
      str = str + ",";
      float lat = gps.location.lat();
      dtostrf(lat, 5, 6, buff);
      str = str + buff;
      str = str + ",";            
      float lng = gps.location.lng();
      dtostrf(lng, 5, 6, buff);               
      str = str + buff;
      str = str + ",";
      str = str + gps.altitude.meters();
      str = str + ",";      
      str = str + pressure;
      str = str + ",";
      str = str + tmp;
      str = str + ",";
      str = str + hum;
      str = str + ",";                 
      out = str;
  } while (millis() - start < ms);
}
