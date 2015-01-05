#include "graph.h"
#include "MinHeap.h"

/* Create a new node in the adjacency list*/
ListNode* newListNode(int dest, int weight)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

/* Create a graph with V vertices*/
Graph* createGraph(int V)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->array = (AdjList*)malloc(V * sizeof(AdjList));
	for (int i = 0; i < V; ++i)
	{
		graph->array[i].head = NULL;
	}
	return graph;
}

/* Add an edge to a graph*/
void addEdge(Graph*  graph, int src, int dest, int weight) 
{
	ListNode* newNode = newListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	newNode = newListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

/*Create e new node in min_heap*/
MinHeapNode *newMinHeapNode(int v, int key) 
{
	MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->key = key;
	return minHeapNode;
}

/* Create a new Min Heap*/
MinHeap *createMinHeap(int capacity)
{
	MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
	return minHeap;
}

/*Exchange 2 nodes from min heap*/
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) 
{
	MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

/*Keep the properties of min heap structure*/
void minHeapify(MinHeap* minHeap, int idx) 
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
	{
		smallest = left;
	}
	if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key) 
	{
		smallest = right;
	}
	if (smallest != idx)
	{
		MinHeapNode *smallestNode = minHeap->array[smallest];
		MinHeapNode *idxNode = minHeap->array[idx];
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

/* Verifica dacA minHeap-ul dat este gol sau nu*/
int isEmpty(MinHeap* minHeap)
{
	return minHeap->size == 0;
}

/* Extrage nodul de cost minim din min-heap*/
MinHeapNode* extractMin(MinHeap* minHeap) 
{
	MinHeapNode* root, *lastNode ;
	if (isEmpty(minHeap))
	{
		return NULL;
	}
	root = minHeap->array[0];
	lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;
	--minHeap->size;
	minHeapify(minHeap, 0);	
	return root;
}

void decreaseKey(MinHeap* minHeap, int v, int key)
{
	int i = minHeap->pos[v];
	minHeap->array[i]->key = key;

	while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
	{
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

/* Check if a particular node v is in min heap or not*/
int isInMinHeap(MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* Print the minimum spanning tree.*/
void printSol(int arr[], int n,int m[])
{
	int x=0;
	printf("\nEDGE CONTAINED IN THE MINIMUM SPANNING TREE:\n\n");
	for (int i = 1; i <n; ++i) 
	{
		printf("Edge %d <---> %d with cost %d\n", arr[i], i, m[i]);
		x += m[i];
	}
	printf("\nThe total cost of minimum spanning tree:%d\n",x);
}
