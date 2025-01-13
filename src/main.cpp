#include <Arduino.h>
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <BH1750.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

BH1750 lightMeter;

#define DHT112PIN D5// Digital pin connected to the DHT11 sensor
#define DHT11PIN D6// Digital pin connected to the DHT11 sensor
#define DHT22PIN D7// Digital pin connected to the DHT22 sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Initialize DHT sensor.
DHT dht22(DHT22PIN, DHTTYPE);
DHT dht11(DHT11PIN, DHT11);
DHT dht112(DHT112PIN, DHT11);



void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));

  dht22.begin();         //C: start the first measurement
  dht11.begin();         //C: start the first measurement
  dht112.begin();        //C: start the first measurement


  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();

  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  delay(5000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humidity22 = dht22.readHumidity();
  // Read temperature as Celsius (the default)
  float temp22 = dht22.readTemperature();
  if (isnan(humidity22) || isnan(temp22)) {
    Serial.println("Failed to read from dht22 sensor!");
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht22.computeHeatIndex(temp22, humidity22, false);

  Serial.print(F("DHT22 -=-"));
  Serial.print(F("Humidity: "));
  Serial.print(humidity22);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp22);
  Serial.print(F("°C "));
  Serial.print(F("-- Heat index: "));
  Serial.print(hic);
  Serial.println(F("°C "));

  delay(500);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humidity11 = dht11.readHumidity();
  // Read temperature as Celsius (the default)
  float temp11 = dht11.readTemperature();
  if (isnan(humidity11) || isnan(temp11)) {
    Serial.println("Failed to read from dht11 sensor number 1!");
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic11 = dht11.computeHeatIndex(temp11, humidity11, false);

  Serial.print(F("DHT11 No.1 -=-"));
  Serial.print(F("Humidity: "));
  Serial.print(humidity11);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp11);
  Serial.print(F("°C "));
  Serial.print(F("-- Heat index: "));
  Serial.print(hic11);
  Serial.println(F("°C "));

  delay(500);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humidity112 = dht112.readHumidity();
  // Read temperature as Celsius (the default)
  float temp112 = dht112.readTemperature();
  if (isnan(humidity112) || isnan(temp112)) {
    Serial.println("Failed to read from dht11 sensor number 2!");
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic112 = dht112.computeHeatIndex(temp112, humidity112, false);

  Serial.print(F("DHT11 No.2 -=-"));
  Serial.print(F("Humidity: "));
  Serial.print(humidity112);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp112);
  Serial.print(F("°C "));
  Serial.print(F("-- Heat index: "));
  Serial.print(hic112);
  Serial.println(F("°C "));


  // Take light sensor reading and print it
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");

  // clear display
  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(temp22);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");

  display.display();

  delay(5000);

  // clear display
  display.clearDisplay();

  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print(humidity22);
  display.print(" %");

  display.display();
}
