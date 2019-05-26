#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INIT 3
#define OK 1

typedef struct DulCom{  //创建节点
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

//创建空表头
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

//打印通讯录
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
}

DulList clear_comm(DulList l){  //清空通讯录
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

//新增联系人,在i位置
int add_comm(DulList l, int i){
    DulList p, t;
    int j = 1;
    p = l;
    while (p && j<i){
        p = p->next;
        j++;
    }
    if(!p){
        printf("%d position error.\n", i);
    }
    t = (DulList)malloc(sizeof(DulCommu));
    printf("新增联系人信息\n");
    printf("=========================\n");
    printf("姓名：\n");
    scanf("%s", t->name);
    printf("电话：\n");
    scanf("%s", t->phone_number);
    printf("性别：\n");
    scanf("%s", t->sex);

    t->next = p->next;
    p->next = t;
    return OK;
}

//查找联系人-电话/姓名
void find_comm(DulList l, char *data){
    DulList check, p;
    p = l;
    char input[15];
    printf("查询信息:\n");
    scanf("%s", input);
    check = p;
    while (p){
        if ((strcmp(check->name, input) == 0) || (strcmp(check->phone_number, input) == 0))
        {
            printf("查到信息:\n");
            printf("姓名:%s\n", check->name);
            printf("性别:%s\n", check->sex);
            printf("电话:%s\n", check->phone_number);
            break;
        }
        else{
            printf("查不到信息:\n");
            check = check->next;
            p = check;
        }
    }
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