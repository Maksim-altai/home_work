#include <stdio.h>
int a = 0;
int recurs(int i)
{ 
   
    if (i > 1)
        recurs(i / 2);
    return a += i % 2;
}


int main(int argc, char** argv)
{
    int res;
    scanf("%d", &res);
    printf("%d ", recurs(res));
    return 0;
}







