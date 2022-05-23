#include "UserModbus.h"


/*****test data*****/

#define Status_bit_L1 0X0001
#define Status_bit_L2 0X0002
#define Status_bit_L3 0X0004
#define Status_bit_L4 0X0008
#define Status_bit_L5 0X001F

//输入寄存器起始地址
#define REG_INPUT_START       0x0000
//输入寄存器数量
#define REG_INPUT_NREGS       8

//线圈起始地址
#define REG_COILS_START       0x0000
//线圈数量
#define REG_COILS_SIZE        16

//开关寄存器起始地址
#define REG_DISCRETE_START    0x0000
//开关寄存器数量
#define REG_DISCRETE_SIZE     16


 /* Private variables ---------------------------------------------------------*/
//输入寄存器内容 
uint16_t usRegInputBuf[REG_INPUT_NREGS] = {0x1000,0x1001,0x1002,0x1003,0x1004,0x1005,0x1006,0x1007};
//寄存器起始地址
uint16_t usRegInputStart = REG_INPUT_START;


//线圈状态
uint8_t ucRegCoilsBuf[REG_COILS_SIZE] = {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01};
//开关输入状态
uint8_t ucRegDiscreteBuf[REG_DISCRETE_SIZE] = {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01};
uint8_t u8ModbusDataSet_ADDR_08XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case INPUT_SIGNAL_POLARITY_DEFINITION_ADDR:{
			u16InputSignalPolarityDefinition=(*pucRegBuffer++ << 8);
      u16InputSignalPolarityDefinition |= *pucRegBuffer++;
		}break;
		case INPUT_PORT_SIGNAL_SIMULATION:{
			u16InputPortSignalSimulation=(*pucRegBuffer++ << 8);
      u16InputPortSignalSimulation |= *pucRegBuffer++;
		}break;
		case DIGITAL_INPUT_1_ADDR:{
			u16DigitalInput1=(*pucRegBuffer++ << 8);
      u16DigitalInput1 |= *pucRegBuffer++;
		}break;
		case DIGITAL_INPUT_2_ADDR:{
			u16DigitalInput2=(*pucRegBuffer++ << 8);
      u16DigitalInput2 |= *pucRegBuffer++;
			
		}break;
		case DIGITAL_INPUT_3_ADDR:{
			u16DigitalInput3=(*pucRegBuffer++ << 8);
      u16DigitalInput3 |= *pucRegBuffer++;
			
		}break;
		case DIGITAL_INPUT_4_ADDR:{
			u16DigitalInput4=(*pucRegBuffer++ << 8);
      u16DigitalInput4 |= *pucRegBuffer++;

			
		}break;
		case INPUT_STATUS2_ADDR:{
			u16InputPortStatus2=(*pucRegBuffer++ << 8);
      u16InputPortStatus2 |= *pucRegBuffer++;

			
		}break;
		case OUTPUT_SINGAL_POLARITY_DEFINITION_ADDR:{
			
			u16OutputSignalPolarityDefinition=(*pucRegBuffer++ << 8);
      u16OutputSignalPolarityDefinition |= *pucRegBuffer++;

			
		}break;
		case OUTPUT_PORT_SIGNAL_SIMNLATION_ADDR:{
			u16OutputPortSignalSimulation=(*pucRegBuffer++ << 8);
      u16OutputPortSignalSimulation |= *pucRegBuffer++;

			
		}break;
		case DIGITAL_OUTPUT_1_ADDR:{
			u16DigitalOutput1=(*pucRegBuffer++ << 8);
      u16DigitalOutput1 |= *pucRegBuffer++;

			
		}break;
		case DIGITAL_OUTPUT_2_ADDR:{
			u16DigitalOutput2=(*pucRegBuffer++ << 8);
      u16DigitalOutput2 |= *pucRegBuffer++;
			
		}break;
		case OUTPUT_PORT_STATUS_ADDR:{
			u16OutputPortStatus=(*pucRegBuffer++ << 8);
      u16OutputPortStatus |= *pucRegBuffer++;
			
		}break;
		case ACTUAL_VELOCITY_ERROR_WIN_ADDR:{
			u16ActualVelocity0ErrorWin=(*pucRegBuffer++ << 8);
      u16ActualVelocity0ErrorWin |= *pucRegBuffer++;
			
		}break;
		case LIMIT_FUNCTION_DEFINTION_ADDR:{
      u8LimitFunctionDefintion |= *pucRegBuffer++;
		}break;
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}

