#ifndef LT768UI_CONFIG_H
#define LT768UI_CONFIG_H

//w25q ic pin
#define W25Q_PIN_NUM_MOSI 5 //right 10
#define W25Q_PIN_NUM_MISO 27 //
#define W25Q_PIN_NUM_CLK  25 //10
#define W25Q_PIN_NUM_CS 26 //11


//lt768 ic pin
#define LT768_PIN_NUM_MOSI 12
#define LT768_PIN_NUM_CLK 32
#define LT768_PIN_NUM_CS 14
#define LT768_PIN_NUM_BL 2
#define LT768_PIN_NUM_INIT 33

//touch i2c pin
#define TP_I2C_MASTER_SCL_IO          13             /*!< gpio number for I2C master clock */
#define TP_I2C_MASTER_SDA_IO          4               /*!< gpio number for I2C master data  */
#define TP_PIN_NUM_INIT 35


#endif