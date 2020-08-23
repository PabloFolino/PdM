/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: fsm_timer.c
 * Version: 1
 *===========================================================================*/
/*Descripción: ese módulo  lee el vector de los estados de las teclas, y si se
 *  encuentran en ON o en OFF actualiza los contadores de los timers.
 *  Los estados de los timers, pueden ser:
 *       SLEEP     --> el timer se encuentra inactivo
 *       READY_ON  --> se encuentra presionada una tecla y se esta incrementando
 *       			   el contador
 *       READY_OFF --> la tecla se encuentra liberada, se decrementa el contador
 *===========================================================================*/


/*==================[inclusions]=============================================*/
#include "fsm_timer.h"
#include "fsm_button.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
void timerUpdate (estadoPulsador_t * ,uint8_t);

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
extern timerReg_t temporizadores[CANT_MAX_TIMERS];
extern timerReg_t  *ptr_temporizadores;

/*==================[internal functions definition]==========================*/
void  timerUpdate (estadoPulsador_t *ptr_estadoPulsa,uint8_t c){
	estadoPulsador_t estPul;
	uint32_t contador;

	estPul=*(ptr_estadoPulsa+c);
	switch (estPul){
		case B_ON:
			if((*(ptr_temporizadores+c)).contador == 0)
				(*(ptr_temporizadores+c)).estadoTimer=READY_UP;
			if((*(ptr_temporizadores+c)).estadoTimer == READY_UP)
				(*(ptr_temporizadores+c)).contador++;
			break;
		case B_OFF:
			if((*(ptr_temporizadores+c)).contador>0)
				(*(ptr_temporizadores+c)).estadoTimer=READY_DOWN;
			if((*(ptr_temporizadores+c)).estadoTimer==READY_DOWN)
				(*(ptr_temporizadores+c)).contador--;
			if((*(ptr_temporizadores+c)).contador==0
					)(*(ptr_temporizadores+c)).estadoTimer=SLEEP;
			break;
		default:
			break;
		}
}
/*==================[external functions definition]==========================*/
void fsmTimerInit(timerReg_t * ptr_temporizadores){
	int c=0;
	for(c=0;c<CANT_MAX_TIMERS;c++){
		(ptr_temporizadores+c)->contador=0;
		(ptr_temporizadores+c)->estadoTimer=SLEEP;
		}
}

void fsmTimerUpdate(void* taskParam){
	estadoPulsador_t * ptr_estadoPulsa;

	uint8_t c=0;

	ptr_estadoPulsa=(estadoPulsador_t*)taskParam;
	for(c=0;c<CANT_MAX_TIMERS;c++){
	    timerUpdate(ptr_estadoPulsa,c);
		}
}







