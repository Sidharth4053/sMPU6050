# sMPU6050
Simplified MPU6050 (aka sMPU6050) Library v1.0

This library provide simplifed form to use MPU6050.

# Methods

<b> sMPU6050() </b>

default constructor, It will set code to Slave mode and in low scale mode of MPU6050. i.e. (+/- 2g and +/- 250 deg/sec) mode



<b> initMode(int mode, int type) </b>

This method is very important, it need to be set first. As soon as you initialize the object this need to be called to setup your chip.
otherwise default constructor will set your MPU6050 to "Slave Mode" plus +/- 2g Accerlation and +/- 250 deg/sec Gyro.



<b> readAccel() </b>

<b> readGyro() </b>

These two methods read the current value of x/y/z-axis Accerlation and x/y/z-axis Gyro. So everytime loop iterate this need to calls everytime, so as to read refreshed values.



<b> double getXAccel() </b>

<b> double getYAccel() </b>

<b> double getZAccel() </b>

<b> double getXGyro() </b>

<b> double getYGyro() </b>

<b> double getZGyro() </b>


As there name suggest they return the processed values of whatever type is set. 
Ex: for 4g it will return : x-axis/8192.0 value, similarly for gyro as well



# PS
This library is version 1.0, will update it more to make it more simplified velocity,accerlation,displacement and angle.
Temperature methods might not work effectively in current state, will improve in due time.

I would like to thanks jeff's MPU6050 lib for this.

-Sidharth




