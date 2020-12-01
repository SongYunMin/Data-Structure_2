#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[10];
	char b[10];

	scanf("%s", a);
	scanf("%s", b);
	

	printf("%d", strcmp(a, b));
	return 0;
}