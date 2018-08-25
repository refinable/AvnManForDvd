//----------------------------------------------------------------------------------------------------
// ID Code      : func_s.h
// Update Note  :
//----------------------------------------------------------------------------------------------------

///*---------------------------------------------------------------
// TJA1045 SLEEP MODE CONFIG[/STB:PC2, EN:PC1]
//  /STB  |   EN  |    STATE
//    1   |   1   |   NORMAL
//    0   |   1   |   GOTO SLEEP
//    0   |   0   |   SLEEP
//---------------------------------------------------------------*/
#define _NSTB_PC2_ON			GPIOC->BSRR = 0x00000004  // 1
#define _NSTB_PC2_OFF			GPIOC->BRR  = 0x00000004  // 0
#define _EN_PC1_ON				GPIOC->BSRR = 0x00000002  // 1
#define _EN_PC1_OFF				GPIOC->BRR  = 0x00000002  // 0

///*---------------------------------------------------------------
// [PB1] 화면모드 세팅 : [1]HU, [0]NAVI
//---------------------------------------------------------------*/
	//Touch /CHG연결
	#define _VID_NAVI_DISP_ON			GPIOB->BSRR = 0x00000002  // 1
	#define _VID_NAVI_DISP_OFF			GPIOB->BRR  = 0x00000002  // 0

///*---------------------------------------------------------------
// PC0: TW_RESET(출력) :[H]RESET, [L]NORMAL,TW8836 RESET입력과 연결
//TR통해서 반전됨.
//---------------------------------------------------------------*/
#define _TW_RESET_RESET_HIGH	GPIOC->BSRR  = 0x00000001  // 0
#define _TW_RESET_NORMAL_LOW	GPIOC->BRR  = 0x00000001  // 0

///*---------------------------------------------------------------
// PA15: TW_SPI_IN(입력) :[H]NORMAL, [L]SPI 동글 연결됨.TW8836 RESET 출력으로 만들어야 함.
//---------------------------------------------------------------*/
#define _TW_SPI_IN_CHK			GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15)


///*---------------------------------------------------------------
// PB15: HU_High(출력) :NAVI화면:L, HU화면:H
//---------------------------------------------------------------*/
#define HU_HIGH_ON				GPIOB->BSRR = 0x00008000  // 1
#define HU_HIGH_OFF				GPIOB->BRR  = 0x00008000  // 0

#if 0
///*---------------------------------------------------------------
// TOUCH_EN_CHK : PA7
//---------------------------------------------------------------*/
#define TOUCH_EN_CHK			GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7)
#endif

#if 1
///*---------------------------------------------------------------
// TOUCH_EN_CHK : PC4
//---------------------------------------------------------------*/
#define TOUCH_EN_CHK			GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4)
#endif

//SELECT SWITCH INPUT
///*---------------------------------------------------------------
// PB5: ST06
//---------------------------------------------------------------*/
#define _ST06_CHK			              GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)
#define _TCH_UART_ON_ST06_CHK			  GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)

///*---------------------------------------------------------------
// PB6: ST05
//---------------------------------------------------------------*/
#define _ST05_CHK			                        GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14)

///*---------------------------------------------------------------
// PB7: ST04
//---------------------------------------------------------------*/
#define _ST04_CHK						GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)
#define _PAS_H_OFF_ST04_CHK				GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)

///*---------------------------------------------------------------
// PC13: ST03
//---------------------------------------------------------------*/
#define _ST03_CHK						GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9)
#define _RR_CAM_H_ON_ST03_CHK			GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9)
//#define _TCH_UART_ON_ST03_CHK			GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9)

///*---------------------------------------------------------------
// PC14: ST02
//---------------------------------------------------------------*/
//#define _ST02_CHK						GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8)
#define _ST02_CHK						GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)
#define _FR_CAM_H_ON_ST02_CHK			GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8)

///*---------------------------------------------------------------
// PC15: ST01
//---------------------------------------------------------------*/
//#define _ST01_CHK						GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define _ST01_CHK						GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14)
#define _OR_CAM_H_ON_ST01_CHK			GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)

///*---------------------------------------------------------------
// PA2: ENCODER_A
//---------------------------------------------------------------*/
#define _ENCODER_A_CHK		GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)


