/*
 * scheduler.c
 *
 *
 *  Created on: Nov 20, 2024
 *      Author: Galaxy
 */

#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void) {
	for (int i = 0; i < current_index_task; i++) {
		SCH_Delete_Tasks(i);
	}
}

void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	if (current_index_task < SCH_MAX_TASKS) {
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY / TICK;
		SCH_tasks_G[current_index_task].Period = PERIOD / TICK;
		SCH_tasks_G[current_index_task].RunMe = 0;
		SCH_tasks_G[current_index_task].TaskID = current_index_task;
		current_index_task++;
	}
}

void SCH_Update(void) {
	for (int i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].Delay > 0) {
			SCH_tasks_G[i].Delay--;
		}
		else {
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void) {
	for (int i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].RunMe > 0) {
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)(); //chạy task
			if (SCH_tasks_G[i].Period == 0) {
				SCH_Delete_Tasks(i); //1 shot task
			}
		}
	}
}

void SCH_Delete_Tasks(uint32_t taskID) {
	for (uint32_t i = taskID; i < current_index_task; i++) {
		SCH_tasks_G[i] = SCH_tasks_G[i + 1];
	}
	SCH_tasks_G[current_index_task].pTask = 0x0000;
	SCH_tasks_G[current_index_task].Delay = 0;
	SCH_tasks_G[current_index_task].Period = 0;
	SCH_tasks_G[current_index_task].RunMe = 0;
	current_index_task--;
}
