/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: motor.h
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of public function dependencies]==========================*/
#include "sapi.h"

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
typedef enum {
	Motor_OFF,
	Motor_ON
} enableDisable_t;

typedef enum {
	MOT_DER=PWM0,
	MOT_IZQ=PWM1
} numeroMotor_t;

typedef enum {
	MOT_ADELANTE=0,
	MOT_ATRAS=1
} spinMotor_t;

/*=====[Prototypes (declarations) of public functions]=======================*/

// Funcion que inicializa la tarea
void motorInit( void );

// Funcion que se ejecuta periodicamente
bool_t motorSpeed(int16_t velocidad, bool_t numeroMotor);
void motorEnable(enableDisable_t enableDisable, numeroMotor_t numeroMotor);
void motorSpeedMax(uint8_t valor);
void motorSpeedMin(uint8_t valor);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/







