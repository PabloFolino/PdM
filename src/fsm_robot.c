/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: fsm_robot.c
 * Version: 1
 *===========================================================================*/
/*Descripción: esta función lee el vector de los "temporizadores", y actualiza
 * el estado del robot. Los estados posibles son:
 *       ESPERA     --> el robot se encuentra en reposo
 *       ADELANTE  	--> mueve los dos motores con un velocidad positiva cte.
 *       ATRAS 		--> mueve los dos motores con un velocidad negativa cte.
 *       NN    		--> para posibles actualizaciones
 *===========================================================================*/

/*==================[inclusions]=============================================*/
#include "sapi.h"
#include "fsm_robot.h"
#include "motor.h"
#include "fsm_timer.h"

/*==================[macros and definitions]=================================*/
#define VEL_CTE 230
/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
extern timerReg_t temporizadores[CANT_MAX_TIMERS];
extern timerReg_t  *ptr_temporizadores;

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void fsmRobotInit(void* taskParam){
	estadoRobot_t * ptr_estado;
	ptr_estado=(estadoRobot_t*)taskParam;

	motorInit();
	*ptr_estado=ESPERA;
}

// Tiene prioridad el movimiento hacia adelante
void fsmRobotUpdate(void* taskParam){
	estadoRobot_t * ptr_estadoTemp;
	ptr_estadoTemp=(estadoRobot_t*)taskParam;

	switch(*ptr_estadoTemp){
	case ESPERA:
		if((*ptr_temporizadores).estadoTimer==READY_DOWN){
				motorSpeed(VEL_CTE, MOT_DER);
				motorSpeed(VEL_CTE, MOT_IZQ);
				*ptr_estadoTemp=ADELANTE;
				}
				else{
				if((*(ptr_temporizadores+1)).estadoTimer==READY_DOWN){
					motorSpeed(-VEL_CTE, MOT_DER);
					motorSpeed(-VEL_CTE, MOT_IZQ);
					*ptr_estadoTemp=ATRAS;
					}
				}
		break;
	case ADELANTE:
		if((*ptr_temporizadores).estadoTimer==SLEEP){
				motorSpeed(0, MOT_DER);
				motorSpeed(0, MOT_IZQ);
				*ptr_estadoTemp=ESPERA;
				fsmTimerInit(ptr_temporizadores);
				}
		break;
	case ATRAS:
		if((*(ptr_temporizadores+1)).estadoTimer==SLEEP){
				motorSpeed(0, MOT_DER);
				motorSpeed(0, MOT_IZQ);
				*ptr_estadoTemp=ESPERA;
				fsmTimerInit(ptr_temporizadores);
				}
			break;
	default:
		// Posibles estados no válidos
		break;
	}
}



