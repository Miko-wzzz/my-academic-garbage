#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

uint8_t ret;

void Task_UserInit(void)
{
	Drv_GPIO_Init(&LED, 3);   

    Drv_Uart_DMAInit(&Uart1);

    ret = OCD_AD24BIT_Init(&AD4111_1);/*24位AD初始化 */
	if (ret != 0)
	{
		printf("##AD1 init fail, error code:%d!!!\r\n",ret);
		while(1);  //程序报错stop	
	}
    printf("init complete\r\n");

	ret = OCD_AD24BIT_Init(&AD4111_2);/*24位AD初始化 */
	if (ret != 0)
	{
		printf("##AD2 init fail, error code:%d!!!\r\n",ret);
		while(1);  //程序报错stop	
	}

}
