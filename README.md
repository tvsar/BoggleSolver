# C Boggle Solver

## How to compile

To compile `spellcheck`

```
make spellcheck
```

To compile `onePlayerBoggle`

```
make onePlayerBoggle
```

## Testing using ./test.sh

Note the test file may take some time to run because of `valgrind`. If you are completing this project on replit, this may be quite, quite slow. I recommend you use smaller dictionaries and test different aspects of your program and avoid simply testing with `./teset.sh`

## Program Description

Basic work for llist.c was done following the nodes to a degree that the linked list would allow. ll_init() was completed by allocating space for the head and setting the size as part of the initialization method. ll_delete() followed a pointer, freeing nodes as they were passed, then freeing the llist_t strucutre itself. ll_push() required making a new node pointing to the old head, then setting the new head equal to the new node.

In hashmap.c, the resize function was completed by making a new llist_t structure with twice the number of buckets. From there, each of the elements in each of the buckets were parsed through in the old hashmap_t with a pointer and added to the new llist_t. ll_delete() was then used in conjunction with free() to deallocate the old strucutre. hm_init() simply required making a hashmap with size 0 and the predermined number of buckets, and then making a new llist_t for each bucket. hm_delete() was done by calling ll_delete() on each bucket and then freeing the structure as a whole. hm_check() simply required finding the hash value and checking the associated bucket for the value.

boggle.c was completed using the functions written in the previous two programs. Loading the words into the dictionary was done using hm_add() and parsing through each word in the txt file until EOF was reached. \_bg_all_words() was structured to first check for the dimensions being out of bounds, over the allowed length, or the current coordinates being already visited. If passing that check, the old string was copied to cur_word. After this, either the new letter would be added or 'Q' and 'U' would be added if the letter was a 'Q'. If not already in the hashmap and of sufficient length, the word was then added to the hashmap. The visited array was then updated, and all of the following recursive calls were made.



