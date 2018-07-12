#include <stdio.h>

//位置式PID计算
typedef struct {
    float Kp, Ki, Kd; //定义pid系数变量
    float Ek, Ek1; //Ek--误差,Ek1--之前一次的误差
    float loksum;  //累积积分location
}PID_LockTypeDef;

/**
 * ---------------------------------
 *  PID_Loc:位置式PID计算
 *  参数:SetValue--设置值(预期量);
 *      ActualValue--实际值(反馈量);
 *      PIDLoc--pid位置(返回值);
 * ---------------------------------
 *  遗留问题:位置计算的累积误差不断增大,在debug时容易出现超调量,可以尝试Nichols方法整定pid参数
 * ref:http://dictionary.sensagent.com/%E9%BD%90%E6%A0%BC%E5%8B%92%EF%BC%8D%E5%B0%BC%E7%A7%91%E5%B0%94%E6%96%AF%E6%96%B9%E6%B3%95/zh-zh/
 * 
 */
float PID_Loc(float SetValue,float ActualValue, PID_LockTypeDef *PID){
    float PIDLoc; //位置
    PID->Ek = SetValue - ActualValue;
    PID->loksum += PID->Ek;
    PIDLoc = PID->Kp * PID->Ek + (PID->Ki * PID->loksum) + PID->Kd * (PID->Ek1 - PID->Ek);
    PID->Ek1 = PID->Ek;
    return PIDLoc;
}