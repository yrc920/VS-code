#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char name[20];
    long num;
    struct student *next;      
}*head;
int n;

int judge1()//判断学号是否有重复
{
    struct student *p1,*p2;
    p1=head;
    for(int i=n;i>0;i--)
    {
        p2=p1->next;
        for(int j=i-1;j>0;j--)
        {
            if(p1->num==p2->num)
            {
                printf("输入的数据有重复\n");
                return 0;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    return 1;
}
int judge2(long a)//判断学号是否有重复
{
    struct student *p;
    p=head;
    for(int i=0;i<n;i++)
    {
        if(p->num==a)
        {
            printf("输入的数据有重复\n");
            return 0;
        }
        p=p->next;
    }
    return 1;
}
void found()//创建学生表
{
    struct student *p1,*p2;
    p1=p2=(struct student*)malloc(sizeof(struct student));
    n=0;
    printf("请输入学生姓名 学号\n");
    int b1=0,b2=0;
    while(b1==0||b2==0)
    {
        b1=scanf("%s",p1->name);
        if(p1->name[0]=='0')
        {
            free(p1);
            return ;
        }
        for(int i=0;i<strlen(p1->name);i++)
        {
            if(p1->name[i]>'0' && p1->name[i]<='z')
            {
                b1=0;
                break;
            }
        }
        b2=scanf("%ld",&p1->num);
        if(b1==0||b2==0)
        {
            while(getchar()!='\n');//清空缓冲区
            printf("请输入正确的姓名和学号\n");
        }
    }
    head=NULL;
    while(p1->num!=0)
    {
        n++;
        if(n==1) head=p1;
        else p2->next=p1;
        p2=p1;
        if(judge1()==0)
        {
            n--;
            free(p1);
            p1=(struct student*)malloc(sizeof(struct student));
            int c1=0,c2=0;
            while(c1==0||c2==0)
            {
                c1=scanf("%s",p1->name);
                if(p1->name[0]=='0')
                {
                    free(p1);
                    p2->next=NULL;
                    return ;
                }
                for(int i=0;i<strlen(p1->name);i++)
                {
                    if(p1->name[i]>'0' && p1->name[i]<='z')
                    {
                        c1=0;
                        break;
                    }
                }
                c2=scanf("%ld",&p1->num);
                if(c1==0||c2==0)
                {
                    while(getchar()!='\n');//清空缓冲区
                    printf("请输入正确的姓名和学号\n");
                }
            }
            continue;
        }
        p1=(struct student*)malloc(sizeof(struct student));
        int c1=0,c2=0;
        while(c1==0||c2==0)
        {
            c1=scanf("%s",p1->name);
            if(p1->name[0]=='0')
            {
                free(p1);
                p2->next=NULL;
                return ;
            }
            for(int i=0;i<strlen(p1->name);i++)
            {
                if(p1->name[i]>'0' && p1->name[i]<='z')
                {
                    c1=0;
                    break;
                }
            }
            c2=scanf("%ld",&p1->num);
            if(c1==0||c2==0)
            {
                while(getchar()!='\n');//清空缓冲区
                printf("请输入正确的姓名和学号\n");
            }
        }
    }
    p2->next=NULL;
    free(p1);
}
void insert()//插入学生数据
{
    struct student *p0,*p1,*p2;
    int b=0,c=0;
    p1=head;
    p2=(struct student*)malloc(sizeof(struct student));
    printf("请输入插入学生的姓名 学号\n");
    while(b==0||c==0)
    {
        b=scanf("%s",p2->name);
        for(int i=0;i<strlen(p2->name);i++)
        {
            if(p2->name[i]>='0' && p2->name[i]<='z')
            {
                b=0;
                break;
            }
        }
        c=scanf("%ld",&p2->num);
        c=judge2(p2->num);
        if(b==0||c==0)
        {
            while(getchar()!='\n');//清空缓冲区
            printf("请输入正确的姓名和学号\n");
        }
    }
    while(p1&&p2->num>p1->num)
    {
        p0=p1;
        p1=p1->next;
    }
    if(p1==head)
    {
        p2->next=head;
        head=p2;
    }
    else
    {
        p2->next=p0->next;
        p0->next=p2;
    }
    n++;
}
void del()//删除学生数据
{
    struct student *p1,*p2;
    long num;
    if(head==NULL)
    {
        printf("表中暂无数据\n");
        return;
    }
    printf("请输入要删除的学生学号\n");
    int b=0;
    while(!b){
        b=scanf("%ld",&num);
        if(b==0)
        {
            while(getchar()!='\n');//清空缓冲区
            printf("请输入正确的数字\n");
        }
    }
    p1=head;
    while(num!=p1->num&&p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(num==p1->num)
    {
        if(p1==head) head=p1->next;
        else p2->next=p1->next;
        printf("删除的学生姓名%s 学号%ld\n",p1->name,p1->num);
        free(p1);
        n--;
    }
    else printf("没有此学生\n");
}
void output()//对整个链表的输出
{
    struct student *p;
    printf("姓名\t学号\n");
    p=head;
    if(head==NULL)
    {
        printf("表中暂无数据\n");
        return;
    }
    else
    {
        do
        {
            printf("%s\t%ld\n",p->name,p->num);
            p=p->next;
        }while(p!=NULL);
    }
}
void count()//对学生个数的统计
{
    printf("学生个数为%d\n",n);
}
void sort1()//按姓名排序
{
    if(head==NULL||head->next==NULL) return;
    struct student p;//设置哨兵
    p.next=NULL;
    struct student *p1=head;
    while(p1!=NULL)
    {
        struct student *p2=p1->next;
        struct student *p3=&p;
        struct student *p4=p.next;
        while(p4!=NULL&&strcmp(p4->name,p1->name)<0)
        {
            p3=p4;
            p4=p4->next;
        }
        p3->next=p1;
        p1->next=p4;
        p1=p2;
    }
    printf("完成\n");
    head=p.next;
}
void sort2()//按学号排序
{
    if(head == NULL || head->next == NULL) return;
    struct student *p;
    p=(struct student *)malloc(sizeof(struct student));
    p->next=head;//设置哨兵
    int change;//判断是否有交换
    struct student *p1=NULL;
    do {
        change=0;
        struct student *p2=p;
        struct student *p3=p->next;
        while (p3->next!=p1)
        {
            struct student *p4=p3->next;
            if(p3->num>p4->num)
            {
                p2->next=p4;
                p3->next=p4->next;
                p4->next=p3;
                change=1;
                p2=p4;
            }
            else
            {
                p2=p3;
                p3=p3->next;
            }
        }
        p1=p3;
    }while(change);
    head=p->next;
    free(p);
    printf("完成\n");
}
void find1()//按姓名查找
{
    char b[20];
    struct student *p;
    p=head;
    printf("请输入要查找的学生姓名\n");
    int b1=0;
    while(b1==0)
    {
        b1=scanf("%s",b);
        for(int i=0;i<strlen(b);i++)
        {
            if(b[i]>'0' && b[i]<'z')
            {
                b1=0;
                break;
            }
        }
        if(b1==0)
        {
            while(getchar()!='\n');//清空缓冲区
            printf("请输入正确的姓名\n");
        }
    }
    for(int i=0;i<n;i++)
    {
        if(strcmp(p->name,b)==0)
        {
            printf("姓名\t学号\n");
            printf("%s\t%ld\n",p->name,p->num);
            return;
        }
        p=p->next;
    }
    printf("没有此学生\n");
}
void find2()//按学号查找
{
    long num;
    struct student *p;
    p=head;
    printf("请输入要查找的学生学号\n");
    int b=0;
    while(b==0)
    {
        b=scanf("%ld",&num);
        if(b==0)
        {
            while(getchar()!='\n');//清空缓冲区
            printf("请输入正确的学号\n");
        }
    }
    for(int i=0;i<n;i++)
    {
        if(p->num==num)
        {
            printf("姓名\t学号\n");
            printf("%s\t%ld\n",p->name,p->num);
            return;
        }
        p=p->next;
    }
    printf("没有此学生\n");
}

