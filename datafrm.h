//----------------------------------------------------------------------------------------------------
// ID Code      : datafrm.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define _SYNC1		                        0x84
#define _SYNC2		                        0x85
#define _AVN_ACK	                        0x10
#define _AVN_NACK	                        0xF0
#define _FRAME_DATA	                        0x30

#define _ACK_DATA					        1
#define _CAN_EVENT_DATA			            3 //CAN DATA가 수신 되었을 때 B0X->AVN으로전송.
#define _CAN_RESP_DATA				        4 //CAN DATA가 수신 되었을 때 B0X->AVN으로전송.
#define _CAN_RSND_DATA				        5 //CAN DATA가 수신 되었을 때 B0X->AVN으로전송.


#define MAX_RX_BUFF		                    30
#define MAX_TX_BUFF		                    30
#define RS_BUF_MAX 							32
#define MCU2AVN_RS_BUF_MAX	        		80

//AVN->MCU Commands
#define _INIT_COMPLETE_COMM		            0x90
#define _UPDATE_READY				        0x91
#define _VEHICLE_INFO				        0x20


//MCU=>AVN Commands
#define _MCU_VEHICLE_INFO			        0x10
#define _MCU_VERSION_INFO			        0x11
#define _MCU_SWRC_STATUS			        0x12
#define _MCU_AIRCON_STATUS			        0x1A



#if 1   // NEXELL SETTOP COMMAND    // USART2
//AVN->MCU Commands
#define _RADIO_SYNC1                        0x47
#define _RADIO_SYNC2                        0x48

#define _RADIO_SOURCE   		            0x20
#define _RADIO_VOLUME				        0x21
#define _RADIO_TUNER_CH     		        0x22
#define _RADIO_SEEK_CH 		                0x23
#define _RADIO_PRESET_CH		            0x24
#define _RADIO_SEL_MEM_CH_NUM	            0x25
#define _RADIO_CUR_CH_FREQ_REQ	            0x26
#define _RADIO_MANUAL_SAVE_CH_SET           0x27
#define _RADIO_RESERVED		                0x28
#define _RADIO_GET_FREQ_INFO                0x28

//MCU=>AVN Commands
#define _MCU_RADIO_CONTROL                  0xA0
#define _MCU_VOL_REP                        0xA1
#define _MCU_SEEK_CH_FREQ  			        0xA3
#define _MCU_PRESET_CH     			        0xA4
//#define _MCU_SEL_MEM_CH_NUM			        0xA5
#define _MCU_SAVED_CH_FREQ_REP		        0xA5
#define _MCU_CUR_CH_FREQ_REP    	        0xA6
#define _MCU_MANUAL_SAVE_CH_FREQ_REP        0xA7
#define _MCU_RESERVED           	        0xA8
#endif

/* Structure Definition ----------------------------------------*/
typedef struct
{
	u8 nVehicleInfo;	
} RespCmdTypeDef;
extern RespCmdTypeDef				RespCmd;

typedef struct
{
	u8 SeqNoOld;
	u8 SeqNoNew;
	u8 nAccValBuf;
	u8 nMain5VOn;
	u8 nDspPwrOn;
	u8 nLcdDriverOn;
	u8 nDeckPwrOn;
	u8 nLcdResetOn; 
	u8 nLcdDimmerOn;
	u32 iPowerTmrCnt;

	u8 bPowerWarmBootOn;


} PowerControlDef;
extern PowerControlDef				Pwr;

typedef struct
{
	u8 nD0_State;	
	u8 nD1_Temp;	
	u8 nD2_FanDir;	
	u8 nD3_FanSpeed;	
	u8 nD0_StateOld;	
	u8 nD1_TempOld;	
	u8 nD2_FanDirOld;	
	u8 nD3_FanSpeedOld;	
} AirconTypeDef;
extern AirconTypeDef				Air;

typedef struct
{
	u8 TCnt;	
	u8 bSelfRefreshOn;	
	u16 iSelfTmrCnt;	
} SelfTypeDef;
extern SelfTypeDef					Self;


typedef struct
{
	u8 nGPosCheckCnt;	
	u8 bReverseOnOld;	
	u8 bReverseOn;	
	u16 iGpTmrCnt;	
	u8 nReverseChkBuf;	
	u8 bFrCameraUseEn;
	u8 bRrCameraUseEn;
	u8 bFrontCamChkEn;	
	u8 bFrontCamOn;	
	u8 bFrontCamState;	
	u16 iFrontCamTmrCnt;
	u8 bPassiveFrontCamOn;

	u8 bOrCameraUseEn;
	u8 bOriginCamOn;
	u8 bOldOriginCamOn;
	u8 bOriginCamState;
	
	u8 bReverseOnCheck;
	u8 nReverseCamStepCnt;
	u16 iReverseCamTmrCnt;

	u8 bReversePasUseEn;
    u8 bTWCameraUseEn;
} GPTypeDef;
extern GPTypeDef					GP;

typedef struct
{
	u8 nPasImgNumOld;	
	u8 nPasImgNum;	
	u8 bPasDispOn;	
	u8 nPasCanold;
	u8 bPasUseEn;
} WheelTypeDef;
extern WheelTypeDef				WH;

