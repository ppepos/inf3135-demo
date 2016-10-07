#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *entree = fopen(argv[1], "r");
	char ligne[512];
	char *nom = "";
	char *pays = "";
	char *population_str = "";
	char *delim = ",";
	int rang = 1;
	int population = 0;

	if (argc != 2) {
		printf("Erreur! Utilisation: <%s> <fichier>", argv[0]);
		return 1;
	}

	printf("Rang  Nom              Pays  Population\n");
	printf("----  ---              ----  ----------\n");

	while(fgets(ligne, 512, entree) != NULL) {

		nom = strtok(ligne, delim);
		pays = strtok(NULL, delim);
		population_str = strtok(NULL, delim);

		population = strtol(population_str, NULL, 10);

		printf("%04d  %-15.15s  %.4s  %10d\n", rang, nom, pays, population);

		rang++;
	}

	return 0;

}
