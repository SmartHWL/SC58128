#ifndef USERMODBUS_H
#define USERMODBUS_H


#include "stdint.h"
#include "SC32F58128.h"
#include "mb.h"
#include "mbport.h"
#include "mbutils.h"


#define INPUT_SIGNAL_POLARITY_DEFINITION_ADDR                 0X0810            //改变输入信号极性
#define INPUT_PORT_SIGNAL_SIMULATION                          0X0820            //输入口信号模拟
#define DIGITAL_INPUT_1_ADDR                                  0X0830            //数字输入1
#define DIGITAL_INPUT_2_ADDR                                  0X0840            //数字输入2
#define DIGITAL_INPUT_3_ADDR                                  0X0850            //数字输入3
#define DIGITAL_INPUT_4_ADDR                                  0X0860            //数字输入4
#define INPUT_STATUS2_ADDR                                    0X08A0            //输入口状态
#define OUTPUT_SINGAL_POLARITY_DEFINITION_ADDR                0X08D0            //输出口极性定义
#define OUTPUT_PORT_SIGNAL_SIMNLATION_ADDR                    0X08E0            //输出口信号模拟
#define DIGITAL_OUTPUT_1_ADDR                                 0X08F0            //数字输出1
#define DIGITAL_OUTPUT_2_ADDR                                 0X0900            //数字输出2
#define OUTPUT_PORT_STATUS_ADDR                               0X0940            //输出口状态
#define ACTUAL_VELOCITY_ERROR_WIN_ADDR                        0X0980            //零速输出速度窗口
#define LIMIT_FUNCTION_DEFINTION_ADDR                         0X0990            //限位功能定义

#define MULTISTAGE_POSITION_CONTROL_0_ADDR                    0X0C10            //多段位置控制0
#define MULTISTAGE_POSITION_CONTROL_1_ADDR                    0X0C20            //多段位置控制1
#define MULTISTAGE_POSITION_CONTROL_2_ADDR                    0X0C30            //多段位置控制2
#define MULTISTAGE_POSITION_CONTROL_3_ADDR                    0X0C40            //多段位置控制3
#define MULTISTAGE_VELOCITY_CONTROL_0_ADDR                    0X0C50            //多段速度控制0
#define MULTISTAGE_VELOCITY_CONTROL_1_ADDR                    0X0C60            //多段速度控制1
#define MULTISTAGE_VELOCITY_CONTROL_2_ADDR                    0X0C70            //多段速度控制2
#define MULTISTAGE_VELOCITY_CONTROL_3_ADDR                    0X0C80            //多段速度控制3
#define POSITION_CONTROL_SELECTION_ADDR                       0X0CF0            //绝对/相对位置控制选择
#define MULTISTAGE_POSITION_CONTROL_4_ADDR                    0X0D00            //多段位置控制4
#define MULTISTAGE_POSITION_CONTROL_5_ADDR                    0X0D10            //多段位置控制5
#define MULTISTAGE_POSITION_CONTROL_6_ADDR                    0X0D20            //多段位置控制6
#define MULTISTAGE_POSITION_CONTROL_7_ADDR                    0X0D30            //多段位置控制7
#define MULTISTAGE_VELOCITY_CONTROL_4_ADDR                    0X0D40            //多段速度控制4
#define MULTISTAGE_VELOCITY_CONTROL_5_ADDR                    0X0D50            //多段速度控制5
#define MULTISTAGE_VELOCITY_CONTROL_6_ADDR                    0X0D60            //多段速度控制6
#define MULTISTAGE_VELOCITY_CONTROL_7_ADDR                    0X0D70            //多段速度控制7

