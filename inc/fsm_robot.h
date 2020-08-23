/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Archivo: fsm_robotmotor.h
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of public function dependencies]==========================*/

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
typedef enum{
	ESPERA,
	ADELANTE,
	ATRAS,
	NN
} estadoRobot_t;

/*=====[Prototypes (declarations) of public functions]=======================*/
void fsmRobotInit(void* taskParam);
void fsmRobotUpdate(void* taskParam);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/
