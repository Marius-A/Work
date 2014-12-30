#ifndef __Graph_H__
#define __Graph_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define nr_vertex 25


/*--------begin.linked_list.structures---------*/
typedef struct ListNode {
	int dest;
	int weight;
	struct ListNode* next;
} ListNode;

typedef struct AdjList {
	struct ListNode *head;  
} AdjList;
/*--------end.linked_list.structures----------*/



/*--------begin.graph.structures---------*/
typedef struct Graph {
	int V;						 // numarul de noduri din graf
	struct AdjList* array;		 // graful este vazut ca un vector de liste de adiacenta
} Graph;
/*--------end.graph.structures----------*/




/*--------begin.functions.prototypes---------*/
ListNode* newListNode(int, int);
Graph* createGraph(int);
void addEdge(Graph*, int, int, int);
/*--------end.functions.prototypes----------*/

#endif