#define ELECTRONIC_GEARS_NUMERATOR_0_ADDR                     0X1910            //电子齿轮分子0
#define ELECYRONIC_GEARS_DENOMINATOR_0_ADDR                   0X1920            //电子齿轮分母0
#define PULSE_MODE_ADDR                                       0X1930            //脉冲模式控制
#define ELECTRONIC_GEARS_INPUT_PULSE_FRONT_ADDR               0X1940            //电子齿轮前输入脉冲数
#define ELECTRONIC_GEARS_INPUT_PULSE_BACK_ADDR                0X1950            //电子齿轮后输入脉冲数
#define PULSE_FILTER_PARAMETER_ADDR                           0X1960            //脉冲滤波参数
#define LOCATION_TIME_WIN_ADDR                                0X1990            //目标到时间窗口
#define GEARS_PULSE_FREQ_FRONT_ADDR                           0X19C0            //齿轮前脉冲频率
#define GEARS_PULSE_FREQ_BACK_ADDR                            0X19D0            //齿轮后脉冲频率	
#define ERROR_WORD_ADDR                                       0X1F00            //错误字
#define SAVE_CONTROL_NUM_ADDR                                 0X2910            //储存控制参数
#define SAVE_MOTOR_NUM_ADDR                                   0X2930            //储存电机参数

#define CONTROL_WORD_ADDR                                     0x3100            //控制字
#define STATUE_WORD_ADDR                                      0x3200            //状态字
#define QUICK_STOP_MODE_DECELERATION_ADDR                     0X3300            //快速停止减速度
#define QUICK_STOP_MODE_ADDR                                  0X3400            //快速停止模式
#define SHUTDOWN_STOP_MODE_ADDR                               0X3410            //关机停止模式
#define DISABLE_STOP_MODE_ADDR                                0X3420            //禁止停止模式
#define SUSPEND_MODE_ADDR                                     0X3430            //暂停模式
#define ERROR_STOP_MODE_ADDR                                  0X3440            //报错停止模式
#define WORKING_MODE_ADDR                                     0X3500            //工作模式
#define PHYSICL_LOCATION_ADDR                                 0X3700            //实际位置
#define FOLLOWING_ERROR_MAX_ADDR                              0X3800            //最大跟随误差
#define TARGET_LOCATION_WIN_ADDR                              0X3900            //目标位置窗口
#define ACTUAL_VELOCITY_ADDR                                  0X3B00            //实际速度
#define TARGET_TORQUE_ADDR                                    0X3C00            //目标力矩
#define TARGET_CURRENT_MAX_ADDR                               0X3D00            //目标电流限制
#define ACTUAL_CURRENT_ADDR                                   0X3E00            //实际电流值

#define TARGET_POSITION_ADDR                                  0X4000            //目标位置
#define ORIGIN_OFFSET_ADDR                                    0X4100            //原点偏移
#define SOFT_LIMIT_POSITIVE_SETTING_ADDR                      0X4410            //软限位正设置
#define SOFT_LIMIT_NEGATIVE_SETTING_ADDR                      0X4420            //软限位负设置
#define DIRECTION_CONTROL_ADDR                                0X4700            //速度位置方向控制
#define VELOCITY_MAX_ADDR                                     0X4900            //最大速度限制
#define TRAPEZOID_VELOCITY_ADDR                               0x4a00            //梯形速度
#define TRAPEZOID_ACCELERATION_ADDR                           0X4B00            //梯形加速度
#define TRAPEZOID_DECELERATION_ADDR                           0X4C00            //梯形曲线减速度
#define ORIGIN_MODEL_ADDR                                     0X4D00            //原点模式

