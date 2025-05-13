#ifndef HW_Motor_h
#define HW_Motor_h

#include "Arduino.h"
#include "inttypes.h"

#define DEV_ADDR 0x32

#define SET_SPEED_ADDR            0xC0

#define GET_SPEED_ADDR            0xC1

#define GET_ENCODER_COUNT_ADDR    0xC2

#define CLEAR_ENCODER_COUNT_ADDR  0xC3

#define MOTOR_TYPE_TT             0xCA

#define MOTOR_TYPE_JGB37_520R30      0xCB

#define MOTOR_TYPE_JGB37_528R131      0xCC

#define MOTOR_TYPE_JGB3865_520R45      0xCD

class Motor
{
  public:
    void begin();
    bool set_speed(uint8_t motor_type, uint8_t id, uint8_t mode, float velocity);
    float get_speed(uint8_t id);
    uint16_t get_encoder_count(uint8_t id);
    bool clear_encoder_count(uint8_t id);   
};

#endif
