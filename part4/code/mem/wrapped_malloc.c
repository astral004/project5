#include "wrapped_malloc.h"
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"

void* shelf[MAX_ALLOC];
unsigned numAlloc = 0;

void * w_malloc(int numBytes){
    void * returnable = malloc(numBytes);
    if (returnable != NULL){
        shelf[numAlloc++] = returnable;
        return returnable;
    }
    else {
        printf("ERROR! Mem returned null!\n");
        return NULL;
    }
}
void w_free(void * ptr){
    if(ptr){
        for (int i = 0; i < numAlloc; i++) {
            if (shelf[i] == ptr && shelf[i] != NULL){
                free(shelf[i]);
                shelf[i] = NULL;
                break;
            }
        }
    }
}

void whole_free(){
    for (int i = 0; i < numAlloc; ++i) {
        if (shelf[i]){
            free(shelf[i]);
        }
    }
}