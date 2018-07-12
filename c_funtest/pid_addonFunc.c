#include <stdio.h>

typedef struct {
    //PID定义系数
    float Kp, Ki, Kd;
    /**
     * Ek--当前误差ek
     * Ek1--前一次误差e(k-1)
     * Ek2--再前一次误差e(k-2)
     * 
    */
    float Ek, Ek1,Ek2;
}AddTypeDef;

/**
 * --------------------------------
 * 增量式PID--只和当前及前两次误差;
 * 参数:SetValue:设置值(预期值)
 *     ActualValue:实际值(反馈值)
 * --------------------------------
 *     Addint:PID增量返回值
 *     ps.最终返回值是增量值,在累积误差较大的情况下
 * 
*/
float Add_cout(float SetValue, float ActualValue, AddTypeDef *PID) {
    float Addint;  //反馈增量
    PID->Ek = SetValue - ActualValue; //误差计算
    Addint = PID->Kp * (PID->Ek1 - PID->Ek)+PID->Ki * PID->Ek + PID->Kd * (PID->Ek - 2 * PID->Ek1 + PID->Ek2);
    /**
     * 误差更新
    */
    PID->Ek1 = PID->Ek2;
    PID->Ek1 = PID->Ek;
    return Addint;
}