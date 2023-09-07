#include "Encoder.h"


static uint16_t value;
static uint16_t newCount;
static uint16_t prevCount;

void Encoder_Init(void) {
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
}

uint16_t Encoder_Read() {
 value = __HAL_TIM_GET_COUNTER(&htim2);
  return value;
}

Encoder_Status Encoder_Get_Status()
{
  newCount = Encoder_Read();
  if (newCount != prevCount) {
    if (newCount > prevCount) {
      prevCount = newCount;
      return Incremented;
    }
    else
    {
      prevCount = newCount;
      return Decremented;
    }
  }
  return Neutral;
}
