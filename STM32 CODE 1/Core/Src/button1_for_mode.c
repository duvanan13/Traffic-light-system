/*
 * button1_for_mode.c
 *
 *  Created on: 13 Sep 2023
 *      Author: duvan
 */
#include "button1_for_mode.h"
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"
#include "mode4.h"
void mode_run(){
	switch(status){
		case 0:
			if(isButtonPressed(0)){	// nhan button 1 se chuyen sang trang thai tiep theo
				status = 1;		// trang thai cua may trang thai
				modamber = 2;	// thoi gian den vang ban dau
				modgreen= 3;	// thoi gian den xanh ban dau
				modred= 5;		// thoi gian den do ban dau
				counter0 = modamber + modgreen + modred;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				x = modred/10;	// x de luu hang chuc cua gia tri den led do
				y = modred%10;	// y de luu hang don vi cua gia tri den led do
				x1 = modgreen/10; 	// x1 de luu hang chuc cua gia tri den led xanh
				t1 = modgreen%10;	// t1 de luu hang don vi cua gia tri den led xanh
				x2 = modamber/10;	// x2 de luu hang chuc cua gia tri den led vang
				y2 = modamber%10;	// y2 de luu hang don vi cua gia tri den led vang
			}
			break;
		case 1:
			mode1_run();
			if(isButtonPressed(0)){	// nhan button 1 se chuyen sang trang thai tiep theo
				status = 2;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				display7SEG(0);
			}
			break;
		case 2:
			mode2_run();
			if(isButtonPressed(0)){ // nhan button 1 se chuyen sang trang thai tiep theo
				status = 3;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				display7SEG(0);
			}
			break;
		case 3:
			mode3_run();
			if(isButtonPressed(0)){ // nhan button 1 se chuyen sang trang thai tiep theo
				status = 4;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				display7SEG(0);
			}
			break;
		case 4:
			mode4_run();
			if(isButtonPressed(0)){	// nhan button 1 se chuyen sang trang thai tiep theo
				// thay doi gia tri cac den led thanh gia tri moi sau khi tang
				x = modred/10;
				y = modred%10;
				x1 = modgreen/10;
				t1 = modgreen%10;
				x2 = modamber/10;
				y2 = modamber%10;
				counter0 = modamber+modgreen+modred;
				status = 1;
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
				display7SEG(0);
			}
			break;
		default:
			break;
	}
}
