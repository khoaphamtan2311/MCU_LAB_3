/*
 * initial.c
 *
 *
 *
 */
#include "initial.h"

int mode=1;
int red_value,yellow_value,green_value;
int red_manual,yellow_manual,green_manual;

void LedInitial(){
	red_value		= Red_time;
	yellow_value		= Yellow_time;
	green_value		= Green_time;
	red_manual		= red_value;
	yellow_manual		= yellow_value;
	green_manual		= green_value;
}

int getMode(){
	return mode;
}
