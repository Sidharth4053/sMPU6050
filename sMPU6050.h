#ifndef sMPU6050_H
#define sMPU6050_H

#define SCALE_L0 0  // +/- 2g or +/- 250 deg/second
#define SCALE_L1 1  // +/- 4g or +/- 500 deg/second
#define SCALE_L2 2  // +/- 8g or +/- 1000 deg/second
#define SCALE_L3 3  // +/- 16g or +/- 2000 deg/second

#define AD0_LOW  0b1101000    // 0x68 Address I2C
#define AD0_HIGH 0b1101001 	  // 0x69 Address I2C

#define SLEEP_PW 1
#define AWAKE_PW 0

#define MASTER 1
#define SLAVE 0

//Scale Sentivity
#define GSCALE_L0 131.0 
#define GSCALE_L1 65.5
#define GSCALE_L2 32.8
#define GSCALE_L3 16.4

#define ASCALE_L0 16384.0
#define ASCALE_L1 8192.0
#define ASCALE_L2 4096.0
#define ASCALE_L3 2048.0

#define DEG_TO_RAD 57.2957786  //there are like 57 degrees in a radian.
 
class sMPU6050
{
private:
    double _rawXAccel;
    double _rawYAccel;
    double _rawZAccel;
	
	double _rawXGryo;
    double _rawYGryo;
    double _rawZGryo;
	
	double _rawTemp;
	
	int _mode;
	int _type;
	void _setType(int address);
 
public:

	// Reference for Constructor
    
	
	// Reference to make methods
    // void SetDate(int year, int month, int day);
    // int getYear() { return m_year; }
    // int getMonth() { return m_month; }
    // int getDay()  { return m_day; }
	sMPU6050();
	void initMode(int mode,int type);
	void initPower();
	void initPower(int sleepMode);
	void initAccel();
	void initGyro();
	void readAccel();
	void readGyro();
	void readTemp();
	void reset();
	double getXAccel();
	double getYAccel();
	double getZAccel();
	double getXGyro();
	double getYGyro();
	double getZGyro();
	double getTemp();
   
   
};
 
#endif