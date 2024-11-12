/*
 * input_processing.c
 *
 *
 *
 */
#include "main.h"
#include "initial.h"
#include "input_reading.h"
#include "led_display.h"

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED ,BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
enum ButtonState buttonState[3] = {BUTTON_RELEASED} ;

void fsm_for_input_processing ( void ){
	switch ( buttonState[0] ){
	case BUTTON_RELEASED :
		if( is_button_pressed (0)){
			buttonState[0] = BUTTON_PRESSED ;
			mode++;
			if (mode>4){
				mode=1;
				resetToInitial();
			}
			// INCREASE VALUE OF PORT A BY ONE UNIT
		}
		break ;
	case BUTTON_PRESSED :
		if (! is_button_pressed (0)){
			buttonState[0] = BUTTON_RELEASED ;
		}
		break ;
	default:
		break;
	}
}

void IncreaseManualValue(){
	switch (mode){
	case 2:
		red_manual++;
		if (red_manual>99) red_manual =0;
		break;
	case 3:
		yellow_manual++;
		if (yellow_manual >99) yellow_manual=0;
		if (yellow_manual + green_value >= red_value) yellow_manual--;
		break;
	case 4:
		green_manual++;
		if (green_manual >99) green_manual=0;
		if (green_manual > red_value - 1) green_manual = red_value - 1;
		break;
	default:
		break;
	}
}

void setDurationValue(){
	int dif=0;
	switch (mode){
	case 2:
		dif= red_manual-red_value;
		red_value=red_manual;
		green_value+=dif;
		green_manual+=dif;
		break;
	case 3:
		dif=yellow_manual-yellow_value;
		yellow_value=yellow_manual;
		red_value+=dif;
		red_manual+=dif;
		break;
	case 4:
		dif=green_manual-green_value;
		green_value=green_manual;
		yellow_value-=dif;
		yellow_manual-=dif;
		break;
	default:
		break;
	}
}
void UpdateDurationValue() {
	switch (buttonState[1]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1)) {
				buttonState[1] = BUTTON_PRESSED;
				IncreaseManualValue();
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1)) {
				buttonState[1] = BUTTON_RELEASED;
			}
			if (is_button_pressed_1s(1)) {
				buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				IncreaseManualValue();
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1)) {
				buttonState[1] = BUTTON_RELEASED;
			}
			if (is_button_held(1)) {
				resetHoldingFlag(1);
				IncreaseManualValue();
			}
			break;
		default:
			break;
	}

	switch (buttonState[2]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(2)) {
				buttonState[2] = BUTTON_PRESSED;
				setDurationValue();
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(2)) {
				buttonState[2] = BUTTON_RELEASED;
			}
			break;
		default:
			break;
	}
}

