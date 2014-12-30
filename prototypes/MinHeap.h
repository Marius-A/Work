#ifndef __MinHeap_H__
#define __MinHeap_H__

#include "graph.h"

/*--------begin.min_heap.structures---------*/
typedef struct MinHeapNode {
	int  v;			// numarul de noduri
	int key;		// valaoarea nodului
} MinHeapNode;


typedef struct MinHeap {
	int size;				// nr  curent noduri heap,
	int capacity;		    // capacitatea heap-ului
	int *pos;				// pozitia nodului necesara pt functia decresing key
	struct MinHeapNode **array;
} MinHeap;
/*--------end.min_heap.structures----------*/



/*--------begin.functions.prototypes-----------*/
MinHeapNode *newMinHeapNode(int, int);
MinHeap *createMinHeap(int);
void swapMinHeapNode(MinHeapNode**, MinHeapNode**);
void minHeapify(MinHeap*, int);
int isEmpty(MinHeap*);
MinHeapNode* extractMin(MinHeap*);
void decreaseKey(MinHeap*, int, int);
int isInMinHeap(MinHeap*, int);
/*----------end.functions.prototypes-----------*/

#endif