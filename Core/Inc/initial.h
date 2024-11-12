/*
 * initial.h
 *
 *  Created on: Nov 3, 2023
 *      Author: 84869
 */

#ifndef INC_INITIAL_H_
#define INC_INITIAL_H_

#define Red_time 	5
#define Yellow_time 2
#define Green_time 	3

void LedInitial();

extern int mode;
extern int red_value,yellow_value,green_value;
extern int red_manual,yellow_manual,green_manual;

#endif /* INC_INITIAL_H_ */