#define SEARCH_ORIGIN_VELOCITY_ADDR                           0X5010            //原点转折信号速度
#define STARTING_SEARCH_ORIGIN_VELOCITY_ADDR                  0X5020            //原点信号速度
#define ORIGIN_OFFSET_MODEL_ADDR                              0X5050            //原点偏移模式
#define SEARCH_ORIGIN_ACCELERATION_ADDR                       0X5200            //寻找原点时的加速度
#define TARGET_CURRENT_ADDR                                   0X5880            //目标电流
#define VELOCITY_LOOP_GAIN_P_ADDR                             0X6310            //速度环比例增益
#define VELOCITY_LOOP_GAIN_I_ADDR                             0X6320            //速度环积分增益
#define VELOCITY_FEED_BACK_FILTER_ADDR                        0X6350            //速度反馈滤波
#define VELOCITY_LOOP_GAIN_32_I_ADDR                          0X6370            //速度环积分增益/32
#define VELOCITY_WIN_ADDR                                     0X63A0            //速度到窗口
#define VELOCITY_ZERO_OUTPUT_TIME_ADDR                        0X6440            //零速输出时间
#define POSITION_LOOP_GAIN_P_ADDR                             0X6810            //位置环比例增益
#define POSITION_LOOP_VELOCITY_FEED_FORWARD_ADDR              0X6820            //位置环速度前馈
#define POSITION_LOOP_ACC_FEED_FORWARD_ADDR                   0X6830            //位置环加速度前馈
#define SMOOTHING_FILTER_ADDR                                 0X6850            //平滑滤波
#define INPUT_PORT_STATUS1_ADDR                               0X6D00            //输入口状态
#define TARGET_VELOCITY_ADDR                                  0X6F00            //目标速度

uint16_t   u16ControlWord=0;
uint16_t   u16StatusWord=0;
int8_t     int8WorkingMode=0;
uint16_t   u16PositionControlSelection=0;
int32_t    int32PhysicalLocation=0;
int16_t    int16ActualCurrent=0;
uint32_t u32InputPortStatus1=0;                     
int32_t	int32ActualVelocity=0;                       
uint8_t    u8DirectionContol=0;
int32_t    int32TargetPosition=0;
uint32_t   u32TrapezoidVelocity=0;
int32_t    int32TargetVelocity=0;
uint16_t   u16VelocityMAX=0;
uint32_t   u32TrapezoidalAcceleration=0;
uint32_t	u32TrapezoidalDeceleration=0;              
int16_t  int16TargetTorque=0;                        
int16_t	int16TargetCurrent=0;                           
uint16_t	u16TargetCurrentMAX=0;                    
int32_t	int32MultistagePositionControl0=0;            
int32_t	int32MultistagePositionControl1=0;            
int32_t	int32MultistagePositionControl2=0;              
int32_t	int32MultistagePositionControl3=0;             
int32_t	int32MultistagePositionControl4=0;             
int32_t	int32MultistagePositionControl5=0;             
int32_t	int32MultistagePositionControl6=0;             
int32_t	int32MultistagePositionControl7=0;          
int32_t	int32MultistageVelocityControl0=0;          
int32_t  int32MultistageVelocityControl1=0;          
int32_t  int32MultistageVelocityControl2=0;           
int32_t  int32MultistageVelocityControl3=0;            
int32_t  int32MultistageVelocityControl4=0;          
int32_t  int32MultistageVelocityControl5=0;           
int32_t  int32MultistageVelocityControl6=0;          
int32_t  int32MultistageVelocityControl7=0;          
uint32_t  u32FollowingErrorMAX=0;                     
uint32_t	u32TargetLocationWin=0;                     
uint16_t	u16LocationToTimeWin=0;                    
int32_t	int32VelocityWin=0;                             
uint16_t	u16ActualVelocity0ErrorWin=0;                
uint16_t	u16Velocity0OutputTime=0;                    
int32_t	int32SoftLimitPositiveSetting=0;              
int32_t	int32SoftLimitNegativeSetting=0;               
uint8_t	u8LimitFunctionDefintion=0;                
int8_t	int8OriginModel=0;                           
uint32_t	u32SearchOriginVelocity=0;                   
uint32_t	u32StartingSearchOriginVelocity=0;          
uint32_t	u32SearchOriginAcceleration=0;               
int32_t	int32OriginOffset=0;                            
uint8_t	u8OriginOffsetModel=0;                     
uint16_t	u16VelocityLoopGain_P=0;                    
uint16_t	u16VelocityLoopGain_I=0;                  
uint16_t	u16VelocityLoopGain_32_I=0;                
uint8_t	u8VelocityFeedBackFilter=0;               
uint16_t	u16PositionLoopGain_P=0;                    
uint16_t	u16PositionLoopVelocityFeedforward=0;    
uint16_t	u16PositionLoopAccFeedforward=0;              
uint16_t	u16SmoothingFilter=0;                         
uint16_t  u16DigitalInput1=0;                          
uint16_t	u16DigitalInput2=0;                           
uint16_t	u16DigitalInput3=0;                           
uint16_t	u16DigitalInput4=0;                           
uint16_t	u16DigitalOutput1=0;                    	    
uint16_t	u16DigitalOutput2=0;                     		  
uint16_t	u16InputPortStatus2=0;                       
uint16_t	u16OutputPortStatus=0;                        
uint16_t	u16InputSignalPolarityDefinition=0;           
uint16_t	u16OutputSignalPolarityDefinition=0;          
uint16_t	u16InputPortSignalSimulation=0;
uint16_t	u16OutputPortSignalSimulation=0;
int16_t	int16ElectronicGearsNumerator0=0;
uint16_t	u16ElectronicGearsDenominator=0;
int16_t	int16PulseMode=0;
int16_t	int16ElectronicGearsInputPulseNum_Front=0;
int16_t	int16ElectronicGearsInputPulseNum_Back=0;
uint16_t	u16PulseFilterParameter=0;
int16_t	int16GearsPulseFreq_Front=0;
int16_t	int16GearsPulseFreq_Back=0;
uint8_t	u8SaveControlNum=0;
uint8_t	u8SaveMotorNum=0;
uint16_t	u16ErrorWord=0;
int16_t	int16QuickStopMode=0;
int16_t	int16ShutdownStopMode=0;
int16_t	int16DisableStopMode=0;
int16_t	int16SuspendMode=0;
uint32_t	u32ErrorStopMode=0;
uint32_t	u32QuickStopModeDeceleration=0;  


