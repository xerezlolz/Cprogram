#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INIT 1

//创建节点
typedef struct DulCom
{
    char name[10]; //姓名
    char sex[4];  //性别
    char phone_number[12];  //电话
    char note;  //备注
    struct DulCom *next;
}DulCommu, *DulList;

//创建界面
void window(){
    printf("\\*************************************************\\\n");
    printf("1.显示全部联系人信息\n");
    printf("2.清空联系人信息\n");
    printf("3.插入新联系人\n");
    printf("4.查找联系人(按 姓名/电话)\n");
    printf("5.删除联系人信息(按 姓名/电话)\n");
    printf("6.筛选联系人-性别\n");
    printf("7.按0退出\n");
    printf("\\*************************************************\\\n");
}

//创建空表
DulList creat_comm(){
    DulList p;
    if(NULL== (p = (DulList)malloc(sizeof(struct DulCom)))){
        printf("creat new infomation form error\n");
        exit(0);
    }
    p->next = NULL;
    return p;
}

//初始化,头插
DulList init_comm(DulList l,int n){
    //char nm[10], sx[4];
    int i, num;
    DulList a;
    for (i=0; i< INIT; i++){
        a = (DulList)malloc(sizeof(DulCommu));
        printf("\\==============================\\\n");
        printf("输入第%d个初始联系人:\n", i+1);
        printf("==============================\n");
        printf("第%d个联系人-姓名:\n", i+1);
        scanf("%s", a->name);
        printf("==============================\n");
        printf("第%d个联系人-电话:\n", i+1);
        scanf("%s", a->phone_number);
        printf("==============================\n");
        printf("第%d个联系人-性别:\n", i+1);
        scanf("%s",a->sex);
        printf("\n");

        a->next = l->next;
        l->next = a;
    }
    return l;
}
void print_comm(DulList p){
    int i = 1;
    DulList s;
    s = p->next;
    printf("==============================\n");
    while (s)
    {
        printf("第%d个初始联系人:\n", i);
        /*printf("姓名:%c\n", while (s->name[x] != '\0') {
            s->name[x];
            x++;
        });*/

        printf("姓名:%s\n", s->name);
        printf("性别:%s\n", s->sex);
        printf("电话:%s\n", s->phone_number);
        printf("==============================\n");
        s = s->next;
        i++;
    }
    getchar();
}


int main(int argc, const char *argv[]) {
    DulList source1;
    source1 = creat_comm();
    source1 = init_comm(source1, INIT);
    print_comm(source1);
    getchar();
    return 0;
}