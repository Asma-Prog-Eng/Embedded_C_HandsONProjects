

#ifndef I2C_H_
#define I2C_H_


#define DS323_ADDR               0x68

void read_Byte(char saddr, char maddr, char* data);

void I2C_init(void);

void GPIO_I2C_init(void);


#endif /* I2C_H_ */
