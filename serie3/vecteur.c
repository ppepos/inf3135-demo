#include <stdio.h>
#include <stdbool.h>

struct Vecteur {
	float x;
	float y;
	float z;
};

void initialiser(struct Vecteur *vecteur,
		 float x, float y, float z)
{
	vecteur->x = x;
	vecteur->y = y;
	vecteur->z = z;
}

void afficher(const struct Vecteur *vecteur)
{
	printf("(%f, %f, %f)\n", vecteur->x, vecteur->y, vecteur->z);
}

void additionner(const struct Vecteur *v1,
		 const struct Vecteur *v2,
		 struct Vecteur *resultat)
{
	resultat->x = v1->x + v2->x;
	resultat->y = v1->y + v2->y;
	resultat->z = v1->z + v2->z;
}

float produitScalaire(const struct Vecteur *v1,
		      const struct Vecteur *v2)

{
	float produit = 0;

	produit += v1->x * v2->x;
	produit += v1->y * v2->y;
	produit += v1->z * v2->z;

	return produit;
}

bool sontPerpendiculaires(const struct Vecteur *v1,
		          const struct Vecteur *v2)
{
	return produitScalaire(v1, v2) == 0.0;
}

int main(int argc, char *argv[])
{

	struct Vecteur v;
	struct Vecteur v1;
	struct Vecteur vp1;
	struct Vecteur vp2;

	initialiser(&v, 3.5, 4.5, 5.5);
	afficher(&v);

	initialiser(&v1, 1.0, 1.0, 1.0);
	additionner(&v, &v1, &v);
	afficher(&v);

	initialiser(&vp1, 1.0, 0.0, 0.0);
	initialiser(&vp2, 0.0, 1.0, 0.0);
	printf("%s\n", sontPerpendiculaires(&vp1, &vp2) ? "true" : "false");
	additionner(&vp1, &v1, &vp1);
	printf("%s\n", sontPerpendiculaires(&vp1, &vp2) ? "true" : "false");

	return 0;
};
