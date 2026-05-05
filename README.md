# ESP32 Temperature and Light Sensor

A PlatformIO project for the DFRobot FireBeetle 2 ESP32-E that reads temperature, humidity, and ambient light from three sensors and displays live readings on an SSD1306 OLED.

## What it does

- Reads temperature and humidity from one DHT22 and two DHT11 sensors every five seconds
- Computes a heat index from each sensor's readings
- Measures ambient light level in lux via a BH1750 sensor
- Prints all readings to the serial monitor at 115200 baud
- Alternates the OLED display between a temperature view and a humidity view

## Hardware

| Component | Detail |
| --------- | ------ |
| Microcontroller | DFRobot FireBeetle 2 ESP32-E |
| DHT22 | Pin D7 — temperature and humidity, higher accuracy |
| DHT11 #1 | Pin D6 — temperature and humidity |
| DHT11 #2 | Pin D5 — temperature and humidity |
| BH1750 | I2C — ambient light level (lux) |
| SSD1306 OLED | I2C, address 0x3C, 128×32 pixels — live display |

The BH1750 and SSD1306 share the I2C bus (SDA/SCL).

## Wiring

```
DHT22  DATA → D7
DHT11#1 DATA → D6
DHT11#2 DATA → D5

BH1750  SDA → SDA
        SCL → SCL
        VCC → 3.3 V
        GND → GND

SSD1306 SDA → SDA
        SCL → SCL
        VCC → 3.3 V
        GND → GND
```

## Setup

### Prerequisites

- [PlatformIO](https://platformio.org/) (VS Code extension or CLI)
- DFRobot FireBeetle 2 ESP32-E connected via USB

### Build and upload

```bash
pio run --target upload
```

Open the serial monitor:

```bash
pio device monitor --baud 115200
```

Libraries are declared in `platformio.ini` and installed automatically by PlatformIO on first build:

| Library | Purpose |
| ------- | ------- |
| `adafruit/DHT sensor library` | DHT22 and DHT11 sensor reading |
| `adafruit/Adafruit Unified Sensor` | Sensor abstraction layer |
| `adafruit/Adafruit SSD1306` | OLED display driver |
| `claws/BH1750` | BH1750 ambient light sensor |

## Serial output format

Each loop iteration prints readings from all three sensors followed by the light level:

```
DHT22 -=-Humidity: 52.40%  Temperature: 22.30°C -- Heat index: 21.87°C
DHT11 No.1 -=-Humidity: 54.00%  Temperature: 23.00°C -- Heat index: 22.61°C
DHT11 No.2 -=-Humidity: 53.00%  Temperature: 22.00°C -- Heat index: 21.57°C
Light: 312.50 lx
```

## Project structure

```
├── src/
│   └── main.cpp        # Sensor reads, OLED output, serial logging
├── include/            # Project headers (currently empty)
├── lib/                # Local libraries (currently empty)
├── test/               # Unit tests (currently empty)
└── platformio.ini      # Board, framework, upload port, and library declarations
```
