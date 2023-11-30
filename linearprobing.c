#include<stdio.h>

int linearProbing(int Table[],int ts, int x)
{
    int m=x%ts;
    int flag=1;
    if(Table[m]==0)
        Table[m]=x;
    else
    {
        flag=0;
        for(int i=1; i<ts; i++)
        {
            int newPos=(m+i)%ts;
            if(Table[newPos]==0)
            {
                Table[newPos]=x;
                flag=1;
                break;
            }
        }
    }
    return flag;
}


int main()
{
    int key ,ts=15;
    int n,x;
    int TableLP[15]={0};

    printf("Enter No of the element to store");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        linearProbing(TableLP,ts,x);
    }
    for(int i=0; i<=ts-1; i++)
    {
        printf("%d",i);
        printf("   ");
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("--------");
    }
    printf("\n");
    for(int i=0; i<=ts-1; i++)
    {
        printf("%d   ",TableLP[i]);

    }
    return 0;

}
