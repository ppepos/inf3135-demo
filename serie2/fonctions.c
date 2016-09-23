#include <stdbool.h>
#include <stdio.h>

#include "fonctions.h"

int somme(int tab[], int len) {
	int i;
	int somme = 0;

	for(i = 0; i < len; i++) {
		somme += tab[i];
	}

	return somme;
}

bool estTrie(int tab[], int len) {
	int i = 1;

	if (len < 2) {
		return true;
	}

	while(i < len) {
		if (tab[i - 1] > tab[i]) {
			return false;
		}
		i++;
	}

	return true;
}

int elementPlusFrequent(int tab[], int len) {
	int meilleure_freq = 0;
	int meilleur = 0;
	int i, j;
	int courant;
	int score;

	for(i = 0; i < len; i++) {

		courant = tab[i];
		score = 0;

		for(j = 0; j < len; j++) {
			if(tab[j] == courant) {
				score += 1;
			}
		}

		if(score > meilleure_freq) {
			meilleure_freq = score;
			meilleur = courant;
		}
	}

	return meilleur;
}

int nombreOccurrences(char *str, char c) {
	char i = 0;
	int cpt = 0;

	while (str[i]) {
		if (str[i] == c) {
			cpt++;
		}
		i++;
	}

	return cpt;
}

int main(int argc, char *argv[]) {
	int somme1[] = {1,0,0,0};
	int somme2[] = {1,0,1,1};
	int somme3[] = {1,0,2};
	int somme4[] = {1,4,2};

	int non_trie[] = {1,2,4,3};
	int trie[] = {1,2,4};

	int freq1[] = {1,2,1};
	int freq2[] = {3};
	int freq3[] = {3,2,2,3,3,3};
	int freq4[] = {7,7};

	char *str = "flag{31337_15_8357_31337}";

	printf("%d", somme(somme1, 4));
	printf("%d", somme(somme2, 4));
	printf("%d", somme(somme3, 3));
	printf("%d\n", somme(somme4, 3));

	printf("%d", estTrie(non_trie, 4));
	printf("%d\n", estTrie(trie, 3));

	printf("%d", elementPlusFrequent(freq1, 3));
	printf("%d", elementPlusFrequent(freq2, 1));
	printf("%d", elementPlusFrequent(freq3, 6));
	printf("%d\n", elementPlusFrequent(freq4, 2));

	printf("%d", nombreOccurrences(str, 'f'));
	printf("%d", nombreOccurrences(str, '1'));
	printf("%d", nombreOccurrences(str, '7'));
	printf("%d\n", nombreOccurrences(str, '3'));

	return 0;
}
