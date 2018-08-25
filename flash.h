//----------------------------------------------------------------------------------------------------
// ID Code      : flash.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifndef  _FLASH_H
#define  _FLASH_H

#ifdef __cplusplus
extern "C" {
#endif


#define NB_OF_VAR		4
extern u16 VirtAddVarTab[NB_OF_VAR];
extern u16 VarDataTab[NB_OF_VAR];

extern void ClearFlash_PresetFreq(void);
extern void SaveFlash_PresetFreq(u8 Addr, u16 Freq);
extern u16 LoadFlash_PresetFreq(u8 Addr);
extern void SaveFlash_LastFreq(u16 Freq);
extern void LoadFlash_LastFreq(void);
extern void SaveFlash_LastVol(u16 Volume);
extern void LoadFlash_LastVol(void);


#ifdef __cplusplus
}
#endif

#endif // _FLASH_H

