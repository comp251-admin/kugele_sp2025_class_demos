#include <stdlib.h>
#include <stdio.h>

typedef struct node_t node;

struct node_t {
  char *name;
	int value;

	struct node_t *left;
	struct node_t *right;
};

void display_node(node *n) {
  if (!n) {
    return;
  }

  printf("%s: %d\n", n->name, n->value);

  display_node(n->left);
  display_node(n->right);
}

int main(void) {
  node root = {"root", 0, NULL, NULL};

  node left = {"left", 5, NULL, NULL};
  node right = {"right", 15, NULL, NULL};

  root.left = &left; 
  root.right = &right; 

  display_node(&root);

	return 0;
}
