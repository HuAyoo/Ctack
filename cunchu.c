#include <stdio.h>
#include<string.h>
int main()
{
	char *c1 = "adddb";
	char c2[] = "asdfdfcdsdasddd";
	char *c3 = (char *)malloc(3);
	c3 = "abc";
	printf("%d %d %s\n",&c1,c1,c1);	
	printf("%d %d %s\n",&c2,c2,c2);
	printf("%d %d %s\n",&c3,c3,c3);

}