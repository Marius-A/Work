#include "graph.h"
#include "MinHeap.h"

/* Creaza un nou nod in lista de adiacenta*/
ListNode* newListNode(int dest, int weight) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

/* Creaza un graf cu V noduri*/
Graph* createGraph(int V) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->array = (AdjList*)malloc(V * sizeof(AdjList));
	for (int i = 0; i < V; ++i)
	{
		graph->array[i].head = NULL;
	}
	return graph;
}

/* Adauga o muchie la un graf*/
void addEdge(Graph*  graph, int src, int dest, int weight) 
{
	ListNode* newNode = newListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	newNode = newListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

/*Creaza un nod in min_heap*/
MinHeapNode *newMinHeapNode(int v, int key) 
{
	MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->key = key;
	return minHeapNode;
}

/* Creaza un Min Heap*/
MinHeap *createMinHeap(int capacity)
{
	MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
	return minHeap;
}

/*Interschimba doua noduri din min heap*/
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) 
{
	MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

/*Pastreaza proprietatea de minheap a structurii*/
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

/* Functie utilizata pentru a reduce valoarea key a unui anumit nod v. 
	Această functie utilizeaza poz [] min-heap-ului pentru a obtine indicele actual al nodului in min heap*/
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

/* Verifica daca un anumit nod "v" este in min heap sau nu*/
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

/* Tipareste arborele minim de acoperire.*/
void printSol(int arr[], int n,int m[])
{
	int x=0;
	printf("\nMUCHIILE CONTINUTE IN ARBORELE MINIM DE ACOPERIRE:\n\n");
	for (int i = 1; i <n; ++i) 
	{
		printf("Muchia %d <---> %d cu costul %d\n", arr[i], i, m[i]);
		x += m[i];
	}
	printf("\nCostul total al arborelui minim de acoperire este:%d\n",x);
}