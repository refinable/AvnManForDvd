//----------------------------------------------------------------------------------------------------
// ID Code      : I2c.h
// Update Note  :
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Definitions of I2c.c
//--------------------------------------------------
#define _I2C_WRITE_SIZE                 16
#define _I2C_TIMEOUT_LIMIT              200

#define _I2C_BUSY                       0
#define _I2C_OK                         1

#define _I2C_WR                         0
#define _I2C_RD                         1

//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern void Delay5us(void);
extern void Delay1us(void);
extern void DelayI2C(void);
//extern void Delay50us(void);
extern uint8_t CI2cStart(uint8_t ucDeviceAddr);
extern void CI2cStop(void);
extern uint8_t CI2cGetAck(void);
extern void CI2cSendAck(void);
extern uint8_t CI2cSendByte(uint8_t ucValue);
extern uint8_t CI2cGetByte(void);
extern u8 CI2cRead(uint8_t ucDeviceAddr, uint8_t ucStartAddr, uint16_t usLength, uint8_t *pReadArray);
extern u8 CI2cWrite(uint8_t ucDeviceAddr, uint8_t ucStartAddr, uint16_t usLength, uint8_t *pWriteArray);

extern void I2cStart(void);
extern void I2cSendByte(uint8_t ucValue);
extern void I2cAckCheck(void);
extern void I2cAckCheck(void);
extern void I2cRead(uint8_t ucDeviceAddr, uint8_t ucStartAddr, uint16_t usLength, uint8_t *pReadArray);
extern void I2cWrite(uint8_t ucDeviceAddr, uint8_t ucStartAddr, uint16_t usLength, uint8_t *pWriteArray);
extern s32 TwiWrite(u8 device_addr, u8 addr,u8 *buffer, s32 length);
extern s32 TwiRead(u8 device_addr, u8 addr,u8 *buffer, s32 length);

extern void CInitGpio(void);
extern void Delay1ms(void);
extern void CStopGpioSet(void);
extern void CForcedGpioSet(void);

//----------------------------------------------------------------------------------------------------

