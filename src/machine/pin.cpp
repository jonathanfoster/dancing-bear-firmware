#include "machine/pin.h"

#include <Arduino.h>

namespace machine {

Pin::Pin(uint8_t id) {
  this->_id = id;
  this->init(OUTPUT);
}

Pin::Pin(uint8_t id, uint8_t mode) {
  this->_id = id;
  this->init(mode);
}

Pin::Pin(uint8_t id, uint8_t mode, uint8_t pull) {
  this->_id = id;
  this->init(mode, pull);
}

void Pin::init(uint8_t mode) { this->init(mode, LOW); }

void Pin::init(uint8_t mode, uint8_t pull) {
  this->pull(pull);
  this->mode(mode);
  pinMode(this->_id, mode);
  this->value(pull);
}

uint8_t Pin::id() { return this->_id; }

int Pin::debounce() { return this->_debounce; }

void Pin::debounce(int new_value) { this->_debounce = new_value; }

uint8_t Pin::mode() { return this->_mode; }

void Pin::mode(uint8_t new_value) { this->_mode = new_value; }

uint8_t Pin::pull() { return this->_pull; }

void Pin::pull(uint8_t new_value) { this->_pull = new_value; }

uint8_t Pin::value() { return this->_value; }

void Pin::value(uint8_t new_value) {
  if (this->mode() == OUTPUT) {
    digitalWrite(this->_id, new_value);
  }

  this->_value = new_value;
  this->_last_value = new_value;
}

void Pin::on() { this->value(HIGH); }

void Pin::off() { this->value(LOW); }

void Pin::toggle() {
  if (this->_value == HIGH) {
    this->off();
  } else {
    this->on();
  }
}

void Pin::low() { this->off(); }

void Pin::high() { this->on(); }

bool Pin::checkValue() {
  uint8_t current_value = this->readValue();
  if (current_value != this->_last_value || this->_last_debounce == 0) {
    this->_last_value = current_value;
    this->_last_debounce = millis();
  }

  bool value_changed = false;

  if (millis() - this->_last_debounce > this->_debounce) {
    if (current_value != this->value()) {
      value_changed = true;
      this->value(current_value);
      if (this->_change_handler) {
        this->_change_handler(this);
      }
    }
  }

  return value_changed;
}

void Pin::onChange(void (*handler)(Pin*)) { this->_change_handler = handler; }

uint8_t Pin::readValue() { return digitalRead(this->_id); }

}  // namespace machine
