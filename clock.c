#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

int clock_hand;

/* Page to evict is chosen using the clock algorithm.
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */

int clock_evict() {
	int evict_index = -1;

	while (evict_index == -1) {
		if (coremap[clock_hand].ref_bit) {
			coremap[clock_hand].ref_bit = 0;
		} else {
			evict_index = clock_hand;
		}

		clock_hand++;
	
		if (clock_hand == memsize) {
			clock_hand = 0;
		}
	}

	return evict_index;
}

/* This function is called on each access to a page to update any information
 * needed by the clock algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void clock_ref(pgtbl_entry_t *p) {

	coremap[p->frame >> PAGE_SHIFT].ref_bit = 1;
}

/* Initialize any data structures needed for this replacement
 * algorithm. 
 */
void clock_init() {

	clock_hand = 0;
}
