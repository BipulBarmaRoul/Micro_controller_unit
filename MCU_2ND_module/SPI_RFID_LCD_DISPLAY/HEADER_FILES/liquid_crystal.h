/*
 * liquid_crystal.h
 *
 *  Created on: May 2, 2023
 *      Author: BIPUL BARMA ROUL
 */

#ifndef INC_LIQUID_CRYSTAL_H_
#define INC_LIQUID_CRYSTAL_H_

void lcd_init (void);
void lcd_send_string (char *str);
void setCursor(int a, int b);
void lcd_clear (void);

#endif /* INC_LIQUID_CRYSTAL_H_ */
