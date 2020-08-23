/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: fsm_button.h
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of public function dependencies]==========================*/

/*=====[Definition macros of public constants]===============================*/
#define PULSADOR1 TEC1
#define PULSADOR2 TEC2
#define PULSADOR3 TEC3
#define PULSADOR4 TEC4
#define CANT_MAX_PULSA 4

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
typedef enum {
	B_OFF,
	B_ON,
	B_RISING,
	B_FILLING
} estadoPulsador_t;

/*=====[Prototypes (declarations) of public functions]=======================*/
void fsmButtonInit(estadoPulsador_t *ptr_estadoPulsa);
void fsmButtonUpdate(void* taskParam);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/
