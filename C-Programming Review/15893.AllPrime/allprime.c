#include <stdio.h>

int isPrime(int N)
{
    int on_off = 1;
    int div = 2; // 나누는 수

    while (on_off == 1)
    {
        if(N % div == 0)
        {
            on_off = 0;
        }

        div += 1;
    }

    if (on_off == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int max;
    int num = 2;

    scanf("%d", &max);

    for(; num <= max; num++)
    {
        int a;
        a = isPrime(num);
        if ( a == 1 );
        {
            printf("%d ", num);
        }
    }

    printf("\n");

    return 0;
}
