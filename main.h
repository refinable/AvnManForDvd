//----------------------------------------------------------------------------------------------------
// ID Code      : main.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include <string.h>
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_conf.h"
#include "stm32f10x_it.h"

#include "bitvar.h"
#include "sys.h"
#include "can.h"
#include "adc.h"
#include "dac.h"
#include "datafrm.h"
#include "dataload.h"
#include "mondbg.h"
#include "monitor.h"
#include "i2c.h"
#include "isr.h"
#include "uart_debug.h"
#include "rtc.h"
#include "timer.h"
#include "extint.h"
#include "func_s.h"
#include "eeprom.h"
#include "flash.h"
#include "Audio_6635.h"


#define LOBYTE(w)                       ((u8)(w))
#define HIBYTE(w)                       ((u8)(((u16)(w) >> 8) & 0x00FF))

#define LONIBBLE(w)                       ((u8)(w) & 0x0F)
#define HINIBBLE(w)                       ((u8)(((u16)(w) >> 4) & 0x0F))

#define	MAKEWORD(Low,High)					((((u16)(High)) << 8)|(u16)(Low))
#define	MAKEDWORD(Low,High)					((((u16)(High)) << 16)|(u16)(Low))

#define CHECK_EXT_INT						GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)

#define I2C1_SLAVE_ADDRESS7              0x94
#define I2C2_MASTER_ADDRESS7             0x94
#define ClockSpeed                       400000	// 2500
//#define ClockSpeed                       300000	// 3300
//#define ClockSpeed                       200000	// 5000
//#define ClockSpeed                       150000	// 6700
//#define ClockSpeed                       120000	// 8300
//#define ClockSpeed                       105000	// 9500
//#define ClockSpeed                       100000	// 10000
//#define ClockSpeed                       98000	// 10200
//#define ClockSpeed                         85000	// 11700	// MALIBU 순정 11600 정도로 이 값으로 FIX	// 20170301

//============================================================
//MACRO DEFINITION
//------------------------------------------------------------
#define	_TRUE								1
#define _FALSE								0
#define _SUCCESS							1
#define _FAIL								0
#define _NOT_EXIST							0xFF
#define _OFF								0
#define _ON									1
#define _OK									1
#define _NONE								0
#define _INC								0
#define _DEC								1
#define _RIGHT								0
#define _LEFT								1
#define _IWDG								1
#define _WWDG								0
#define _NOT_SUPPORTED_VAL					0xFF
#define _REQUEST_MSG						0x10
#define _RESPONSE_MSG						0x11
#define	_PARK_ON							0x11
#define	_PARK_OFF							0x00

#define _CNT_2MSEC							2
#define _CNT_5MSEC							5
#define _CNT_10MSEC							10
#define _CNT_15MSEC							10
#define _CNT_20MSEC							20
#define _CNT_30MSEC							30
#define _CNT_35MSEC							35
#define _CNT_40MSEC							40
#define _CNT_50MSEC							50
#define _CNT_70MSEC							70
#define _CNT_80MSEC							80
#define _CNT_100MSEC						100
#define _CNT_120MSEC						120
#define _CNT_130MSEC						130
#define _CNT_150MSEC						150
#define _CNT_180MSEC						180
#define _CNT_200MSEC						200
#define _CNT_250MSEC						200
#define _CNT_300MSEC						300
#define _CNT_400MSEC						400
#define _CNT_500MSEC						500
#define _CNT_400MSEC						400
#define _CNT_500MSEC						500
#define _CNT_600MSEC						600
#define _CNT_800MSEC						800
#define _CNT_1000MSEC						1000
#define _CNT_1400MSEC						1400
#define _CNT_1700MSEC						1700
#define _CNT_2000MSEC						2000
#define _CNT_3000MSEC						3000
#define _CNT_5000MSEC						5000
#define _CNT_6000MSEC						6000
#define _CNT_7000MSEC						7000
#define _CNT_9000MSEC						9000
#define _CNT_10000MSEC						10000
#define _CNT_1000MSEC						1000
#define _CNT_1200MSEC						1200
#define _CNT_1500MSEC						1500
#define _CNT_2200MSEC						2200
#define _CNT_2500MSEC						2500
#define _CNT_3000MSEC						3000
#define _CNT_3300MSEC						3300
#define _CNT_4000MSEC						4000
#define _CNT_5000MSEC						5000
#define _CNT_6000MSEC						6000
#define _CNT_7000MSEC						7000
#define _CNT_8000MSEC						8000
#define _CNT_9000MSEC						9000
#define _CNT_10000MSEC						10000
#define _CNT_12000MSEC						12000
#define _CNT_15000MSEC						15000
#define _CNT_3_MIN							180000
#define _CNT_10_MIN							600000
#define _CNT_11_MIN							660000
#define _CNT_60_MIN							3600000

