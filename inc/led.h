/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: led.h
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of public function dependencies]==========================*/
#include "sapi.h"

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
typedef enum {
	LED_ROJO=LED2,
	LED_VERDE=LED3,
	LED_AZUL=LEDB,
	LED_AMARILLO=LED1
} led_t;

/*=====[Prototypes (declarations) of public functions]=======================*/
void ledInit(void);
void ledUpdate( void* taskParam);


/*=====[Prototypes (declarations) of public interrupt functions]=============*/

