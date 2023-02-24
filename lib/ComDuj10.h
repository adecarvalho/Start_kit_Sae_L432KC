#ifndef COM_DUJ10_H
#define COM_DUJ10_H
//
#include "mbed.h"

//
#define SEND_NO_SENSOR_BOARD 'h'
#define SEND_TEMPERATURE_SENSOR_BOARD 'e'
#define SEND_ROTATION_SENSOR_BOARD 'f'
#define SEND_LUX_SENSOR_BOARD 'g'
//
#define SEND_BTN_K_PRESSED 'w'
#define SEND_BTN_K_RELEASED 'v'
#define SEND_P0_ON 's'
#define SEND_P0_OFF 'r'
#define SEND_P1_ON 'u'
#define SEND_P1_OFF 't'
#define SEND_CALIBRATION_ON 'c'
#define SEND_CALIBRATION_OFF 'd'
//
#define RECEIVE_LED_OFF 'k'
#define RECEIVE_LED_ON 'l'
#define RECEIVE_VR_MINUS 'm'
#define RECEIVE_VR_MINUX_MAX 'r'
#define RECEIVE_VR_PLUS 'q'
#define RECEIVE_VR_PLUS_MAX 'p'
//
#define SEND_START_CHAR 'D'
#define SEND_STOP_TEMPERATURE 'T'
#define SEND_STOP_LUX 'L'
#define SEND_STOP_POT 'P'
//
#define SEND_TEMPERATURE_SENSOR_BOARD 'e'
#define SEND_ROTATION_SENSOR_BOARD 'f'
#define SEND_LUX_SENSOR_BOARD 'g'
/////////////
class ComDuj10 {
public:
  enum SensorBoard {
    NO_BOARD = 0,
    TEMPERATURE_BOARD = 1,
    ROTATION_BOARD = 2,
    LUX_BOARD = 3
  };

  ComDuj10(RawSerial *pc);

  ~ComDuj10();

  void receiveChar(char val);
  void sendCommand(char val);

  void sendP0(bool state);
  void sendP1(bool state);

  void sendBtnK(bool state);
  void sendBoardType(SensorBoard board);

  void sendCalibration(bool state);

  void sendTemperature(int temp);
  void sendRotation(int rot);
  void sendLux(int lum);

private:
  RawSerial *_pc;
};
// end class
#endif