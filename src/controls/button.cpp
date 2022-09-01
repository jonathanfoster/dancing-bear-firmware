#include "controls/button.h"

#include <Arduino.h>

namespace controls {

Button::Button(uint8_t pin) {
  this->_pin = pin;
  this->setup();
}

Button::Button(uint8_t pin, int default_pin_state) {
  this->_pin = pin;
  this->_default_pin_state = default_pin_state;
  this->setup();
}

unsigned long Button::debounce() { return this->_debounce; }

void Button::debounce(unsigned long value) { this->_debounce = value; }

void Button::checkState() {
  bool current_is_pressed = this->checkIsPressed();
  if (current_is_pressed != this->_last_is_pressed) {
    this->_last_is_pressed = current_is_pressed;
    this->_last_debounce = millis();
  }

  if (millis() - this->_last_debounce > this->_debounce) {
    if (current_is_pressed == this->_is_pressed) {
      return;
    }

    if (this->_is_pressed && !current_is_pressed) {
      if (this->_press_handler) {
        this->_press_handler();
      }
    }

    this->_is_pressed = current_is_pressed;
  }
}

void Button::onPress(void (*handler)()) { this->_press_handler = handler; }

bool Button::checkIsPressed() {
  return digitalRead(this->_pin) != this->_default_pin_state;
}

void Button::setup() { pinMode(this->_pin, INPUT); }

}  // namespace controls
