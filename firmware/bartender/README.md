# Firmware

Arduino IDE project for the ESP32-S3 cocktail dispenser.

## Current status

This is an intentionally non-operational firmware skeleton. It does not configure GPIOs, start Wi-Fi or activate pumps.

Before implementing pump control:

1. Identify the exact FNK0084 board revision.
2. Verify its official pinout and boot-strapping pin restrictions.
3. Verify EKM014 input polarity and logic requirements.
4. Assign four safe output GPIOs in `config.h`.
5. Bench-test the driver with pump power disconnected before connecting pumps.

The planned implementation uses a non-blocking `millis()`-based state machine so the HTTP server remains responsive during dispensing. STOP must cancel the current recipe and set every pump output inactive.
