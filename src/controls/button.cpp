#include "controls/button.h"

#include <Arduino.h>

namespace controls {

Button::Button(uint8_t pin) {
  this->_pin = pin;
  pinMode(this->_pin, INPUT);
}

void Button::checkState() {
  int current_state = digitalRead(_pin);
  if (current_state != this->_last_state) {
    this->_last_debounce_time = millis();
  }

  if (millis() - _last_debounce_time > _debounce_delay) {
    if (current_state != this->_state) {
      this->_state = current_state;
    }

    if (this->_state == HIGH) {
      if (this->_press_handler) {
        this->_press_handler();
      }
    }
  }

  this->_last_state = current_state;
}

void Button::onPress(void (*handler)()) { this->_press_handler = handler; }

}  // namespace controls
