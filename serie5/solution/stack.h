#include <stdbool.h>

// Types
// -----

struct StackNode;
typedef struct {
    struct StackNode *first; // Pointeur vers le premier noeud
    int size;                // Nombre d'elements dans la pile
} Stack;


/**
 * Cree une pile vide et la retourne.
 *
 * @returns  La pile vide
 *
 * TESTS:
 *
 *     Stack s = stackCreate();
 *     printf("%d\n", s.size);
 *     >>> 0
 *
 */
Stack stackCreate();

/**
 * Verifie si la pile pointee est vide.
 *
 * @param s  Un pointeur vers la pile
 * @returns  Vrai si et seulement si la pile est vide
 *
 * TESTS:
 *
 *     Stack s = stackCreate();
 *     printf("%s\n", stackIsEmpty(&s) ? "true" : "false");
 *     stackPush(&s, 'a');
 *     printf("%s\n", stackIsEmpty(&s) ? "true" : "false");
 *     >>> true
 *     >>> false
 *
 */
bool stackIsEmpty(const Stack *s);

/**
 * Ajoute un element sur le dessus de la pile.
 *
 * @param s        Un pointeur vers la pile
 * @param content  Le contenu de l'element a ajouter
 *
 * TESTS:
 *
 *     Stack s = stackCreate();
 *     printf("%d\n", s.size);
 *     stackPush(&s, 'a');
 *     stackPush(&s, 'b');
 *     printf("%d\n", s.size);
 *     stackPush(&s, 'c');
 *     printf("%d\n", s.size);
 *     >>> 0
 *     >>> 2
 *     >>> 3
 *
 */
void stackPush(Stack *s, char content);

/**
 * Supprime l'element sur le dessus de la pile et le retourne.
 *
 * @param s  Un pointeur vers la pile
 * @returns  Le contenu de l'element au-dessus de la pile
 *
 * TESTS:
 *
 *     Stack s = stackCreate();
 *     stackPush(&s, 'a');
 *     printf("%c\n", stackPop(&s));
 *     stackPush(&s, 'b');
 *     stackPush(&s, 'c');
 *     stackPush(&s, 'd');
 *     printf("%c\n", stackPop(&s));
 *     printf("%c\n", stackPop(&s));
 *     printf("%c\n", stackPop(&s));
 *     >>> a
 *     >>> d
 *     >>> c
 *     >>> b
 *
 */
char stackPop(Stack *s);

/**
 * Supprime la pile pointee.
 *
 * @param s  Un pointeur vers la pile
 */
void stackDelete(Stack *s);
