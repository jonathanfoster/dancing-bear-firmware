#include "machine/button.h"

#include <Arduino.h>

namespace machine {

Button::Button(uint8_t id) { this->_pin = new Pin(id, INPUT, HIGH); }

Button::Button(uint8_t id, uint8_t pull) {
  this->_pin = new Pin(id, INPUT, pull);
}

bool Button::checkValue() {
  bool value_changed = this->_pin->checkValue();

  if (value_changed) {
    if (this->_pin->value() == this->_pin->pull()) {
      if (this->_press_handler) {
        this->_press_handler(this);
      }
    }
  }

  return value_changed;
}

void Button::onPress(void (*handler)(Button*)) {
  this->_press_handler = handler;
}

}  // namespace machine
