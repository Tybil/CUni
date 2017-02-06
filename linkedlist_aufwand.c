#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

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

// Berechnet die Groesse der Liste
int list_size(linked_list_t *ll) {
  node_t *n = ll->first;
  int size = 0;
  while (n != NULL) {
    size++;
    n = n->next;
  }
  return size;
}

// Liefert das Element an der gegebenen Position in der Liste
int list_get(linked_list_t *ll, int pos)
{
  node_t *node = ll->first;
  for (int i=0; node != NULL && i<pos; i++)
  {
    node = node->next;
  }
  if (node == NULL)
  {
    printf("Position %d nicht in Liste enthalten.", pos);
    abort();
  }
  return node->value;
}

// prueft, ob die Zahl elem in der Liste ll enthalten ist
bool list_contains(linked_list_t *ll, int elem)
{
  int size = list_size(ll);
  bool contained = false;
  for (int i=0; i<size-1; i++)
  {
    contained = list_get(ll, i) == elem || contained;
  }
  return contained;
}


int main ( int argc , char ** argv ) {
  int size = 1;
  double max_time = 5000;
  double time ;
  do {
    linked_list_t *ll = new_list();
    for(int i = 0;i<size;i++){
      add_elem(ll,2);
    }
    // Zeit vor Sortieren :
    clock_t start_time = clock() ;
    // Sortieren :
    list_contains(ll,2) ;
    // Zeit nach Sortieren :
    clock_t end_time = clock () ;
    // Verbrauchte Zeit in ms berechnen :
    time = ( end_time - start_time ) *1000.0 / CLOCKS_PER_SEC;
    printf ( "%d,%lf\n" , size , time ) ;
    free_list(ll);
    size = size * 2;
    } while ( time < max_time ) ;
  return 0;
}
