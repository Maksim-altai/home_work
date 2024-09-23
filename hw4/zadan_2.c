#include <stdio.h>

int main() {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if (a>b&&a>c&&a>d&&a>e)
		printf("%d", a);
    if (b>a&&b>c)
	        printf("%d", b);
    if (c>a&&c>b)
	        printf("%d", c); 

    if(a==b&&a==c)
	        printf("%d",a);        
}