uint8_t u8ModbusDataSet_ADDR_0CXX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case MULTISTAGE_POSITION_CONTROL_0_ADDR:{
			int32MultistagePositionControl0 |=(*pucRegBuffer++ << 24);
			int32MultistagePositionControl0 |=(*pucRegBuffer++ << 16);
			int32MultistagePositionControl0 |=(*pucRegBuffer++ << 8);
      int32MultistagePositionControl0 |= *pucRegBuffer++;
		}break;
		case MULTISTAGE_POSITION_CONTROL_1_ADDR:{
			int32MultistagePositionControl1 |=(*pucRegBuffer++ << 24);
			int32MultistagePositionControl1 |=(*pucRegBuffer++ << 16);
			int32MultistagePositionControl1 |=(*pucRegBuffer++ << 8);
      int32MultistagePositionControl1 |= *pucRegBuffer++;
		}break;
		case MULTISTAGE_POSITION_CONTROL_2_ADDR:{
			int32MultistagePositionControl2 |=(*pucRegBuffer++ << 24);
			int32MultistagePositionControl2 |=(*pucRegBuffer++ << 16);
			int32MultistagePositionControl2 |=(*pucRegBuffer++ << 8);
      int32MultistagePositionControl2 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_3_ADDR:{
			int32MultistagePositionControl3 |=(*pucRegBuffer++ << 24);
			int32MultistagePositionControl3 |=(*pucRegBuffer++ << 16);
			int32MultistagePositionControl3 |=(*pucRegBuffer++ << 8);
      int32MultistagePositionControl3 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_0_ADDR:{
			int32MultistageVelocityControl0 |=(*pucRegBuffer++ << 24);
			int32MultistageVelocityControl0 |=(*pucRegBuffer++ << 16);
			int32MultistageVelocityControl0 |=(*pucRegBuffer++ << 8);
      int32MultistageVelocityControl0 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_1_ADDR:{
			int32MultistageVelocityControl1 |=(*pucRegBuffer++ << 24);
			int32MultistageVelocityControl1 |=(*pucRegBuffer++ << 16);
			int32MultistageVelocityControl1 |=(*pucRegBuffer++ << 8);
      int32MultistageVelocityControl1 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_2_ADDR:{
			int32MultistageVelocityControl2 |=(*pucRegBuffer++ << 24);
			int32MultistageVelocityControl2 |=(*pucRegBuffer++ << 16);
			int32MultistageVelocityControl2 |=(*pucRegBuffer++ << 8);
      int32MultistageVelocityControl2 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_3_ADDR:{
			int32MultistageVelocityControl3 |=(*pucRegBuffer++ << 24);
			int32MultistageVelocityControl3 |=(*pucRegBuffer++ << 16);
			int32MultistageVelocityControl3 |=(*pucRegBuffer++ << 8);
      int32MultistageVelocityControl3 |= *pucRegBuffer++;
			
		}break;
		case POSITION_CONTROL_SELECTION_ADDR:{
			u16PositionControlSelection=(*pucRegBuffer++ << 8);
      u16PositionControlSelection |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_4_ADDR:{
			int32MultistagePositionControl4 |=(*pucRegBuffer++ << 24);
			int32MultistagePositionControl4 |=(*pucRegBuffer++ << 16);
			int32MultistagePositionControl4 |=(*pucRegBuffer++ << 8);
      int32MultistagePositionControl4 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_5_ADDR:{
			int32MultistagePositionControl5 |=(*pucRegBuffer++ << 24);
			int32MultistagePositionControl5 |=(*pucRegBuffer++ << 16);
			int32MultistagePositionControl5 |=(*pucRegBuffer++ << 8);
      int32MultistagePositionControl5 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_6_ADDR:{
			int32MultistagePositionControl6 |=(*pucRegBuffer++ << 24);
			int32MultistagePositionControl6 |=(*pucRegBuffer++ << 16);
			int32MultistagePositionControl6 |=(*pucRegBuffer++ << 8);
      int32MultistagePositionControl6 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_7_ADDR:{
			int32MultistagePositionControl7 |=(*pucRegBuffer++ << 24);
			int32MultistagePositionControl7 |=(*pucRegBuffer++ << 16);
			int32MultistagePositionControl7 |=(*pucRegBuffer++ << 8);
      int32MultistagePositionControl7 |= *pucRegBuffer++;
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_4_ADDR:{
			int32MultistageVelocityControl4 |=(*pucRegBuffer++ << 24);
			int32MultistageVelocityControl4 |=(*pucRegBuffer++ << 16);
			int32MultistageVelocityControl4 |=(*pucRegBuffer++ << 8);
      int32MultistageVelocityControl4 |= *pucRegBuffer++;
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_5_ADDR:{
			int32MultistageVelocityControl5 |=(*pucRegBuffer++ << 24);
			int32MultistageVelocityControl5 |=(*pucRegBuffer++ << 16);
			int32MultistageVelocityControl5 |=(*pucRegBuffer++ << 8);
      int32MultistageVelocityControl5 |= *pucRegBuffer++;
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_6_ADDR:{
			int32MultistageVelocityControl6 |=(*pucRegBuffer++ << 24);
			int32MultistageVelocityControl6 |=(*pucRegBuffer++ << 16);
			int32MultistageVelocityControl6 |=(*pucRegBuffer++ << 8);
      int32MultistageVelocityControl6 |= *pucRegBuffer++;
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_7_ADDR:{
			int32MultistageVelocityControl7 |=(*pucRegBuffer++ << 24);
			int32MultistageVelocityControl7 |=(*pucRegBuffer++ << 16);
			int32MultistageVelocityControl7 |=(*pucRegBuffer++ << 8);
      int32MultistageVelocityControl7 |= *pucRegBuffer++;
		}break;
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}
uint8_t u8ModbusDataSet_ADDR_19XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case ELECTRONIC_GEARS_NUMERATOR_0_ADDR:{
			int16ElectronicGearsNumerator0 |=(*pucRegBuffer++ << 8);
      int16ElectronicGearsNumerator0 |= *pucRegBuffer++;
		}break;
		case ELECYRONIC_GEARS_DENOMINATOR_0_ADDR:{
			u16ElectronicGearsDenominator |=(*pucRegBuffer++ << 8);
      u16ElectronicGearsDenominator |= *pucRegBuffer++;
		}break;
		case PULSE_MODE_ADDR:{
			int16PulseMode |=(*pucRegBuffer++ << 8);
      int16PulseMode |= *pucRegBuffer++;
		}break;
		case ELECTRONIC_GEARS_INPUT_PULSE_FRONT_ADDR:{
			int16ElectronicGearsInputPulseNum_Front |=(*pucRegBuffer++ << 8);
      int16ElectronicGearsInputPulseNum_Front |= *pucRegBuffer++;
			
		}break;
		case ELECTRONIC_GEARS_INPUT_PULSE_BACK_ADDR:{
			int16ElectronicGearsInputPulseNum_Back |=(*pucRegBuffer++ << 8);
      int16ElectronicGearsInputPulseNum_Back |= *pucRegBuffer++;
			
		}break;
		case PULSE_FILTER_PARAMETER_ADDR:{
			u16PulseFilterParameter |=(*pucRegBuffer++ << 8);
      u16PulseFilterParameter |= *pucRegBuffer++;
			
		}break;
		case LOCATION_TIME_WIN_ADDR:{
			u16LocationToTimeWin |=(*pucRegBuffer++ << 8);
      u16LocationToTimeWin |= *pucRegBuffer++;
			
		}break;
		case GEARS_PULSE_FREQ_FRONT_ADDR:{
			int16GearsPulseFreq_Front |=(*pucRegBuffer++ << 8);
      int16GearsPulseFreq_Front |= *pucRegBuffer++;
			
		}break;
		case GEARS_PULSE_FREQ_BACK_ADDR:{
			int16GearsPulseFreq_Back |=(*pucRegBuffer++ << 8);
      int16GearsPulseFreq_Back |= *pucRegBuffer++;
			
		}break;
		case ERROR_WORD_ADDR:{
			u16ErrorWord |=(*pucRegBuffer++ << 8);
      u16ErrorWord |= *pucRegBuffer++;
			
		}break;
		case SAVE_CONTROL_NUM_ADDR:{
      u8SaveControlNum |= *pucRegBuffer++;
			
		}break;
		case SAVE_MOTOR_NUM_ADDR:{
      u8SaveMotorNum |= *pucRegBuffer++;
			
		}break;
		
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}
uint8_t u8ModbusDataSet_ADDR_31XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case CONTROL_WORD_ADDR:{
			u16ControlWord |=(*pucRegBuffer++ << 8);
      u16ControlWord |= *pucRegBuffer++;
		}break;
		case STATUE_WORD_ADDR:{
			u16StatusWord |=(*pucRegBuffer++ << 8);
      u16StatusWord |= *pucRegBuffer++;
		}break;
		case QUICK_STOP_MODE_DECELERATION_ADDR:{
			u32QuickStopModeDeceleration |=(*pucRegBuffer++ << 24);
			u32QuickStopModeDeceleration |=(*pucRegBuffer++ << 16);
			u32QuickStopModeDeceleration |=(*pucRegBuffer++ << 8);
      u32QuickStopModeDeceleration |= *pucRegBuffer++;
		}break;
		case SHUTDOWN_STOP_MODE_ADDR:{
			int16ShutdownStopMode |=(*pucRegBuffer++ << 8);
      int16ShutdownStopMode |= *pucRegBuffer++;
		}break;
		case DISABLE_STOP_MODE_ADDR:{
			int16DisableStopMode |=(*pucRegBuffer++ << 8);
      int16DisableStopMode |= *pucRegBuffer++;
		}break;
		case SUSPEND_MODE_ADDR:{
			int16SuspendMode |=(*pucRegBuffer++ << 8);
      int16SuspendMode |= *pucRegBuffer++;
		}break;
		case ERROR_STOP_MODE_ADDR:{
			u32ErrorStopMode |=(*pucRegBuffer++ << 24);
			u32ErrorStopMode |=(*pucRegBuffer++ << 16);
			u32ErrorStopMode |=(*pucRegBuffer++ << 8);
      u32ErrorStopMode |= *pucRegBuffer++;
		}break;
		case WORKING_MODE_ADDR:{
      int8WorkingMode |= *pucRegBuffer++;
			
		}break;
		case PHYSICL_LOCATION_ADDR:{
			int32PhysicalLocation |=(*pucRegBuffer++ << 24);
			int32PhysicalLocation |=(*pucRegBuffer++ << 16);
			int32PhysicalLocation |=(*pucRegBuffer++ << 8);
      int32PhysicalLocation |= *pucRegBuffer++;
			
		}break;
		case FOLLOWING_ERROR_MAX_ADDR:{
			u32FollowingErrorMAX |=(*pucRegBuffer++ << 24);
			u32FollowingErrorMAX |=(*pucRegBuffer++ << 16);
			u32FollowingErrorMAX |=(*pucRegBuffer++ << 8);
      u32FollowingErrorMAX |= *pucRegBuffer++;
			
		}break;
		case TARGET_LOCATION_WIN_ADDR:{
			u32TargetLocationWin |=(*pucRegBuffer++ << 24);
			u32TargetLocationWin |=(*pucRegBuffer++ << 16);
			u32TargetLocationWin |=(*pucRegBuffer++ << 8);
      u32TargetLocationWin |= *pucRegBuffer++;
			
		}break;
		case ACTUAL_VELOCITY_ADDR:{
			int32ActualVelocity |=(*pucRegBuffer++ << 24);
			int32ActualVelocity |=(*pucRegBuffer++ << 16);
			int32ActualVelocity |=(*pucRegBuffer++ << 8);
      int32ActualVelocity |= *pucRegBuffer++;
			
		}break;
		case TARGET_TORQUE_ADDR:{

			int16TargetTorque |=(*pucRegBuffer++ << 8);
      int16TargetTorque |= *pucRegBuffer++;
			
		}break;
		case TARGET_CURRENT_MAX_ADDR:{

			u16TargetCurrentMAX |=(*pucRegBuffer++ << 8);
      u16TargetCurrentMAX |= *pucRegBuffer++;
			
		}break;
		case ACTUAL_CURRENT_ADDR:{
			int16ActualCurrent |=(*pucRegBuffer++ << 8);
      int16ActualCurrent |= *pucRegBuffer++;
			
		}break;
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}
uint8_t u8ModbusDataSet_ADDR_40XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case TARGET_POSITION_ADDR:{
			int32TargetPosition |=(*pucRegBuffer++ << 24);
			int32TargetPosition |=(*pucRegBuffer++ << 16);
			int32TargetPosition |=(*pucRegBuffer++ << 8);
      int32TargetPosition |= *pucRegBuffer++;
			
		}break;
		case ORIGIN_OFFSET_ADDR:{
			int32OriginOffset |=(*pucRegBuffer++ << 24);
			int32OriginOffset |=(*pucRegBuffer++ << 16);
			int32OriginOffset |=(*pucRegBuffer++ << 8);
      int32OriginOffset |= *pucRegBuffer++;
		}break;
		case SOFT_LIMIT_POSITIVE_SETTING_ADDR:{
			int32SoftLimitPositiveSetting |=(*pucRegBuffer++ << 24);
			int32SoftLimitPositiveSetting |=(*pucRegBuffer++ << 16);
			int32SoftLimitPositiveSetting |=(*pucRegBuffer++ << 8);
      int32SoftLimitPositiveSetting |= *pucRegBuffer++;
			
		}break;
		case SOFT_LIMIT_NEGATIVE_SETTING_ADDR:{
			int32SoftLimitNegativeSetting |=(*pucRegBuffer++ << 24);
			int32SoftLimitNegativeSetting |=(*pucRegBuffer++ << 16);
			int32SoftLimitNegativeSetting |=(*pucRegBuffer++ << 8);
      int32SoftLimitNegativeSetting |= *pucRegBuffer++;
			
		}break;
		case DIRECTION_CONTROL_ADDR:{

      u8DirectionContol |= *pucRegBuffer++;

			
		}break;
		case VELOCITY_MAX_ADDR:{

			u16VelocityMAX |=(*pucRegBuffer++ << 8);
      u16VelocityMAX |= *pucRegBuffer++;
			
		}break;
		case TRAPEZOID_VELOCITY_ADDR:{
			int32TargetVelocity |=(*pucRegBuffer++ << 24);
			int32TargetVelocity |=(*pucRegBuffer++ << 16);
			int32TargetVelocity |=(*pucRegBuffer++ << 8);
      int32TargetVelocity |= *pucRegBuffer++;
			
		}break;
		case TRAPEZOID_ACCELERATION_ADDR:{
			u32TrapezoidalAcceleration |=(*pucRegBuffer++ << 24);
			u32TrapezoidalAcceleration |=(*pucRegBuffer++ << 16);
			u32TrapezoidalAcceleration |=(*pucRegBuffer++ << 8);
      u32TrapezoidalAcceleration |= *pucRegBuffer++;
			
		}break;
		case TRAPEZOID_DECELERATION_ADDR:{
			u32TrapezoidalDeceleration |=(*pucRegBuffer++ << 24);
			u32TrapezoidalDeceleration |=(*pucRegBuffer++ << 16);
			u32TrapezoidalDeceleration |=(*pucRegBuffer++ << 8);
      u32TrapezoidalDeceleration |= *pucRegBuffer++;
			
		}break;
		case ORIGIN_MODEL_ADDR:{

      int8OriginModel |= *pucRegBuffer++;
			
		}break;
		
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}

uint8_t u8ModbusDataSet_ADDR_50XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case SEARCH_ORIGIN_VELOCITY_ADDR:{
			u32SearchOriginVelocity |=(*pucRegBuffer++ << 24);
			u32SearchOriginVelocity |=(*pucRegBuffer++ << 16);
			u32SearchOriginVelocity |=(*pucRegBuffer++ << 8);
      u32SearchOriginVelocity |= *pucRegBuffer++;
		}break;
		case STARTING_SEARCH_ORIGIN_VELOCITY_ADDR:{
			u32StartingSearchOriginVelocity |=(*pucRegBuffer++ << 24);
			u32StartingSearchOriginVelocity |=(*pucRegBuffer++ << 16);
			u32StartingSearchOriginVelocity |=(*pucRegBuffer++ << 8);
      u32StartingSearchOriginVelocity |= *pucRegBuffer++;
		}break;
		case ORIGIN_OFFSET_MODEL_ADDR:{
      u8OriginOffsetModel |= *pucRegBuffer++;
			
		}break;
		case SEARCH_ORIGIN_ACCELERATION_ADDR:{
			u32SearchOriginAcceleration |=(*pucRegBuffer++ << 24);
			u32SearchOriginAcceleration |=(*pucRegBuffer++ << 16);
			u32SearchOriginAcceleration |=(*pucRegBuffer++ << 8);
      u32SearchOriginAcceleration |= *pucRegBuffer++;
			
		}break;
		case TARGET_CURRENT_ADDR:{
			int16TargetCurrent |=(*pucRegBuffer++ << 8);
      int16TargetCurrent |= *pucRegBuffer++;
			
		}break;
		case VELOCITY_LOOP_GAIN_P_ADDR:{
			u16VelocityLoopGain_P |=(*pucRegBuffer++ << 8);
      u16VelocityLoopGain_P |= *pucRegBuffer++;
			
		}break;
		case VELOCITY_LOOP_GAIN_I_ADDR:{
			u16VelocityLoopGain_I |=(*pucRegBuffer++ << 8);
      u16VelocityLoopGain_I |= *pucRegBuffer++;
			
		}break;
		case VELOCITY_FEED_BACK_FILTER_ADDR:{
      u8VelocityFeedBackFilter |= *pucRegBuffer++;
			
		}break;
		case VELOCITY_LOOP_GAIN_32_I_ADDR:{
			u16VelocityLoopGain_32_I |=(*pucRegBuffer++ << 8);
      u16VelocityLoopGain_32_I |= *pucRegBuffer++;
			
		}break;
		case VELOCITY_WIN_ADDR:{
			int32VelocityWin |=(*pucRegBuffer++ << 8);
      int32VelocityWin |= *pucRegBuffer++;
			
		}break;
		case VELOCITY_ZERO_OUTPUT_TIME_ADDR:{

			u16Velocity0OutputTime |=(*pucRegBuffer++ << 8);
      u16Velocity0OutputTime |= *pucRegBuffer++;
			
		}break;
		case POSITION_LOOP_GAIN_P_ADDR:{
			u16PositionLoopGain_P |=(*pucRegBuffer++ << 8);
      u16PositionLoopGain_P |= *pucRegBuffer++;

		}break;
		case POSITION_LOOP_VELOCITY_FEED_FORWARD_ADDR:{
			u16PositionLoopVelocityFeedforward |=(*pucRegBuffer++ << 8);
      u16PositionLoopVelocityFeedforward |= *pucRegBuffer++;
			
		}break;
		case POSITION_LOOP_ACC_FEED_FORWARD_ADDR:{
			u16PositionLoopAccFeedforward |=(*pucRegBuffer++ << 8);
      u16PositionLoopAccFeedforward |= *pucRegBuffer++;
			
		}break;
		case SMOOTHING_FILTER_ADDR:{
			u16SmoothingFilter |=(*pucRegBuffer++ << 8);
      u16SmoothingFilter |= *pucRegBuffer++;
			
		}break;
		case INPUT_PORT_STATUS1_ADDR:{
			u32InputPortStatus1 |=(*pucRegBuffer++ << 24);
			u32InputPortStatus1 |=(*pucRegBuffer++ << 16);
			u32InputPortStatus1 |=(*pucRegBuffer++ << 8);
      u32InputPortStatus1 |= *pucRegBuffer++;
			
		}break;
		case TARGET_VELOCITY_ADDR:{
			int32TargetVelocity |=(*pucRegBuffer++ << 24);
			int32TargetVelocity |=(*pucRegBuffer++ << 16);
			int32TargetVelocity |=(*pucRegBuffer++ << 8);
      int32TargetVelocity |= *pucRegBuffer++;
			
		}break;
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}


uint8_t u8ModbusDataGet_ADDR_08XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case INPUT_SIGNAL_POLARITY_DEFINITION_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16InputSignalPolarityDefinition>>8);
			*pucRegBuffer++ =(uint8_t)(u16InputSignalPolarityDefinition&0xff);
		}break;
		case INPUT_PORT_SIGNAL_SIMULATION:{
			*pucRegBuffer++ =(uint8_t)(u16InputPortSignalSimulation>>8);
			*pucRegBuffer++ =(uint8_t)(u16InputPortSignalSimulation&0xff);
		}break;
		case DIGITAL_INPUT_1_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16DigitalInput1>>8);
			*pucRegBuffer++ =(uint8_t)(u16DigitalInput1&0xff);
			
		}break;
		case DIGITAL_INPUT_2_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16DigitalInput2>>8);
			*pucRegBuffer++ =(uint8_t)(u16DigitalInput2&0xff);
			
		}break;
		case DIGITAL_INPUT_3_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16DigitalInput3>>8);
			*pucRegBuffer++ =(uint8_t)(u16DigitalInput3&0xff);
			
		}break;
		case DIGITAL_INPUT_4_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16DigitalInput4>>8);
			*pucRegBuffer++ =(uint8_t)(u16DigitalInput4&0xff);
			
		}break;
		case INPUT_STATUS2_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16InputPortStatus2>>8);
			*pucRegBuffer++ =(uint8_t)(u16InputPortStatus2&0xff);
			
		}break;
		case OUTPUT_SINGAL_POLARITY_DEFINITION_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16OutputSignalPolarityDefinition>>8);
			*pucRegBuffer++ =(uint8_t)(u16OutputSignalPolarityDefinition&0xff);
			
		}break;
		case OUTPUT_PORT_SIGNAL_SIMNLATION_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16OutputPortSignalSimulation>>8);
			*pucRegBuffer++ =(uint8_t)(u16OutputPortSignalSimulation&0xff);
			
		}break;
		case DIGITAL_OUTPUT_1_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16DigitalOutput1>>8);
			*pucRegBuffer++ =(uint8_t)(u16DigitalOutput1&0xff);
			
		}break;
		case DIGITAL_OUTPUT_2_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16DigitalOutput2>>8);
			*pucRegBuffer++ =(uint8_t)(u16DigitalOutput2&0xff);
			
		}break;
		case OUTPUT_PORT_STATUS_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16OutputPortStatus>>8);
			*pucRegBuffer++ =(uint8_t)(u16OutputPortStatus&0xff);
			
		}break;
		case ACTUAL_VELOCITY_ERROR_WIN_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16ActualVelocity0ErrorWin>>8);
			*pucRegBuffer++ =(uint8_t)(u16ActualVelocity0ErrorWin&0xff);
			
		}break;
		case LIMIT_FUNCTION_DEFINTION_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u8LimitFunctionDefintion&0xff);
		}break;
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}

