#include <stdio.h>
int result = 0;
int a=1; 
int b, maximum = 0; 
int function(int x)
{
    if (x >= -2 && x < 2)
        result = x*x;
    if (x >= 2)
        result = x*x+4*x+5;
    if (x < -2)
        result = 4;
    return result;
}
 
int main(void)
{
    while (a != 0)
    {
        scanf("%d", &a);
        b = function(a);
        if (b > maximum)
            maximum = b;
    }
    printf("%d ", maximum);
    return 0;
}


