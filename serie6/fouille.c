#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int read_file(*file)

int cmp(char **a, char **b)
{
	return strcmp(*a, *b);
}

int cmp_search(char *a, char **b)
{
	return strcmp(a, *b);
}

void trim(char *s)
{
	char *offset;
	offset = strchr(s, '\n');
	if (offset) {
		*offset = '\0';
	}
}

void read_file_lines(FILE *f, char **list, int *count)
{
	char line[128];
	int c = 0;

	while (fgets(line, 128, f) != 0) {
		trim(line);
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
		printf("%s\n", list[i]);
	}
}

int main (int argc, char* argv[])
{
	FILE * f = fopen("capitales.txt", "r");
	int capital_count = 0;
	char *list[256];
	char *res;

	if (argc != 2) {
		printf("Usage: fouille <capitale>");
	}

	read_file_lines(f, list, &capital_count);

	qsort((void *) list, capital_count, sizeof(char *), (const void *) &cmp);

	res = bsearch(argv[1], list, capital_count, sizeof(char *), (const void *) &cmp_search);
	if (res) {
		printf("Trouvé %s dans la liste.", argv[1]);
	} else {
		printf("L'élément %s n'est pas dans la liste", argv[1]);
	}

	return 0;
}
