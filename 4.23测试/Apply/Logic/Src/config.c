#include "config.h"


/* GPIO句柄示例 */
tagGPIO_T LED[] =
{
	
	[0]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_13,				/* GPIO引脚 */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
		.tGPIOPort 			= GPIOD,					/* GPIO分组 */
	},
    [1]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_14,				/* GPIO引脚 */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
		.tGPIOPort 			= GPIOD,					/* GPIO分组 */
	},
    [2]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_15,				/* GPIO引脚 */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
		.tGPIOPort 			= GPIOD,					/* GPIO分组 */
	},
    
};

/* 串口句柄示例 */
tagUART_T Uart1 = 
{
	//串口工作模式配置
	.tUARTHandle.Instance 				= USART1,					/* STM32 串口设备 */
	.tUARTHandle.Init.BaudRate   		= 115200,					/* 串口波特率 */
	.tUARTHandle.Init.WordLength 		= UART_WORDLENGTH_8B,
	.tUARTHandle.Init.StopBits   		= UART_STOPBITS_1,
	.tUARTHandle.Init.Parity     		= UART_PARITY_NONE,
	.tUARTHandle.Init.HwFlowCtl  		= UART_HWCONTROL_NONE,
	.tUARTHandle.Init.Mode       		= UART_MODE_TX_RX,
	.tUARTHandle.Init.OverSampling 		= UART_OVERSAMPLING_16,

#if defined (STM32L4_SGA_ENABLE)
	.tUARTHandle.Init.OneBitSampling 	= UART_ONE_BIT_SAMPLE_DISABLE,
	.tUARTHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT,
#endif
	
	.ucPriority							= 1,						/* 中断优先级 */
	.ucSubPriority						= 3,						/* 中断子优先级 */
	
	//串口DMA接收参数配置
	.tUartDMA.bRxEnable					= true,						/* DMA接收使能 */
	.tUartDMA.tDMARx.Instance			= DMA1_Channel5,
	.tUartDMA.tDMARx.Init.Direction		= DMA_PERIPH_TO_MEMORY,
	.tUartDMA.tDMARx.Init.PeriphInc		= DMA_PINC_DISABLE,
	.tUartDMA.tDMARx.Init.MemInc		= DMA_MINC_ENABLE,
	.tUartDMA.tDMARx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.MemDataAlignment	  = DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.Mode			= DMA_CIRCULAR,
	.tUartDMA.tDMARx.Init.Priority		= DMA_PRIORITY_LOW,

	.tRxInfo.usDMARxMAXSize             	= 100,              	/* 接收数据长度 长度保持在协议最长字节*2以上，确保缓存池一定能够稳定接收一个完整的数据帧*/

	.tUartDMA.ucDMARxPriority				= 1,					/* DMA接收中断优先级 */
	.tUartDMA.ucDMARxSubPriority			= 1,					/* DMA接收中断子优先级 */
	
	//串口DMA发送参数配置
	.tUartDMA.bTxEnable					= true,						/* DMA发送使能 */
	.tUartDMA.tDMATx.Instance			= DMA1_Channel4,
	.tUartDMA.tDMATx.Init.Direction		= DMA_MEMORY_TO_PERIPH,
	.tUartDMA.tDMATx.Init.PeriphInc		= DMA_PINC_DISABLE,
	.tUartDMA.tDMATx.Init.MemInc		= DMA_MINC_ENABLE,
	.tUartDMA.tDMATx.Init.PeriphDataAlignment	= DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.MemDataAlignment		= DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.Mode			= DMA_NORMAL,
	.tUartDMA.tDMATx.Init.Priority		= DMA_PRIORITY_LOW,

	.tTxInfo.usDMATxMAXSize				= 50,						/* 最大发送数据长度 */
	
	.tUartDMA.ucDMATxPriority				= 1,					/* DMA发送中断优先级 */
	.tUartDMA.ucDMATxSubPriority			= 1,					/* DMA发送中断子优先级 */

	//串口GPIO配置
	.tGPIO[0].tGPIOInit.Pin 			= GPIO_PIN_9,				/* GPIO引脚 */
	.tGPIO[0].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tGPIO[0].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tGPIO[0].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tGPIO[0].tGPIOPort 				= GPIOA,					/* GPIO分组 */
	.tGPIO[0].ucAFMode					= NO_REMAP,					/* GPIO重映射 */
	
	.tGPIO[1].tGPIOInit.Pin 			= GPIO_PIN_10,				/* GPIO引脚 */
	.tGPIO[1].tGPIOInit.Mode 			= GPIO_MODE_INPUT,			/* GPIO模式 */
	.tGPIO[1].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tGPIO[1].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tGPIO[1].tGPIOPort 				= GPIOA,					/* GPIO分组 */
	.tGPIO[1].ucAFMode					= NO_REMAP,					/* GPIO重映射 */
};

