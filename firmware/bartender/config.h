#pragma once

#include <Arduino.h>

// Hardware pin mapping is intentionally not assigned yet.
// Confirm the exact Freenove FNK0084 board revision and its matching pinout
// before selecting GPIOs. Do not replace these placeholders with guessed pins.
static constexpr int PUMP_GPIO[4] = {-1, -1, -1, -1};

static constexpr uint8_t PUMP_COUNT = 4;

// Network configuration for the standalone ESP32 access point.
static constexpr char WIFI_AP_SSID[] = "Bartender";
static constexpr char WIFI_AP_PASSWORD[] = "change-this-password";
static constexpr uint16_t HTTP_PORT = 80;

// Dispensing safeguards. These are conservative software limits, not a
// substitute for electrical protection or a physical power disconnect.
static constexpr uint32_t MAX_SINGLE_PUMP_RUNTIME_MS = 120000UL;
static constexpr uint32_t MAX_RECIPE_RUNTIME_MS = 300000UL;
