#include "Prim.h"

vector<find_edge> Prim(graph *g, int s)
{
	int V = g->noOfVertices;
	int E = g->noOfEdges;

	vector<vector<pair<int, int>>> G(V);//The weighted undirected graph

	for (int i = 0; i<E; i++)
	{
		int u = g->pEdge[i].source;
		int v = g->pEdge[i].destination;
		int wt = g->pEdge[i].weight;
		G[u].push_back(make_pair(v, wt));
		G[v].push_back(make_pair(u, wt));
	}

	vector<bool>visited(V, false);//whether the vertex is visited or not
	vector<int> d(V, MAX);//all distance initialised
	vector<int> par(V, -1);//parent of the vertex
	vector<find_edge> edge;//The edges of the MST :weight-(src-dest)


	set<pair<int, int>> Q;//set is a RBT.Since this is a set of pairs.A pair(i,j)<pair(l,m) if i<l.if i=l then j<m
	for (int i = 0; i < V; i++)
	{
		Q.insert(make_pair(d[i], i));//Insert all the vertices in the Queue
	}

	Q.erase(Q.find(make_pair(d[s], s)));
	d[s] = 0;//Thus in this set the first element is an edge weight since we want it to be sorted by edge weights
	Q.insert(make_pair(d[s], s));

	while (!Q.empty())
	{
		pair<int, int> top = *Q.begin();
		Q.erase(Q.begin());
		int v = top.second;//the vertex whose adjacent vertices have to be analyzed
		visited[v] = true;

		if (v != s)//ie v isn't the source vertex since in the first iteration we have the source vertex
		{
			edge.push_back(make_pair(d[v], make_pair(par[v], v)));
		}

		for (int i = 0; i<G[v].size(); i++)
		{
			if (visited[G[v][i].first] == false)//The vertex isn't visited only their d[] will change
			{
				int v2 = G[v][i].first;
				int cost = G[v][i].second;//weight of edge v,v2
				if (d[v2]>cost)
				{
					Q.erase(Q.find(make_pair(d[v2], v2)));
					d[v2] = cost;
					Q.insert(make_pair(d[v2], v2));
					par[v2] = v;//parent will be updated in this loop
				}
			}
		}
	}
	return edge;
	
}

int Prepair_Prim_MST_test(FILE* f)
{
	graph *g;
	vector<find_edge> mst;
	int ct = 0;
	g = loadGraph(f);

	printf("\nPrim's algorithm!\n\n");
	cout << "Choose start vertex from 0 to " << g->noOfVertices - 1 << endl;
	int s;
	cin >> s;

	mst=Prim(g, s);

	printf("MST CONTAINS THE FOLLOWING EDGES:\n\n");
	for (int i = 0; i < mst.size(); i++)
	{
		printf("%d\t<-\t(weight %d )\t->\t%d\n", mst[i].second.first, mst[i].first, mst[i].second.second);
		ct += mst[i].first;
	}
	printf("\n\nTOTAL COST OF THE MST  = %d \n\n", ct);

	return ct;
}

int Prepair_Prim_MST_Graph_gen(FILE* f)
{
	graph *g;
	vector<find_edge> mst;
	int ct = 0;
	g = loadGraph(f);

	printf("\nPrim's algorithm!\n\n");
	cout << "Choose start vertex from 0 to " << g->noOfVertices - 1 << endl;
	int s;
	cin >> s;

	mst = Prim(g, s);

	for (int i = 0; i < mst.size(); i++)
	{
		ct += mst[i].first;
	}
	printf("\n\nTOTAL COST OF THE MST  = %d \n\n", ct);

	return ct;
}
