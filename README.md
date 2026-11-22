# Smart Home Environmental Monitoring System

An ESP32-based room monitor that reads temperature and relative humidity, detects motion, displays local status on an OLED, and sounds a buzzer while motion is detected. The supplied project is configured for Wokwi simulation.

## Features

- Reads temperature and humidity from a DHT22 sensor.
- Detects motion using a PIR sensor.
- Shows readings and motion status on a 128x64 SSD1306 OLED.
- Sounds a 1 kHz tone while the PIR output is HIGH.
- Prints readings and motion state to the serial monitor once per second.

## Hardware and pin map

| Part | ESP32 connection |
| --- | --- |
| DHT22 data | GPIO 4 |
| PIR output | GPIO 14 |
| Buzzer signal | GPIO 27 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| Peripherals power | 3V3 and GND as shown in `diagram.json` |

The OLED uses I2C address `0x3C`. Check voltage and current requirements for the exact physical modules before wiring a real board. Use a suitable driver if a buzzer draws more current than an ESP32 GPIO can safely supply.

## Run in Wokwi

1. Open [Wokwi](https://wokwi.com/) and create an ESP32 project.
2. Add the contents of `diagram.json` to the project's diagram file.
3. Add `ece.ino` as the sketch and `libraries.txt` as the library list.
4. Start the simulation. Use the PIR component's motion control to trigger the detection state.
5. Open the serial monitor at **115200 baud** to view sensor values and motion messages.

`wokwi-project.txt` records the original Wokwi project link supplied with the files.
