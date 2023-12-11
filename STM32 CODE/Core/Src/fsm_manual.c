/*
 * fsm_manual.c
 *
 *  Created on: 12 Sep 2023
 *      Author: duvan
 */
#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, 0);
		HAL_GPIO_WritePin(AMBER_GPIO_Port, AMBER_Pin, 1);
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, 1);
		if(timer1_flag==1){
			status = AUTO_RED;
			setTimer1(500);
		}
		if(isButtonPressed(1)){
			status = MAN_GREEN;
			setTimer1(1000);
		}
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, 1);
		HAL_GPIO_WritePin(AMBER_GPIO_Port, AMBER_Pin, 1);
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, 0);
		if(timer1_flag==1){
			status = AUTO_AMBER;
			setTimer1(200);
		}
		if(isButtonPressed(1)){
			status = MAN_AMBER;
			setTimer1(1000);
		}
		break;
	case MAN_AMBER:
		HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, 1);
		HAL_GPIO_WritePin(AMBER_GPIO_Port, AMBER_Pin, 0);
		HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, 1);
		if(timer1_flag==1){
			status = AUTO_RED;
			setTimer1(500);
		}
		if(isButtonPressed(1)){
			status = MAN_RED;
			setTimer1(1000);
		}
		break;
	default:
		break;
	}
}

