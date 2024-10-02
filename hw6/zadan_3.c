#include <stdio.h>

int rezult = 0;
int middle(int a, int b);

 int middle (int a, int b)
 {
     rezult = (a+b)/2;
     return rezult;
     }
int main() {
    int a,b;
    scanf("%d %d", &a,&b);
    printf("%d", middle(a,b));
    return 0;
}