uint8_t u8ModbusDataGet_ADDR_0CXX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case MULTISTAGE_POSITION_CONTROL_0_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl0>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl0>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl0>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistagePositionControl0&0xff);
		}break;
		case MULTISTAGE_POSITION_CONTROL_1_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl1>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl1>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl1>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistagePositionControl1&0xff);
		}break;
		case MULTISTAGE_POSITION_CONTROL_2_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl2>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl2>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl2>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistagePositionControl2&0xff);
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_3_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl3>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl3>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl3>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistagePositionControl3&0xff);
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_0_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl0>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl0>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl0>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistageVelocityControl0&0xff);
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_1_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl1>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl1>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl1>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistageVelocityControl1&0xff);
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_2_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl2>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl2>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl2>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistageVelocityControl2&0xff);
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_3_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl3>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl3>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl3>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistageVelocityControl3&0xff);
			
		}break;
		case POSITION_CONTROL_SELECTION_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u16PositionControlSelection>>8);
			*pucRegBuffer++ =(uint8_t)(u16PositionControlSelection&0xff);
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_4_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl4>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl4>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl4>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistagePositionControl4&0xff);
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_5_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl5>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl5>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl5>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistagePositionControl5&0xff);
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_6_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl6>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl6>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl6>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistagePositionControl6&0xff);
			
		}break;
		case MULTISTAGE_POSITION_CONTROL_7_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl7>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl7>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistagePositionControl7>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistagePositionControl7&0xff);
			
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_4_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl4>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl4>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl4>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistageVelocityControl4&0xff);
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_5_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl5>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl5>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl5>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistageVelocityControl5&0xff);
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_6_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl6>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl6>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl6>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistageVelocityControl6&0xff);
		}break;
		case MULTISTAGE_VELOCITY_CONTROL_7_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl7>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl7>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32MultistageVelocityControl7>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32MultistageVelocityControl7&0xff);
		}break;
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}
uint8_t u8ModbusDataGet_ADDR_19XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case ELECTRONIC_GEARS_NUMERATOR_0_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16ElectronicGearsNumerator0>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16ElectronicGearsNumerator0&0xff);
		}break;
		case ELECYRONIC_GEARS_DENOMINATOR_0_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16ElectronicGearsDenominator>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16ElectronicGearsDenominator&0xff);
		}break;
		case PULSE_MODE_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16PulseMode>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16PulseMode&0xff);
			
		}break;
		case ELECTRONIC_GEARS_INPUT_PULSE_FRONT_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16ElectronicGearsInputPulseNum_Front>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16ElectronicGearsInputPulseNum_Front&0xff);
			
		}break;
		case ELECTRONIC_GEARS_INPUT_PULSE_BACK_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16ElectronicGearsInputPulseNum_Back>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16ElectronicGearsInputPulseNum_Back&0xff);
			
		}break;
		case PULSE_FILTER_PARAMETER_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16PulseFilterParameter>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16PulseFilterParameter&0xff);
			
		}break;
		case LOCATION_TIME_WIN_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16LocationToTimeWin>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16LocationToTimeWin&0xff);
			
		}break;
		case GEARS_PULSE_FREQ_FRONT_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16GearsPulseFreq_Front>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16GearsPulseFreq_Front&0xff);
			
		}break;
		case GEARS_PULSE_FREQ_BACK_ADDR:{
			*pucRegBuffer++ =(uint8_t)(int16GearsPulseFreq_Back>>8);
			*pucRegBuffer++ =(uint8_t)(int16GearsPulseFreq_Back&0xff);
			
		}break;
		case ERROR_WORD_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16ErrorWord>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16ErrorWord&0xff);
			
		}break;
		case SAVE_CONTROL_NUM_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u8SaveControlNum&0xff);
			
		}break;
		case SAVE_MOTOR_NUM_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u8SaveMotorNum&0xff);
			
		}break;
		
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}
uint8_t u8ModbusDataGet_ADDR_31XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case CONTROL_WORD_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16ControlWord>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16ControlWord&0xff);
		}break;
		case STATUE_WORD_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16StatusWord>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16StatusWord&0xff);
		}break;
		case QUICK_STOP_MODE_DECELERATION_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32QuickStopModeDeceleration>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32QuickStopModeDeceleration>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32QuickStopModeDeceleration>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32QuickStopModeDeceleration&0xff);
			
		}break;
		case SHUTDOWN_STOP_MODE_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16ShutdownStopMode>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16ShutdownStopMode&0xff);
			
		}break;
		case DISABLE_STOP_MODE_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16DisableStopMode>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16DisableStopMode&0xff);
			
		}break;
		case SUSPEND_MODE_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16SuspendMode>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16SuspendMode&0xff);
			
		}break;
		case ERROR_STOP_MODE_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32ErrorStopMode>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32ErrorStopMode>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32ErrorStopMode>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32ErrorStopMode&0xff);
			
		}break;
		case WORKING_MODE_ADDR:{
			*pucRegBuffer++ =(uint8_t)(int8WorkingMode&0xff);
			
		}break;
		case PHYSICL_LOCATION_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32PhysicalLocation>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32PhysicalLocation>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32PhysicalLocation>>8);
			*pucRegBuffer++ =(uint8_t)(int32PhysicalLocation&0xff);
			
		}break;
		case FOLLOWING_ERROR_MAX_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32FollowingErrorMAX>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32FollowingErrorMAX>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32FollowingErrorMAX>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32FollowingErrorMAX&0xff);
			
		}break;
		case TARGET_LOCATION_WIN_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32TargetLocationWin>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32TargetLocationWin>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32TargetLocationWin>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32TargetLocationWin&0xff);
			
		}break;
		case ACTUAL_VELOCITY_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32ActualVelocity>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32ActualVelocity>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32ActualVelocity>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32ActualVelocity&0xff);
			
		}break;
		case TARGET_TORQUE_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16TargetTorque>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16TargetTorque&0xff);
			
		}break;
		case TARGET_CURRENT_MAX_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16TargetCurrentMAX>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16TargetCurrentMAX&0xff);
			
		}break;
		case ACTUAL_CURRENT_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16ActualCurrent>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16ActualCurrent&0xff);
			
		}break;
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}
uint8_t u8ModbusDataGet_ADDR_40XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case TARGET_POSITION_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32TargetPosition>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32TargetPosition>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32TargetPosition>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32TargetPosition&0xff);
		}break;
		case ORIGIN_OFFSET_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32OriginOffset>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32OriginOffset>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32OriginOffset>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32OriginOffset&0xff);
		}break;
		case SOFT_LIMIT_POSITIVE_SETTING_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32SoftLimitPositiveSetting>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32SoftLimitPositiveSetting>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32SoftLimitPositiveSetting>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32SoftLimitPositiveSetting&0xff);
			
		}break;
		case SOFT_LIMIT_NEGATIVE_SETTING_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32SoftLimitNegativeSetting>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32SoftLimitNegativeSetting>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32SoftLimitNegativeSetting>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32SoftLimitNegativeSetting&0xff);
			
		}break;
		case DIRECTION_CONTROL_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u8DirectionContol&0xff);
			
		}break;
		case VELOCITY_MAX_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16VelocityMAX>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16VelocityMAX&0xff);
			
		}break;
		case TRAPEZOID_VELOCITY_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32TargetVelocity>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32TargetVelocity>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32TargetVelocity>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32TargetVelocity&0xff);
			
		}break;
		case TRAPEZOID_ACCELERATION_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32TrapezoidalAcceleration>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32TrapezoidalAcceleration>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32TrapezoidalAcceleration>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32TrapezoidalAcceleration&0xff);
			
		}break;
		case TRAPEZOID_DECELERATION_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32TrapezoidalDeceleration>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32TrapezoidalDeceleration>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32TrapezoidalDeceleration>>8);
			*pucRegBuffer++ =(uint8_t)(u32TrapezoidalDeceleration&0xff);
			
		}break;
		case ORIGIN_MODEL_ADDR:{
			*pucRegBuffer++ =(uint8_t)(int8OriginModel&0xff);
			
		}break;
		
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}

