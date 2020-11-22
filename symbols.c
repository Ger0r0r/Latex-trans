#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main () 
{
	for (int i = 0; i < 256; i = i + 4)
	{
		printf("%d - %c %d - %c %d - %c %d - %c\n", i, i, i+1, i+1,i+2,i+2,i+3,i+3);
	}
}
