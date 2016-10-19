#include <stdbool.h>
// Types
// -----

struct TreeNode {
    char *key;              // Cle du noeud
    char *value;            // Valeur associee
    struct TreeNode *left;  // Fils gauche
    struct TreeNode *right; // Fils droit
};

typedef struct {
    struct TreeNode *root; // Pointeur vers la racine
} TreeMap;

// Prototypes
// ----------

TreeMap treemapCreate();
char *treemapGet(const TreeMap *t, char *key);
void treemapSet(TreeMap *t, char *key, char *value);
void treemapInsertNode(struct TreeNode **node, char *key, char *value);
bool treemapHasKey(const TreeMap *t, char *key);
struct TreeNode *treemapGetNode(const TreeMap *t, char *key);
void treemapPrint(const TreeMap *t);
void treemapPrintRecursive(const struct TreeNode *node);
void treemapDelete(TreeMap *t);
void treemapDeleteRecursive(struct TreeNode *node);
