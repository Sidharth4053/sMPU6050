#include "sMPU6050.h"
#include <Wire.h>
 
// Init constructor
sMPU6050::sMPU6050()
{
	//default intialisation
	initMode(SLAVE,SCALE_L0);
	initPower();
	initAccel();
	initGyro();
	
}
 
// Power Mode function
void sMPU6050::initPower()
{
	if(_mode == 0){
		Wire.beginTransmission(AD0_LOW);   
	   }else if(_mode == 1){
		Wire.beginTransmission(AD0_HIGH);
	   }
	Wire.write(0x6B);
	Wire.write(0b00000000);
    Wire.endTransmission();
}

void sMPU6050::initPower(int sleepMode)
{
	if(_mode == 0){
		Wire.beginTransmission(AD0_LOW);   
	   }else if(_mode == 1){
		Wire.beginTransmission(AD0_HIGH);
	   }
	Wire.write(0x6B);
	if(sleepMode == 0){
		Wire.write(0b00000000);
	}else if(sleepMode == 1){
		Wire.write(0b11000000);
	}
    Wire.endTransmission();
}

// Accel Mode function
void sMPU6050::initAccel()
{
	if(_mode == 0){
		Wire.beginTransmission(AD0_LOW);   
	   }else if(_mode){
		Wire.beginTransmission(AD0_HIGH);
	   }
	Wire.write(0x1B);
	_setType(_type);
    Wire.endTransmission();
}

// Gyro Mode function
void sMPU6050::initGyro()
{
	if(_mode == 0){
		Wire.beginTransmission(AD0_LOW);   
	   }else if(_mode == 1){
		Wire.beginTransmission(AD0_HIGH);
	   }
	Wire.write(0x1C);
	_setType(_type);
    Wire.endTransmission();
}

// Set type
void sMPU6050::initMode(int mode,int type)
{
	_mode = mode;
	_type = type;
}

void sMPU6050::_setType(int address){
	
	if(address == 0){
	  Wire.write(0b00000000);  // L0 
   }else if(address == 1){
	 Wire.write(0b00001000);   // L1
   }else if(address == 2){
	 Wire.write(0b00010000);   // L2
   }else if(address == 3){
	Wire.write(0b00011000);    // L3
   }
}

void sMPU6050::readAccel(){
  if(_mode == 0){
		Wire.beginTransmission(AD0_LOW);   
	   }else if(_mode == 1){
		Wire.beginTransmission(AD0_HIGH);
	   }
  Wire.write(0x3B); //Starting register for Accel Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Accel Registers (3B - 40)
  while(Wire.available() < 6);
	_rawXAccel=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
	_rawYAccel=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
	_rawZAccel=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
}

void sMPU6050::readGyro(){
	 if(_mode == 0){
		Wire.beginTransmission(AD0_LOW);   
	   }else if(_mode == 1){
		Wire.beginTransmission(AD0_HIGH);
	   }
  Wire.write(0x43); //Starting register for Gyro Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Gyro Registers (43 - 48)
  while(Wire.available() < 6);
	_rawXGryo=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
	_rawYGryo=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
	_rawZGryo=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)	
}

void sMPU6050::readTemp(){
	 if(_mode == 0){
		Wire.beginTransmission(AD0_LOW);   
	   }else if(_mode == 1){
		Wire.beginTransmission(AD0_HIGH);
	   }
  Wire.write(0x41); //Starting register for Temp Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,2); //Request Temp Registers (41 - 42)
  while(Wire.available() < 2);
	_rawTemp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)	
}

double sMPU6050::getXAccel(){
	if(_type == 0){
	return _rawXAccel/ASCALE_L0;
	}else if(_type == 1){
	return _rawXAccel/ASCALE_L1; 
	}else if(_type == 2){
	return _rawXAccel/ASCALE_L2; 
	}else if(_type == 3){
	return _rawXAccel/ASCALE_L3; 
	}else {
		return 0;
	}
}

double sMPU6050::getYAccel(){
	if(_type == 0){
	return _rawYAccel/ASCALE_L0;
	}else if(_type == 1){
	return _rawYAccel/ASCALE_L1; 
	}else if(_type == 2){
	return _rawYAccel/ASCALE_L2; 
	}else if(_type == 3){
	return _rawYAccel/ASCALE_L3; 
	}else {
		return 0;
	}
}

double sMPU6050::getZAccel(){
	if(_type == 0){
	return _rawZAccel/ASCALE_L0;
	}else if(_type == 1){
	return _rawZAccel/ASCALE_L1; 
	}else if(_type == 2){
	return _rawZAccel/ASCALE_L2; 
	}else if(_type == 3){
	return _rawZAccel/ASCALE_L3; 
	}else {
		return 0;
	}
}

double sMPU6050::getXGyro(){
	if(_type == 0){
	return _rawXGryo/ASCALE_L0;
	}else if(_type == 1){
	return _rawXGryo/ASCALE_L1; 
	}else if(_type == 2){
	return _rawXGryo/ASCALE_L2; 
	}else if(_type == 3){
	return _rawXGryo/ASCALE_L3; 
	}else {
		return 0;
	}
}

double sMPU6050::getYGyro(){
	if(_type == 0){
	return _rawYGryo/ASCALE_L0;
	}else if(_type == 1){
	return _rawYGryo/ASCALE_L1; 
	}else if(_type == 2){
	return _rawYGryo/ASCALE_L2; 
	}else if(_type == 3){
	return _rawYGryo/ASCALE_L3; 
	}else {
		return 0;
	}
}

double sMPU6050::getZGyro(){
	if(_type == 0){
	return _rawZGryo/ASCALE_L0;
	}else if(_type == 1){
	return _rawZGryo/ASCALE_L1; 
	}else if(_type == 2){
	return _rawZGryo/ASCALE_L2; 
	}else if(_type == 3){
	return _rawZGryo/ASCALE_L3; 
	}else {
		return 0;
	}
}

double sMPU6050::getTemp(){
	if(_type == 0){
	return _rawTemp/ASCALE_L0;
	}else if(_type == 1){
	return _rawTemp/ASCALE_L1; 
	}else if(_type == 2){
	return _rawTemp/ASCALE_L2; 
	}else if(_type == 3){
	return _rawTemp/ASCALE_L3; 
	}else {
		return 0;
	}
}

