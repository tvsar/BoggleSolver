#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <string.h>

#include "llist.h"
#include "hashmap.h"

//local function for hashing an input value (do not edit)
unsigned int _hash(hashmap_t * hm, char * val){
  //based on Java's String.hashcode()
  double k = 0;
  double len = (double) strlen(val);
  int i=1;
  for(char * c = val; *c ; c++,i++){
    k += (*c) * pow(31,len-i);
  }

  return (unsigned int) (((unsigned long) k) % hm->num_buckets);
}


//local function: resize the hashmap by doubling the number of buckets and rehashing
void _resize(hashmap_t * hm){
  //TODO: resize the hashmap if the load gets too high
  //hm->num_buckets = hm->num_buckets * 2;
  llist_t ** old = hm->buckets;
  llist_t ** new = calloc(sizeof(llist_t *), hm->num_buckets*2);
  hm->buckets = new;
  hm->num_buckets *= 2;
  for(int i =0; i < hm->num_buckets; i++){
    new[i] = ll_init();
  }
  for(int i = 0; i < hm->num_buckets/2; i++){
  if(old[i]->head != NULL){
    ll_node_t * my_pointer = old[i]->head;
    while(my_pointer != NULL){
      //hm_add(hmdup, my_pointer->val);
      int has = _hash(hm, my_pointer->val);
      ll_push(hm->buckets[has],my_pointer->val);
      my_pointer = my_pointer->next;
      //ll_
      //DO AN LL ADD HERE TO ADD TO DUP
    }
    //ll_delete(old[i]);
  }
}
for (int i =0; i < hm->num_buckets/2; i++){
  ll_delete(old[i]);
}
  free(old);


  //old__________________

  // hashmap_t * hmdup = hm_init();
  // hmdup->num_buckets = hm->num_buckets * 2;
  // //free other buckets before you do this next calloc
  // for(int j = 0; j < 16; j++){
  //   ll_delete(hmdup->buckets[j]);
  // }
  // free(hmdup->buckets);
  // hmdup->buckets = calloc(sizeof(llist_t * ), hm->num_buckets * 2);
  // //for i in buckets, recall ll_init
  // for(int k = 0; k < hmdup->num_buckets; k++){
  //   hmdup->buckets[k] = ll_init();
  // }
  // for(int i = 0; i < hm->num_buckets; i++){
  //   if(hm->buckets[i]->head != NULL){
  //     ll_node_t * my_pointer = hm->buckets[i]->head;
  //     while(my_pointer != NULL){
  //       //hm_add(hmdup, my_pointer->val);
  //       int has = _hash(hmdup, my_pointer->val);
  //       ll_push(hmdup->buckets[has],my_pointer->val);
  //       my_pointer = my_pointer->next;
  //       //ll_
  //       //DO AN LL ADD HERE TO ADD TO DUP
  //     }
  //     ll_delete(hm->buckets[i]);
  //   }
  // }
  // hmdup->size = hm->size;
  // hm = hmdup;
}


//initliaze a hashmap with initial number of buckets
hashmap_t * hm_init(){

  //create the hashmap
  hashmap_t * hm = calloc(sizeof(hashmap_t),1);
  hm->size = 0;
  hm->num_buckets = HM_INIT_NUM_BUCKETS;
  hm->buckets = calloc(sizeof(llist_t), HM_INIT_NUM_BUCKETS);
  for(int i = 0; i < HM_INIT_NUM_BUCKETS; i++){
    hm->buckets[i] = ll_init();
  }
  //TODO the rest of the setup!
  
  return hm;
}


//delete/deallocate the hashmap
void hm_delete(hashmap_t * hm){

  //TODO: properly deallocate

  ////
  //llist_t * my_pointer = hm->buckets[0];
  //llist_t * next = NULL;
  int count = 0;
  while(count < hm->num_buckets){
    ll_delete(hm->buckets[count]);
    count++;
    //llist_t * my_pointer = hm->buckets[count];
  }
  ////

  //delete the hashmap
  free(hm->buckets);
  free(hm);
}

//add a string value to the hashmap
void hm_add(hashmap_t * hm, char * val){
  // You get this function for free :)
  
  //check the load on the hashtable, if > max load, resize!
  if(((hm->size+1)/(double) hm->num_buckets) > HM_MAX_LOAD){
    _resize(hm); 
  }

  unsigned int h = _hash(hm,val); //get hash
  ll_push(hm->buckets[h],val); //note that list does string dup
  hm->size++; //increase size

}

//see if a string value is in the hashmap
bool hm_check(hashmap_t * hm, char * val){

  //TODO check if a value is in the hashmap

  unsigned int h = _hash(hm,val); //get hash
  ll_node_t * my_pointer = hm->buckets[h]->head;
  while(my_pointer != NULL){
    if(strcmp(my_pointer->val, val)==0){
      return true;
    }
    my_pointer = my_pointer->next;
  }

  return false; //otherwise false
}


