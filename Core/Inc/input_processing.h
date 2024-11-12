#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "main.h"
#include "led_display.h"
#include "timer.h"
#include "initial.h"

void fsm_for_input_processing ( void );
void IncreaseManualValue();
void LedInitial();
void UpdateDurationValue();

#endif /* INC_INPUT_PROCESSING_H_ */
