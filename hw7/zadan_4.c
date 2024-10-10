#include <stdio.h>

void recurs(int i, int a)
{
    if (i >= a)
    {
        printf("%d ", i);
        if (i > a)
            recurs(i - 1,a);
    }
    else
    if (i < a)
    {
        if (i < a)
            recurs(i ,a - 1);
        printf("%d ", a);
    }
}


int main(int argc, char** argv)
{
    int resi, resa;
    scanf("%d%d", &resi, &resa);
    recurs(resi, resa);
    return 0;
}






