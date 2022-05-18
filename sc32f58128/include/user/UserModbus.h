#ifndef USERMODBUS_H
#define USERMODBUS_H


#include "stdint.h"
#include "SC32F58128.h"
#include "mb.h"
#include "mbport.h"
#include "mbutils.h"




typedef enum
{
  ModbusENABLE=0x00,
  DriveENABLE,
	MotorTargetVelocity,
	MotorAcceleration,
	WeakMagneticAngle,
	VelocityLoop_P,
	VelocityLoop_I,   
	PositionLoop_P,
	VelocityFeedforward,
	DIRPolarity,
	ElectronicGearNumerator ,
	ElectronicGearDenominator,
	TargetLocationLow,
	TargetLocationHigh,
	WarningNum,
	SysElectricity,
	MotorCurrentSpeed,
	SysVoltage,
	SysTemperature,
	SysOutputPWM,
	ParameterSaveFlg,
	DriveAddress,
	AbsolutePositionLow,
	AbsolutePositionHigh,
	RestMaximumOutput,
	SpecificFunction
}e_ModbusRegAdr;
		     			
#define   READREG                   0x03
#define   WRITEREG                  0x06
#define   WRITE_TARGETPOSITION      0X78
#define   WRITE_DRIVEADR            0X7A
	













#endif