/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: fsm_button.c
 * Version: 1
 *===========================================================================*/
/*Descripción: esta función lee mediante una máquina de estados las teclas
 * de la EDU_CIAA, y actualiza en un vector "estadosPulsadores[]" que se
 * pasa como parámetro del programa principal.Los estados posibles son de
 * cada tecla son(posee una lógica de antirebote):
 *       B_ON    	--> se considera pulsador presionado
 *       B_OFF 		--> se condidera pulsador sin presionar
 *       B_RISING 	--> transición de estado OFF a ON
 *       B_FILING   --> transición de estado ON a OFF
 *
 * Tiempo de ejecución de la rutina "fmsButtonUpdate()"  es < 4useg.
 *===========================================================================*/

/*==================[inclusions]=============================================*/
#include "sapi.h"
#include "fsm_button.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
void  buttonUpdate(estadoPulsador_t *ptr_estadoPulsa, uint8_t c, bool_t tecla){
	estadoPulsador_t estPul;
	estPul=*(ptr_estadoPulsa+c);
	switch (estPul){
		case B_ON:
			if(tecla){
				*(ptr_estadoPulsa+c)=B_ON;
				}
				else{
					*(ptr_estadoPulsa+c)=B_FILLING;
				}
			break;
		case B_OFF:
			if(tecla){
				*(ptr_estadoPulsa+c)=B_RISING;
				}
				else{
					*(ptr_estadoPulsa+c)=B_OFF;
				}
			break;
		case B_RISING:
			if(tecla){
				*(ptr_estadoPulsa+c)=B_ON;
				}
				else{
					*(ptr_estadoPulsa+c)=B_OFF;
				}
			break;
		case B_FILLING:
			if(tecla){
				*(ptr_estadoPulsa+c)=B_ON;
				}
				else{
					*(ptr_estadoPulsa+c)=B_OFF;
				}
			break;
		default:
			*(ptr_estadoPulsa+c)=B_OFF;
			break;
		}
}

/*==================[external functions definition]==========================*/
void fsmButtonInit(estadoPulsador_t *ptr_estadoPulsa){
	int c=0;
	for(c=0;c<CANT_MAX_PULSA;c++) *(ptr_estadoPulsa+c)=B_OFF;
}

void fsmButtonUpdate(void* taskParam){
	estadoPulsador_t * ptr_estadoPulsa;
	bool_t tecla;
	int c=0;

	ptr_estadoPulsa=(estadoPulsador_t*)taskParam;

	tecla= !gpioRead(PULSADOR1);
    buttonUpdate(ptr_estadoPulsa,c,tecla);
    c++;
    tecla= !gpioRead(PULSADOR2);
    buttonUpdate(ptr_estadoPulsa,c,tecla);
    c++;
    tecla= !gpioRead(PULSADOR3);
    buttonUpdate(ptr_estadoPulsa,c,tecla);
    c++;
    tecla= !gpioRead(PULSADOR4);
    buttonUpdate(ptr_estadoPulsa,c,tecla);

}


