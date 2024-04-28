#ifndef __CONFIG_H_
#define __CONFIG_H_

#include "drv_hal_conf.h"
#include "ocd_conf.h"
#include "algo_conf.h"
#include "dev_conf.h"

/* 用户句柄声明包含区 */

extern tagGPIO_T LED[];

extern tagUART_T Uart1;

extern tagAD24BIT_T AD4111_1;
extern tagAD24BIT_T AD4111_2;

#endif
