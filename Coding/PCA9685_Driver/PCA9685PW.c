/*
 * PCA9685PW.c
 *
 *  Created on: Dec 26, 2024
 *      Author: David Bascom
 */

#include "PCA9685PW.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t PCA9685_Init(PCA9685 *dev, I2C_HandleTypeDef *i2cHandle) {

	/* Set up struct params */
	dev->i2cHandle		=i2cHandle;
	dev->frequency      =50;


	/* Store number of transaction errors (to be returned at the end of function) */
	uint8_t errNum = 0;
	HAL_StatusTypeDef status;

	PCA9685_SetPWMFrequency(dev->frequency); // 50 Hz for servo
	PCA9685_SetBit(PCA9685_MODE1, PCA9685_MODE1_AI_BIT, 1);
}


void Servo_Init(Servo *dev, uint8_t Channel, uint8_t deg, uint16_t home_flag, uint16_t home) {

	dev->Channel		=Channel;
	dev->deg_range		=deg;
	dev->home_flag		=home_flag;
	if (home_flag == 1){
		dev->home		=home;
	}
}



/* LOW-LEVEL FUNCTIONS */

HAL_StatusTypeDef PCA9685_ReadRegister(uint8_t Register, uint8_t *data) {
	return HAL_I2C_Mem_Read(&hi2c1,PCA9685_I2C_ADDR, Register, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}


HAL_StatusTypeDef PCA9685_ReadRegisters(uint8_t Register, uint8_t *data, uint8_t Length) {
	return HAL_I2C_Mem_Read(&hi2c1,PCA9685_I2C_ADDR, Register, I2C_MEMADD_SIZE_8BIT, data, Length, HAL_MAX_DELAY);
}


HAL_StatusTypeDef PCA9685_WriteRegister(uint8_t Register, uint8_t *data) {
	return HAL_I2C_Mem_Write(&hi2c1, PCA9685_I2C_ADDR, Register, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);
}


HAL_StatusTypeDef PCA9685_WriteRegisters(uint8_t Register, uint8_t *data, uint8_t Length) {
	return HAL_I2C_Mem_Write(&hi2c1, PCA9685_I2C_ADDR, Register, I2C_MEMADD_SIZE_8BIT, data, Length, HAL_MAX_DELAY);
}


// Read all 8 bits and set only one bit to 0/1 (Value) and write all 8 bits back
void PCA9685_SetBit(uint8_t Register, uint8_t Bit, uint8_t Value) {
  uint8_t readValue;
  PCA9685_ReadRegister(Register, &readValue);
  if (Value == 0) readValue &= ~(1 << Bit);
  else readValue |= (1 << Bit);
  PCA9685_WriteRegister(Register, &readValue);
  HAL_Delay(1);
}


void PCA9685_SetPWMFrequency(uint16_t frequency) {
  uint8_t prescale;
  if(frequency >= 1526) prescale = 0x03;
  else if(frequency <= 24) prescale = 0xFF;      //  internal 25 MHz oscillator as in the datasheet page no 1/52
  else prescale = 25000000 / (4096 * frequency); // prescale changes 3 to 255 for 1526Hz to 24Hz as in the datasheet page no 1/52
  PCA9685_SetBit(PCA9685_MODE1, PCA9685_MODE1_SLEEP_BIT, 1);
  PCA9685_WriteRegister(PCA9685_PRE_SCALE, &prescale);
  PCA9685_SetBit(PCA9685_MODE1, PCA9685_MODE1_SLEEP_BIT, 0);
  PCA9685_SetBit(PCA9685_MODE1, PCA9685_MODE1_RESTART_BIT, 1);
}


void PCA9685_SetPWM(Servo* dev, uint16_t OnTime, uint16_t OffTime) {
  uint8_t registerAddress;
  uint8_t pwm[4];
  registerAddress = PCA9685_LED0_ON_L + (4 * dev->Channel);
  pwm[0] = OnTime & 0xFF;
  pwm[1] = OnTime>>8;
  pwm[2] = OffTime & 0xFF;
  pwm[3] = OffTime>>8;
  PCA9685_WriteRegisters(registerAddress, pwm, 4);
}


void PCA9685_SetServoAngle(Servo* dev, float Angle)
{
  float Value;
  Value = (Angle * (511.9 - 102.4) / dev->deg_range) + 102.4;
  PCA9685_SetPWM(dev, 0, (uint16_t)Value);
}
