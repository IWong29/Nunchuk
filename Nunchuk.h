#ifndef Nunchuk_h
#define Nunchuk_h
#include "Arduino.h"

class Nunchuk {
  public:
    Nunchuk();
    bool begin();
    bool getC();
    bool getZ();
    int getJoystick(int axis);
    int getAccel(int axis);

  private:
    int aX;
    int aY;
    int aZ;
    int jX;
    int jY;
    bool c;
    bool z;
    byte data[6];
    const byte address = 0x52;
    int writeRegister(byte add, byte reg, byte val);
    int writeRegister(byte add, byte reg);
    void getData();
};

#endif