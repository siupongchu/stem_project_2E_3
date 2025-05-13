#include "differential_chassis.h"

typedef enum
{
  NULL_KEY = 0,
  STOP,
  GO_FORWARD,
  TURN_LEFT,
  TURN_RIGHT,
  GO_BACK,
  SPEED_UP,
  SPEED_DOWN,
  LEFT_SPIN,
  RIGHT_SPIN
}Mode_State;

// 定义键值对结构
typedef struct {
    const char *value;
    Mode_State key;
} HashTableEntry;

/* 哈希表 */
#define TABLE_SIZE 9
HashTableEntry table[TABLE_SIZE] = {
    {"A", GO_FORWARD},
    {"C", TURN_LEFT},
    {"G", TURN_RIGHT},
    {"E", GO_BACK},
    {"I", STOP},
    {"j", SPEED_UP},
    {"n", SPEED_DOWN},
    {"l", LEFT_SPIN},
    {"p", RIGHT_SPIN}
};


Tank tank;
Mode_State key = NULL_KEY;

float speed = 150.0f;
float speed_limit = 300.0f;

// 查找函数
Mode_State lookup(char val)
{
    for (int i = 0; i < TABLE_SIZE && table[i].value != NULL; ++i)
    {
        if (strcmp(table[i].value, &val) == 0)
        {
            return table[i].key;
        }
    }
    return NULL_KEY;
}

void setup() {
  Serial.begin(9600);
  tank.begin(TANK_CHASSIS);  //选择履带底盘
  tank.set_offset(1, 1, 0.14);      //设置前进左轮偏差
  tank.set_offset(2, 2, 0.05);      //设置后退右轮偏差
}

void loop() {
  /*
  if(Serial.available() > 0)
  {
    char cmd;
    cmd = Serial.read();
    key = lookup(cmd);


    switch(key)
    {
    case STOP:
      tank.move(0, 0.0f);
      break;

    case GO_FORWARD:
      tank.move(speed, 0.0f);
      break;

    case TURN_LEFT:
      tank.move(speed/1.5, -0.5f);
      break;

    case TURN_RIGHT:
      tank.move(speed/1.5, 0.5f);
      break;

    case GO_BACK:
      tank.move(-speed, 0.0f);
      break;

    case SPEED_UP:
      if(speed < speed_limit)
      {
          speed += 10.0f;
      }
      break;

    case SPEED_DOWN:
      if(speed > 0)
      {
          speed -= 10.0f;
      }
      break;
    
    case LEFT_SPIN:
      tank.move(0, -2.0f);
      break;
    
    case RIGHT_SPIN:
      tank.move(0, 2.0f);
      break;

    default:
      break;
    }
    key = NULL_KEY;
  }
  */
  tank.move(200, 0.0f);
  delay(3000);
  tank.move(0, 0.0f);
  delay(3000);
  tank.move(1.5,-0.5f);
  delay(2000);
  tank.move(1.5,0.5f);
  delay(2000);
}
