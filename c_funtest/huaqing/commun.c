#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INIT 2

//创建节点
typedef struct DulCom
{
    char name[10]; //姓名
    char sex[4];  //性别
    char phone_number[12];  //电话
    char note;  //备注
    struct DulCom *next;
}DulCommu, *DulList;

//创建交互界面
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

//初始化,尾插
DulList init_comm(DulList l,int n){
    //char nm[10], sx[4];
    int i;
    DulList a, last;
    last = l;
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

        last->next = a;
        last = a;
        /*
        a->next = l->next;
        l->next = a;
        */
    }
    last->next = NULL;
    return l;
}

//输出通讯录
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

//清空通讯录
DulList clear_comm(DulList l){
    DulList cast,p;
    p = l->next;
    while (p)
    {
        cast = p->next;
        free(p);
        p = cast;
    }
    l->next = NULL;
    return l;
}


int main(int argc, const char *argv[]) {
    DulList source1;
    source1 = creat_comm();
    source1 = init_comm(source1, INIT);
    print_comm(source1);
    getchar();

    /**
     * 交互逻辑: 输入
     * 1.显示全部联系人信息;
     * 2.清空联系人信息;
     * 3.插入新联系人;
     * 4.查找联系人(按 姓名/电话);
     * 5.删除联系人信息(按 姓名/电话);
     * 6.筛选联系人-性别;
     * 7.按0退出;
    */
    return 0;
}