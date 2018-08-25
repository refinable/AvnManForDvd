//----------------------------------------------------------------------------------------------------
// ID Code      : adc.h
// Update Note  :
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Definitions of adc.c
//--------------------------------------------------
#define _ADC_AVG_CNT		10

void CBtnKeyCheck(void);


void CKeyInfoDisp(u8 key_val);
extern void CEncoderCheck(void);

typedef struct
{
	u8 bAdcAvgOn;

	u8 bAdcCalOn1;
	u8 nAdcCount1;
	u16 iAdcValue1;
	u16 iAdcValue1Old;
	u16 iAdcAvgVal1;

	u8 bAdcCalOn2;
	u8 nAdcCount2;
	u16 iAdcValue2;
	u16 iAdcValue2Old;
	u16 iAdcAvgVal2;

	u8 bAdcCalOn3;
	u8 nAdcCount3;
	u16 iAdcValue3;
	u16 iAdcValue3Old;
	u16 iAdcAvgVal3;
} AdcTypeDef;
extern AdcTypeDef					Adc;

typedef struct
{
	u8 nKeyChkCnt;
	u8 nBtnKeyName;
	u8 bDvdpKeyOld;
	u8 bDvdpKeyNew;
	u8 bBtnKeyOn;
	u8 bHomeKeyOld;
	u8 bHomeKeyNew;
	u8 nBtnDlyCnt;
	u16 iBtnDlyTmrCnt;
	u8 nKeyValOld;
	u8 nKeyValNew;
	u16 iBtnKeyIntervalTime;
} BtnTypeDef;
extern BtnTypeDef					Btn;

typedef struct
{
	u8 bRightEnVal;
	u8 bLeftEnVal;

} EncTypeDef;
extern EncTypeDef					Enc;
//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
void reset_calibration(ADC_TypeDef *ADCx);
void AdcInit();
void CGetAdcAverage(void);
//----------------------------------------------------------------------------------------------------

