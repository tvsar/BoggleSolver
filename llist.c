#include <stdlib.h>
#include <string.h>

#include "llist.h"

//initialize a linked list
llist_t * ll_init(){
  //TODO

  llist_t * lis = malloc(sizeof(llist_t));
  lis->head = NULL;
  lis->size = 0;
  return lis;  

  //return NULL; //clearly it shouldn't return null when you finish it
}

//delete a linked list
void ll_delete(llist_t * ll){
  //TODO

  ll_node_t * my_pointer = ll->head;
  ll_node_t * next_node = NULL;
  while(my_pointer != NULL){
    next_node = my_pointer->next;
    free(my_pointer->val);
    free(my_pointer);
    my_pointer = next_node;
  }
  free(ll);
  ll=NULL;
}


//push an item onto the front of the list
void ll_push(llist_t * ll, char * s){
  //TODO

  ll_node_t * new_head = malloc(sizeof(ll_node_t));
  new_head->val = strdup(s);
  new_head->next = ll->head;
  ll->head = new_head;
  ll->size = ll->size + 1; 
}