#define _CNT_BACKSONAR_DEFAULT				500
//SWRC MALIBU CAN Data Define
#define _SPK_RELEASE_VAL					0x00
#define _SPK_VOLUME_UP_VAL					0x03
#define _SPK_VOLUME_DN_VAL					0x04
#define _SPK_SRC_UP_VAL						0x10
#define _SPK_SRC_DN_VAL						0x20
#define _SPK_PHONE_PUSH_VAL					0x05
#define _SPK_MUTE_PUSH_VAL					0x06
#define _ML_SWRC_LEFT_VAL					0x07
#define _ML_SWRC_RIGHT_VAL					0x08

#if 1   // for NEXELL SETTOP
#define _ML_SWRC_VOL_UP_VAL					0x03
#define _ML_SWRC_VOL_DN_VAL					0x04
#define _ML_SWRC_UP_VAL					    0x10
#define _ML_SWRC_DN_VAL					    0x20
#define _ML_SWRC_MUTE_VAL					0x06
#define _ML_SWRC_PREV_VAL					0x01 	//왼편 뒤에 위
#define _ML_SWRC_NEXT_VAL					0x02 	//왼편 뒤에 아래

#define _ML_SWRC_SELECT_VAL				    0x09
#define _ML_SWRC_VOICE_VAL				    0x05
#endif

//SWRC TRAX CAN Data Define
#define _TRAX_RELEASE_VAL					0x00
#define _TRAX_VOLUME_UP_VAL					0x01
#define _TRAX_VOLUME_DN_VAL					0x02
#define _TRAX_SRC_UP_VAL					0x03
#define _TRAX_SRC_DN_VAL					0x04
#define _TRAX_SRC_PUSH_VAL					0x05
#define _TRAX_PHONE_PUSH_VAL				0x06
#define _TRAX_MUTE_PUSH_VAL					0x07
//self test seq. count
#define _SELF_TEST_SEQ_CNT_MAX				35

#define _MAX9275_REG_ADR					0x80

//차종정보
#define _VEHICLE_GM_CHEVROLET				0x01
//RESEND COUNT
#define _FRM_RESEND_CNT_MAX					5
//------------------------------------------------------------
//FOR Debug...
#define _FROM_AVN_MSG_DISPLAY_ENABLE				_OFF  //ON:AVN->MCU UART Rx.메시지 출력ENABLE
#define _UART_TX_DATA_MON_ENABLE					_ON  //ON:MCU->AVN UART TX DATA ENABLE
#define _UART_TX_ACK_MON_ENABLE						_ON  //ON:MCU->AVN UART TX ACK ENABLE
#define _UART_RX_DATA_MON_ENABLE					_ON  //ON:AVN->MCU UART RX DATA ENABLE
#define _UART_RX_ACK_MON_ENABLE						_ON  //ON:AVN->MCU UART RX ACK ENABLE
#define _CAN_TX_DATA_MON_ENABLE						_ON  //ON:MCU->CAR CAN TX DATA ENABLE
#define _CAN1_RX_DATA_MON_ENABLE					_ON  //ON:CAR->MCU CAN1 RX DATA ENABLE
#define _CAN2_RX_DATA_MON_ENABLE					_ON  //ON:CAR->MCU CAN2 RX DATA ENABLE
#define _REQUEST_MON_ENABLE							_ON  //ON:AVN->MCU REQUEST MSG. MONITORING ENABLE
//------------------------------------------------------------
//FOR Test(생산 시 OFF할 것)...
//============================================================
//MASS PRODUCTION
#define _SYSTEM_STATE_SET_ENABLE					_ON   //ON :생산 시, 적용(최초 POWER ON시, CAN DATA 수신되지 않으면, 2초 후, WWDG RESET 진입), OFF:디버깅 시, 적용
#define _WATCHODG_ENABLE							_ON   //ON :생산 시, 적용, OFF:디버깅 시, 적용
#define _WATCHDOG_SELECT							_WWDG  //_IWDG<1>:IWDG선택(생산 시 적용), _WWDG<0>:WWDG선택
//============================================================

//thinkware New Function Macro
#define _SELF_TEST_FUNC_ENABLE						_OFF   //ON:H/W테스트위해 차에 연결하지 않고 동작(Standby mode 안 들어감)

#define _INVALID_CMD_TEST_ENABLE					_OFF   //ON:잘못된 커멘드 전송 테스트. 양산 시, 반드시 OFF할것.

//============================================================
//소프트웨어 버전표시
#define _SW_VERSION_NUM1							0		//Ver x.901 , <x>:0,1,2,3,...,9(1자리)
#define _SW_VERSION_NUM2							2		//Ver 0.x01 , <x>:9,1,2,3,...,9(1자리)
#define _SW_VERSION_NUM3							00		//Ver 0.9xx , <x>:01,02,03,..,99(2자리)
#define _SW_VERSION_CHAR							'j'		//Ver 0.903x, <x>:a,b,c,...(1자리)

//============================================================
//Version History

//============================================================


//============================================================
//UART Definintion
//============================================================
#define _UART1							1
#define _UART2							2
#define _UART3							3
#define _UART4							4
#define _UART5							5

