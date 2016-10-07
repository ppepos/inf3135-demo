#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j;

	printf("digraph {\n");

	for(i = 1; i <= 48; i++) {
		printf("\t%d\n", i);
	}

	for(i = 1; i <= 47; i++) {
		for(j = i; j <= 48; j++) {
			if(j % i == 0) {
				printf("\t%d -> %d\n", i, j);
			}
		}
	}

	printf("}\n");

	return 0;
}
