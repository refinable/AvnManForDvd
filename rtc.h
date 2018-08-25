//----------------------------------------------------------------------------------------------------
// ID Code      : rtc.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifndef  _RTC_H
#define  _RTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>

extern char TimeDisplay;

extern void RTC_Config(void);
extern void RTC_SetTime(uint32_t CounterValue);
extern uint32_t RTC_GetTime();
//extern void ClockSetTime(time_t *tTS);
extern void ClockGetTime(time_t *tTS);

#ifdef __cplusplus
}
#endif

#endif // _RTC_H

