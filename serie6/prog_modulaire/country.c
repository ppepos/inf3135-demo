#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "treemap.h"

void read_file_lines(FILE *f, TreeMap *tree)
{
	char line[128];

	while (fgets(line, 128, f) != 0) {
		char *key = strtok(line, ",");
		char *value = strtok(NULL, ",");
		treemapSet(tree, key, value);
	}
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
	TreeMap tree = treemapCreate();

	read_file_lines(f, &tree);

	printf("%s\n", treemapGet(&tree, "TH"));

	return 0;
}
