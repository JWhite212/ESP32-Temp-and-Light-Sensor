# ESP32 Temperature and Light Sensor

An ESP32-based environment monitoring station that reads temperature and humidity from three DHT sensors (one DHT22 and two DHT11), ambient light from a BH1750 sensor, and displays readings on an SSD1306 OLED screen.

## Hardware

| Component | Description |
|-----------|-------------|
| DFRobot FireBeetle 2 ESP32-E | Microcontroller board |
| DHT22 (AM2302) | Temperature and humidity sensor |
| DHT11 x2 | Temperature and humidity sensors |
| BH1750 | Digital ambient light sensor (I2C) |
| SSD1306 128x32 OLED | I2C display (address `0x3C`) |

## Pin Connections

| Sensor | Pin |
|--------|-----|
| DHT22 | D7 |
| DHT11 #1 | D6 |
| DHT11 #2 | D5 |
| BH1750 SDA | SDA (I2C) |
| BH1750 SCL | SCL (I2C) |
| SSD1306 SDA | SDA (I2C) |
| SSD1306 SCL | SCL (I2C) |

The BH1750 and SSD1306 share the I2C bus.

## Output

### Serial (115200 baud)

Every 5 seconds the firmware prints readings from all three DHT sensors (humidity, temperature in Celsius, and computed heat index) plus the BH1750 light level in lux.

### OLED Display

The display alternates between two screens every 5 seconds, showing the DHT22 readings:

1. **Temperature** in degrees Celsius
2. **Humidity** as a percentage

## Building and Flashing

This is a [PlatformIO](https://platformio.org/) project targeting the `dfrobot_firebeetle2_esp32e` board with the Arduino framework.

```bash
# Build
pio run

# Upload (default port: COM3, adjust in platformio.ini if needed)
pio run --target upload

# Open serial monitor
pio device monitor
```

### Dependencies

Managed automatically by PlatformIO via `platformio.ini`:

- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) (Adafruit)
- [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor)
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [BH1750](https://github.com/claws/BH1750)
- [hp_BH1750](https://github.com/starmbi/hp_BH1750)

## Project Structure

```
src/main.cpp       # Application source (single file)
platformio.ini     # PlatformIO build configuration
include/           # Header files (unused)
lib/               # Project-specific libraries (unused)
test/              # Test files (unused)
```
