//----------------------------------------------------------------------------------------------------
//
// ID Code      : monitor.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
extern void Mon_tx(u8 ch);

extern void MonHelp(void);
extern u8 MonGetCommand( void);
extern void Monitor(void);
extern void Prompt(void);
extern void RS_ungetch(u8 ch);
extern int my_htoi(char *Str);
extern void my_toupper(char *Str);
extern void UpperStr(char *Str);

extern u8 bPromptOn;

#define RS_BUF_MAX 	32
extern u8 RS_buf[RS_BUF_MAX];
extern u8 RS_in, RS_out;
extern u8 argc;
extern u8 echo;
extern u8 access;
extern u8 DebugLevel;
extern u8 MonIndex;
extern u8 MonRdata, MonWdata;
extern u8 monstr[40];
extern u8 *argv[10];
extern u8 bPromptOn;


extern void Mon_tx(u8 ch);
extern void MonHelp(void);
extern u8 MonGetCommand( void);
extern void Prompt(void);

extern u8 RS_ready(void);
extern u8 RS_rx(void);
extern void RS_ungetch(u8 ch);
extern int my_htoi(char *Str);
extern void my_toupper(char *Str);
extern void UpperStr(char *Str);



