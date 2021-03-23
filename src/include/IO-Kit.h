#ifndef IS_IOKIT_INCLUDED

#define IS_IOKIT_INCLUDED

class Output {
 public:
  Output(int pin);

  void set(bool val);
  void pwmSet(int val);

  Output& operator=(bool val);
  Output& operator<<(int val);

 private:
  int _pinNumber;
  bool _pinStatus;
  int _pinPwmStatus;
  bool _pwmExp = false;

  bool _isPwmUsed = false;
};

#endif