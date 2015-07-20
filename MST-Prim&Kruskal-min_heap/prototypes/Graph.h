#ifndef graph_H
#define graph_H

#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include <functional>
#include <fstream>
#include <conio.h>
#include <time.h>
using namespace std;

typedef struct edge	{					//structure for edge
	int source;							//source vertex
	int destination;					//destination vertex
	int weight;							//edge weight
}edge;

typedef struct graph {					//structure for graph
	int noOfVertices;					//number of vertixes
	int noOfEdges;						//number of edges
	edge *pEdge;						//edges
}graph;



struct comparator{
	int operator()(const edge &e1, const edge &e2)
	{
		if (e1.weight > e2.weight)
			return 1;
		return 0;
	}
};

typedef priority_queue<edge, vector<edge>, comparator> min_heap;
typedef pair<int, pair<int, int> > find_edge;

graph* loadGraph(FILE* fp);	
void graphGenerator(char * fileName);
#endif;