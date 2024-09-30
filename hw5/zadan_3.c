#include <stdio.h>

int main() 
{
    int a, proverka1 = 0;
    scanf("%d",&a);
    proverka1 = 999 - a; 
    if(proverka1 > 0 && a>=100)
     {
	  printf("YES");
	 }
     else 
      {
	   printf("NO");
	   }       
    return 0;
}


