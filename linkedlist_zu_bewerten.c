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
    prev = &((*prev)->next);
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
  if (is_empty(ll))
  {
    return true;
  }
  int prev = ll->first->value;
  for (node_t *n = ll->first; n; n = n->next)
  {
    if (prev > n->value){
      return false;
    }
    prev = n->value;
  }
  return true;
}



bool list_has_duplicates(linked_list_t *ll)
{
  for(node_t *n = ll->first; n; n = n->next)
  {
    for(node_t *m = n->next; m; m = m->next)
    {
      if(n->value == m->value)
      {
        return true;
      }
    }
  }
  return false;
}

void list_add_before(linked_list_t *ll, int x, int y)
{
  if (ll->first->value == y)
  {
    add_elem_front(ll, x);
    return;
  }

  // Alloziere neue Knoten-Stuktur
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node)
  {
    printf("Couldn't allocate new node");
    exit(-1);
  }

  for(node_t *n = ll->first; n->next; n = n->next)
  {
    if(n->next->value == y)
    {
    // Initalisiere den neuen Knoten
    new_node->value = x;
    new_node->next = n->next;
    n->next = new_node;
    return;
    }
  }
  add_elem(ll, x);
}

int list_remove(linked_list_t *ll, int value)
{
  int pos = 0;
  int a = 0;
  node_t *help;
  for(node_t *n = ll->first; n; n = n->next)
  {
    if (n->value == value)
    {
      //list_remove
      if (pos!=0)
      {
        remove_elem(ll, pos);
        n=help;
      } else {
        ll->first = ll->first->next;
      }
      a++;
      
    } else {
      pos++;
    }
    help = n;
  }
  return a;
}

void merge (linked_list_t *ll1, linked_list_t *ll2,int size){
  node_t *n2=ll2->first;
  node_t *n1=ll1->first;
  node_t *prev=NULL;
  while(n1&&n2){
    if(n1->value<=n2->value){
      prev=n1;
      n1=n1->next;
    } else {
      if(prev==NULL){
        node_t *help = n2->next;
        ll1->first=n2;
        n2->next=n1;
        prev=n2;
        n2=help;
      } else {
        node_t *help = n2->next;
        prev->next=n2;
        n2->next = n1;
        prev = n2;
        n2=help;
      }
    }
  }
  while(n2){
    prev->next=n2;
    prev=prev->next;
    n2=n2->next;
  }
}

void sort(linked_list_t *ll){
  if(ll->first->next){
    int i=0;
    for(node_t *n=ll->first;n;n=n->next){
      i++;
    }
    node_t *n=ll->first;
    for(int a=0;a<(i/2)-1;a++){
      n=n->next;
    }
    linked_list_t *llh=new_list();
    llh->first=n->next;
    n->next=NULL;
    sort(ll);
    sort(llh);
    merge(ll,llh, i);
  }
}


int main(void)
{
  
  //Test
  
  linked_list_t *ll = new_list();
  add_elem(ll, 2);
  add_elem(ll, 1);
  add_elem(ll, 3);
  add_elem(ll, 4);
  add_elem(ll, 5);
  add_elem(ll, 6);
  add_elem(ll, 8);
  add_elem(ll, 7);
  sort(ll);
  printf("%i",list_is_sorted(ll));
  print_list(ll);
  free_list(ll);
}