///*---------------------------------------------------------------
// VDD5V_OP_EN SLEEP MODE CONFIG[PC6] : [1]OPERATE, [0]STANDBY
//---------------------------------------------------------------*/
#define _VDD5V_OP_EN_ON		GPIOC->BSRR = 0x00000040  // 1
#define _VDD5V_OP_EN_OFF		GPIOC->BRR  = 0x00000040  // 0

///*---------------------------------------------------------------
// V3P3D_OP_EN SLEEP MODE CONFIG[PC7] : [1]OPERATE, [0]STANDBY
//---------------------------------------------------------------*/
#define _V3P3D_OP_EN_ON			GPIOC->BSRR = 0x00000080  // 1
#define _V3P3D_OP_EN_OFF		GPIOC->BRR  = 0x00000080  // 0



#define _FF_CLK_HIGH			GPIOC->BSRR = 0x00000001  // 1
#define _FF_CLK_LOW			GPIOC->BRR  = 0x00000001  // 0

///*---------------------------------------------------------------
// VBUS INPUT CHECK				[PB6] : [1]VBUS ENABLE, [0]DISABLE
//---------------------------------------------------------------*/
#define _VBUS_ENABLE			GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3)

///*---------------------------------------------------------------
// RELAY SWITCH INPUT CHECK		[PC9] : [1]NAVI, [0]HU
//---------------------------------------------------------------*/
#define _NAVI_MODE_CHK			GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9)



////////////// [ O U T P U T ]


///*---------------------------------------------------------------
// [PC1]: EN, [PC2]: /STB. TJA1043 SLEEP MODE CONFIG[/STB:PC2, EN:PC1]
//  /STB  |   EN  |    STATE
//    1   |   1   |   NORMAL
//    0   |   1   |   GOTO SLEEP
//    0   |   0   |   STANDBY
//---------------------------------------------------------------*/
#define _NSTB_PC2_ON			GPIOC->BSRR = 0x00000004  // 1
#define _NSTB_PC2_OFF			GPIOC->BRR  = 0x00000004  // 0
#define _EN_PC1_ON				GPIOC->BSRR = 0x00000002  // 1
#define _EN_PC1_OFF				GPIOC->BRR  = 0x00000002  // 0

///*---------------------------------------------------------------
// [PC4]: STB. TJA1042 SLEEP MODE CONFIG[STB:PC4]
//   STB  | STATE
//    1   | STANDBY
//    0   | NORMAL
//---------------------------------------------------------------*/
#define _STB_PC4_ON				GPIOC->BSRR = 0x00000008  // 1
#define _STB_PC4_OFF			GPIOC->BRR  = 0x00000008  // 0

///*---------------------------------------------------------------
// [PC13]: HU I2C SWITCH CONTROL	: [1]ON, [0]OFF	// Default HU=OFF
//---------------------------------------------------------------*/
#define _HU_I2C_SW_CTRL_ON		GPIOC->BSRR = 0x00002000  // 1
#define _HU_I2C_SW_CTRL_OFF		GPIOC->BRR  = 0x00002000  // 0

///*---------------------------------------------------------------
// [PA6]: INTERRUPT AMP MUTE CONTROL	: [1]ON, [0]OFF // ACTIVE LOW
//---------------------------------------------------------------*/
//#define _INT_AMP_MUTE_ON		GPIOA->BSRR = 0x00000040  // 1
//#define _INT_AMP_MUTE_OFF		GPIOA->BRR = 0x00000040  // 0
#define _INT_AMP_MUTE_OFF		GPIOA->BSRR = 0x00000040  // 1
#define _INT_AMP_MUTE_ON		GPIOA->BRR = 0x00000040  // 0

///*---------------------------------------------------------------
// [PA7]: CPU RESET CONTROL	: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _CPU_RESET_ON			GPIOA->BSRR = 0x00000080  // 1
#define _CPU_RESET_OFF			GPIOA->BRR = 0x00000080  // 0

///*---------------------------------------------------------------
// [PB0]: DSP POWER CONTROL	: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _DSP_POWER_ON			GPIOB->BSRR = 0x00000001  // 1
#define _DSP_POWER_OFF			GPIOB->BRR = 0x00000001  // 0

