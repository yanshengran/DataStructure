//
//  Graph.h
//  Graph
//
//  Created by 颜圣燃 on 2021/2/10.
//

#ifndef Graph_h
#define Graph_h
#define MAXINT 32767
#define MAXVEXNUM 100
#include <stdio.h>
struct AMGraph;
typedef struct AMGraph* Graph;
typedef int ArcType;
typedef char VerTexType;

int LocateVex(Graph G, VerTexType u);
Graph CreateUDN(int VexNum, VerTexType* VerTex); //初始化一个无向网
int LocateVex(Graph G, VerTexType u);
void AssignWeight(Graph G, VerTexType u1, VerTexType u2, ArcType w);
int GetArrayLength(int* array);
void PrintADjM(Graph G);//打印无向网
void DFS(Graph G, int v, int* visited);//连通图的深度优先遍历
void BFS(Graph G);
int FirstAdjVex(Graph G, int u);
int NextAdjVex(Graph G, int u, int w);
int PrimMST(Graph G);
int KruskalMST(Graph G);
void Dijkstra(Graph G, int v);
void Floyd(Graph G);
#endif /* Graph_h */