#if 0
typedef enum
{
	ControlWord=0x3100,                             //控制字
	StatusWord=0x3200,                              //状态字
	WorkingMode=3500,                               //工作模式
	PositionControlSelection=0x0cf0,                //绝对/相对位置控制选择
	PhysicalLocation=0x3700,                        //实际位置
	ActualCurrent=0x3e00,                           //实际电流值
	InputPortStatus1=0x6d00,                        //输入口状态
	ActualVelocity=0x3b00,                          //实际速度
	DirectionContol=0x4700,                         //速度位置方向控制
	TargetPosition=0x4000,                          //目标位置
	TrapezoidVelocity=0x4a00,                       //  梯形速度
	TargetVelocity=0x6f00,                          //目标速度
	VelocityMAX=0x4900,                             //最大速度限制
	TrapezoidalAcceleration=0x4b00,                 //梯形加速度
	TrapezoidalDeceleration=0x4c00,                 //梯形曲线减速度
  TargetTorque=0x3c00,                            //目标力矩
	TargetCurrent=0x5880,                           //目标电流
	TargetCurrentMAX=0x3D00,                        //目标电流限制
	MultistagePositionControl0=0x0c10,              //多段位置控制0
	MultistagePositionControl1=0x0c20,              //多段位置控制1
	MultistagePositionControl2=0x0c30,              //多段位置控制2
	MultistagePositionControl3=0x0c40,              //多段位置控制3
	MultistagePositionControl4=0x0D00,              //多段位置控制4
	MultistagePositionControl5=0x0d10,              //多段位置控制5
	MultistagePositionControl6=0x0d20,              //多段位置控制6
	MultistagePositionControl7=0x0d30,              //多段位置控制7
	MultistageVelocityControl0=0x0c50,              //多段速度控制0
  MultistageVelocityControl1=0x0c60,              //多段速度控制1
  MultistageVelocityControl2=0x0c70,              //多段速度控制2
  MultistageVelocityControl3=0x0c80,              //多段速度控制3
  MultistageVelocityControl4=0x0d40,              //多段速度控制4
  MultistageVelocityControl5=0x0d50,              //多段速度控制5
  MultistageVelocityControl6=0x0d60,              //多段速度控制6
  MultistageVelocityControl7=0x0d70,              //多段速度控制7
  FollowingErrorMAX=0x3800,                       //最大跟随误差
	TargetLocationWin=0x3900,                       //目标位置窗口
	LocationToTimeWin=0x1990,                       //目标到时间窗口
	VelocityWin=0x63a0,                             //速度到窗口
	ActualVelocity0ErrorWin=0x0980,                 //零速输出速度窗口
	Velocity0OutputTime=0x6440,                     //零速输出时间
	SoftLimitPositiveSetting=0x4410,                //软限位正设置
	SoftLimitNegativeSetting=0x4420,                //软限位负设置
	LimitFunctionDefintion=0x0990,                  //限位功能定义
	OriginModel=0x4d00,                             //原点模式
	SearchOriginVelocity=0x5010,                    //原点转折信号速度
	StartingSearchOriginVelocity=0x5020,            //原点信号速度
	SearchOriginAcceleration=0x5200,                //寻找原点时的加速度
	OriginOffset=0x4100,                            //原点偏移
	OriginOffsetModel=0x5050,                       //原点偏移模式
	VelocityLoopGain_P=0x6310,                      //速度环比例增益
	VelocityLoopGain_I=0x6310,                      //速度环积分增益
	VelocityLoopGain_32_I=0x6370,                   //速度环积分增益/32
	VelocityFeedBackFilter=0x6350,                  //速度反馈滤波
	PositionLoopGain_P=0x6810,                      //位置环比例增益
	PositionLoopVelocityFeedforward=0x6820,         //位置环速度前馈
	PositionLoopAccFeedforward=0x6830,              //位置环加速度前馈
	SmoothingFilter=0x6850,                         //平滑滤波
  DigitalInput1=0x0830,                           //数字输入1
	DigitalInput2=0x0840,                           //数字输入2
	DigitalInput3=0x0850,                           //数字输入3
	DigitalInput4=0x0860,                           //数字输入4
	DigitalOutput1=0x08f0,                    	    //数字输出1
	DigitalOutput2=0x0900,                     		  //数字输出2
	InputPortStatus2=0x08a0,                        //输入口状态
	OutputPortStatus=0x0940,                        //输出口状态
	InputSignalPolarityDefinition=0x0810,           //改变输入信号极性定义
	OutputSignalPolarityDefinition=0x08d0,          //输出口极性定义
	InputPortSignalSimulation=0x0820,               //输入口信号模拟
	OutputPortSignalSimulation=0x08e0,              //输出口信号模拟
	ElectronicGearsNumerator0=0x1910,               //电子齿轮分子0
	ElectronicGearsDenominator=0x1920,              //电子齿轮分母0
	PulseMode=0x1930,                               //脉冲模式控制
	ElectronicGearsInputPulseNum_Front=0x1940,      //电子齿轮前输入脉冲数
	ElectronicGearsInputPulseNum_Back=0x1950,       //电子齿轮后输入脉冲数
	PulseFilterParameter=0x1960,                    //脉冲滤波参数
	GearsPulseFreq_Front=0x19c0,                    //齿轮前脉冲频率
	GearsPulseFreq_Back=0x19d0,                     //齿轮后脉冲频率
	SaveControlNum=0x2910,                          //储存控制参数
	SaveMotorNum=0x2930,                            //储存电机参数
	ErrorWord=0x1F00,                               //错误字
	QuickStopMode=0x3400,                           //快速停止模式
	ShutdownStopMode=0x3410,                        //关机停止模式
	DisableStopMode=0x3420,                         //禁止停止模式
	SuspendMode=0x3430,                             //暂停模式
	ErrorStopMode=0x3440,                           //报错停止模式
	QuickStopModeDeceleration=0x3300                //快速停止减速度
}e_ModbusRegAdr;
#endif




#endif
