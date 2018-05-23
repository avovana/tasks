#include <stdio.h>

int main()
{
    unsigned long long int n, i, sum, a, b;
    while(scanf("%lld", &n)==1)
    {
        a=4, b=6;
        if(n==1||n==2)
            sum=2;
        else if(n==3)
            sum=4;
        else if(n==4)
            sum=6;
        else
        {
            for(i=5; i<=n; i++)
            {
                sum=a+b;
                a=b;
                b=sum;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}