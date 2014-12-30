#ifndef __MinHeap_H__
#define __MinHeap_H__

#include "graph.h"

/*--------begin.min_heap.structures---------*/
typedef struct MinHeapNode {
	int  v;			// number of vertices
	int key;		// key value of a vertex
} MinHeapNode;


typedef struct MinHeap {
	int size;				// actual number of nodes from min_heap,
	int capacity;				// capacity of min_heap
	int *pos;				
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
