#include <stdio.h>
#include <stdlib.h>
typedef int data_int;

typedef struct linklist
{
    data_int data;
    struct linklist *next;

}sequence_link, *sequence_point;

//build new
sequence_point build()
{
    sequence_point tar;
    tar = (sequence_point)malloc(sizeof(sequence_link));
    if(tar == NULL)
    {
        printf("malloc fail.\n");
        exit(0);
    }
    tar->data = 5;
    tar->next = NULL;
    return tar;
}

//tail add
sequence_point addnew_tail(sequence_point src, int n)
{
    sequence_point r, p;
    r = src;
    int i;
    for (int i=0; i<n; i++)
    {
        p = (sequence_point)malloc(sizeof(sequence_link));
        p->data = 10;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return src;
}
