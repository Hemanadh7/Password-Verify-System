typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;

void delay_ms(u16);

void i2c_start(void);
void i2c_stop(void);
void i2c_write(u8);
u8 i2c_read(void);
bit i2c_ack(void);
void i2c_noack(void);

void lcd_init();
void lcd_data(u8);
void lcd_cmd(u8);
void lcd_string(s8*);

u8 GetKey();

void eeprom_byte_write(u8,u8,u8);
u8 eeprom_byte_read(u8,u8);

void en_ext_interrupt(void);