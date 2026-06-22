# ESP32 Temperature and Light Sensor

An environmental monitoring station built with an ESP32 microcontroller. Reads temperature, humidity, and ambient light levels from multiple sensors and displays readings on an OLED screen and via serial output.

The project uses three DHT sensors simultaneously (one DHT22 and two DHT11 units) to allow cross-comparison of sensor accuracy, alongside a BH1750 digital light sensor for lux readings.

## Features

- Temperature and humidity readings from a DHT22 sensor displayed on a 128x32 OLED screen
- Parallel readings from two DHT11 sensors output to serial for accuracy comparison
- Ambient light level measurement (lux) via a BH1750 I2C sensor
- OLED display alternates between temperature and humidity on a 5-second cycle
- Error detection for failed sensor reads

## Hardware Requirements

| Component | Details |
|---|---|
| Board | DFRobot FireBeetle 2 ESP32-E |
| DHT22 sensor | 1x, connected to pin D7 |
| DHT11 sensors | 2x, connected to pins D6 and D5 |
| BH1750 light sensor | I2C (default address, shared bus) |
| SSD1306 OLED display | 128x32 pixels, I2C at address 0x3C |

The BH1750 and SSD1306 share the default I2C bus (SDA/SCL).

## Dependencies

| Library | Version |
|---|---|
| Adafruit DHT sensor library | ^1.4.6 |
| Adafruit Unified Sensor | ^1.1.14 |
| Adafruit SSD1306 | ^2.5.11 |
| claws/BH1750 | ^1.3.0 |

## Build and Upload

This project uses [PlatformIO](https://platformio.org/) with the Arduino framework on the Espressif32 platform.

```bash
# Build the firmware
pio run

# Upload to the board
pio run --target upload

# Monitor serial output (115200 baud)
pio device monitor --baud 115200
```

The upload port is configured as COM3 in `platformio.ini`. Update this to match your system.

## Project Structure

```
ESP32-Temp-and-Light-Sensor/
  platformio.ini          # Build configuration and dependencies
  src/
    main.cpp              # Application code (sensor reads, display, serial output)
  lib/                    # Private libraries (unused)
  include/                # Header files (unused)
  test/                   # PlatformIO test runner (unused)
```

## Notes

- All temperatures are in Celsius.
- The OLED displays data from the DHT22 only (the more accurate sensor). DHT11 readings are serial-only, used for comparison.
- The project was developed iteratively: starting with basic hardware tests, then adding sensors individually to debug a temperature discrepancy between the DHT22 and DHT11 units.
