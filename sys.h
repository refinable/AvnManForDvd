//----------------------------------------------------------------------------------------------------
// ID Code      : sys.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifndef  _SYS_H
#define  _SYS_H

#ifdef __cplusplus
extern "C" {
#endif

extern u8 nBufVbusState;
extern u8 nVBusStateOn;

extern void CSysInit(void);
extern void delay_us (const uint32_t usec);
extern void delay_ms (const uint32_t msec);
extern void CVBusInputCheck(void);

#ifdef __cplusplus
}
#endif

#endif // _SYS_H

