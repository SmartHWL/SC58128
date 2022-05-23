#ifndef USERMODBUS_H
#define USERMODBUS_H


#include "stdint.h"
#include "SC32F58128.h"
#include "mb.h"
#include "mbport.h"
#include "mbutils.h"


#define INPUT_SIGNAL_POLARITY_DEFINITION_ADDR                 0X0810            //�ı������źż���
#define INPUT_PORT_SIGNAL_SIMULATION                          0X0820            //������ź�ģ��
#define DIGITAL_INPUT_1_ADDR                                  0X0830            //��������1
#define DIGITAL_INPUT_2_ADDR                                  0X0840            //��������2
#define DIGITAL_INPUT_3_ADDR                                  0X0850            //��������3
#define DIGITAL_INPUT_4_ADDR                                  0X0860            //��������4
#define INPUT_STATUS2_ADDR                                    0X08A0            //�����״̬
#define OUTPUT_SINGAL_POLARITY_DEFINITION_ADDR                0X08D0            //����ڼ��Զ���
#define OUTPUT_PORT_SIGNAL_SIMNLATION_ADDR                    0X08E0            //������ź�ģ��
#define DIGITAL_OUTPUT_1_ADDR                                 0X08F0            //�������1
#define DIGITAL_OUTPUT_2_ADDR                                 0X0900            //�������2
#define OUTPUT_PORT_STATUS_ADDR                               0X0940            //�����״̬
#define ACTUAL_VELOCITY_ERROR_WIN_ADDR                        0X0980            //��������ٶȴ���
#define LIMIT_FUNCTION_DEFINTION_ADDR                         0X0990            //��λ���ܶ���

#define MULTISTAGE_POSITION_CONTROL_0_ADDR                    0X0C10            //���λ�ÿ���0
#define MULTISTAGE_POSITION_CONTROL_1_ADDR                    0X0C20            //���λ�ÿ���1
#define MULTISTAGE_POSITION_CONTROL_2_ADDR                    0X0C30            //���λ�ÿ���2
#define MULTISTAGE_POSITION_CONTROL_3_ADDR                    0X0C40            //���λ�ÿ���3
#define MULTISTAGE_VELOCITY_CONTROL_0_ADDR                    0X0C50            //����ٶȿ���0
#define MULTISTAGE_VELOCITY_CONTROL_1_ADDR                    0X0C60            //����ٶȿ���1
#define MULTISTAGE_VELOCITY_CONTROL_2_ADDR                    0X0C70            //����ٶȿ���2
#define MULTISTAGE_VELOCITY_CONTROL_3_ADDR                    0X0C80            //����ٶȿ���3
#define POSITION_CONTROL_SELECTION_ADDR                       0X0CF0            //����/���λ�ÿ���ѡ��
#define MULTISTAGE_POSITION_CONTROL_4_ADDR                    0X0D00            //���λ�ÿ���4
#define MULTISTAGE_POSITION_CONTROL_5_ADDR                    0X0D10            //���λ�ÿ���5
#define MULTISTAGE_POSITION_CONTROL_6_ADDR                    0X0D20            //���λ�ÿ���6
#define MULTISTAGE_POSITION_CONTROL_7_ADDR                    0X0D30            //���λ�ÿ���7
#define MULTISTAGE_VELOCITY_CONTROL_4_ADDR                    0X0D40            //����ٶȿ���4
#define MULTISTAGE_VELOCITY_CONTROL_5_ADDR                    0X0D50            //����ٶȿ���5
#define MULTISTAGE_VELOCITY_CONTROL_6_ADDR                    0X0D60            //����ٶȿ���6
#define MULTISTAGE_VELOCITY_CONTROL_7_ADDR                    0X0D70            //����ٶȿ���7

