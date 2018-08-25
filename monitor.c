//*****************************************************************************
// Title		: MONITOR
// Author		: Thinkware - Copyright (C) 2018
// Created		: 3.2018
// Revised		: 3.2018
// Version		: 1.0
// Target MCU	: STM32F10x
//*****************************************************************************
#include "main.h"
#include "string.h"
#include "stdlib.h"


void Monitor(void);

u8 *MonString = 0;

//*****************************************************************************
//				Monitoring Command
//*****************************************************************************
void Monitor(void)
{
	if( MonString )
	{
		RS_ungetch( *MonString++ );
		if( *MonString==0 ) MonString = 0;
	}

	if( !MonGetCommand() ) return;

	if( !strcmp( (const char *) argv[0], "help" ) || !strcmp( (const char *) argv[0], "HELP" ) || !strcmp( (const char *) argv[0], "?" ) )
	{
		MonHelp();
	}
	//CAN DATA Monitering...
	else if( !strcmp( (const char *) argv[0], "2id01" ) || !strcmp( (const char *) argv[0], "2ID01" ) )
	{
		nFilter2Id01 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilter2Id01 : %x\r\n", nFilter2Id01);
	}
	else if( !strcmp( (const char *) argv[0], "2id02" ) || !strcmp( (const char *) argv[0], "2ID02" ) )
	{
		nFilter2Id02 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilter2Id02 : %x\r\n", nFilter2Id02);
	}
	else if( !strcmp( (const char *) argv[0], "2id03" ) || !strcmp( (const char *) argv[0], "2ID03" ) )
	{
		nFilter2Id03 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilter2Id03 : %x\r\n", nFilter2Id03);
	}
	else if( !strcmp( (const char *) argv[0], "2id04" ) || !strcmp( (const char *) argv[0], "2ID04" ) )
	{
		nFilter2Id04 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilter2Id04 : %x\r\n", nFilter2Id04);
	}
	else if( !strcmp( (const char *) argv[0], "2id05" ) || !strcmp( (const char *) argv[0], "2ID05" ) )
	{
		nFilter2Id05 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilter2Id05 : %x\r\n", nFilter2Id05);
	}
	//Uart TX CMD Monitering...
	else if( !strcmp( (const char *) argv[0], "cmdtx01" ) || !strcmp( (const char *) argv[0], "CMDTX01" ) )
	{
		nFilterUartTxCmd01 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartTxCmd01 : %x\r\n", nFilterUartTxCmd01);
	}
	else if( !strcmp( (const char *) argv[0], "cmdtx02" ) || !strcmp( (const char *) argv[0], "CMDTX02" ) )
	{
		nFilterUartTxCmd02 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartTxCmd02 : %x\r\n", nFilterUartTxCmd02);
	}
	else if( !strcmp( (const char *) argv[0], "cmdtx03" ) || !strcmp( (const char *) argv[0], "CMDTX03" ) )
	{
		nFilterUartTxCmd03 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartTxCmd03 : %x\r\n", nFilterUartTxCmd03);
	}
	else if( !strcmp( (const char *) argv[0], "cmdtx04" ) || !strcmp( (const char *) argv[0], "CMDTX04" ) )
	{
		nFilterUartTxCmd04 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartTxCmd04 : %x\r\n", nFilterUartTxCmd04);
	}
	else if( !strcmp( (const char *) argv[0], "cmdtx05" ) || !strcmp( (const char *) argv[0], "CMDTX05" ) )
	{
		nFilterUartTxCmd05 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartTxCmd05 : %x\r\n", nFilterUartTxCmd05);
	}
	//Uart RX CMD Monitering...
	else if( !strcmp( (const char *) argv[0], "cmdrx01" ) || !strcmp( (const char *) argv[0], "CMDRX01" ) )
	{
		nFilterUartRxCmd01 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartRxCmd01 : %x\r\n", nFilterUartRxCmd01);
	}
	else if( !strcmp( (const char *) argv[0], "cmdrx02" ) || !strcmp( (const char *) argv[0], "CMDRX02" ) )
	{
		nFilterUartRxCmd02 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartRxCmd02 : %x\r\n", nFilterUartRxCmd02);
	}
	else if( !strcmp( (const char *) argv[0], "cmdrx03" ) || !strcmp( (const char *) argv[0], "CMDRX03" ) )
	{
		nFilterUartRxCmd03 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartRxCmd03 : %x\r\n", nFilterUartRxCmd03);
	}
	else if( !strcmp( (const char *) argv[0], "cmdrx04" ) || !strcmp( (const char *) argv[0], "CMDRX04" ) )
	{
		nFilterUartRxCmd04 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartRxCmd04 : %x\r\n", nFilterUartRxCmd04);
	}
	else if( !strcmp( (const char *) argv[0], "cmdrx05" ) || !strcmp( (const char *) argv[0], "CMDRX05" ) )
	{
		nFilterUartRxCmd05 = my_htoi((char *)argv[1]); dPrintf("\r\n nFilterUartRxCmd05 : %x\r\n", nFilterUartRxCmd05);
	}
	//µð¹ö±ë Ä¿¸àµå Ãß°¡...
    else
    {
        dPrintf("\r\nInvalid command...");
    }

    Prompt();
}



