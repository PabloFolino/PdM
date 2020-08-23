/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: led.c
 * Version: 1
 *===========================================================================*/
/*Descripción: este módulo lee la variable "estado" del programa principal
 *             y la muestra mediante una combinación de LEDs.
 *===========================================================================*/

/*==================[inclusions]=============================================*/
#include "sapi.h"
#include "led.h"
#include "fsm_robot.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
void ledInit(void){
	gpioWrite(LED_ROJO,OFF);
    gpioWrite(LED_VERDE,OFF);
}


void ledUpdate(void* taskParam){
	estadoRobot_t * ptr_estadoTemp;
	ptr_estadoTemp=(estadoRobot_t*)taskParam;

	switch (*ptr_estadoTemp){
	case ESPERA:
		gpioWrite(LED_ROJO,OFF);
		gpioWrite(LED_VERDE,OFF);
		break;
	case ADELANTE:
		gpioWrite(LED_ROJO,ON);
		gpioWrite(LED_VERDE,OFF);
		break;
	case ATRAS:
		gpioWrite(LED_ROJO,OFF);
		gpioWrite(LED_VERDE,ON);
		break;
	default:
		gpioWrite(LED_ROJO,ON);
		gpioWrite(LED_VERDE,ON);
	}

}






