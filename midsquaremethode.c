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

int midsquareHash(long long key, int ts)
{
    int d=digitcount(ts-1);
    int l=digitcount(key);
    int k=(2*l-d)/2;
    int e=power(10,k);
    key=(key*key)/e;
    int mod=power(10,d);
    // printf("%d %d %d %d %d %lld",d,l,k,e,mod ,key);
    return key%mod;
}
int main()
{
    // int x=digitcount(1);
    int x=midsquareHash(1234,100);
    int  y=midsquareHash(4565,100);
    printf("%d  %d",x,y);
    return 0;
}
