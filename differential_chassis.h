#include <stdint.h>
#include "HW_Motor.h"

#define SUSPENDEDTANK_CHASSIS 1
#define SUSPENDEDTANK_WHEEL_DIAMETER 54.0 /* mm */
#define SUSPENDEDTANK_CORRECITION_FACTOR 1.0 /* mm */
#define SUSPENDEDTANK_SHAFT_LENGTH 152.8 /* mm */

#define TANK_CHASSIS 2
#define TANK_WHEEL_DIAMETER 54.0 /* mm */
#define TANK_CORRECITION_FACTOR 1.0 /* mm */
#define TANK_SHAFT_LENGTH 203.8 /* mm */ 

typedef struct
{
  float shaft_length;
  float wheel_diameter;
  float correction_factor;
  float v_r;
  float v_l;
  float rps_l;
  float rps_r;
  float go_forward_l_offset;
  float go_forward_r_offset;
  float go_back_l_offset;
  float go_back_r_offset;
  uint8_t motor_type;
} TankObjectTypeDef;

class Tank{
  private:
    TankObjectTypeDef tank;
    Motor motor;
  
  public:
    void begin(uint8_t type);
    void move(float vx, float omega);
    void set_velocity_radius(float linear, float r,  bool insitu);
    void set_offset(uint8_t mode, uint8_t wheel, float offset);
    float get_right_wheel_speed_result(void);
    float get_left_wheel_speed_result(void);
};
