#include <stdio.h>

int main() {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    if (a>b&&a>c&&a>d&&a>e)
		printf("%d", a);
	if (b>a&&b>c&&b>d&&b>e)
	    printf("%d", b);
	if (c>a&&c>b&&c>d&&c>e)
	    printf("%d", c); 
    if (d>a&&d>b&&d>c&&d>e)
	    printf("%d", d);
	if (e>a&&e>b&&e>c&&e>d)
	    printf("%d", e);
	if(a==b&&a==c&&a==d&&a==e)
	   printf("%d",a);        
}

