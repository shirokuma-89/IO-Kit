#include "Arduino.h"
#include "IO-Kit.h"

Output::Output(int pin) {
  this->_pinNumber = pin;
  pinMode(this->_pinNumber, OUTPUT);
}

void Output::set(bool val) {
#ifdef _STM32_DEF_
  if (!this->_pwmExp) {
    digitalWrite(this->_pinNumber, val);
  } else {
    analogWrite(this->_pinNumber, val * 255);
  }
#else
  digitalWrite(this->_pinNumber, val);
#endif
  this->_pinStatus = val;
}

void Output::pwmSet(int val) {
  analogWrite(this->_pinNumber, val);
  this->_pinPwmStatus = val;

  if (!this->_pwmExp) {
    this->_pwmExp = true;
  }
}

Output& Output::operator=(bool val) {
  this->set(val);
  return *this;
}
