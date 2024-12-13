/*
 * global.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Galaxy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "traffic_light.h"
#include "led7_segment.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_setting.h"
#include "scheduler.h"

//define các trạng thái toàn hệ thống
#define AUTO 			1
#define RED_LED 		2
#define YELLOW_LED 		3
#define GREEN_LED 		4

//define trạng thái đèn giao thông mỗi chiều (AUTO)
#define RED_VER			5
#define YELLOW_VER		6
#define GREEN_VER		7

#define RED_HOR			8
#define YELLOW_HOR		9
#define GREEN_HOR		10

//define trạng thái modify time duration từng led màu
#define RED_MODIFY		11
#define YELLOW_MODIFY	12
#define GREEN_MODIFY	13

//đỏ
extern int time_red_ver;			//time đèn đỏ (auto) của đèn giao thông chiều dọc
extern int time_red_hor;			//time đèn đỏ (auto) của đèn giao thông chiều ngang
extern int time_red_ver_temp;		//biến để countdown đèn đỏ của đèn giao thông chiều dọc
extern int time_red_hor_temp;		//biến để countdown time đèn đỏ của đèn giao thông chiều ngang
//vàng
extern int time_yellow_ver;
extern int time_yellow_hor;
extern int time_yellow_ver_temp;
extern int time_yellow_hor_temp;
//xanh
extern int time_green_ver;
extern int time_green_hor;
extern int time_green_ver_temp;
extern int time_green_hor_temp;

//đếm time cho led nhấp nháy 2Hz
extern int count_toggle_led;

//đếm time cho đèn giao thông auto
extern int count_down_ver;
extern int count_down_hor;

//đếm time hiển thị led7SEG
extern int count_led7SEG;

#endif /* INC_GLOBAL_H_ */
