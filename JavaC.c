#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
  int value;
} node_t;

void scale(node_t *n, int factor) {
    n->value = n->value*factor;
}

void scale_All(node_t *ar, int factor, int laenge) {
    for (int i = 0; i<laenge; i++) {
        scale(&ar[i], factor);
    }
}

node_t Node(int value) {
    node_t *n = malloc(sizeof(node_t));
    n->value = value;
    return *n;
}

int main(void) {
    node_t *ar = malloc(5*sizeof(node_t));
    int i = 0;
    while (i<5) {
        ar[i] = Node(i+1);
        i++;
    }
    scale_All(ar, 2, 5);
    for (int i = 0; i<5; i++) {
        printf("%i\n", ar[i].value);
    }
    free(ar);
}
