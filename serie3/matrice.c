#include <stdio.h>
#include <stdbool.h>

struct Matrice {
	double contenu[20][20];
};

void initialiser(struct Matrice *matrice)
{
	int i, j;

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			matrice->contenu[i][j] = 0.0;
		}
	}
}

void afficher(const struct Matrice *matrice)
{
	int i, j;

	for (i = 0; i < 20; i++) {
		printf("[ ");
		for (j = 0; j < 20; j++) {
			printf("%.2f ", matrice->contenu[i][j]);
		}
		printf("]\n");
	}
	printf("\n");
}

void additionner(const struct Matrice *m1,
                 const struct Matrice *m2,
                 struct Matrice *resultat)
{
	int i, j;

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			resultat->contenu[i][j] = m1->contenu[i][j] + m2->contenu[i][j];
		}
	}
}

void multiplier(const struct Matrice *m1,
                const struct Matrice *m2,
                struct Matrice *resultat)
{
	int i, j, k;
	double res;

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			res = 0.0;

			for (k = 0; k < 20; k++) {
				res += m1->contenu[i][k] * m2->contenu[k][j];
			}

			resultat->contenu[i][j] = res;
		}
	}
}


int main (int argc, char *argv[])
{
	struct Matrice m;
	struct Matrice I;
	int i;

	initialiser(&m);

	m.contenu[3][1] = 9.0;
	m.contenu[7][19] = 3.0;
	afficher(&m);

	// Creer la matrice Identite
	for (i = 0; i < 20; i++) {
		I.contenu[i][i] = 1.0;
	}

	multiplier(&m, &I, &m);
	afficher(&m);

	return 0;
}