uint8_t u8ModbusDataGet_ADDR_50XX(UCHAR * pucRegBuffer,USHORT usAddress){
	int usValue=0;
	switch(usAddress){
		case SEARCH_ORIGIN_VELOCITY_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32SearchOriginVelocity>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32SearchOriginVelocity>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32SearchOriginVelocity>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32SearchOriginVelocity&0xff);
		}break;
		case STARTING_SEARCH_ORIGIN_VELOCITY_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32StartingSearchOriginVelocity>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32StartingSearchOriginVelocity>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32StartingSearchOriginVelocity>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32StartingSearchOriginVelocity&0xff);
		}break;
		case ORIGIN_OFFSET_MODEL_ADDR:{
			*pucRegBuffer++ =(uint8_t)(u8OriginOffsetModel&0xff);
			
		}break;
		case SEARCH_ORIGIN_ACCELERATION_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32SearchOriginAcceleration>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32SearchOriginAcceleration>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32SearchOriginAcceleration>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32SearchOriginAcceleration&0xff);
			
		}break;
		case TARGET_CURRENT_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int16TargetCurrent>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int16TargetCurrent&0xff);
			
		}break;
		case VELOCITY_LOOP_GAIN_P_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16VelocityLoopGain_P>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16VelocityLoopGain_P&0xff);
			
		}break;
		case VELOCITY_LOOP_GAIN_I_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16VelocityLoopGain_I>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16VelocityLoopGain_I&0xff);
			
		}break;
		case VELOCITY_FEED_BACK_FILTER_ADDR:{

			*pucRegBuffer++ =(uint8_t)(u8VelocityFeedBackFilter&0xff);
			
		}break;
		case VELOCITY_LOOP_GAIN_32_I_ADDR:{

			*pucRegBuffer++ =(uint8_t)(u16VelocityLoopGain_32_I>>8);
			*pucRegBuffer++ =(uint8_t)(u16VelocityLoopGain_32_I&0xff);
			
		}break;
		case VELOCITY_WIN_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32VelocityWin>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32VelocityWin>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32VelocityWin>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32VelocityWin&0xff);
			
		}break;
		case VELOCITY_ZERO_OUTPUT_TIME_ADDR:{

			*pucRegBuffer++ =(uint8_t)((u16Velocity0OutputTime>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16Velocity0OutputTime&0xff);
			
		}break;
		case POSITION_LOOP_GAIN_P_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16PositionLoopGain_P>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16PositionLoopGain_P&0xff);
			
		}break;
		case POSITION_LOOP_VELOCITY_FEED_FORWARD_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16PositionLoopVelocityFeedforward>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16PositionLoopVelocityFeedforward&0xff);
			
		}break;
		case POSITION_LOOP_ACC_FEED_FORWARD_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16PositionLoopAccFeedforward>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16PositionLoopAccFeedforward&0xff);
			
		}break;
		case SMOOTHING_FILTER_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u16SmoothingFilter>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u16SmoothingFilter&0xff);
			
		}break;
		case INPUT_PORT_STATUS1_ADDR:{
			*pucRegBuffer++ =(uint8_t)((u32InputPortStatus1>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32InputPortStatus1>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((u32InputPortStatus1>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(u32InputPortStatus1&0xff);
			
		}break;
		case TARGET_VELOCITY_ADDR:{
			*pucRegBuffer++ =(uint8_t)((int32TargetVelocity>>24)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32TargetVelocity>>16)&0xff);
			*pucRegBuffer++ =(uint8_t)((int32TargetVelocity>>8)&0xff);
			*pucRegBuffer++ =(uint8_t)(int32TargetVelocity&0xff);
			
		}break;
		default:return MB_ENOREG;break;
	}
	return MB_ENOERR;
}


/**
  * @brief  输入寄存器处理函数，输入寄存器可读，但不可写。
  * @param  pucRegBuffer  返回数据指针
  *         usAddress     寄存器起始地址
  *         usNRegs       寄存器长度
  * @retval eStatus       寄存器状态
  */
eMBErrorCode 
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
  eMBErrorCode    eStatus = MB_ENOERR;
  int16_t         iRegIndex;
  
  //查询是否在寄存器范围内
  //为了避免警告，修改为有符号整数
  if( ( (int16_t)usAddress >= REG_INPUT_START ) \
        && ( usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS ) )
  {
    //获得操作偏移量，本次操作起始地址-输入寄存器的初始地址
    iRegIndex = ( int16_t )( usAddress - usRegInputStart );
    //逐个赋值
    while( usNRegs > 0 )
    {
      //赋值高字节
      *pucRegBuffer++ = ( uint8_t )( usRegInputBuf[iRegIndex] >> 8 );
      //赋值低字节
      *pucRegBuffer++ = ( uint8_t )( usRegInputBuf[iRegIndex] & 0xFF );
      //偏移量增加
      iRegIndex++;
      //被操作寄存器数量递减
      usNRegs--;
    }
  }
  else
  {
    //返回错误状态，无寄存器  
    eStatus = MB_ENOREG;
  }

  return eStatus;
}
/**
  * @brief  保持寄存器处理函数，保持寄存器可读，可读可写
  * @param  pucRegBuffer  读操作时--返回数据指针，写操作时--输入数据指针
  *         usAddress     寄存器起始地址
  *         usNRegs       寄存器长度
  *         eMode         操作方式，读或者写
  * @retval eStatus       寄存器状态
  */

