#include "graph.h"
#include "MinHeap.h"
#include "Prim.h"

int main()
{
	int k, src, dst, cost, cnx, V;
	FILE *f;

	f = fopen("imput.in", "r+");

	fscanf(f, "%d", &V);
	Graph* graph = createGraph(V);

	fscanf(f, "%d", &cnx);				/*number of conexions (edges)*/

	for (k = 0; k <cnx; k++)
	{
		fscanf(f, "%d", &src);
		fscanf(f, "%d", &dst);
		fscanf(f, "%d", &cost);
		addEdge(graph, src, dst, cost);
	}
	fclose(f);


	PrimMST(graph);

	system("pause");

	return 0;
}
