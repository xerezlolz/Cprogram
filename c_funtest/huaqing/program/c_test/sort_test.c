#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct sort
{
    int *a;
    int que[MAX];
    struct sort *node;
    int length;
}sort_demo, *sort_link;

int swap(sort_link list, int i, int j)
{
    int temp = list->que[i];
    list->que[i] = list->que[j];
    list->que[j] = temp;
}