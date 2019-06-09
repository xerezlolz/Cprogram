#include<stdio.h>
#include<stdlib.h>
#define BALL 28
#define HOUR 12
#define QUART 12
#define MINUTE 5
#define OK 1
#define ERROR 0

//小球队列
typedef struct ball_queue
{
    int ball_data[BALL];  //27个球,28个位置
    int front, rear;
}ball;

/**
 * 时间栈
 * 1h_逢12清空,12个回到ball_queue;
 * 5min_逢12进1,1个进到1h栈,剩余11个回到ball_queue;
 * 1min_逢5进1,1个进到5min栈,剩下4个回到ball_queue;
 * 
*/
typedef struct time_stack
{
    int *time_data; 
    int hour_top;
    int time_max;
}time;

//创建空表
time *creat_empty_stack(int length)
{
    time *stack;
    if(NULL == (stack = (time *)malloc(sizeof(time))))  //void *malloc()
    {
        printf("creat empty stack error.\n");
        exit(0);
    }
    stack->hour_top = -1;
    stack->time_data = (int *)malloc(sizeof(time)*length);
    stack->time_max = length;
    return stack;
}

//初始化_小球队列
ball *init_ballqueue()
{
    ball *init_ball;
    if (NULL == (init_ball = (ball*)malloc(sizeof(ball))))
    {
        printf("creat ball_queue error.\n");
        return NULL;
    }
    init_ball->front = 0;
    init_ball->rear = 0;
    return init_ball;
}

/**
 * 运行逻辑
 * h-hour:逢12,执行清空;
 * fmin-five_min:逢12,执行 进1到hour,剩下11个返回ball_queue;
 * omin-one_min:逢5,执行 进1到five_min,剩下4个返回ball_queue;
 * 
*/
time clock_running_logic(time *h, time *fmin, time *omin)
{
    

}

//清空


//进位


int main(int argc, const char* argvs[])
{
    time *hour, *five_min, *one_min;
    //创建时间栈
    hour = creat_empty_stack(12);
    five_min = creat_empty_stack(12);
    one_min = creat_empty_stack(5);
    while (1)
    {
        int one_min_count, five_min_count, hour_count;
        //当one_min为5时进1
        clock_running_logic(hour, five_min, one_min);
    }
    
    return 0;
}