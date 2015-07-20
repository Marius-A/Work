#ifndef _Prim_H_
#define _Prim_H_

#include "Graph.h"		//--From Core--

#define MAX 1e8//very large number

vector<find_edge> Prim(graph*, int, vector<vector<pair<int, int>>>);
int Prepair_Prim_MST_test(FILE* f);
int Prepair_Prim_MST_Graph_gen(FILE* f);

#endif