///*---------------------------------------------------------------
// [PB1]: DSP RESET CONTROL	: [0]ON, [1]OFF     // ACTIVE LOW
//---------------------------------------------------------------*/
//#define _DSP_RESET_ON			GPIOB->BSRR = 0x00000002  // 1
//#define _DSP_RESET_OFF			GPIOB->BRR = 0x00000002  // 0
#define _DSP_RESET_OFF			GPIOB->BSRR = 0x00000002  // 1
#define _DSP_RESET_ON			GPIOB->BRR = 0x00000002  // 0  

///*---------------------------------------------------------------
// [PB14]: BACKLIGHT DIMMER: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _LCD_DIM_ON  				GPIOB->BSRR = 0x00004000  // 1
#define _LCD_DIM_OFF				GPIOB->BRR =  0x00004000  // 0

///*---------------------------------------------------------------
// [PC6]: MAIN 5V CONTROL	: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _MAIN_5V_ON				GPIOC->BSRR = 0x00000040  // 1
#define _MAIN_5V_OFF			GPIOC->BRR = 0x00000040  // 0

///*---------------------------------------------------------------
// [PA8]: DSP FAST MUTE CONTROL	: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _DSP_FAST_MUTE_ON		GPIOA->BSRR = 0x00000100  // 1
#define _DSP_FAST_MUTE_OFF		GPIOA->BRR = 0x00000100  // 0

///*---------------------------------------------------------------
// [PD0]: AMP CONTROL	: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _AMP_ON					GPIOD->BSRR = 0x00000001  // 1
#define _AMP_OFF				GPIOD->BRR = 0x00000001  // 0

///*---------------------------------------------------------------
// [PB5]: TW SUB RESET CONTROL	: [1]ON, [0]OFF	// 반전 됨  // ==> 반전 안 함
//---------------------------------------------------------------*/
#define _ANT_SENSE_HIGH			GPIOB->BSRR = 0x00000020  // 1
#define _ANT_SENSE_LOW			GPIOB->BRR =  0x00000020  // 0

// [PC15]: REAR CAM CONTROL	: [1]OFF, [0]ON
#define _REAR_CAM_OFF			GPIOC->BSRR = 0x00008000  // 1
#define _REAR_CAM_ON		    GPIOC->BRR =  0x00008000  // 0

///*---------------------------------------------------------------
// [PD13]: DECK 3V3 CONTROL	: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _DECK_3V3_ON			GPIOD->BSRR = 0x00002000  // 1
#define _DECK_3V3_OFF		    GPIOD->BRR =  0x00002000  // 0
///*---------------------------------------------------------------
// [PD14]: DECK A-POWER CONT'L	: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _DECK_A_PWR_ON			GPIOD->BSRR = 0x00004000  // 1
#define _DECK_A_PWR_OFF		    GPIOD->BRR =  0x00004000  // 0
///*---------------------------------------------------------------
// [PD15]: DECK 5V CONT'L		: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define DECK_5V_ON				GPIOD->BSRR = 0x00008000  // 1
#define DECK_5V_OFF			    GPIOD->BRR =  0x00008000  // 0
///*---------------------------------------------------------------
// [PE12]: _LCD_RESET_ON	: [1]ON, [0]DISABLE
//---------------------------------------------------------------*/
#define _LCD_RESET_ON			GPIOE->BSRR = 0x00001000  // 1
#define _LCD_RESET_OFF		    GPIOE->BRR =  0x00001000  // 0

///*---------------------------------------------------------------
// [PE13]: HU LCD CONTROL	: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _LCD_ON					GPIOE->BSRR = 0x00002000  // 1
#define _LCD_OFF		        GPIOE->BRR =  0x00002000  // 0

///*---------------------------------------------------------------
// [PE14]: BACKLIGHT ON: [1]ON, [0]OFF
//---------------------------------------------------------------*/
#define _BL_ON  				GPIOE->BSRR = 0x00004000  // 1
#define _BL_OFF					GPIOE->BRR =  0x00004000  // 0


///////////// [ I N P U T  ]
///*---------------------------------------------------------------
// [PC0]: BATTERY CHECK
//---------------------------------------------------------------*/
#define _BAT_CHK				GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0)

