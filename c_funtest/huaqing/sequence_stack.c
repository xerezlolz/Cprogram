#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

/**
 * 栈-顺序结构
 * 
 */

typedef int data_t;
typedef struct
{
    data_t data[MAXSIZE];
    int top; //栈顶元素所在的数组下标位置
} SqStack;

int PushStack(SqStack *s, data_t e) //压栈
{
    if (s->top == MAXSIZE - 1)
    {
        printf("Stack is Full\n");
        return ERROR;
    }
    s->top++;
    s->data[s->top] = e;
    return OK;
}

int PopStack(SqStack *s, data_t *e) //弹栈
{
    if (s->top == -1)
    {
        printf("Stack is Empty\n");
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;
    return OK;
}
SqStack *CreateEmptyStack() //创建栈
{
    SqStack *stack = (SqStack *)malloc(sizeof(SqStack));
    if (stack == NULL)
    {
        printf("CreateEmptyStack Error\n");
        exit(0);
    }
    stack->top = -1;
    return stack;
}
int EmptyStack(SqStack *s) //判断栈是否是空栈
{
    return -1 == s->top ? OK : ERROR;
}
int FullStack(SqStack *s) //判断栈是否是满栈
{
    return MAXSIZE - 1 == s->top ? OK : ERROR;
}
int ClearStack(SqStack *s) //清空栈内元素
{
    s->top = -1;
    return OK;
}
int main()
{
    /*
    SqStack *stack = CreateEmptyStack();
    data_t data;
    PushStack(stack,20);
    PushStack(stack,30);
    PopStack(stack,&data);
    printf("pop:%d\n",data);
    PopStack(stack,&data);
    printf("pop:%d\n",data);
    PopStack(stack,&data);
    printf("pop:%d\n",data);
    if(EmptyStack(stack)==OK)
        printf("Stack is Empty!\n");
    if(FullStack(stack)==OK)
        printf("Stack is Full!\n");
	*/
    return 0;
}
