/*****************************************************************
** �ļ���: user-timer.c
** Copyright (c) 2020 zucker-chen
 
** ������: 
** ��  ��: 
** ��  ��: ��ʱ��
** ��  ��: V1.0

** �޸���:
** ��  ��:
** �޸�����:
** ��  ��: 
******************************************************************/

/*****************************************************************
* ����ͷ�ļ�
******************************************************************/
#include <linux/module.h>
#include <linux/types.h>
#include <linux/init.h>
#include "utimer.h"



static usr_timer_t utimer;
static int utimer_demo_handle(void *param)
{

    printk("%s - - - \n", __FUNCTION__);
    //utimer_restart(&utimer, 1000000);
    
    return 0;
}

static int utimer_demo_init(void)
{
    utimer.type = USER_TIMER_HIGH;
    utimer.function = utimer_demo_handle;
    utimer.data = (void *)&utimer;
    utimer_init(&utimer);
    
    utimer_start(&utimer, 1000000);

    return 0;
}

static int utimer_demo_deinit(void)
{
    return utimer_destory(&utimer);
}


static int __init utimer_mod_init(void)
{
    printk("%s - hello - \n", __FUNCTION__);
    utimer_demo_init();
	
    printk("%s - utimer_usleep 5s start - \n", __FUNCTION__);
	utimer_usleep(5000000);
    printk("%s - utimer_usleep 5s end - \n", __FUNCTION__);
    
    return 0;
}

static void __exit utimer_mod_exit(void)
{
    utimer_demo_deinit();
    printk("%s - bye - \n", __FUNCTION__);
}


MODULE_AUTHOR("zucker-chen <timeontheway@163.com>");
MODULE_DESCRIPTION("user timer");
MODULE_LICENSE("GPL");

module_init(utimer_mod_init);
module_exit(utimer_mod_exit);




