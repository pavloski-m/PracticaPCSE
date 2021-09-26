/*=============================================================================
 * Author: pablo <pablomorzan@gmail.com>
 * Date: 2021/09/20
 * Version: 1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "servoPCSE.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/
#define BASE 10000
#define MIN_DUTY 0.5
#define MAX_DUTY 2.5
#define MIN_ANGLE 0
#define MAX_ANGLE 180
#define SLOPE 	(((MAX_DUTY - MIN_DUTY) / (MAX_ANGLE - MIN_ANGLE)) * BASE)
#define INTERCEPT 2.5*BASE
#define SERVO_ERROR 66
#define SERVO_OK 1
#define PERIOD_MS 20

/*=====[Definition of private data type]==============================*/

typedef struct{
	void (*pwmSetDuty)(void*);
	void (*pwmConfiguration)(void*);
}api_t;

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

static api_t servoPort;

/*=====[Main function, program entry point after power on or reset]==========*/

uint8_t servoInit(void){

}

uint8_t servoSetAngle(uint8_t angle){

	uint8_t message = SERVO_OK;

	if(angle<=180) {
		uint8_t defDuty = (SLOPE * angle + INTERCEPT) / BASE;
		servoPort->pwmSetDuty((void*)&defDuty);
	}
	else {
		message = SERVO_ERROR;
	}

	return(message);
}

