# Wiring notes

This document records the intended electrical topology. It is not a pin-by-pin wiring diagram; GPIO assignments are deliberately pending confirmation of the exact FNK0084 board revision.

## Power topology

1. Regulated 12 V positive goes through the correctly sized main fuse to the EKM014 motor supply input (VH).
2. 12 V negative connects to EKM014 power GND.
3. The EKM014 channel outputs connect to the four pumps, one pump per channel.
4. The ESP32 is powered separately through USB-C.
5. ESP32 GND connects to the EKM014 logic GND.
6. Each ESP32 control GPIO connects to the corresponding EKM014 input (IN1–IN4), after the pinout and logic requirements are verified.

## Pump channel assignment

| Driver channel | Pump | Ingredient |
|---|---|---|
| CH1 | P1 | White Rum |
| CH2 | P2 | Gin |
| CH3 | P3 | Orange Juice |
| CH4 | P4 | Blue Curaçao |

For the EKM014 low-side outputs, follow the polarity labels printed on the actual board and its documentation. Do not assume that a channel's negative output terminal is a permanent ground connection.

## Wiring rules

- Keep pump-current wiring separate from low-current GPIO signal wiring.
- Use appropriately rated insulated wire and connectors.
- Fit ferrules to stranded wires used in screw terminals when compatible with the terminal size.
- Provide strain relief and protect exposed conductors.
- Keep a physical means of disconnecting the 12 V pump supply within reach.
- Verify all connections with a multimeter before connecting the pumps.

## Pending

Do not assign GPIO numbers or connect control wires until the exact FNK0084 pinout has been checked.
