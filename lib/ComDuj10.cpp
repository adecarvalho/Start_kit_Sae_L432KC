#include "lib/ComDuj10.h"
//
ComDuj10::ComDuj10(RawSerial *pc) {
  if (pc != nullptr) {
    _pc = pc;

    // indiquer a la carte pas de calibration
    _pc->putc(SEND_NO_SENSOR_BOARD);
    _pc->putc(SEND_CALIBRATION_OFF);
  }
}
//
ComDuj10::~ComDuj10() {
  if (_pc != nullptr) {
    delete _pc;
  }
}
//
void ComDuj10::receiveChar(char val) {}
//
void ComDuj10::sendCommand(char val) {
  if (_pc != nullptr) {
    _pc->putc(val);
  }
}
//
void ComDuj10::sendCalibration(bool state) {
  if (state) {
    sendCommand(SEND_CALIBRATION_ON);
  } else {
    sendCommand(SEND_CALIBRATION_ON);
  }
}
//
void ComDuj10::sendTemperature(int temp) {
  //
  _pc->putc(SEND_START_CHAR);
  _pc->printf("%d", temp);
  _pc->putc(SEND_STOP_TEMPERATURE);
}
//
void ComDuj10::sendRotation(int rot) {}
//
void ComDuj10::sendLux(int lum) {}
//
void ComDuj10::sendP0(bool state) {
  if (state) {
    sendCommand(SEND_P0_ON);
  } else {
    sendCommand(SEND_P0_OFF);
  }
}
//
void ComDuj10::sendP1(bool state) {
  if (state) {
    sendCommand(SEND_P1_ON);
  } else {
    sendCommand(SEND_P1_OFF);
  }
}
//
void ComDuj10::sendBtnK(bool state) {
  if (state) {
    sendCommand(SEND_BTN_K_PRESSED);
  } else {
    sendCommand(SEND_BTN_K_RELEASED);
  }
}
//
void ComDuj10::sendBoardType(SensorBoard board) {
  switch (board) {
  case NO_BOARD:
    sendCommand(SEND_NO_SENSOR_BOARD);
    break;
  //
  case TEMPERATURE_BOARD:
    sendCommand(SEND_TEMPERATURE_SENSOR_BOARD);
    break;
  //
  case ROTATION_BOARD:
    sendCommand(SEND_ROTATION_SENSOR_BOARD);
    break;
  //
  case LUX_BOARD:
    sendCommand(SEND_LUX_SENSOR_BOARD);
    break;
  //
  default:
    break;
  }
}