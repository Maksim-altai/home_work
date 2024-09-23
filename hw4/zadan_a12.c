#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    int n1 = a/100;
    int n2 = (a-n1*100)/10;
    int n3 = (a-n1*100-n2*10);
    printf("%d",n1+n2+n3);        
    return 0;
}