///*---------------------------------------------------------------
// [PA1]: ACC DET
//---------------------------------------------------------------*/
#define _ACC_DET				GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)

///*---------------------------------------------------------------
// [PC14]: ST01
//---------------------------------------------------------------*/
#define _AVN_ST01_CHK			GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14)

///*---------------------------------------------------------------
// [PC15]: ST02
//---------------------------------------------------------------*/
#define _AVN_ST02_CHK			GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)

///*---------------------------------------------------------------
// [PC4]: TOUCH
//---------------------------------------------------------------*/
#define _HU_TCH_CHK			    GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4)

///*---------------------------------------------------------------
// [PD9]:  DVDP_EJECT		:TATC S/W : <H>PRESSED, <L>RELEASE
//---------------------------------------------------------------*/
#define _DVDP_EJECT_CHK		    GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_9)

///*---------------------------------------------------------------
// [PE8]:  ENCODER_LA		:ENCODER-L A
//---------------------------------------------------------------*/
#define _ENCODER_LA_CHK		    GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_9)
///*---------------------------------------------------------------
// [PE9]:  ENCODER_LB		:ENCODER-L B
//---------------------------------------------------------------*/
#define _ENCODER_LB_CHK		    GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_8)
///*---------------------------------------------------------------
// [PE10]:  ENCODER_RA		:ENCODER-R A
//---------------------------------------------------------------*/
#define _ENCODER_RA_CHK		    GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_11)
///*---------------------------------------------------------------
// [PE11]:  ENCODER_RB		:ENCODER-R B
//---------------------------------------------------------------*/
#define _ENCODER_RB_CHK		    GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_10)



//-----------------------------------
extern u8 nCanTxResusult;
extern u8 iCan2TxTmrCnt;
extern u8 nCan2TxCount;

//-----------------------------------
//#define CAN1_RS_BUF_MAX 	3
#define CAN1_RS_BUF_MAX 	80
//#define CAN2_RS_BUF_MAX 	80
//#define CAN2_TX_RS_BUF_MAX 	80
#define CAN2_RS_BUF_MAX 	3
#define CAN2_TX_RS_BUF_MAX 	3

//CAN1 BLOCK
extern u8 CCan1EventCheck(void);
extern u8 CCan1RS_Ready(void);
extern void CCan1RS_rx(void);
extern void CCan1RS_ungetch(void);

extern u32 lCan1IdRS_buf[CAN1_RS_BUF_MAX];
extern u32 lCan1ExtIdRS_buf[CAN1_RS_BUF_MAX];
extern u8 nCan1RS_buf[CAN1_RS_BUF_MAX][13];
extern u8 nCan1RS_in;
extern u8 nCan1RS_out;

//CAN2 BLOCK
extern u8 CCan2EventCheck(void);
extern u8 CCan2RS_Ready(void);
extern void CCan2RS_rx(void);
extern void CCan2RS_ungetch(void);

extern u32 lCan2IdRS_buf[CAN2_RS_BUF_MAX];
extern u32 lCan2ExtIdRS_buf[CAN2_RS_BUF_MAX];
extern u8 nCan2RS_buf[CAN2_RS_BUF_MAX][13];
extern u8 nCan2RS_in;
extern u8 nCan2RS_out;

extern u8 CCan2TxEventCheck(void);
extern u8 CCan2TxRS_Ready(void);
extern void CCan2TxRS_rx(void);
extern void CCan2TxRS_ungetch(void);

extern u32 lCan2TxIdRS_buf[CAN2_TX_RS_BUF_MAX];
extern u32 lCan2TxExtIdRS_buf[CAN2_TX_RS_BUF_MAX];
extern u8 nCan2TxRS_buf[CAN2_TX_RS_BUF_MAX][13];
extern u8 nCan2TxRS_in;
extern u8 nCan2TxRS_out;
extern u8 nCan2TxDataResusult;
extern u8 nCan2TxDataCount;
extern u8 bCan2TxDataOn;
extern u16 iCan2TxDataTmrCnt;


extern void CSendToCan2Data(void);
extern void CSendToCan2Tx(void);
extern void CSubDWatchDogCheck(void);



