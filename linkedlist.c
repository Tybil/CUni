#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
  int value;
  struct node *next;
} node_t;

typedef struct linked_list
{
  node_t *first;
} linked_list_t;

bool is_empty(linked_list_t *ll)
{
  return !ll->first;
}

/* Fuegt ein Element hinten in die Liste ein */
void add_elem(linked_list_t *ll, int i)
{
  // Alloziere neue Knoten-Stuktur
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node)
  {
    printf("Couldn't allocate new node");
    exit(-1);
  }
  // Initalisiere den neuen Knoten
  new_node->value = i;
  new_node->next = NULL;

  // Iteriere ueber die Liste bis zum Ende
  // current ist ein Zeiger auf einen Zeiger, der auf einen Knoten zeigt
  node_t **current = &ll->first;
  while (*current)
  {
    current = &(*current)->next;
  }
  *current = new_node;
}

/* Fuegt ein Element vorne in die Liste ein */
void add_elem_front(linked_list_t *ll, int i)
{
  // Alloziere neue Knoten-Stuktur
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node)
  {
    printf("Couldn't allocate new node");
    exit(-1);
  }
  // Initalisiere den neuen Knoten
  new_node->value = i;
  new_node->next = ll->first;
  ll->first = new_node;
}

/* Entfernt das Element an Position pos, falls vorhanden */
void remove_elem(linked_list_t *ll, int pos)
{
  node_t **prev = &(ll->first);
  while (pos > 0 && (*prev)->next)
  {
    pos--;
    prev = &(*prev)->next;
  }
  node_t *n = *prev;
  if (!pos)
  {
    *prev = n->next;
    free(n);
  }
}

void print_list(linked_list_t *ll)
{
  for (node_t *n = ll->first; n; n = n->next)
  {
    printf("%d  ", n->value);
  }
  printf("\n");
}

linked_list_t *new_list(void)
{
  // Alloziere und initalisiere Speicher auf dem Heap fuer die Listen-Struktur
  linked_list_t *ll = calloc(1, sizeof(linked_list_t));
  if (ll)
  {
    return ll;
  }
  else
  {
    printf("Couldn't allocate linked_list");
    abort(); // Programmabbruch
  }
}

void free_list(linked_list_t *ll)
{
  // Entferne zunaechst alle Knoten der Liste
  node_t *n = ll->first;
  while (n)
  {
    // Merken, was der naechste Knoten ist, da nach dem free die Information nicht mehr verfuegbar ist
    node_t *next = n->next;
    free(n);
    n = next;
  }
  // Entferne die Listen-Stuktur
  free(ll);
}

bool list_is_sorted(linked_list_t *ll)
{
  if(is_empty(ll)){
    return true;
  }
  int prev = ll->first->value;
  for (node_t *n = ll->first; n; n = n->next)
  {
    if(prev>n->value) {
      return false;
    }
    prev = n->value;
  }

  return true;
}



bool list_has_duplicates(linked_list_t *ll)
{
  
  return false;
}

void list_add_before(linked_list_t *ll, int x, int y)
{
  // Aufgabe c)
}

int list_remove(linked_list_t *ll, int value)
{
  // Aufgabe d)
  return 0;
}


int main(void)
{
  linked_list_t *ll = new_list();
  add_elem(ll,1);
  add_elem(ll,2);
  add_elem(ll,3);
  if(list_is_sorted(ll)){
    printf("ist sortiert\n");
  } else {
    print_list(ll);
  }
  free_list(ll);
}