extern uint8_t menu;
eMBErrorCode 
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs,
                 eMBRegisterMode eMode )
{
	/**
	  *目前对于地址的处理是按照从小到大排序分为几大段，而后再不同段再进行不同的处理
	  */
  //错误状态
  eMBErrorCode    eStatus = MB_ENOERR;
  //偏移量
  int16_t         iRegIndex;
	usAddress--;
  //判断寄存器是不是在范围内
  if( ( (int16_t)usAddress >= INPUT_SIGNAL_POLARITY_DEFINITION_ADDR ) \
     && ( usAddress + usNRegs <= TARGET_VELOCITY_ADDR+ usNRegs ) )
  {
    
    switch ( eMode )
    {
      //读处理函数  
      case MB_REG_READ:
        while( usNRegs > 0 )
        {
					if((usAddress>=INPUT_SIGNAL_POLARITY_DEFINITION_ADDR)
						&&(usAddress<=LIMIT_FUNCTION_DEFINTION_ADDR+ usNRegs)){//得到的地址再0x0810-0x0990之间
							eStatus=u8ModbusDataGet_ADDR_08XX(pucRegBuffer,usAddress);
					}
					else if((usAddress>=MULTISTAGE_POSITION_CONTROL_0_ADDR)
						&&(usAddress<=MULTISTAGE_VELOCITY_CONTROL_7_ADDR+ usNRegs)){//得到的地址0x0c10-0x0d70
							eStatus=u8ModbusDataGet_ADDR_0CXX(pucRegBuffer,usAddress);
					}
					else if((usAddress>=ELECTRONIC_GEARS_NUMERATOR_0_ADDR)
						&&(usAddress<=SAVE_MOTOR_NUM_ADDR+ usNRegs)){//得到的地址0x1910-0x2930
							eStatus=u8ModbusDataGet_ADDR_19XX(pucRegBuffer,usAddress);
					}
					else if((usAddress>=CONTROL_WORD_ADDR)
						&&(usAddress<=ACTUAL_CURRENT_ADDR+ usNRegs)){//得到的地址0x3100-0x3e00
							eStatus=u8ModbusDataGet_ADDR_31XX(pucRegBuffer,usAddress);
					}	
					else if((usAddress>=TARGET_POSITION_ADDR)
						&&(usAddress<=ORIGIN_MODEL_ADDR+ usNRegs)){//得到的地址0x4000-0x4d00
							eStatus=u8ModbusDataGet_ADDR_40XX(pucRegBuffer,usAddress);
					}	
					else if((usAddress>=SEARCH_ORIGIN_VELOCITY_ADDR)
						&&(usAddress<=TARGET_VELOCITY_ADDR+ usNRegs)){//得到的地址0x5010-0x6f00
							eStatus=u8ModbusDataGet_ADDR_50XX(pucRegBuffer,usAddress);
					}
					else {
						eStatus = MB_ENOREG;
					}
          usNRegs--;
					//usAddress++;
        }
        break;

      //写处理函数 
      case MB_REG_WRITE:
        while( usNRegs > 0 )
        {
					if((usAddress>=INPUT_SIGNAL_POLARITY_DEFINITION_ADDR)
						&&(usAddress<=LIMIT_FUNCTION_DEFINTION_ADDR+ usNRegs)){//得到的地址再0x0810-0x0990之间
							eStatus=u8ModbusDataSet_ADDR_08XX(pucRegBuffer,usAddress);
					}
					else if((usAddress>=MULTISTAGE_POSITION_CONTROL_0_ADDR)
						&&(usAddress<=MULTISTAGE_VELOCITY_CONTROL_7_ADDR+ usNRegs)){
							eStatus=u8ModbusDataSet_ADDR_0CXX(pucRegBuffer,usAddress);
					}
					else if((usAddress>=ELECTRONIC_GEARS_NUMERATOR_0_ADDR)
						&&(usAddress<=SAVE_MOTOR_NUM_ADDR+ usNRegs)){
							eStatus=u8ModbusDataSet_ADDR_19XX(pucRegBuffer,usAddress);
					}
					else if((usAddress>=CONTROL_WORD_ADDR)
						&&(usAddress<=ACTUAL_CURRENT_ADDR+ usNRegs)){
							eStatus=u8ModbusDataSet_ADDR_31XX(pucRegBuffer,usAddress);
					}	
					else if((usAddress>=TARGET_POSITION_ADDR)
						&&(usAddress<=ORIGIN_MODEL_ADDR+ usNRegs)){
							eStatus=u8ModbusDataSet_ADDR_40XX(pucRegBuffer,usAddress);
					}	
					else if((usAddress>=SEARCH_ORIGIN_VELOCITY_ADDR)
						&&(usAddress<=TARGET_VELOCITY_ADDR+ usNRegs)){
							eStatus=u8ModbusDataSet_ADDR_50XX(pucRegBuffer,usAddress);
					}
					else {
							eStatus = MB_ENOREG;
					}
          iRegIndex++;
					//usAddress++;
          usNRegs--;
        }
        break;
     }
  }
  else
  {
    //返回错误状态
    eStatus = MB_ENOREG;
  }
  
  return eStatus;
}

