#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

int evict_index;
struct frame *tail;

/* Page to evict is chosen using the accurate LRU algorithm.
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */

int lru_evict() {

	return evict_index;
}


/* This function is called on each access to a page to update any information
 * needed by the lru algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void lru_ref(pgtbl_entry_t *p) {

	unsigned int index = p->frame >> PAGE_SHIFT;

	// If this frame is not the tail, move it to the tail.
	if (coremap[index].next) {
		if (coremap[index].prev) {  
			coremap[index].prev->next = coremap[index].next;
			coremap[index].next->prev = coremap[index].prev;
		} else { // If this frame is the head, set evict_index to the next frame's index
			coremap[index].next->prev = NULL;
			evict_index = coremap[index].next->frame_index;
		}

		tail->next = &coremap[index];
		coremap[index].prev = tail;
		coremap[index].next = NULL;
		tail = &coremap[index];
	}
}


/* Initialize any data structures needed for this 
 * replacement algorithm 
 */
void lru_init() {

	assert(memsize > 0);

	evict_index = 0;
	tail = &coremap[memsize - 1];

	coremap[0].prev = NULL;
	coremap[0].next = NULL;
	coremap[0].frame_index = 0;

	if (memsize > 1) {
		coremap[0].next = &coremap[1];
		coremap[memsize - 1].prev = &coremap[memsize - 2];
		coremap[memsize - 1].next = NULL;
		coremap[memsize - 1].frame_index = memsize - 1;
	}

	for (int i = 1; i < memsize - 1; i++) {
		coremap[i].next = &coremap[i + 1];
		coremap[i].prev = &coremap[i - 1];
		coremap[i].frame_index = i;
	}
}
