#include <stdio.h>

int main() {
int a,b, n, summa= 0;
scanf ("%d %d", &a, &b);
int q = b - a;
for(int i = 0; i<= q; i++)
 {
	n = a*a;
	summa=summa+n;
    a++;
 }
printf("%d ", summa);
}