/* AD芯片配置 */
tagAD24BIT_T AD4111_1 =
{
	.tSPI.tSPIHandle.Instance 		    = SPI2,		
    .tSPI.tGPIO[0].tGPIOInit.Pin 		= GPIO_PIN_13,				/* GPIO引脚 ,SPI2_SCK*/
	.tSPI.tGPIO[0].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[0].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[0].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[0].tGPIOPort 			= GPIOB,					/* GPIO分组 */	
	.tSPI.tGPIO[1].tGPIOInit.Pin 		= GPIO_PIN_15,				/* GPIO引脚 ,SPI2_MOSI*/
	.tSPI.tGPIO[1].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[1].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[1].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[1].tGPIOPort 			= GPIOB,					/* GPIO分组 */	
	.tSPI.tGPIO[2].tGPIOInit.Pin 		= GPIO_PIN_14,				/* GPIO引脚 ,SPI2_MISO*/
	.tSPI.tGPIO[2].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[2].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[2].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[2].tGPIOPort 			= GPIOB,					/* GPIO分组 */		
    .tSPI.tGPIO[3].tGPIOInit.Pin 		= GPIO_PIN_12,				/* GPIO引脚 ,CS*/
	.tSPI.tGPIO[3].tGPIOInit.Mode 		= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
	.tSPI.tGPIO[3].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[3].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[3].tGPIOPort 			= GPIOB,					/* GPIO分组 */	
	.port_num = 8,  //测量的端口数，跟下面配置的端口对应起来
	.port[0].enable = PORT_ENABLE,//端口使能
	.port[0].num = VIN0,  //采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[0].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[0].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[1].enable = PORT_ENABLE,
	.port[1].num = VIN1,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[1].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[1].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;	
	.port[2].enable = PORT_ENABLE,
	.port[2].num = VIN2,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[2].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[2].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[3].enable = PORT_ENABLE,//端口使能
	.port[3].num = VIN3,  //采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[3].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[3].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[4].enable = PORT_ENABLE,
	.port[4].num = VIN4,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[4].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[4].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;	
	.port[5].enable = PORT_ENABLE,
	.port[5].num = VIN5,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[5].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[5].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
    .port[6].enable = PORT_ENABLE,
	.port[6].num = VIN6,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[6].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[6].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
    .port[7].enable = PORT_ENABLE,
	.port[7].num = VIN7,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[7].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[7].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
};

/* AD芯片配置 */
tagAD24BIT_T AD4111_2 =
{
	.tSPI.tSPIHandle.Instance 		    = SPI3,		
    .tSPI.tGPIO[0].tGPIOInit.Pin 		= GPIO_PIN_3,				/* GPIO引脚 ,SPI3_SCK*/
	.tSPI.tGPIO[0].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[0].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[0].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[0].tGPIOPort 			= GPIOB,					/* GPIO分组 */	
	.tSPI.tGPIO[1].tGPIOInit.Pin 		= GPIO_PIN_5,				/* GPIO引脚 ,SPI3_MOSI*/
	.tSPI.tGPIO[1].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[1].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[1].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[1].tGPIOPort 			= GPIOB,					/* GPIO分组 */	
	.tSPI.tGPIO[2].tGPIOInit.Pin 		= GPIO_PIN_4,				/* GPIO引脚 ,SPI3_MISO*/
	.tSPI.tGPIO[2].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[2].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[2].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[2].tGPIOPort 			= GPIOB,					/* GPIO分组 */		
    .tSPI.tGPIO[3].tGPIOInit.Pin 		= GPIO_PIN_7,				/* GPIO引脚 ,SPI3_CS*/
	.tSPI.tGPIO[3].tGPIOInit.Mode 		= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
	.tSPI.tGPIO[3].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[3].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[3].tGPIOPort 			= GPIOD,					/* GPIO分组 */	
	.port_num = 8,  //测量的端口数，跟下面配置的端口对应起来
	.port[0].enable = PORT_ENABLE,//端口使能
	.port[0].num = VIN0,  //采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[0].gain = 1.00193174,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[0].offset= 0.001524093,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[1].enable = PORT_ENABLE,
	.port[1].num = VIN1,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[1].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[1].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;	
	.port[2].enable = PORT_ENABLE,
	.port[2].num = VIN2,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[2].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[2].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[3].enable = PORT_ENABLE,//端口使能
	.port[3].num = VIN3,  //采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[3].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[3].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[4].enable = PORT_ENABLE,
	.port[4].num = VIN4,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[4].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[4].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;	
	.port[5].enable = PORT_ENABLE,
	.port[5].num = VIN5,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[5].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[5].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
    .port[6].enable = PORT_ENABLE,
	.port[6].num = VIN6,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[6].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[6].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
    .port[7].enable = PORT_ENABLE,
	.port[7].num = VIN7,	//采集信号的,单端模式，信号的地接Vincom端口;差分模式，信号接对应端口
	.port[7].gain = 1.0,  //校正参数增益Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
	.port[7].offset= 0.0,//校正参数偏移量Y =  gain*X+offset,若不需要校正则默认gain = 1.0,offset = 0.0;
};
