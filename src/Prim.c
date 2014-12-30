#include "graph.h"
#include "MinHeap.h"


void PrimMST(Graph* graph) 
{
	int V = graph->V;		
	int parent[nr_vertex];
	int key[nr_vertex];    

	MinHeap* minHeap = createMinHeap(V);

	for (int v = 1; v < V; ++v)
	{
		parent[v] = -1;
		key[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, key[v]);
		minHeap->pos[v] = v;
	}

	key[0] = 0;
	minHeap->array[0] = newMinHeapNode(0, key[0]);
	minHeap->pos[0] = 0;
	minHeap->size = V;
	while (!isEmpty(minHeap))
	{
		MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v;
		ListNode* l_nod = graph->array[u].head;
		while (l_nod != NULL)
		{
			int v = l_nod->dest;
			if (isInMinHeap(minHeap, v) && l_nod->weight < key[v]) 
			{
				key[v] = l_nod->weight;
				parent[v] = u;
				decreaseKey(minHeap, v, key[v]);
			}
			l_nod = l_nod->next;
		}
	}
	printSol(parent, V,key);
}
