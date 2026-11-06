# Hardware baseline

## Confirmed project selections

| Component | Selection | Notes |
|---|---|---|
| Controller | Freenove FNK0084 | Exact PCB revision, ESP32-S3 variant and pinout must be checked against the physical board and its matching documentation before GPIO selection |
| Pump driver | Electrokit EKM014 | Four-channel MOSFET driver; intended for low-side switching |
| Pumps | 4 × Kamoer NKP, 12 V DC | One pump per ingredient |
| Pump supply | Regulated 12 V DC | Verify connector polarity and measure pump startup/stall current before final fuse selection |
| User interface | iPad Safari | Connects to ESP32-hosted Wi-Fi AP |

## Ingredient assignment

| Pump | Ingredient |
|---|---|
| P1 | White Rum |
| P2 | Gin |
| P3 | Orange Juice |
| P4 | Blue Curaçao |

## Power and grounding

- The 12 V supply powers the pump side of the EKM014.
- The ESP32 is powered separately through USB-C during development.
- Connect ESP32 GND to the EKM014 logic GND so the control signals have a common reference.
- Never apply 12 V to ESP32 5 V, 3V3 or GPIO pins.
- Use suitable wire gauge, strain relief and insulated terminals.
- Use bootlace ferrules for stranded conductors in screw-clamp terminals where appropriate; do not tin stranded wire ends for screw terminals.

## Current and fuse sizing

The pump documentation previously reviewed indicates approximately 0.3 A nominal current per 12 V pump, but this is not a verified startup or stall-current value. Four pumps are expected to draw approximately 1.2 A total at that nominal figure. The v1 firmware will run only one pump at a time.

Do not finalize the main fuse solely from nominal current. Measure the actual operating and startup current, then select a fuse that protects the wiring and tolerates normal startup. The driver board's fitted fuse does not replace appropriate upstream protection.

## Items to verify before GPIO implementation

- Exact FNK0084 PCB revision and matching pinout.
- Which pins are exposed and safe for output use at boot.
- EKM014 input logic behavior and any required driver supply/jumper arrangement.
- Pump startup and stall current.
- Actual PSU output connector, polarity and current rating.
