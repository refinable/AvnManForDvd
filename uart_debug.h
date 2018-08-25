//----------------------------------------------------------------------------------------------------
// ID Code      : uart_debug.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include <stdarg.h>
#include <stdio.h>

extern void USART1_Init (USART_TypeDef* usartx, uint32_t baud);
extern void USART2_Init (USART_TypeDef* usartx, uint32_t baud);
extern void UART4_Init (USART_TypeDef* usartx, uint32_t baud);
extern uint8_t UART4_DebugRun();
extern void UART_DebugGetString(char *pStr);
extern int  UART_DebugGetIntNum(void);
extern int  Char2int (char *pStr);
extern void inScanf(char *pFmt,...);
extern void dPrintf (char *pformat,...);
extern void MsgTx (char *pformat,...);
extern void UART_DebugTxByte (u8 ch, u8 Data);
extern void Delay(void);

#define assert(a) {if(!(a)) {uPrintf("\r\n %s(line %d)\r\n", __FILE__, __LINE__); while(1);}}

