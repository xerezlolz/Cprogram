#include<stdatomic.h>
#include<stdlib.h>

typedef struct Linkque{
    int data;
    struct linkque *node;
}Linkqueue, *Linkqueue_list;

typedef
