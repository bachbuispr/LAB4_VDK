/*
 * fsm_automatic.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Galaxy
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"

//biến xác định chế độ tự động
extern int manual_auto;

//biến trạng thái đèn giao thông chiều dọc và ngang
extern int status_traffic_ver;
extern int status_traffic_hor;

////mảng lưu trữ thời gian từng đèn mỗi chiều
//extern int traffic_buffer_ver[3]; //ví dụ số 0 cho đèn xanh, số 1 cho đèn đỏ, số 2 cho đèn vàng
//extern int traffic_buffer_hor[3];

void task_traffic_ver_red();
void task_traffic_ver_green();
void task_traffic_ver_yellow();

void task_traffic_hor_red();
void task_traffic_hor_green();
void task_traffic_hor_yellow();

void fsm_traffic_ver();
void fsm_traffic_hor();
void fsm_automatic();

#endif /* INC_FSM_AUTOMATIC_H_ */