#define ELECTRONIC_GEARS_NUMERATOR_0_ADDR                     0X1910            //���ӳ��ַ���0
#define ELECYRONIC_GEARS_DENOMINATOR_0_ADDR                   0X1920            //���ӳ��ַ�ĸ0
#define PULSE_MODE_ADDR                                       0X1930            //����ģʽ����
#define ELECTRONIC_GEARS_INPUT_PULSE_FRONT_ADDR               0X1940            //���ӳ���ǰ����������
#define ELECTRONIC_GEARS_INPUT_PULSE_BACK_ADDR                0X1950            //���ӳ��ֺ�����������
#define PULSE_FILTER_PARAMETER_ADDR                           0X1960            //�����˲�����
#define LOCATION_TIME_WIN_ADDR                                0X1990            //Ŀ�굽ʱ�䴰��
#define GEARS_PULSE_FREQ_FRONT_ADDR                           0X19C0            //����ǰ����Ƶ��
#define GEARS_PULSE_FREQ_BACK_ADDR                            0X19D0            //���ֺ�����Ƶ��	
#define ERROR_WORD_ADDR                                       0X1F00            //������
#define SAVE_CONTROL_NUM_ADDR                                 0X2910            //������Ʋ���
#define SAVE_MOTOR_NUM_ADDR                                   0X2930            //����������

#define CONTROL_WORD_ADDR                                     0x3100            //������
#define STATUE_WORD_ADDR                                      0x3200            //״̬��
#define QUICK_STOP_MODE_DECELERATION_ADDR                     0X3300            //����ֹͣ���ٶ�
#define QUICK_STOP_MODE_ADDR                                  0X3400            //����ֹͣģʽ
#define SHUTDOWN_STOP_MODE_ADDR                               0X3410            //�ػ�ֹͣģʽ
#define DISABLE_STOP_MODE_ADDR                                0X3420            //��ֹֹͣģʽ
#define SUSPEND_MODE_ADDR                                     0X3430            //��ͣģʽ
#define ERROR_STOP_MODE_ADDR                                  0X3440            //����ֹͣģʽ
#define WORKING_MODE_ADDR                                     0X3500            //����ģʽ
#define PHYSICL_LOCATION_ADDR                                 0X3700            //ʵ��λ��
#define FOLLOWING_ERROR_MAX_ADDR                              0X3800            //���������
#define TARGET_LOCATION_WIN_ADDR                              0X3900            //Ŀ��λ�ô���
#define ACTUAL_VELOCITY_ADDR                                  0X3B00            //ʵ���ٶ�
#define TARGET_TORQUE_ADDR                                    0X3C00            //Ŀ������
#define TARGET_CURRENT_MAX_ADDR                               0X3D00            //Ŀ���������
#define ACTUAL_CURRENT_ADDR                                   0X3E00            //ʵ�ʵ���ֵ

#define TARGET_POSITION_ADDR                                  0X4000            //Ŀ��λ��
#define ORIGIN_OFFSET_ADDR                                    0X4100            //ԭ��ƫ��
#define SOFT_LIMIT_POSITIVE_SETTING_ADDR                      0X4410            //����λ������
#define SOFT_LIMIT_NEGATIVE_SETTING_ADDR                      0X4420            //����λ������
#define DIRECTION_CONTROL_ADDR                                0X4700            //�ٶ�λ�÷������
#define VELOCITY_MAX_ADDR                                     0X4900            //����ٶ�����
#define TRAPEZOID_VELOCITY_ADDR                               0x4a00            //�����ٶ�
#define TRAPEZOID_ACCELERATION_ADDR                           0X4B00            //���μ��ٶ�
#define TRAPEZOID_DECELERATION_ADDR                           0X4C00            //�������߼��ٶ�
#define ORIGIN_MODEL_ADDR                                     0X4D00            //ԭ��ģʽ

