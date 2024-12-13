/*
 * scheduler.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Galaxy
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

// thêm 1 số thư viện
#include <stdint.h>

#define TICK 10

typedef struct {
	void (*pTask)(void);
	uint32_t	Delay; 	// giống software_timer
	uint32_t	Period;	// giống software_timer
	uint8_t		RunMe; 	// giống timer_flag
	uint32_t	TaskID;
} sTasks;

#define SCH_MAX_TASKS 40 // số lượng task

void SCH_Init(void);
void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD); // giống setTimer
void SCH_Update(void);  // giống timer_run
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Tasks(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