typedef struct
{
	u16 iDispChgTmrCnt;	
	u8 bInitTime5SecPassOn;
	u16 i5SecPassChkTmrCnt;
	u16 iInitChkTmrCnt;
	u8 nInitTimeTickCnt;
	u8 bInitTimeTickOn;
	u8 nScaleRstStepCnt;
	u8 nSetScaleDispMode;
	u16 iScaleRstTmrpCnt;

	u8 bWaitCam;
	u8 nWaitCamStepCnt;
	u16 iWaitCamTmrCnt;

	u8 bSpiResetEn;
	u8 nSpiResetStepCnt;
	u16 iSpiResetTmrCnt;
} SysTypeDef;
extern SysTypeDef					Sys;


typedef struct
{
	u8 Cmd;
	u8 SeqNo;
	u8 len;
	u8 bMsgResendOn;
} ResendTypeDef;
extern ResendTypeDef				ResendStruct;


typedef struct
{
	u8 nKeyValue;	
	u8 bKeyEnable;
	u8 nEncoderAVal;
	u16 iKeyCheckTmrCnt;	
	u16 iKeyModeTmrCnt;
	u8 bLongKeyOn;
	u8 bShortKeyOn;
	u8 nBackUpVal; //not used
	u8 bKeyModeTimeOn; //not used
	u8 nKeySeq; //not used
	u8 nKeyModeOn; //not used
} KeyTypeDef;
extern KeyTypeDef					Key;

/* -------------------------------------------------------------*/
//debug message display option...
extern u8 nDbgLevelVal; //0:ALL OFF, 1: _UART_TX_EN, 2: _UART_RX_EN, 3: _UART_TX_RX_EN
extern u8 nCanDbgLevelVal; //0:ALL OFF, 1: _CAN_TX_EN, 2: _CAN_RX_EN, 3: _CAN_TX_RX_EN

extern u16 iUpdateStatVal;

extern u8 bVehicleInfoOn;
extern u8 bAirInfoSendOk; //<1>Aircon 초기 데이터 전송 완료
extern u8 nSendToAvnDataDelay10ms; //1:ACK 전송 후, 10ms 대기 2 : MCU->AVN Data 전송
extern u8 bAvnAckInitOn;
extern u8 RX_ACK;
extern u8 RX_RADIOACK;
extern u8 RX_RECEIVE;
extern u8 RX_RADIORECEIVE;
extern u8 RX_DATA[MAX_RX_BUFF];
extern u8 RX_RADIODATA[MAX_RX_BUFF];
extern u8 RX_ACKD[3];
extern u8 RX_RADIOACKD[3];
extern u8 nIndex;
extern u8 nAckSeqNo;
extern u8 nMCUToAvnSeqNo;
extern u8 TX_DATA[MAX_TX_BUFF];
extern u8 TX_RADIODATA[MAX_TX_BUFF];
extern u8 nSyncOn;
extern u8 nDataLength;
extern u8 nRxCrcValue;
extern u8 tx1_in;
extern u8 tx1_out;
extern u8 RS1_buf[RS_BUF_MAX];
extern u8 RXD_BACKUP[MAX_RX_BUFF];
extern u8 nNeedResendChkCnt;
extern u8 nNeedResendChkCntOld;
extern u16 iResendTmrCnt;
extern u8 RS1_in;
extern u8 RS1_out;

extern u8 nMCUToAvnRS_buf[MCU2AVN_RS_BUF_MAX];
extern u8 nMCUToAvnRS_in;
extern u8 nMCUToAvnRS_out;

extern u8 nCan1MsgEventOn; //0:event msg. none, xx:해당 값의 msg. event 발생 ON
extern u8 nCheckSumVal;
extern u8 nCrcValue;
extern u8 bSendAckDataEn; //1:ACK 전송해야함.
extern u8 nSendToAvnAckDelayTmrCnt;
extern u8 nSendFrameCnt;	//재 전송 횟수
extern u8 bDbgUartAckOn;

extern u8 bNaviDeOn;
extern u8 bHuDeOn;

extern void CFrmCopy(u8 data, u8 crc);
extern void CDataCopy(u8 *dest, u8 val, u8 len);
extern void CUartRxPrintFunc(u8 *msg);
extern void CRequestCommandBackup(void);
extern void CResponseFramDataResend(void);
extern void CAckWaitTimeCheckStart(void);
extern void CResponseProcClear(void);
extern void CTxProcess(u8 val, u8 state);
extern void CGetCommand(void);
extern void TaskProcess(void);
extern void DataProcess(unsigned char c );
extern void CRxProcessClear(u8 err_val);
extern u8 RS1_ready(void);
extern u8 RS1_rx(void);
extern void TxData(u8 buf);
extern void RS1_tx(u8 buf);
extern void RS1_ungetch(u8 ch);

extern void CSend2NaviSwrcStatus(u8 state, u8 seq_no);
extern void CSend2NaviAirconStatus(u8 state, u8 seq_no);
extern void CSend2NaviVehicleInfo(u8 state, u8 val);
extern void CSend2NaviVersionInfo(u8 state, u8 val);

extern void CSendAvnFrameMsg(u8 command);
extern void CReqErrMsg(u8 cmd, u8 err_val);
extern u8 CAvnToMCUCmdCheck(u8 cmd);
extern void CAckSendToAvn(u8 state);
extern u8 CCrcSet(u8 val, u8 crc_val);
extern u8 CChecksumSet(u8 val);


extern u8 MCUToAvnRS_ready(void);
extern u8 MCUToAvnRS_rx(void);
extern void MCUToAvnRS_ungetch(u8 ch);
extern void CMCUToAvnCommandSave(u8 cmd);
extern void CMCUToAvnCommandRead(void);

extern void CSend2AvnVolumeRep(u8 vol);  // 0xA1

