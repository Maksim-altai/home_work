#include <stdio.h>

int main() {
    int a, max;
    scanf("%d",&a);
    int n1 = a/100;
    int n2 = (a-n1*100)/10;
    int n3 = (a-n1*100-n2*10);
    max = n1 > n2 ? n1 : n2;
    max = max> n3 ? max: n3;
    printf("%d",max);        
    return 0;
}

