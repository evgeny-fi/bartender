# Bartender

ESP32-S3-based, four-channel cocktail dispenser controlled from an iPad browser.

## Project status

**Stage:** Initial software and firmware setup.

The first firmware target is a safe, sequential pump controller with a local Wi-Fi access point and browser interface. Hardware-specific GPIO assignments are intentionally pending verification of the exact Freenove FNK0084 board revision and pinout.

## Hardware baseline

- Controller: Freenove FNK0084 (exact board revision/pinout to be verified)
- Pump driver: Electrokit EKM014, four-channel low-side MOSFET driver
- Pumps: 4 × Kamoer NKP, 12 V DC peristaltic pumps
- Supply: regulated 12 V DC supply for pumps and driver
- User interface: iPad Safari connected to the ESP32 access point

The ESP32 logic is powered separately over USB-C during development. The ESP32 and driver must share a common ground. Never connect the 12 V pump supply to an ESP32 5 V or 3.3 V pin.

## Firmware scope (v1)

- ESP32 creates its own Wi-Fi access point.
- iPad connects to the access point and opens `http://192.168.4.1`.
- Four pumps are controlled sequentially; only one pump may run at a time.
- Fixed 100 ml cocktail recipes; no serving-size scaling.
- Four ingredient channels: White Rum, Gin, Orange Juice and Blue Curaçao.
- Recipe and pump calibration settings are stored in ESP32 non-volatile storage.
- Two recipes have a layered preparation instruction: Barbados Sunrise and Gin Sunrise.
- A STOP command cancels the active dispense and switches all pump outputs off.
- Pump outputs default to OFF at startup and are never resumed automatically after reset.

## Repository layout

- `docs/` — hardware, wiring and calibration documentation
- `firmware/bartender/` — Arduino IDE firmware
- `web/` — browser interface assets (to be added)

## Development sequence

1. Verify the exact FNK0084 board pinout and safe GPIO choices.
2. Confirm the EKM014 input polarity and output wiring against its documentation.
3. Implement and bench-test the pump controller with pumps disconnected initially.
4. Add calibration and recipe management.
5. Add the Wi-Fi access point, HTTP API and iPad interface.
6. Test STOP, reset, timeout and fault-handling behavior before connecting liquids.

## Build

Open `firmware/bartender/bartender.ino` in Arduino IDE after selecting the correct ESP32-S3 board package and board variant. Complete the pin assignments in `config.h` only after confirming the FNK0084 pinout.

## Safety

Do not leave the dispenser unattended during testing. Use a physical way to disconnect the 12 V pump supply. Firmware STOP is not a substitute for physical power isolation.
