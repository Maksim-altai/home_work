#include <stdio.h>
#include <math.h>

int rezult = 0;
int power(int n, int p);

 int power (int n, int p)
 {
     rezult = pow(n, p);
     return rezult;
     }
int main() {
    int n,p;
    scanf("%d %d", &n,&p);
    if(abs(n)<1000 && p>=0){
    printf("%d", power(n,p));
}
    return 0;
}

