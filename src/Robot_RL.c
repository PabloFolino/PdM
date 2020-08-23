/*=============================================================================
 * Author: Pablo Daniel Folino  <pfolino@gmail.com>
 * Date: 2020/08/17
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/
#include "sapi.h"
#include "seos_pont.h" 		// <= Simple Embedded Operating System (cooperative)
#include "Robot_RL.h"

#include "fsm_button.h"		// <= Task 1
#include "fsm_timer.h"		// <= Task 2
#include "fsm_robot.h"		// <= Task 3
#include "led.h"		    // <= Task 4

/*=====[Definition macros of private constants]==============================*/
#define SCHEDULER_MAX_TASKS   (5)

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/
timerReg_t temporizadores[CANT_MAX_TIMERS];
timerReg_t  *ptr_temporizadores;

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   // En la variable "estado" se evalúa el estado gral del robot
   estadoRobot_t estado=NN;
   estadoRobot_t *ptr_estado;

   /* En el vector estadosPulsadores se lleva el estado de los mismos
    * Los estados posibles son; B_ON ; B_OFF ; B_FILLING y B_RISING
    */
   estadoPulsador_t estadosPulsadores[] = {B_OFF,B_OFF,B_OFF,B_OFF};
   estadoPulsador_t *ptr_estadosPulsadores;

   ptr_estadosPulsadores = &estadosPulsadores[0];
   ptr_temporizadores = &temporizadores[0];
   ptr_estado=&estado;

   // Se inicializan cada una de las tareas del planificador
   fsmButtonInit(ptr_estadosPulsadores);
   fsmTimerInit(ptr_temporizadores);
   fsmRobotInit(ptr_estado);
   ledInit();

   // FUNCION que inicializa el planificador de tareas
   schedulerInit();

   // Se agrega la tarea tarea1 al planificador
   schedulerAddTask( fsmButtonUpdate, 		// funcion de tarea a agregar
		   	   	     (void*)ptr_estadosPulsadores, // parametro de la tarea
                     0,         			// offset de ejecucion en ticks
                     30       				// periodicidad de ejecucion en ticks
                   );						// en este caso es 30mseg

   schedulerAddTask( fsmTimerUpdate,(void*)ptr_estadosPulsadores,1,40);
   schedulerAddTask( fsmRobotUpdate,(void*)ptr_estado,2,50);
   schedulerAddTask( ledUpdate,(void*)ptr_estado,3,250);

   // FUNCION que inicializa la interrupción que ejecuta el planificador de
   // tareas con tick cada 1ms.
   schedulerStart(1);

   // ----- Repeat for ever -------------------------
   while(TRUE) {
	      // Se despachan (ejecutan) las tareas marcadas para su ejecucion.
	      // Luego se pone el sistema en bajo consumo hasta que ocurra la
	      // proxima interrupcion, en este caso la de Tick.
	      // Al ocurrir la interrupcion de Tick se ejecutara el planificador
	      // que revisa cuales son las tareas a marcar para su ejecucion.
	      schedulerDispatchTasks();
	   }

	   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
	   // directamenteno sobre un microcontroladore y no es llamado por ningun
	   // Sistema Operativo, como en el caso de un programa para PC.
	   return 0;
}
