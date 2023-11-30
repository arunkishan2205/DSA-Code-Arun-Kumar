#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* next;
};
struct node * Start;
struct node* getnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
void freeNode(struct node* temp)
{
    free(temp);
    printf("\nmemory free\n");
}

void insetEnd(int x)
{
    struct node* p,*Q;
    Q=getnode();
    p=Start;
    while (p->next)
    {
        p=p->next;
    }
    p->next=Q;
    Q->info=x;
    Q->next=NULL;

}
int count()
{
    int count=0;
    struct node* p;
    p=Start;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;


}
void reverse()
{
    struct node *p=NULL;
    struct node *c=Start;
    struct node *n=Start->next;
    while(c)
    {
        c->next=p;
        p=c;
        c=n;
        if(n)
            n=n->next;
    }
    Start=p;


}
void traverse()
{
    struct  node *temp=Start;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
    printf("\n");
}

void count_even_odd()
{
    int counte=0,counto=0;
    struct node* p;
    p=Start;
    while(p!=NULL)
    {
        if(p->info%2==0)
            counte++;
        else
            counto++;
        p=p->next;
    }
    printf("\nodd : %d",counto);
    printf("\neven : %d",counte);



}
void  insert_beginnig(int x)
{
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=Start;
    Start=p;
}
void  delete_beginning()
{
    struct node* temp;
    int x;
    if(Start==NULL)
    {
        printf("\n void deletion");
    }
    else
    {
        temp=Start;
        Start=Start->next;
        x=temp->info;
        freeNode(temp);
        printf("\n deleted node is %d\n",x);
    }

}
void detete_end()
{
    struct node* temp,*del;
    int x=-1;
    if(Start== NULL)
        printf("\n void detetion");
    else
        del=Start;
        temp=NULL;
        while(del->next)
        {
            temp=del;
            del=del->next;
        }
        if(temp!=NULL)
            temp->next=NULL;
        else
        {
            Start=NULL;
        }
        x=del->info;
        freeNode(del);
        printf("\n deleted node is %d\n",x);

}
void insert_any(int x,int pos)
{

    struct node* temp,*insert;
    temp->info=x;
    if(!Start)
    {
        Start=insert;
        temp->next=NULL;
    }
    else
    {
        struct node* prev,*after;
        prev=NULL;
        after=Start;
        if(pos>count())
            printf("not valid position");
        while(pos--)
        {
            prev=after;
            after=after->next;
        }
        insert->next=after;
        prev->next=insert;




    }




}
int find_middle()
{
    struct node* mid,*end;
    mid=Start;
    end=Start->next;
    while(end && end->next)
    {
        mid=mid->next;
        end=end->next->next;
    }
    return mid->info;
}
int main()
{
    Start=NULL;
    insert_beginnig(200);
    insert_beginnig(300);
    insert_beginnig(500);
    insert_beginnig(600);
    insetEnd(77);
    traverse();
    // insert_any(44,1);
    traverse();
    reverse();
    traverse();
    // printf("%d",mid);
    return 0;
}
