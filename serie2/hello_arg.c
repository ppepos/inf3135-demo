#include <stdio.h>

int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf("Erreur: 1 seul argument est permis");
		return 1;
	}

	printf("Hello, %s!", argv[1]);
	return 0;
}
