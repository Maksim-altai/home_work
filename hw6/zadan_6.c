#include <stdio.h>
#include <math.h>

int N =0;
unsigned long long summa = 0;

int zerna_v_kletke(int N)
{
    for ( int i = 0; i<N; i++)
       {
        summa = pow(2.0, i);
       }
       return summa;
}
int main(void)
{
    scanf("%d", &N);
    printf("%d\n", zerna_v_kletke(N));
    return 0;
}


