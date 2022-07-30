/*
 * LCD_init.h
 *
 *  Created on: Jul 17, 2022
 *      Author: P4P4
 */

#ifndef LCD_LCD_INIT_H_
#define LCD_LCD_INIT_H_

void H_LCD_void_Init(void);
void H_LCD_void_SendData(u8 Copy_u8data);
void H_LCD_void_SendCommand(u8 Copy_u8command);
void H_LCD_void_SendString(u8 *Copy_u8str);
void H_LCD_void_SendNumber(s32 Copy_s32num);
void H_LCD_void_Clear(void);
void H_LCD_void_GotoXY(u8 Copy_u8Row,u8 Copy_u8Col);
void H_LCD_void_SetCustomChar(u8 * Arr_Pattern,u8 Char_Code);
void H_LCD_void_DisplayCustomChar(u8 Char_Code);

#endif /* LCD_LCD_INIT_H_ */
