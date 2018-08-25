//----------------------------------------------------------------------------------------------------
// ID Code      : can.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifndef  _CAN_H
#define  _CAN_H

#ifdef __cplusplus
extern "C" {
#endif

#define CAN1_BAUDRATE  333	/* 33.3kBps */
#define CAN2_BAUDRATE  333	/* 33_3kBps */


extern u8 bCan1Rx0DataOn;
extern u8 bCan2Rx0DataOn;
extern u16 iCan1NodeChkTmrCnt;

extern void CCanCheck(void);
extern void CInhStateCheck(void);
extern void CLsCanBusStateCheck(void);
extern void CCan2DriverInit(void);


#ifdef __cplusplus
}
#endif

#endif // _CAN_H

