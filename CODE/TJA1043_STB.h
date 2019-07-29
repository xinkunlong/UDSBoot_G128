/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TJA1043_STB.h
**     Project   : Bootloader
**     Processor : MC9S12G128MLF
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.16, CPU db: 3.00.017
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2019/7/29, 10:07
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       41            |  PS2_RXD1
**             ----------------------------------------------------
**
**         Port name                   : S
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : $0004
**
**         Initial direction           : Output (direction can be changed)
**         Safe mode                   : yes
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTS       [$0248]
**         Port control register       : DDRS      [$024A]
**
**         Optimization for            : speed
**     Contents  :
**         SetDir - void TJA1043_STB_SetDir(bool Dir);
**         GetVal - bool TJA1043_STB_GetVal(void);
**         PutVal - void TJA1043_STB_PutVal(bool Val);
**         ClrVal - void TJA1043_STB_ClrVal(void);
**         SetVal - void TJA1043_STB_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef TJA1043_STB_H_
#define TJA1043_STB_H_

/* MODULE TJA1043_STB. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG TJA1043_STB_CODE
/*
** ===================================================================
**     Method      :  TJA1043_STB_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define TJA1043_STB_GetVal() ( \
    (bool)((getReg8(PTS) & 0x04U))     /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  TJA1043_STB_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**           a) direction = Input  : sets the new output value;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes the value to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void TJA1043_STB_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  TJA1043_STB_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**           a) direction = Input  : sets the output value to "0";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "0" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define TJA1043_STB_ClrVal() ( \
    (void)clrReg8Bits(PTS, 0x04U)      /* PTS2=0x00U */, \
    (Shadow_S &= 0xFBU)                /* Set appropriate bit in shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  TJA1043_STB_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**           a) direction = Input  : sets the output value to "1";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "1" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define TJA1043_STB_SetVal() ( \
    (void)setReg8Bits(PTS, 0x04U)      /* PTS2=0x01U */, \
    (Shadow_S |= 0x04U)                /* Set appropriate bit in shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  TJA1043_STB_SetDir (component BitIO)
**
**     Description :
**         This method sets direction of the component.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
void TJA1043_STB_SetDir(bool Dir);

#pragma CODE_SEG DEFAULT

/* END TJA1043_STB. */
#endif /* #ifndef __TJA1043_STB_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/