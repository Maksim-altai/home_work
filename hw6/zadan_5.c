#include <stdio.h>
int result = 0;
int N=0;  
int summa(int N)
{
   for(int i; i<=N; i++)
   {
       result = result + i;
    } 
    return result;
}
 
int main(void)
{
    scanf("%d", &N);
    printf("%d ", summa(N));
    return 0;
}


