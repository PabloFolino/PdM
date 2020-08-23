/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: fsm_timer.h
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of public function dependencies]==========================*/
#include "sapi.h"

/*=====[Definition macros of public constants]===============================*/
#define CANT_MAX_TIMERS 2

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
typedef enum {
	SLEEP,
	READY_UP,
	READY_DOWN
} estadoTimer_t;

typedef struct timerReg{
	estadoTimer_t estadoTimer;
	uint32_t contador;
} timerReg_t;

/*=====[Prototypes (declarations) of public functions]=======================*/
void fsmTimertInit(timerReg_t * ptr_temporizadores);
void fsmTimerUpdate(void* taskParam);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/
