 #include<stdio.h>
int digitcount(long long n)
{
    int count=0;
    while(n)
    {
        count++;
        n=n/10;
    }
    return count;
}

long long power(int p, int n)
{
    if(n==0)
        return 1;
    long long po;
    po=power(p,n/2);
    if(n%2==0)
        return ((long long)po*po);
    else
        return ((long long)po*po*p);
}

int foldingHash(long long key, int ts)
{
    int d=digitcount(ts-1);
    int p=power(10,d);
    int s=0;
    while(key)
    {
        s=s+(key%p);
        key=key/p;
    }
    return s%ts;
}
int main()
{
    int x=foldingHash(1234,100);
    int y=foldingHash(4565,100);
    printf("%d %d",x,y);
    return 0;
}
