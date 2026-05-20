# ESP32 Temperature, Humidity and Light Sensor

Firmware for a DFRobot Firebeetle 2 ESP32-E that reads temperature and humidity from a DHT22 and two DHT11 sensors, measures ambient light with a BH1750 lux meter, and displays readings on an SSD1306 128x32 OLED display.

This is a local-only prototype with no wireless connectivity. Readings are logged to the serial monitor and alternated on the OLED every five seconds. For a production version that adds WiFi, MQTT, Home Assistant auto-discovery, OTA updates, and non-blocking cooperative scheduling, see [firebeetle-sensor-hub](https://github.com/JWhite212/firebeetle-sensor-hub).

## Hardware

| Component | Interface | Pin |
|-----------|-----------|-----|
| DHT22 (AM2302) | 1-wire | D7 |
| DHT11 No.1 | 1-wire | D6 |
| DHT11 No.2 | 1-wire | D5 |
| BH1750 ambient light | I2C (0x23) | SDA 21 / SCL 22 |
| SSD1306 OLED 128x32 | I2C (0x3C) | SDA 21 / SCL 22 |

Each DHT data pin requires a 4.7 kΩ pull-up resistor to 3.3 V. Many DHT breakout boards include this resistor on-board.

## Behaviour

On each 5-second tick the firmware:

1. Reads temperature, humidity, and heat index from all three sensors.
2. Reads ambient lux from the BH1750.
3. Logs all readings to the serial monitor at 115200 baud.
4. Alternates the OLED between the DHT22 temperature and humidity readings (5 seconds each).

## Getting started

### Prerequisites

- [PlatformIO Core](https://platformio.org/install) or the VS Code PlatformIO extension
- DFRobot Firebeetle 2 ESP32-E wired per the table above

### Build and flash

```bash
pio run -e dfrobot_firebeetle2_esp32e -t upload
```

### Serial monitor

```bash
pio device monitor
```

Baud rate: 115200.

## Libraries

Declared in `platformio.ini`:

| Library | Version | Purpose |
|---------|---------|---------|
| `adafruit/DHT sensor library` | `^1.4.6` | DHT22 and DHT11 reads |
| `adafruit/Adafruit Unified Sensor` | `^1.1.14` | Unified sensor abstraction layer |
| `adafruit/Adafruit SSD1306` | `^2.5.11` | OLED display driver |
| `claws/BH1750` | `^1.3.0` | BH1750 lux meter driver |

## Licence

TBD.
