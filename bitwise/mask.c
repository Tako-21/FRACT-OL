#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	unsigned short n;

	printf("size of unsigned short : %ld\n", sizeof(unsigned short));
	if (scanf("%hx", &n) != 1)
	{
		printf("Error\n");

		perror("scanf");
		return EXIT_FAILURE;
	}

	printf("%X\n", n & 0x7FFF);
	return 0;
}

