#include <LiquidCrystal_I2C.h>

#ifndef CLCD_I2C_H
#define CLCD_I2C_H

#define CLCD_COLS 16
#define CLCD_ROWS 2
#define CLCD_ADDR 0x27

class CharacterLCD {
private:
    uint8_t cols, rows, addr;
    LiquidCrystal_I2C lcd;
public:
    CharacterLCD(uint8_t address, uint8_t c, uint8_t r);
    void init(void);
    void clearLCD(void);
    void selectLine(int l);
    void printLCD(const char* s);
    void printLCD(String s);
    void printLCD(int n);
    void printLCD(float f);
    void printAt(const char* s, uint8_t col, uint8_t row);
    void printAt(String s, uint8_t col, uint8_t row);
};

#endif
