#include "config.h"


/* GPIO���ʾ�� */
tagGPIO_T LED[] =
{
	
	[0]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_13,				/* GPIO���� */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIOģʽ */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
		.tGPIOPort 			= GPIOD,					/* GPIO���� */
	},
    [1]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_14,				/* GPIO���� */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIOģʽ */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
		.tGPIOPort 			= GPIOD,					/* GPIO���� */
	},
    [2]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_15,				/* GPIO���� */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIOģʽ */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
		.tGPIOPort 			= GPIOD,					/* GPIO���� */
	},
    
};

/* ���ھ��ʾ�� */
tagUART_T Uart1 = 
{
	//���ڹ���ģʽ����
	.tUARTHandle.Instance 				= USART1,					/* STM32 �����豸 */
	.tUARTHandle.Init.BaudRate   		= 115200,					/* ���ڲ����� */
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
	
	.ucPriority							= 1,						/* �ж����ȼ� */
	.ucSubPriority						= 3,						/* �ж������ȼ� */
	
	//����DMA���ղ�������
	.tUartDMA.bRxEnable					= true,						/* DMA����ʹ�� */
	.tUartDMA.tDMARx.Instance			= DMA1_Channel5,
	.tUartDMA.tDMARx.Init.Direction		= DMA_PERIPH_TO_MEMORY,
	.tUartDMA.tDMARx.Init.PeriphInc		= DMA_PINC_DISABLE,
	.tUartDMA.tDMARx.Init.MemInc		= DMA_MINC_ENABLE,
	.tUartDMA.tDMARx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.MemDataAlignment	  = DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.Mode			= DMA_CIRCULAR,
	.tUartDMA.tDMARx.Init.Priority		= DMA_PRIORITY_LOW,

	.tRxInfo.usDMARxMAXSize             	= 100,              	/* �������ݳ��� ���ȱ�����Э����ֽ�*2���ϣ�ȷ�������һ���ܹ��ȶ�����һ������������֡*/

	.tUartDMA.ucDMARxPriority				= 1,					/* DMA�����ж����ȼ� */
	.tUartDMA.ucDMARxSubPriority			= 1,					/* DMA�����ж������ȼ� */
	
	//����DMA���Ͳ�������
	.tUartDMA.bTxEnable					= true,						/* DMA����ʹ�� */
	.tUartDMA.tDMATx.Instance			= DMA1_Channel4,
	.tUartDMA.tDMATx.Init.Direction		= DMA_MEMORY_TO_PERIPH,
	.tUartDMA.tDMATx.Init.PeriphInc		= DMA_PINC_DISABLE,
	.tUartDMA.tDMATx.Init.MemInc		= DMA_MINC_ENABLE,
	.tUartDMA.tDMATx.Init.PeriphDataAlignment	= DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.MemDataAlignment		= DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.Mode			= DMA_NORMAL,
	.tUartDMA.tDMATx.Init.Priority		= DMA_PRIORITY_LOW,

	.tTxInfo.usDMATxMAXSize				= 50,						/* ��������ݳ��� */
	
	.tUartDMA.ucDMATxPriority				= 1,					/* DMA�����ж����ȼ� */
	.tUartDMA.ucDMATxSubPriority			= 1,					/* DMA�����ж������ȼ� */

	//����GPIO����
	.tGPIO[0].tGPIOInit.Pin 			= GPIO_PIN_9,				/* GPIO���� */
	.tGPIO[0].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tGPIO[0].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[0].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[0].tGPIOPort 				= GPIOA,					/* GPIO���� */
	.tGPIO[0].ucAFMode					= NO_REMAP,					/* GPIO��ӳ�� */
	
	.tGPIO[1].tGPIOInit.Pin 			= GPIO_PIN_10,				/* GPIO���� */
	.tGPIO[1].tGPIOInit.Mode 			= GPIO_MODE_INPUT,			/* GPIOģʽ */
	.tGPIO[1].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[1].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[1].tGPIOPort 				= GPIOA,					/* GPIO���� */
	.tGPIO[1].ucAFMode					= NO_REMAP,					/* GPIO��ӳ�� */
};

