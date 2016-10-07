#include <stdio.h>

enum e_nombre {
    INT, FLOAT, DOUBLE
};

union u_nombre {
    int i;
    float f;
    double d;
};

struct nombre {
    enum e_nombre typeNombre; // Le type de la valeur
    union u_nombre valeur;    // La valeur
};

struct nombre max(struct nombre n1, struct nombre n2)
{
	int i1, i2;
	float f1, f2;
	double d1, d2;

	struct nombre m;

	if(n1.typeNombre == INT) {
		i1 = n1.valeur.i;

		if(n2.typeNombre == INT) {
			i2 = n2.valeur.i;
			if(i1 >= i2) {
				m = n1;
			} else {
				m = n2;
			}
		} else if(n2.typeNombre == FLOAT) {
			f2 = n2.valeur.f;
			if(i1 >= f2) {
				m = n1;
			} else {
				m = n2;
			}
		} else if(n2.typeNombre == DOUBLE) {
			d2 = n2.valeur.d;
			if(i1 >= d2) {
				m = n1;
			} else {
				m = n2;
			}
		}

	} else if(n1.typeNombre == FLOAT) {
		f1 = n1.valeur.f;

		if(n2.typeNombre == INT) {
			i2 = n2.valeur.i;
			if(f1 >= i2) {
				m = n1;
			} else {
				m = n2;
			}
		} else if(n2.typeNombre == FLOAT) {
			f2 = n2.valeur.f;
			if(f1 >= f2) {
				m = n1;
			} else {
				m = n2;
			}
		} else if(n2.typeNombre == DOUBLE) {
			d2 = n2.valeur.d;
			if(f1 >= d2) {
				m = n1;
			} else {
				m = n2;
			}
		}

	} else if(n1.typeNombre == DOUBLE) {
		d1 = n1.valeur.d;

		if(n2.typeNombre == INT) {
			i2 = n2.valeur.i;
			if(d1 >= i2) {
				m = n1;
			} else {
				m = n2;
			}
		} else if(n2.typeNombre == FLOAT) {
			f2 = n2.valeur.f;
			if(d1 >= f2) {
				m = n1;
			} else {
				m = n2;
			}
		} else if(n2.typeNombre == DOUBLE) {
			d2 = n2.valeur.d;
			if(d1 >= d2) {
				m = n1;
			} else {
				m = n2;
			}
		}
	}

	return m;
}

void print_nombre(struct nombre n)
{
	if(n.typeNombre == INT) {
		printf("%d\n", n.valeur.i);
	} else if (n.typeNombre == FLOAT) {
		printf("%f\n", n.valeur.f);
	} else {
		printf("%f\n", n.valeur.d);
	}
}

int main(int argc, char *argv[])
{
	struct nombre n1 = {INT, 3};
	struct nombre n2 = {FLOAT, {.f = 40.1}};
	struct nombre n3 = {DOUBLE, {.d = 5.5}};
	struct nombre m;

	m = max(n1, n2);
	print_nombre(m);

	m = max(n1, n3);
	print_nombre(m);

	m = max(n2, n3);
	print_nombre(m);

	return 0;
}
