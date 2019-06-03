#include<stdatomic.h>
#include<stdlib.h>

typedef struct linkque{
    int data;
    struct linkque *next;
}linkqueue, *linkqueue_list;


typedef struct {
    linkqueue_list front, rear;
}linkqueue_top;

