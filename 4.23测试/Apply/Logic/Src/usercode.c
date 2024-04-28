#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/* 	demoGPIO[0] PD13 R
	demoGPIO[1] PD14 G
	demoGPIO[2] PD15 B
*/


	int temp_AD1, temp_AD2;
	double X1, Y1, Z1, X2, Y2, Z2, X3, Y3, Z3, X4, Y4, Z4;
	


/* 用户逻辑代码 */
void UserLogic_Code(void)
{
    printf("SGA_DEMO\r\n");


	while(1)
	{

		temp_AD2  = OCD_AD24bit_GetResult(&AD4111_2, 200);
		if(temp_AD2!=0)
		{
	    	DBG_ERROR("OCD_AD24bit_GetResult error：%d\r\n",temp_AD2);
		}
		X1 = AD4111_2.port[0].result * 10000;
		Y1 = AD4111_2.port[1].result * 10000;
		Z1 = AD4111_2.port[4].result * 10000;
		X2 = AD4111_2.port[5].result;
		Y2 = AD4111_2.port[6].result;
		Z2 = AD4111_2.port[7].result;

		temp_AD1  = OCD_AD24bit_GetResult(&AD4111_1, 200);
		if(temp_AD1!=0)
		{
	    	DBG_ERROR("OCD_AD24bit_GetResult error：%d\r\n",temp_AD1);
		}
		X3 = AD4111_1.port[0].result;
		Y3 = AD4111_1.port[1].result;
		Z3 = AD4111_1.port[4].result;
		X4 = AD4111_1.port[5].result;
		Y4 = AD4111_1.port[6].result;
		Z4 = AD4111_1.port[7].result;

		printf("X1 = %f, Y1 = %f, Z1 = %f\r\n", X1, Y1, Z1);
		// printf("X2 = %f, Y2 = %f, Z2 = %f\r\n", X2, Y2, Z2);
		// printf("X3 = %f, Y3 = %f, Z3 = %f\r\n", X3, Y3, Z3);
		// printf("X4 = %f, Y4 = %f, Z4 = %f\r\n", X4, Y4, Z4);


	}
}
