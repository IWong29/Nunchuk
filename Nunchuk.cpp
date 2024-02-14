#include "Arduino.h"
#include "Nunchuk.h"
#include "Wire.h"

Nunchuk::Nunchuk() {
  Wire.begin();
}
bool Nunchuk::begin() {
  int val1 = writeRegister(address, 0xF0, 0x55);
  int val2 = writeRegister(address, 0xFB, 0x00);
  return val1 + val2;
}
int Nunchuk::writeRegister(byte add, byte reg, byte val) {
  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.write(val);
  int res = Wire.endTransmission();
  delay(20);
  return res;
}
int Nunchuk::writeRegister(byte add, byte reg) {
  Wire.beginTransmission(add);
  Wire.write(reg);
  int val = Wire.endTransmission();
  delay(20);
  return val;
}
void Nunchuk::getData() {
  writeRegister(address, 0x00);
  Wire.requestFrom(address, 6);
  for (int i = 0; i < 6; i++) {
    data[i] = Wire.read();
  }
  aX = (data[2] << 2) | (bitRead(data[5], 3) << 1) | bitRead(data[5], 2);
  aY = (data[3] << 2) | (bitRead(data[5], 5) << 1) | bitRead(data[5], 4);
  aZ = (data[4] << 2) | (bitRead(data[5], 7) << 1) | bitRead(data[5], 6);
  jX = data[0];
  jY = data[1];
  z = !bitRead(data[5], 0);
  c = !bitRead(data[5], 1);
}
bool Nunchuk::getC() {
  getData();
  return c;
}
bool Nunchuk::getZ() {
  getData();
  return z;
}
int Nunchuk::getAccel(int axis) {
  getData();
  switch(axis)
  {
    case 0:
      return aX;
    case 1:
      return aY;
    case 2:
      return aZ;
    default:
      return -1;
  } 
}
int Nunchuk::getJoystick(int axis) {
  getData();
  switch(axis)
  {
    case 0:
      return jX;
    case 1:
      return jY;
    default:
      return -1;
  } 
}