/**
  * @brief  线圈寄存器处理函数，线圈寄存器可读，可读可写
  * @param  pucRegBuffer  读操作---返回数据指针，写操作--返回数据指针
  *         usAddress     寄存器起始地址
  *         usNRegs       寄存器长度
  *         eMode         操作方式，读或者写
  * @retval eStatus       寄存器状态
  */
eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
               eMBRegisterMode eMode )
{
  //错误状态
  eMBErrorCode    eStatus = MB_ENOERR;
  //寄存器个数
  int16_t         iNCoils = ( int16_t )usNCoils;
  //寄存器偏移量
  int16_t         usBitOffset;

  //检查寄存器是否在指定范围内
  if( ( (int16_t)usAddress >= REG_COILS_START ) &&
        ( usAddress + usNCoils <= REG_COILS_START + REG_COILS_SIZE ) )
  {
    //计算寄存器偏移量
    usBitOffset = ( int16_t )( usAddress - REG_COILS_START );
    switch ( eMode )
    {
      //读操作
      case MB_REG_READ:
        while( iNCoils > 0 )
        {
          *pucRegBuffer++ = xMBUtilGetBits( ucRegCoilsBuf, usBitOffset,
                                          ( uint8_t )( iNCoils > 8 ? 8 : iNCoils ) );
          iNCoils -= 8;
          usBitOffset += 8;
        }
        break;

      //写操作
      case MB_REG_WRITE:
        while( iNCoils > 0 )
        {
          xMBUtilSetBits( ucRegCoilsBuf, usBitOffset,
                        ( uint8_t )( iNCoils > 8 ? 8 : iNCoils ),
                        *pucRegBuffer++ );
          iNCoils -= 8;
        }
        break;
    }

  }
  else
  {
    eStatus = MB_ENOREG;
  }
  return eStatus;
}

eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
  //错误状态
  eMBErrorCode    eStatus = MB_ENOERR;
  //操作寄存器个数
  int16_t         iNDiscrete = ( int16_t )usNDiscrete;
  //偏移量
  uint16_t        usBitOffset;

  //判断寄存器时候再制定范围内
  if( ( (int16_t)usAddress >= REG_DISCRETE_START ) &&
        ( usAddress + usNDiscrete <= REG_DISCRETE_START + REG_DISCRETE_SIZE ) )
  {
    //获得偏移量
    usBitOffset = ( uint16_t )( usAddress - REG_DISCRETE_START );
    
    while( iNDiscrete > 0 )
    {
      *pucRegBuffer++ = xMBUtilGetBits( ucRegDiscreteBuf, usBitOffset,
                                      ( uint8_t)( iNDiscrete > 8 ? 8 : iNDiscrete ) );
      iNDiscrete -= 8;
      usBitOffset += 8;
    }

  }
  else
  {
    eStatus = MB_ENOREG;
  }
  return eStatus;
}  

















