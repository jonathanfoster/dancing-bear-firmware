#include "controls/button.h"

#include <Arduino.h>

namespace controls {

Button::Button(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
}

void Button::checkState() {
  int current_state = digitalRead(_pin);
  if (current_state != _last_state) {
    _last_debounce_time = millis();
  }

  if (millis() - _last_debounce_time > _debounce_delay) {
    if (current_state != _state) {
      _state = current_state;
    }

    if (_state == HIGH) {
      if (_press_handler) {
        _press_handler();
      }
    }
  }

  _last_state = current_state;
}

void Button::onPress(void (*handler)()) { _press_handler = handler; }

}  // namespace controls
