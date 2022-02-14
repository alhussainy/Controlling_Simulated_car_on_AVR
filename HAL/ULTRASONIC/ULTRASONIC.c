#include "STD_TYPES.h"
#include "ULTRASONIC.h"
#include "REG.h"
#include "BIT_MATH.h"
#include "TIMER_1.h"
#include "LCD.h"

u32 ULTRA_SONIC_READ( )
{

	u32 distance;
	distance=TIMER_1_CALC_TIME();
	
	return distance;
	

}