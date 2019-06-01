#include<stdatomic.h>
#include<stdlib.h>

typedef struct Linkque{
    int data;
    struct linkque *next;
}Linkqueue, *Linkqueue_list;

typedef struct {
    Linkqueue_list front, rear;
}Linkqueue_top;

