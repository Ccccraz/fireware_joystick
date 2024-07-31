#include <Arduino.h>
#include "listener.h"
#include "joystick.h"

uint8_t cmd_report{0x10};

constexpr simia::Stick define{
  .left = 1,
  .right = 2,
  .up = 3,
  .down = 4
};

simia::Joystick joystick{define};

simia::Listener sender{115200};

void setup() {
}

void loop() {
  auto result = joystick.read();
  if (result != simia::DIRECTION::CENTER)
  {
    uint8_t buf[2]{cmd_report, static_cast<uint8_t>(result)};
    sender.send(buf, sizeof(buf));
  }
  
}