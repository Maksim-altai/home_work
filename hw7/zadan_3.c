#include <stdio.h>

void recurs(int i)
{ 
    int a = 0;
    if (i)
    {
        a = i % 10;
        i /= 10;
        recurs(i);
        printf("%d ", a);
    }
}
int main(int argc, char** argv)
{
    int res;
    scanf("%d", &res);
    if (!res)
    {
        printf("%d ", res);
        return 0;
    }
    recurs(res);
    return 0;
}





