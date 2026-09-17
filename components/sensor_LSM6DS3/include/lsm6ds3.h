#ifndef LSM6DS3_H
#define LSM6DS3_H

#include <stdint.h>

// 1. Endereco do barramento (datasheet)
#define LSM6DS3_I2C_ADD_0 0x6B

// 2. Registradores 
#define LSM6DS3_REG_WHO_AM_I 0x0F
#define LSM6DS3_REG_CTRL1_XL 0x10 // Linear acceleration sensor control register
#define LSM6DS3_REG_CTRL2_G 0x11 // Angular rate sensor control register
#define LSM6DS3_REG_STATUS 0x1E // STATUS_REG -> saber se tem dado novo disponivel
#define LSM6DS3_REG_OUTX_L_G 0x22 // Angular rate seensor pitch axis(X) angular rate output register (r)

// 3. constante de validacao de comunicacao
#define LSM6DS3_WHO_AM_I_VAL 0x6A




#endif
