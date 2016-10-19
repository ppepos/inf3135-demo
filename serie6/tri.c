#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int read_file(*file)

int cmp(char **a, char **b)
{
	return strcmp(*a, *b);
}

void read_file_lines(FILE *f, char **list, int *count)
{
	char line[128];
	int c = 0;

	while (fgets(line, 128, f) != 0) {
		list[c] = (char *) malloc(strlen(line));
		strcpy(list[c], line);
		c++;
	}
	*count = c;
}

void print_lines(char **list, int *len)
{
	int i;
	for (i = 0; i < *len; i++) {
		printf("%s", list[i]);
	}
}

int main (int argc, char* argv[])
{
	FILE * f = fopen("capitales.txt", "r");
	int capital_count = 0;
	char *list[256];

	read_file_lines(f, list, &capital_count);

	qsort((void *) list, capital_count, sizeof(char *), (const void *) &cmp);

	print_lines(list, &capital_count);

	return 0;
}
