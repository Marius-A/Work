#include "Kruskal.h"

vector<find_edge> Kruskal(graph * G)
{
	min_heap q;
	vector<find_edge> mst;
	map<int, int> joined;
	int i;
	int n = G->noOfVertices;

	for (int i = 0; i<G->noOfEdges; i++)
	{
		q.push(G->pEdge[i]);
	}

	for (i = 0; i < n; i++)
	{
		joined[i] = i;
	}

	while (!q.empty())
	{
		int u, v, w;
		u = q.top().source;
		v = q.top().destination;
		w = q.top().weight;

		int parent_u = joined[u];
		int parent_v = joined[v];
		if (parent_u != parent_v)	//ne asiguram ca nu exista cicluri
		{
			mst.push_back(make_pair(w, make_pair(u, v)));
			for (i = 0; i < n; i++)
			{
				if (joined[i] == parent_v)
				{
					joined[i] = parent_u;
				}
			}
		}
		q.pop();
	}
	return mst;
}

int Prepair_Kruskall_MST_test(FILE* f)
{
	int ct = 0;
	graph *g;
	g = loadGraph(f);
	vector<find_edge> mst;
	mst = Kruskal(g);
	printf("\nKruskall's algorithm!\n\n");
	printf("MST CONTAINS THE FOLLOWING EDGES:\n\n");

	for (int i = 0; i < mst.size(); i++)
	{
		printf(" %d\t<-\t(weight %d)\t->\t%d\n", mst[i].second.first, mst[i].first, mst[i].second.second);
		ct += mst[i].first;
	}
	printf("\n\nTOTAL COST OF THE MST  = %d \n\n", ct);

	return ct;
}

int Prepair_Kruskall_MST_Graph_gen(FILE* f)
{
	int ct = 0;
	graph *g;
	g = loadGraph(f);
	vector<find_edge> mst;
	mst = Kruskal(g);
	printf("\nKruskall's algorithm!\n\n");

	for (int i = 0; i < mst.size(); i++)
	{
		ct += mst[i].first;
	}
	printf("\n\nTOTAL COST OF THE MST  = %d \n\n", ct);

	return ct;
}