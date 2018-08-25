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




