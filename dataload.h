//----------------------------------------------------------------------------------------------------
// ID Code      : dataload.h
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define STX		0xff
#define ETX		0xfe

//------------------------------------------------------------
//CAN1(HSFT) Rx. ID
#define _ID_GEAR_POSITION			0x102	//0x390
#define _ID_SYS_STAT				0x102C0040u //IGN
#define _ID_SWRC_ML					0x10438060u

#define _ID_SWRC_TRAX				0x10438040u

#define _ID_SWRC_CHG_LONG			0x104380FFu
#define _ID_ACC_STATE				0x621
#define _ID_AGING_728				0x728
#define _ID_WHIEEL_ANGLE			0x10240040u
#define _ID_TURNSIGNAL				0x10ACE060u


//Rx. ID
#define _ID_WAKE_EXT				0x000
#define _ID_EXT_HU				    0x000
#define _ID_AIRCON_RX_33H			0x33

#define SONAR_STEP_END              0x95
#define SONAR_STEP_4_START          0x70
#define SONAR_STEP_3_START          0x43
#define SONAR_STEP_2_START          0x31
#define SONAR_STEP_1_START          0x1A
		


extern unsigned char bSubDispAckRequestOn;
extern unsigned char bSubDispAckEn;

extern u8 CAN_TX_BUF[8];

extern u32 lCan1Id;
extern u32 lCan1ExtId;
extern u8 nCan1IDE;
extern u8 nCan1RTR;
extern u8 nCan1DLC;
extern u8 nCan1Data[8];
extern u32 lCan2Id;
extern u32 lCan2ExtId;
extern u8 nCan2IDE;
extern u8 nCan2RTR;
extern u8 nCan2DLC;
extern u8 nCan2Data[8];
extern u8 bInitOn;
extern u16 iCan2AgingModeTmrCnt;
extern u8 bAgingModeOn;
extern u8 bFwVersionSendOn;
extern u8 zone_dh;
extern u8 zone_cg;
extern u8 zone_bf;
extern u8 zone_ae;

extern u32 nFilter2Id01;
extern u32 nFilter2Id02;
extern u32 nFilter2Id03;
extern u32 nFilter2Id04;
extern u32 nFilter2Id05;
extern u8 nFilterUartTxCmd01;
extern u8 nFilterUartTxCmd02;
extern u8 nFilterUartTxCmd03;
extern u8 nFilterUartTxCmd04;
extern u8 nFilterUartTxCmd05;

extern u8 nFilterUartRxCmd01;
extern u8 nFilterUartRxCmd02;
extern u8 nFilterUartRxCmd03;
extern u8 nFilterUartRxCmd04;
extern u8 nFilterUartRxCmd05;

extern void SendFrame(void);
extern void CCan1RxAnalyze(void);
extern void CCan2RxAnalyze(void);
extern void CSwrcSpkCheck(u8 data0);
extern void CSwrcTraxCheck(u8 data0);
extern void CFrCameraChk(void);
extern void CFrCamVarInit(void);

extern void CAgingModeCheck(u8 data0);
extern void CSelfTestFunc(void);
extern void CSelfTestSeq(u8 cnt);
extern void CSubDispAckChk(void);
extern void CSubDispRequest(void);
extern void CSendSubDisplayMsg(void);



