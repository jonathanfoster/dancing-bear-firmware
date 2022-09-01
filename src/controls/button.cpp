#include "controls/button.h"

#include <Arduino.h>

#include "logging/logger.h"

namespace controls {

logging::Logger* logger = new logging::Logger("button");

Button::Button(uint8_t pin) {
  this->_pin = pin;
  this->setup();
}

Button::Button(uint8_t pin, int default_state) {
  this->_pin = pin;
  this->_default_state = default_state;
  this->setup();
}

unsigned long Button::debounce() { return this->_debounce; }

void Button::debounce(unsigned long value) { this->_debounce = value; }

void Button::checkState() {
  int current_state = digitalRead(this->_pin);
  if (current_state != this->_last_state) {
    this->_last_debounce = millis();
  }

  if (millis() - this->_last_debounce > this->_debounce) {
    if (current_state != this->_state) {
      this->_state = current_state;
    }

    if (this->_state != this->_default_state) {
      if (this->_press_handler) {
        this->_press_handler();
      }
    }
  }

  this->_last_state = current_state;
}

void Button::onPress(void (*handler)()) { this->_press_handler = handler; }

void Button::setup() {
  pinMode(this->_pin, INPUT);
  this->_last_state = this->_default_state;
}

}  // namespace controls
