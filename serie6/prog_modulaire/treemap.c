#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "treemap.h"

/**
 * Cree et retourne une table associative vide.
 *
 * @returns  La table associative
 */
TreeMap treemapCreate() {
    TreeMap t = {NULL};
    return t;
}

/**
 * Retourne la valeur associee a la cle donnee.
 *
 * @param t    La table associative
 * @param key  La cle
 * @returns    La valeur associee
 */
char *treemapGet(const TreeMap *t, char *key) {
    struct TreeNode *node = treemapGetNode(t, key);
    if (node == NULL)
        return NULL;
    else
        return node->value;
}

/**
 * Ajoute ou remplace la paire (key, value).
 *
 * Note : si la cle est deja presente dans la table, alors
 * la valeur associee est ecrasee avec la nouvelle valeur.
 *
 * @param t      La table associative
 * @param key    La cle
 * @param value  La valeur
 */
void treemapSet(TreeMap *t, char *key, char *value) {
    struct TreeNode *node = treemapGetNode(t, key);
    if (node != NULL) {
        node->value = strdup(value);
    } else {
        treemapInsertNode(&(t->root), key, value);
    }
}

/**
 * Insere un noeud dans l'arbre representant une table associative.
 *
 * Note : cette fonction devrait etre privee (lorsqu'on verra les
 * modules, elle ne doit pas etre dans l'interface).
 *
 * @param node   Le noeud courant
 * @param key    La cle a inserer
 * @param value  La valeur associee
 */
void treemapInsertNode(struct TreeNode **node, char *key, char *value) {
    if (*node == NULL) {
        *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*node)->key = strdup(key);
        (*node)->value = strdup(value);
        (*node)->left = NULL;
        (*node)->right = NULL;
    } else if (strcmp(key, (*node)->key) < 0) {
        treemapInsertNode(&(*node)->left, key, value);
    } else {
        treemapInsertNode(&(*node)->right, key, value);
    }
}

/**
 * Retourne vrai si et seulement si la cle apparaît dans la table.
 *
 * @param t    La table associative
 * @param key  La cle a rechercher
 * @returns    Vrai si et seulement si la cle est presente
 */
bool treemapHasKey(const TreeMap *t, char *key) {
    return treemapGetNode(t, key) != NULL;
}

/**
 * Retourne le noeud correspondant a une cle donnee.
 *
 * Si la cle n'y est pas, alors la valeur NULL est retournee.
 *
 * @param t    La table associative
 * @param key  La cle recherchee
 * @returns    Le noeud associee a la cle ou NULL
 */
struct TreeNode *treemapGetNode(const TreeMap *t, char *key) {
    struct TreeNode *node = t->root;
    while (node != NULL) {
        int cmp = strcmp(key, node->key);
        if (cmp == 0)
            return node;
        else if (cmp < 0)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

/**
 * Affiche une table associative sur la sortie standard.
 *
 * @param t  La table associative a afficher
 */
void treemapPrint(const TreeMap *t) {
    printf("TreeMap {\n");
    treemapPrintRecursive(t->root);
    printf("}\n");
}

/**
 * Affiche en ordre infixe les paires (key, value) presentes
 * dans l'arbre.
 *
 * Note : cette fonction devrait etre privee (lorsqu'on verra les
 * modules, elle ne doit pas etre dans l'interface).
 */
void treemapPrintRecursive(const struct TreeNode *node) {
    if (node != NULL) {
        treemapPrintRecursive(node->left);
        printf("  %s: %s\n", node->key, node->value);
        treemapPrintRecursive(node->right);
    }
}

/**
 * Libere l'espace memoire utilise par une table associative.
 *
 * @param t  La table a supprimer
 */
void treemapDelete(TreeMap *t) {
    treemapDeleteRecursive(t->root);
}

/**
 * Libere recursivement l'espace memoire utilise par les noeuds
 * de l'arbre representant une table associative.
 *
 * @param node  Le noeud courant
 *
 * Note : cette fonction devrait etre privee (lorsqu'on verra les
 * modules, elle ne doit pas etre dans l'interface).
 */
void treemapDeleteRecursive(struct TreeNode *node) {
    if (node != NULL) {
        treemapDeleteRecursive(node->left);
        treemapDeleteRecursive(node->right);
        free(node);
    }
}

// int main() {
//     TreeMap t = treemapCreate();
//     treemapSet(&t, "prenom", "alice");
//     treemapSet(&t, "nom", "tremblay");
//     treemapSet(&t, "sexe", "feminin");
//     treemapSet(&t, "ville", "montreal");
//     treemapSet(&t, "province", "quebec");
//     treemapSet(&t, "pays", "canada");
//     treemapSet(&t, "age", "25");
//     printf("Printing the tree map\n");
//     treemapPrint(&t);
//     printf("Get \"prenom\": %s\n", treemapGet(&t, "prenom"));
//     printf("Get \"province\": %s\n", treemapGet(&t, "province"));
//     printf("Get \"age\": %s\n", treemapGet(&t, "age"));
//     printf("Changing age to 21\n");
//     treemapSet(&t, "age", "21");
//     printf("Get \"age\": %s\n", treemapGet(&t, "age"));
//     printf("Printing the tree map\n");
//     treemapPrint(&t);
//     treemapDelete(&t);
// }

