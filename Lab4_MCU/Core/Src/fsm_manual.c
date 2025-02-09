/*
 * fsm_manual.c
 *
 *
 *  Created on: Nov 20, 2024
 *      Author: Galaxy
 */
#include "fsm_manual.h"

int status_system = AUTO;

void fsm_manual() {
	switch(status_system) {
		case AUTO: //đèn hoạt động bình thường
			//button1
			if (isButtonPressed(0) == 1) {
				status_system = RED_LED;
			}
			break;
		case RED_LED: //thiết lập time  4 led red
			status_modify = RED_MODIFY;
			//button3
			if (isButtonPressed(2) == 1) {
				time_red_ver_temp = time_red_ver;
				time_red_hor_temp = time_red_hor;
			}
			//button1
			if (isButtonPressed(0) == 1) {
				status_system = YELLOW_LED;
			}
			break;
		case YELLOW_LED: //thiết lập time 4 led yellow
			status_modify = YELLOW_MODIFY;
			//button3
			if (isButtonPressed(2) == 1) {
				time_yellow_ver_temp = time_yellow_ver;
				time_yellow_hor_temp = time_yellow_hor;
				//sau khi check cập nhật lại countdown đèn đỏ
				time_red_ver_temp = time_red_ver;
				time_red_hor_temp = time_red_hor;
			}
			//button1
			if (isButtonPressed(0) == 1) {
				status_system = GREEN_LED;
			}
			break;
		case GREEN_LED: ////thiết lập time 4 led green
			status_modify = GREEN_MODIFY;
			//button3
			if (isButtonPressed(2) == 1) {
				time_green_ver_temp = time_green_ver;
				time_green_hor_temp = time_green_hor;
				//sau khi check cập nhật lại countdown đèn đỏ
				time_red_ver_temp = time_red_ver;
				time_red_hor_temp = time_red_hor;
			}
			//button1
			if (isButtonPressed(0) == 1) {
				status_traffic_ver = RED_VER;
				status_traffic_hor = GREEN_HOR;
				status_system = AUTO;
			}
			break;
	}
	//hiển thị led
	update_7SEG_ver(idx_vertical);
	idx_vertical++;
	if(idx_vertical == 2) {
		idx_vertical = 0;
	}

	update_7SEG_hor(idx_horizontal);
	idx_horizontal++;
	if (idx_horizontal == 2) {
		idx_horizontal = 0;
	}
}
