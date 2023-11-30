#include<stdio.h>
#include<stdio.h>

int DoubleHash(int Table[],int ts, int x)
{
    int h=x%ts;
    int flag=1;
    if(Table[h]==0)
        Table[h]=x;
    else
    {
        flag=0;
        int hdash=(2*x-7)%ts;
        int i=1;
        while(!flag)
        {
            int newPos=(h+i*hdash)%ts;
            i++;
            if(Table[newPos]==0)
            {
                Table[newPos]=x;
                flag=1;
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
        DoubleHash(TableLP,ts,x);
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
