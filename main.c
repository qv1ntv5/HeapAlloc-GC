#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "./heap.h"
#define WORD 8


int main()
{

    
    char* counter = (char*)heap;

    printf("First, we will see our heap, the region of memory in which we will alloc memory chunks:\n\n\n");
    printf("       HEAP       \n|----------------|\n");

    for (int i = 0; i<16; i++){

        if (i == 15 || i == 7) {          
            printf("| %p | \n|----------------| WORD / 8-bytes\n", counter + i);
        } else {
            printf("| %p | \n", counter + i);
        }
    }
    printf("\nIn total, we have a heap of two-word size.\n\n\n");

    printf("\nNow we alloc two chunks for two values: 10 and 20. This two chunks, due to memory allignment, have word's size (8-bytes), the difference between the memory address in which this values are stored must be 8 bytes:\n\n");

    int* ptr1 = (int*) malloc(sizeof(int));
    int* ptr2 = (int*) malloc(sizeof(int));

    *ptr1 = 10;
    *ptr2 = 20;

    printf(" --> ptr1 = %p; value: %d\n",counter, *(int*)(counter));
    printf(" --> ptr2 = %p; value: %d\n",counter + WORD, *(int*)(counter + WORD));

    printf("\nWe can see that the first memory address which contains each integer are the first address of each chunk in the heap.\n\nThe garbage collector works freeing those of the chunks whose memory references in the programs (pointers) are lost in order to make it usable again.\nTo see how this work we will dereference 'ptr2' making the second alloced chunk unreachable\n\n");
    ptr2=NULL;

    printf(" --> ptr2 = %p; value: none\n", ptr2);

    printf("\nHowever, the integer value still exists the heap chunk and we can access it by the first memory address of the second chunck:\n\n --> %p: %d\n\nWhat happens is that this chunk is not longer pointed by nothing in the program and the value it contains will can never be used:\n",counter + WORD, *(int*)(counter + WORD));

    printf("Thus, we now call heap_collect(), that will we identify that the memory region corresponding to the second chunk  doesn't have any reference in the program and must be freed:\n");

    heap_collect();
    
    printf("\nAfter the GC action, the second chunk of memory; %p will be free and we will be capable to alloc a new chunk and store a new value. To probe this, we can define a new pointer and initialize it with heap alloc, and just show the value of the pointer and his value and check that this pointer is the first address of the second block of our heap and that this address stores now a different value probing that we have overwritten the space of heap freed by the GC.\n",counter + WORD);
    int* ptr3 = (int*) malloc(sizeof(int));
    *ptr3=30;

    printf("\n --> ptr3 = %p; value: %d\n",ptr3,*ptr3);
}