/*
 * TIMER_0_CFG.h
 *
 * Created: 12/01/2022 11:35:26 ص
 *  Author: Alhussainy Khaled Anwar
 */ 


#ifndef TIMER_0_CFG_H_
#define TIMER_0_CFG_H_

/*select timer_0 mode -> NORMAL_MODE , CTC_MODE */
#define TIMER_0_MODE     NORMAL_MODE

/*select timer_0 prescaler devision factor -> _1024  ,  _256 */
#define PRESCALER      _1024
#define CRYSTAL_FREQ     16
/*select fast pwm mode options -> FAST  , PHASE_CORRECT */
#define PWM_0_MODE     PHASE_CORRECT

/*select fast pwm mode options -> NON_INVERTED  , INVERTED */
#define FAST_PWM_0_MODE      NON_INVERTED

/*select fast pwm mode options -> NON_INVERTED  , INVERTED */
#define PHASE_CORRECT_PWM_0_MODE     NON_INVERTED

#endif /* TIMER_0_CFG_H_ */