//------------------------------------------------------------
#define TRUE                            	1
#define FALSE                          		0
#define BOOL                            	u8
#define bool								u8
#define _BIT0								0x01
#define _BIT1								0x02
#define _BIT2								0x04
#define _BIT3								0x08
#define _BIT4								0x10
#define _BIT5								0x20
#define _BIT6								0x30
#define _BIT7								0x80

#define _CNT_100_MSEC						100
#define _CNT_100_MSEC						100
#define _CNT_300_MSEC						300
#define _CNT_500_MSEC						500
#define _CNT_1000_MSEC						1000
#define _CNT_1_SEC							1
#define _CNT_2_SEC							2
#define _CNT_3_SEC							3
#define _CNT_5_SEC							5
#define _VIDEO_ON							1
#define _VIDEO_OFF							0

#define _CAN_OK								0
#define _CAN_NG								1
#define _REVERSE							0xe2
#define _DRIVE								0xe3
#define _CAMERA_TYPE_OLD					0x50
#define _CAMERA_TYPE_NEW					0x51
#define _START_POSITION_X					0x52
#define _START_POSITION_Y					0x53
#define _ADJUST_POSITION					0x54

//UART Debug Message Output...
#define _UART_TX_EN							1
#define _UART_RX_EN							2
#define _UART_TX_RX_EN						3
//CAN Debug Message Output...
#define _CAN_TX_EN							1
#define _CAN_RX_EN							2
#define _CAN_TX_RX_EN						3

//System State
#define _SYSTEM_IDLE						0
#define _SYSTEM_NORMAL						1
#define _SYSTEM_SLEEP						2
#define _SYSTEM_WWDG_RST					3
//MSG. Error Report
#define _UART_RX_HEADER_ERR					1
#define _UART_RX_CRC_ERR					2
#define _UART_RX_FRAME_ERR					3
#define _UART_RX_SYNC_ERR					4
#define _UART_RX_ACK_ERR					5
#define _UART_RX_ACK_LENGTH_ERR				6
//RESET EVENT
#define	_WWDG_RESET_EVENT			0x01
#define	_IWDG_RESET_EVENT			0x02
#define	_PIN_RESET_EVENT			0x03
#define	_POR_RESET_EVENT			0x04
#define	_SOFT_RESET_EVENT			0x05
#define	_LOW_PWR_RESET_EVENT		0x06
//Btn KEY COUNT
#define _Btn_KEY_CNT_0		0
#define _Btn_KEY_CNT_1		1
#define _Btn_KEY_CNT_2		2
#define _HU_HOME_KEY		1
#define _HU_PREV_KEY		2
#define _HU_NEXT_KEY		3
#define _HU_PHONE_KEY		4
#define _HU_ALL_OFF_KEY		5

//DISPLAY MODE
#define _HU_MODE			0
#define _NAVI_MODE			1
#define _RR_CAM_MODE		2
#define _USE_TCH_UART		1

//DAC VALUE
//NORMAL STATE : 2.635V - 2.637V(0xC94)
#define _Btn_DA_NOR_VAL			3218
#define _Btn_DA_HOME_VAL		2315
#define _Btn_DA_PREV_VAL		137
#define _Btn_DA_NEXT_VAL		1570
#define _Btn_DA_PHONE_VAL		869

extern CAN_InitTypeDef						CAN_InitStructure;
extern CAN_FilterInitTypeDef				CAN_FilterInitStructure;
extern CanTxMsg								TxMessage;
extern CanTxMsg								Can2Tx;
extern CanRxMsg								RxMessage;


extern u8 nAccStateOld;
extern u8 nAccStateNew;
extern u8 bAccStateOn; //1:acc on, 0:acc off
extern u8 nIgnStatCnt;
extern u8 bIgnIdReceviedOn; //1:ign on, 0:ign off
extern u8 nSelectSpiBuf;
extern u8 nBootStepCnt;
extern u8 bTchInitOn;
extern u8 nIgnIdEnable;
extern u8 bSystemStateVal;
extern u8 nWwdgResetCnt;

extern u8 bStopModeOn;

extern u32 lCan1SleepWaitTmrCnt;

#define VIRTUAL_PRESET_START_ADDR   0x1000
//#define NB_OF_RADIO_VAR 25
#define NB_OF_RADIO_VAR         30
#define NB_OF_GET_FREQ_SENSE    10

#define VIRTUAL_LAST_RADIO_FREQ_ADDR   0x2000
#define VIRTUAL_LAST_RADIO_VOLUME_ADDR   0x2002


extern u8 nCan2DrvErrBufVal;

extern void CRevVarInit(void);
extern void CInitHUFixSet(void);
extern void CPowerCtrl(void);
extern void CStopModeSet(void);
extern void CSaveCurMode(u8 mode);
extern u16 CReadCurMode(void);


extern void CSystemVarInit(void);
extern void CRstVarInit(void);

extern void CAN_Config(void);
extern void CWatchdogEnable(u8 val);
