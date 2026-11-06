#include <Arduino.h>
#include "config.h"

void allPumpsOff() {
  // GPIO setup is intentionally deferred until FNK0084 pin assignments
  // and EKM014 input polarity have been verified.
}

void setup() {
  Serial.begin(115200);

  // Safe startup policy: no pump GPIO is configured or activated until
  // the exact board pinout and driver logic have been confirmed.
  allPumpsOff();

  Serial.println();
  Serial.println("Bartender firmware starting");
  Serial.println("GPIO mapping is not configured; pump outputs remain inactive.");
}

void loop() {
  // Initial skeleton only. The pump state machine, Wi-Fi AP and HTTP API
  // will be implemented after hardware pin verification.
}
