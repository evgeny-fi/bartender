# Pump calibration

Calibrate each pump independently using the actual tubing, liquid and operating arrangement that will be used in the dispenser.

## Procedure

1. Prime the pump and tubing.
2. Place the outlet into a graduated cylinder or weigh the dispensed liquid on a suitable scale.
3. Run the pump for a measured interval (for example, 30–60 seconds).
4. Record the delivered volume.
5. Repeat at least three times and calculate the mean flow rate.
6. Repeat separately for P1–P4. Recalibrate after changing tubing or materially changing the liquid or setup.

For a timed run:

`flow_ml_per_min = delivered_volume_ml / runtime_seconds * 60`

For a requested volume:

`runtime_seconds = requested_volume_ml / flow_ml_per_min * 60`

Example only: at 70 ml/min, dispensing 50 ml requires approximately 42.9 seconds.

## Calibration record

| Pump | Ingredient | Run 1 (ml/min) | Run 2 (ml/min) | Run 3 (ml/min) | Mean (ml/min) |
|---|---|---:|---:|---:|---:|
| P1 | White Rum | | | | |
| P2 | Gin | | | | |
| P3 | Orange Juice | | | | |
| P4 | Blue Curaçao | | | | |

Record the tubing ID/OD, liquid, supply voltage and test date alongside calibration results. Do not assume all four pumps have identical flow rates.
