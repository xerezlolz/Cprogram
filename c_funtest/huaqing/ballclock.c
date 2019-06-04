#include<stdio.h>
#include<stdlib.h>
#define BALL 28
#define HOUR 12
#define QUART 12
#define MINUTE 5
#define OK 1
#define ERROR 0

//小球队列
struct ball
{
    int ball_data[BALL];  //逢12进1
    int front, rear;
}ball_queue;

/**
 * 栈_1小时
 * 逢12清空,回到ball_queue
*/
struct hour_stack
{
    int hour_data[HOUR]; 
    int hour_top;
}hour;

/**
 * 栈_1小时
 * 逢12进1,1进hour,11回ball_queue
*/
struct five_min_stack
{
    int five_min_data[HOUR];
    int five_min_top;
} five_min;

/**
 * 栈_1min
 * 到5进1,
 * 1进栈,11回队列
*/
struct one_time
{
    int one_time_data[MINUTE];
    int one_time_top;
}one_time_stack;