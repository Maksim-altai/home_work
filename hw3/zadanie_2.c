#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int sum = a + b + c;
    int proizvedenie = a*b*c;
    printf("%d+%d+%d=%d\n",a,b,c,sum );
    printf("              %d*%d*%d=%d\n",a,b,c,proizvedenie );
    return 0;
}

