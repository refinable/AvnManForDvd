//*****************************************************************************
// Title		: MAIN
// Author		: Thinkware - Copyright (C) 2018
// Created		: 3.2018
// Revised		: 3.2018
// Version		: 1.0
// Target MCU	: STM32F10x
//*****************************************************************************
#include "main.h"

/* debug message display option Start ----------------------------------------*/
#if(_UART_TX_ACK_MON_ENABLE == _ON && _UART_RX_DATA_MON_ENABLE == _ON)
	u8 bDbgUartAckOn = 1; //MCU<->AVN ACK MSG. DISPLAY 0:OFF, 1:ON
#else
	u8 bDbgUartAckOn = 0;
#endif
/* debug message display option End ------------------------------------------*/


int main(void)
{
	CSysInit();

    while(1)
    {
		CCanCheck();
		CPowerCtrl();
		CStopModeSet();
		CEncoderCheck();
		CGetAdcAverage();
		CBtnKeyCheck();
		CWatchdogEnable(0xff);

		CSendAvnFrameMsg(nCan1MsgEventOn);      // MCU->AP(CPU) 
		CGetCommand();                                         // AP(CPU)->MCU Message Get, Parsing
		TaskProcess();                                            // AP(CPU)->MCU Receive UART Data Analyze & Process

		WWDG_SetCounter(127);
		CResponseFramDataResend();                      // UART MESSAGE RESEND

		Monitor();                                                    // DEBUG by UART4 MESSAGE

    } //end while
} // end main


/*======================================================================
    AP(CPU)->MCU 로 수신 된 FRAME DATA 처리
=======================================================================*/
void TaskProcess(void)
{
	if( RX_RECEIVE == _TRUE )
	{
		RX_RECEIVE =  _FALSE;

		#if(_FROM_AVN_MSG_DISPLAY_ENABLE== _ON)
			CUartRxPrintFunc(&RX_DATA[0]);
		#endif

		if(RX_DATA[2] == _INIT_COMPLETE_COMM) //0x90
		{
			if(RX_DATA[4] == 1)
			{
				//MCU->AVN:0x10 Vehicle Info(차종 정보) 전송.
				RespCmd.nVehicleInfo = _VEHICLE_GM_CHEVROLET;
				CMCUToAvnCommandSave(_MCU_VEHICLE_INFO);
				nBootStepCnt = 0;
				dPrintf("\r\n=S%02d:AVN INIT COMPLETE=", ++nBootStepCnt);
			}
			else;
		}
		else if(RX_DATA[2] == _UPDATE_READY) //0x90
		{

			CRevVarInit();

			iUpdateStatVal = 0x5555;
			WWDG->CR = 0xff; //WWDG Enable
			while(1){ dPrintf("."); }
		}
		else if(RX_DATA[2] == _CMD_DVD) //0xXX
		{
		}
                //이 곳에 수신 커멘드 추가...
		else CReqErrMsg(RX_DATA[2], RX_DATA[5]);
	}
	else if( RX_ACK == _TRUE )
	{
		RX_ACK = _FALSE;

		if(RX_ACKD[0] == _AVN_ACK) //정상 수신.
		{
			nSendFrameCnt = 0;

			if(nSendToAvnDataDelay10ms == 0) { nSendToAvnAckDelayTmrCnt = 0; nSendToAvnDataDelay10ms = 1; }

			if(bAirInfoSendOk == 1)
			{
				bAirInfoSendOk = 2;
				dPrintf("\r\n=S%02d:AIRCON INFO SEND COMPLETE=", ++nBootStepCnt);

				CMCUToAvnCommandSave(_MCU_AIRCON_STATUS);
				CMCUToAvnCommandSave(_MCU_VERSION_INFO);
			}

			CResponseProcClear();
		}
		else if(RX_ACKD[0] == _AVN_NACK)
		{
			if(++nSendFrameCnt >= 3)
			{
				//3회까지 재 전송 실패...
				nSendFrameCnt = 0;
				CResponseProcClear();
			}
			else
			{
				//FRAME DATA Resend...
				CAckWaitTimeCheckStart();
			}

			//dPrintf("\r\n================== ### RX_NACK : D0=%x, D1=%x, D2=%x #########", RX_ACKD[0], RX_ACKD[1], RX_ACKD[2]);
		}
	}
	else
	{
		if(RX_DATA[0] != 0x00 && RX_DATA[1] != 0x00 && RX_DATA[0] != _SYNC1 && RX_ACKD[0] != _AVN_ACK && RX_ACKD[0] != _AVN_NACK)
		{
			//dPrintf("\r\n================== ### RX_NACK-2 : D0=%x, D1=%x, D2=%x #########", RX_ACKD[0], RX_ACKD[1], RX_ACKD[2]);
		}
	}

}










