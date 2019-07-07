#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
typedef int data_t;

typedef struct
{
    data_t data[MAXSIZE]; //定长情况下
    //data_t *data;//变长情况下
    int length; //表长
} SqList;

SqList *CreateEmptySqList() //定长
{
    SqList *sq;
    if (NULL == (sq = (SqList *)malloc(sizeof(SqList))))
    {
        printf("CreateEmptySqList Error\n");
        exit(0);
    }
    sq->length = 0;
    return sq;
}

int GetElem(SqList *L, int i, data_t *e) //获得顺序表第i个位置的元素
{
    if (i >= L->length && i < 0)
    {
        perror("No this Element");
        return ERROR;
    }
    *e = L->data[i];
    return OK;
}
int ListInsert(SqList *L, int i, data_t e) //在线性表的第i个位置插入元素e
{
    int k;
    if (L->length == MAXSIZE) //线性表已满
    {
        printf("SqList is Full\n");
        return ERROR;
    }
    if (i < 0 || i > L->length) //i不在线性表的范围内
    {
        printf("Position Error\n");
        return ERROR;
    }
    if (i < L->length) //若插入位置不在表尾
    {
        for (k = L->length - 1; k >= i; k--) //当前位置开始到表尾所有元素向后移动1格
            L->data[k + 1] = L->data[k];
    }
    L->data[i] = e; //插入新元素
    L->length++;
    return OK;
}
int ListDelete(SqList *L, int i, data_t *e) //删除线性表的第i个位置元素，并用e得到删除的值
{
    int k;
    if (L->length == 0) //线性表为空
    {
        printf("SqList is Empty\n");
        return ERROR;
    }
    if (i < 0 || i >= L->length) //i不在线性表的范围内
    {
        printf("Position Error\n");
        return ERROR;
    }
    *e = L->data[i];       //取走元素
    if (i < L->length - 1) //若删除位置不在表尾
    {
        for (k = i; k < L->length - 1; k++)
            L->data[k] = L->data[k + 1];
    }
    L->length--;
    return OK;
}
int PrintList(SqList *L) //遍历打印整个顺序表
{
    int k;
    data_t temp = 0;
    if (L->length == 0)
    {
        printf("线性表为空！\n");
        return ERROR;
    }
    for (k = 0; k < L->length; k++)
    {
        GetElem(L, k, &temp);
        printf("%d\t", temp);
    }
    printf("\n");
    return OK;
}
int main()
{
    int i;
    data_t data;
    SqList *sq = CreateEmptySqList();
    for (i = 0; i < 5; i++)
    {
        sq->data[sq->length] = i;
        sq->length++;
    }
    if (GetElem(sq, 3, &data) == OK)
    {
        printf("data is %d\n", data);
    }
    PrintList(sq);
    ListInsert(sq, 2, 20);
    PrintList(sq);
    ListDelete(sq, 2, &data);
    PrintList(sq);
    return 0;
}