#define SEARCH_ORIGIN_VELOCITY_ADDR                           0X5010            //ԭ��ת���ź��ٶ�
#define STARTING_SEARCH_ORIGIN_VELOCITY_ADDR                  0X5020            //ԭ���ź��ٶ�
#define ORIGIN_OFFSET_MODEL_ADDR                              0X5050            //ԭ��ƫ��ģʽ
#define SEARCH_ORIGIN_ACCELERATION_ADDR                       0X5200            //Ѱ��ԭ��ʱ�ļ��ٶ�
#define TARGET_CURRENT_ADDR                                   0X5880            //Ŀ�����
#define VELOCITY_LOOP_GAIN_P_ADDR                             0X6310            //�ٶȻ���������
#define VELOCITY_LOOP_GAIN_I_ADDR                             0X6320            //�ٶȻ���������
#define VELOCITY_FEED_BACK_FILTER_ADDR                        0X6350            //�ٶȷ����˲�
#define VELOCITY_LOOP_GAIN_32_I_ADDR                          0X6370            //�ٶȻ���������/32
#define VELOCITY_WIN_ADDR                                     0X63A0            //�ٶȵ�����
#define VELOCITY_ZERO_OUTPUT_TIME_ADDR                        0X6440            //�������ʱ��
#define POSITION_LOOP_GAIN_P_ADDR                             0X6810            //λ�û���������
#define POSITION_LOOP_VELOCITY_FEED_FORWARD_ADDR              0X6820            //λ�û��ٶ�ǰ��
#define POSITION_LOOP_ACC_FEED_FORWARD_ADDR                   0X6830            //λ�û����ٶ�ǰ��
#define SMOOTHING_FILTER_ADDR                                 0X6850            //ƽ���˲�
#define INPUT_PORT_STATUS1_ADDR                               0X6D00            //�����״̬
#define TARGET_VELOCITY_ADDR                                  0X6F00            //Ŀ���ٶ�

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
	ControlWord=0x3100,                             //������
	StatusWord=0x3200,                              //״̬��
	WorkingMode=3500,                               //����ģʽ
	PositionControlSelection=0x0cf0,                //����/���λ�ÿ���ѡ��
	PhysicalLocation=0x3700,                        //ʵ��λ��
	ActualCurrent=0x3e00,                           //ʵ�ʵ���ֵ
	InputPortStatus1=0x6d00,                        //�����״̬
	ActualVelocity=0x3b00,                          //ʵ���ٶ�
	DirectionContol=0x4700,                         //�ٶ�λ�÷������
	TargetPosition=0x4000,                          //Ŀ��λ��
	TrapezoidVelocity=0x4a00,                       //  �����ٶ�
	TargetVelocity=0x6f00,                          //Ŀ���ٶ�
	VelocityMAX=0x4900,                             //����ٶ�����
	TrapezoidalAcceleration=0x4b00,                 //���μ��ٶ�
	TrapezoidalDeceleration=0x4c00,                 //�������߼��ٶ�
  TargetTorque=0x3c00,                            //Ŀ������
	TargetCurrent=0x5880,                           //Ŀ�����
	TargetCurrentMAX=0x3D00,                        //Ŀ���������
	MultistagePositionControl0=0x0c10,              //���λ�ÿ���0
	MultistagePositionControl1=0x0c20,              //���λ�ÿ���1
	MultistagePositionControl2=0x0c30,              //���λ�ÿ���2
	MultistagePositionControl3=0x0c40,              //���λ�ÿ���3
	MultistagePositionControl4=0x0D00,              //���λ�ÿ���4
	MultistagePositionControl5=0x0d10,              //���λ�ÿ���5
	MultistagePositionControl6=0x0d20,              //���λ�ÿ���6
	MultistagePositionControl7=0x0d30,              //���λ�ÿ���7
	MultistageVelocityControl0=0x0c50,              //����ٶȿ���0
  MultistageVelocityControl1=0x0c60,              //����ٶȿ���1
  MultistageVelocityControl2=0x0c70,              //����ٶȿ���2
  MultistageVelocityControl3=0x0c80,              //����ٶȿ���3
  MultistageVelocityControl4=0x0d40,              //����ٶȿ���4
  MultistageVelocityControl5=0x0d50,              //����ٶȿ���5
  MultistageVelocityControl6=0x0d60,              //����ٶȿ���6
  MultistageVelocityControl7=0x0d70,              //����ٶȿ���7
  FollowingErrorMAX=0x3800,                       //���������
	TargetLocationWin=0x3900,                       //Ŀ��λ�ô���
	LocationToTimeWin=0x1990,                       //Ŀ�굽ʱ�䴰��
	VelocityWin=0x63a0,                             //�ٶȵ�����
	ActualVelocity0ErrorWin=0x0980,                 //��������ٶȴ���
	Velocity0OutputTime=0x6440,                     //�������ʱ��
	SoftLimitPositiveSetting=0x4410,                //����λ������
	SoftLimitNegativeSetting=0x4420,                //����λ������
	LimitFunctionDefintion=0x0990,                  //��λ���ܶ���
	OriginModel=0x4d00,                             //ԭ��ģʽ
	SearchOriginVelocity=0x5010,                    //ԭ��ת���ź��ٶ�
	StartingSearchOriginVelocity=0x5020,            //ԭ���ź��ٶ�
	SearchOriginAcceleration=0x5200,                //Ѱ��ԭ��ʱ�ļ��ٶ�
	OriginOffset=0x4100,                            //ԭ��ƫ��
	OriginOffsetModel=0x5050,                       //ԭ��ƫ��ģʽ
	VelocityLoopGain_P=0x6310,                      //�ٶȻ���������
	VelocityLoopGain_I=0x6310,                      //�ٶȻ���������
	VelocityLoopGain_32_I=0x6370,                   //�ٶȻ���������/32
	VelocityFeedBackFilter=0x6350,                  //�ٶȷ����˲�
	PositionLoopGain_P=0x6810,                      //λ�û���������
	PositionLoopVelocityFeedforward=0x6820,         //λ�û��ٶ�ǰ��
	PositionLoopAccFeedforward=0x6830,              //λ�û����ٶ�ǰ��
	SmoothingFilter=0x6850,                         //ƽ���˲�
  DigitalInput1=0x0830,                           //��������1
	DigitalInput2=0x0840,                           //��������2
	DigitalInput3=0x0850,                           //��������3
	DigitalInput4=0x0860,                           //��������4
	DigitalOutput1=0x08f0,                    	    //�������1
	DigitalOutput2=0x0900,                     		  //�������2
	InputPortStatus2=0x08a0,                        //�����״̬
	OutputPortStatus=0x0940,                        //�����״̬
	InputSignalPolarityDefinition=0x0810,           //�ı������źż��Զ���
	OutputSignalPolarityDefinition=0x08d0,          //����ڼ��Զ���
	InputPortSignalSimulation=0x0820,               //������ź�ģ��
	OutputPortSignalSimulation=0x08e0,              //������ź�ģ��
	ElectronicGearsNumerator0=0x1910,               //���ӳ��ַ���0
	ElectronicGearsDenominator=0x1920,              //���ӳ��ַ�ĸ0
	PulseMode=0x1930,                               //����ģʽ����
	ElectronicGearsInputPulseNum_Front=0x1940,      //���ӳ���ǰ����������
	ElectronicGearsInputPulseNum_Back=0x1950,       //���ӳ��ֺ�����������
	PulseFilterParameter=0x1960,                    //�����˲�����
	GearsPulseFreq_Front=0x19c0,                    //����ǰ����Ƶ��
	GearsPulseFreq_Back=0x19d0,                     //���ֺ�����Ƶ��
	SaveControlNum=0x2910,                          //������Ʋ���
	SaveMotorNum=0x2930,                            //����������
	ErrorWord=0x1F00,                               //������
	QuickStopMode=0x3400,                           //����ֹͣģʽ
	ShutdownStopMode=0x3410,                        //�ػ�ֹͣģʽ
	DisableStopMode=0x3420,                         //��ֹֹͣģʽ
	SuspendMode=0x3430,                             //��ͣģʽ
	ErrorStopMode=0x3440,                           //����ֹͣģʽ
	QuickStopModeDeceleration=0x3300                //����ֹͣ���ٶ�
}e_ModbusRegAdr;
#endif




#endif
