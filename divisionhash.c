#include<stdio.h>
#include<math.h>

int nearest_prime(int n)
{
    for(int i=n; i>=2; i--)
    {
        int j;
        for(j=2; j<=sqrt(i); j++)
        {
            if(i%j==0)
                break;
        }
        if(j>sqrt(i))
            return i;
    }
    return 0;
}


int DivisionHash(int key, int ts)
{
    int np=0;
    int l=0;
    np=nearest_prime(ts);
    l=key%np;
    return l;
}


int main()
{
    int x=DivisionHash(1234,100);
    int y=DivisionHash(2335,100);
    printf("%d",y);

    return 0;
}
