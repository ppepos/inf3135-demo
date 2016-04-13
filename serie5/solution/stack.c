#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Types
// -----

struct StackNode {
    char content;           // Contenu du noeud
    struct StackNode *next; // Noeud suivant
};

// Implementation
// --------------

Stack stackCreate() {
    Stack s;
    s.first = NULL;
    s.size = 0;
    return s;
}

bool stackIsEmpty(const Stack *s) {
    return s->size == 0;
}

void stackPush(Stack *s, char content) {
    struct StackNode *node = (struct StackNode*)malloc(sizeof(struct StackNode));
    node->content = content;
    node->next = s->first;
    s->first = node;
    ++s->size;
}

char stackPop(Stack *s) {
    if (!stackIsEmpty(s)) {
        char content = s->first->content;
        struct StackNode *node = s->first;
        s->first = node->next;
        free(node);
        --s->size;
        return content;
    } else {
        printf("Cannot pop from empty stack");
        return '?';
    }
}

void stackDelete(Stack *s) {
    while (!stackIsEmpty(s)) {
        stackPop(s);
    }
}