/* ADоƬ���� */
tagAD24BIT_T AD4111_1 =
{
	.tSPI.tSPIHandle.Instance 		    = SPI2,		
    .tSPI.tGPIO[0].tGPIOInit.Pin 		= GPIO_PIN_13,				/* GPIO���� ,SPI2_SCK*/
	.tSPI.tGPIO[0].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tSPI.tGPIO[0].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tSPI.tGPIO[0].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tSPI.tGPIO[0].tGPIOPort 			= GPIOB,					/* GPIO���� */	
	.tSPI.tGPIO[1].tGPIOInit.Pin 		= GPIO_PIN_15,				/* GPIO���� ,SPI2_MOSI*/
	.tSPI.tGPIO[1].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tSPI.tGPIO[1].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tSPI.tGPIO[1].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tSPI.tGPIO[1].tGPIOPort 			= GPIOB,					/* GPIO���� */	
	.tSPI.tGPIO[2].tGPIOInit.Pin 		= GPIO_PIN_14,				/* GPIO���� ,SPI2_MISO*/
	.tSPI.tGPIO[2].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tSPI.tGPIO[2].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tSPI.tGPIO[2].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tSPI.tGPIO[2].tGPIOPort 			= GPIOB,					/* GPIO���� */		
    .tSPI.tGPIO[3].tGPIOInit.Pin 		= GPIO_PIN_12,				/* GPIO���� ,CS*/
	.tSPI.tGPIO[3].tGPIOInit.Mode 		= GPIO_MODE_OUTPUT_PP,		/* GPIOģʽ */
	.tSPI.tGPIO[3].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tSPI.tGPIO[3].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tSPI.tGPIO[3].tGPIOPort 			= GPIOB,					/* GPIO���� */	
	.port_num = 8,  //�����Ķ˿��������������õĶ˿ڶ�Ӧ����
	.port[0].enable = PORT_ENABLE,//�˿�ʹ��
	.port[0].num = VIN0,  //�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[0].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[0].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[1].enable = PORT_ENABLE,
	.port[1].num = VIN1,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[1].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[1].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;	
	.port[2].enable = PORT_ENABLE,
	.port[2].num = VIN2,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[2].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[2].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[3].enable = PORT_ENABLE,//�˿�ʹ��
	.port[3].num = VIN3,  //�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[3].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[3].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[4].enable = PORT_ENABLE,
	.port[4].num = VIN4,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[4].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[4].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;	
	.port[5].enable = PORT_ENABLE,
	.port[5].num = VIN5,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[5].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[5].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
    .port[6].enable = PORT_ENABLE,
	.port[6].num = VIN6,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[6].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[6].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
    .port[7].enable = PORT_ENABLE,
	.port[7].num = VIN7,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[7].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[7].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
};

/* ADоƬ���� */
tagAD24BIT_T AD4111_2 =
{
	.tSPI.tSPIHandle.Instance 		    = SPI3,		
    .tSPI.tGPIO[0].tGPIOInit.Pin 		= GPIO_PIN_3,				/* GPIO���� ,SPI3_SCK*/
	.tSPI.tGPIO[0].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tSPI.tGPIO[0].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tSPI.tGPIO[0].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tSPI.tGPIO[0].tGPIOPort 			= GPIOB,					/* GPIO���� */	
	.tSPI.tGPIO[1].tGPIOInit.Pin 		= GPIO_PIN_5,				/* GPIO���� ,SPI3_MOSI*/
	.tSPI.tGPIO[1].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tSPI.tGPIO[1].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tSPI.tGPIO[1].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tSPI.tGPIO[1].tGPIOPort 			= GPIOB,					/* GPIO���� */	
	.tSPI.tGPIO[2].tGPIOInit.Pin 		= GPIO_PIN_4,				/* GPIO���� ,SPI3_MISO*/
	.tSPI.tGPIO[2].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tSPI.tGPIO[2].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tSPI.tGPIO[2].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tSPI.tGPIO[2].tGPIOPort 			= GPIOB,					/* GPIO���� */		
    .tSPI.tGPIO[3].tGPIOInit.Pin 		= GPIO_PIN_7,				/* GPIO���� ,SPI3_CS*/
	.tSPI.tGPIO[3].tGPIOInit.Mode 		= GPIO_MODE_OUTPUT_PP,		/* GPIOģʽ */
	.tSPI.tGPIO[3].tGPIOInit.Pull 		= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tSPI.tGPIO[3].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tSPI.tGPIO[3].tGPIOPort 			= GPIOD,					/* GPIO���� */	
	.port_num = 8,  //�����Ķ˿��������������õĶ˿ڶ�Ӧ����
	.port[0].enable = PORT_ENABLE,//�˿�ʹ��
	.port[0].num = VIN0,  //�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[0].gain = 1.00193174,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[0].offset= 0.001524093,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[1].enable = PORT_ENABLE,
	.port[1].num = VIN1,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[1].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[1].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;	
	.port[2].enable = PORT_ENABLE,
	.port[2].num = VIN2,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[2].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[2].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[3].enable = PORT_ENABLE,//�˿�ʹ��
	.port[3].num = VIN3,  //�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[3].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[3].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[4].enable = PORT_ENABLE,
	.port[4].num = VIN4,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[4].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[4].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;	
	.port[5].enable = PORT_ENABLE,
	.port[5].num = VIN5,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[5].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[5].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
    .port[6].enable = PORT_ENABLE,
	.port[6].num = VIN6,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[6].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[6].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
    .port[7].enable = PORT_ENABLE,
	.port[7].num = VIN7,	//�ɼ��źŵ�,����ģʽ���źŵĵؽ�Vincom�˿�;���ģʽ���źŽӶ�Ӧ�˿�
	.port[7].gain = 1.0,  //У����������Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
	.port[7].offset= 0.0,//У������ƫ����Y =  gain*X+offset,������ҪУ����Ĭ��gain = 1.0,offset = 0.0;
};
