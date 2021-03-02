//
//  Graph.c
//  Graph
//
//  Created by 颜圣燃 on 2021/2/10.
//

#include "Graph.h"
#include <stdlib.h>
#include <stdio.h>
struct AMGraph{
    VerTexType* vexs; //顶点表
    ArcType** arcs; //邻接矩阵
    int vexnum, arcnum; //图的当前点数和边数
};
Graph CreateUDN(int VexNum, VerTexType* VerTex){//创建无向网
    if(VexNum <= 1){
        printf("节点个数过少！\n");
        return NULL;
    }
    Graph G = (Graph)malloc(sizeof(struct AMGraph));
    G->vexs = (VerTexType*)malloc(sizeof(VerTexType)*VexNum);
    G->arcs = (ArcType**)malloc(sizeof(ArcType*)*VexNum);
    G->vexnum = VexNum;
    G->arcnum = 0;
    for(int i = 0; i < VexNum; i++){
        G->arcs[i] = (ArcType*)malloc(sizeof(ArcType)*VexNum);
    }
    for(int i = 0; i < VexNum; i++){//传递节点信息
        G->vexs[i] = VerTex[i];
    }
    for(int i = 0; i < VexNum; i++){
        for(int j = 0; j < VexNum; j++){
            if(i != j)G->arcs[i][j] = MAXINT;
            else G->arcs[i][j] = 0;
        }
    }
    return G;
}
int LocateVex(Graph G, VerTexType u){
    for(int i = 0; i!=G->vexnum; i++)if(G->vexs[i] == u)return i;
    return -1;
}
void AssignWeight(Graph G, VerTexType u1, VerTexType u2, ArcType w){
    int idx1 = LocateVex(G, u1);
    int idx2 = LocateVex(G, u2);
    if(G->arcs[idx1][idx2] != MAXINT)G->arcnum++;
    G->arcs[idx1][idx2] = w;
    G->arcs[idx2][idx1] = w;
}
void PrintADjM(Graph G){
    for(int i = 0; i < G->vexnum; i++){
        for(int j = 0; j < G->vexnum; j++){
            printf("%-7d ",G->arcs[i][j]);
        }
        printf("\n");
    }
}
void DFS(Graph G, int v, int* visited){
    printf("%d ", v);
    visited[v] = 1;
    for(int w = 0; w < G->vexnum; w++)
    if((G->arcs[v][w] != MAXINT) && (visited[w] != 1))
        DFS(G, w, visited);
}
void BFS(Graph G){
    int* visited = (int*)malloc(sizeof(int)*G->vexnum);
    for(int i = 0; i < G->vexnum; i++){
        visited[i] = 0;
    }
    int* queue = (int*)malloc(sizeof(int)*G->vexnum);
    int front = 0, rear = 0;
    queue[rear] = 0;rear = (rear+1)%G->vexnum;
    printf("%d ",queue[front]);
    visited[0] = 1;
    while(front != rear){
        int u = queue[front];
        front = (front+1)%G->vexnum;
        for(int w = FirstAdjVex(G, u); w != -1; w = NextAdjVex(G, u, w)){
            if(visited[w] != 1){
                printf("%d ",w);
                visited[w] = 1;
                queue[rear] = w;
                rear = (rear+1)%G->vexnum;
            }
        }
    }
}
int FirstAdjVex(Graph G, int u){
    for(int i = 0; i < G->vexnum; i++)
        if(G->arcs[u][i] != MAXINT)return i;
    return -1;
}
int NextAdjVex(Graph G, int u, int w){
    for(int i = w + 1; i < G->vexnum; i++)
        if(G->arcs[u][i] != MAXINT)return i;
    return -1;
}

int PrimMST(Graph G){
    int* U = (int*)malloc(sizeof(int)*G->vexnum); //已添加的节点
    int* added = (int*)malloc(sizeof(int)*G->vexnum); //用于标记节点是否在U集合中的数组
    int MinCost = MAXINT;
    for(int i = 0; i < G->vexnum; i++)added[i] = 0;
    U[0] = 0; //设图G顶点表中的第一个节点为最小生成树的初始顶点。
    added[0] = 1;
    int vexcount = 1, curu = -1, curv = -1, TotalCost = 0;
    while(vexcount < G->vexnum){
        for(int i = 0; i < vexcount; i++){
            for(int j = 0; j < G->vexnum; j++){
                if(G->arcs[U[i]][j] < MinCost && added[j] == 0){
                    curu = U[i];
                    curv = j;
                    MinCost = G->arcs[U[i]][j];
                }
            }
        }
        printf("%d   %d\n", curu, curv);
        added[curv] = 1;
        U[vexcount] = curv;
        vexcount++;
        TotalCost += MinCost;
        MinCost = MAXINT;
    }
    free(U);
    free(added);
    return TotalCost;
}

int KruskalMST(Graph G){
    int* label = (int*)malloc(sizeof(int)*G->vexnum);
    int* visited = (int*)malloc(sizeof(int)*G->vexnum);
    for(int i = 0; i < G->vexnum; i++)visited[i] = 0;
    for(int i = 0; i < G->vexnum; i++)label[i] = i;
    int MinCost = MAXINT, edgenum = 0, curi = -1, curj = -1, TotalCost = 0;
    while(edgenum != G->vexnum - 1){
        for(int i = 0; i < G->vexnum; i++){
            for(int j = 0; j < i; j++){
                if(G->arcs[i][j] < MinCost && label[i] != label[j]){
                    MinCost = G->arcs[i][j];
                    curi = i;
                    curj = j;
                }
            }
        }
        if(visited[curi] == 1)
            label[curj] = label[curi];
        else label[curi] = label[curj];
        visited[curi] = 1;
        visited[curj] = 1;
        printf("%d   %d\n",curi, curj);
        TotalCost += MinCost;
        MinCost = MAXINT;
        edgenum++;
    }
    free(label);
    free(visited);
    return TotalCost;
}

void Dijkstra(Graph G, int v){
    //Visited数组用于表示节点是否被访问
    int* Visited = (int*)malloc(sizeof(int)*G->vexnum);
    //Distance数组用于表示起始点到各个节点的最短距离
    int* Distance = (int*)malloc(sizeof(int)*G->vexnum);
    //Parent数组用于表示当前节点的前驱
    int* Parent = (int*)malloc(sizeof(int)*G->vexnum);
    for(int i = 0; i < G->vexnum; i++){//初始化三个数组
        Visited[i] = 0;
        Distance[i] = MAXINT;
        Parent[i] = -1;
    }
    Visited[v] = 1;
    Distance[v] = 0;
    Parent[v] = -2; //起始点的父节点设置为-2
    int visitednum = 1, cur = v; //设置当前节点为v
    while(visitednum < G->vexnum){
        //Update
        for(int i = 0; i < G->vexnum; i++){//若从起始点到当前节点的距离与边的权值之和小于此节点的距离则更新
            if(Visited[i] == 0 && (G->arcs[cur][i] + Distance[cur] < Distance[i])){
                Distance[i] = G->arcs[cur][i] + Distance[cur];
                Parent[i] = cur;
            }
        }
        //Scan
        int Min = MAXINT, add = -1;
        for(int i = 0; i < G->vexnum; i++){//找出未访问的节点中距离最小的节点
            if(Visited[i] == 0 && Distance[i] < Min){
                Min = Distance[i];
                add = i;
            }
        }
        //Add
        Visited[add] = 1;//将未访问的节点中距离最小的设置为已访问
        visitednum++;//更新已访问的节点数
        cur = add;
    }
    for(int i = 0; i < G->vexnum; i++){//打印最短距离
        printf("%d ", Distance[i]);
    }
    printf("\n");
    for(int i = 0; i < G->vexnum; i++){//打印父节点信息
        printf("%d ", Parent[i]);
    }
}

void Floyd(Graph G){
    //分配空间
    int** Distance = (int**)malloc(sizeof(int*)*G->vexnum);
    for(int i = 0; i < G->vexnum; i++)Distance[i] = (int*)malloc(sizeof(int)*G->vexnum);
    int** Source = (int**)malloc(sizeof(int*)*G->vexnum);
    for(int i = 0; i < G->vexnum; i++)Source[i] = (int*)malloc(sizeof(int)*G->vexnum);
    for(int i = 0; i < G->vexnum; i++){
        for(int j = 0; j < G->vexnum; j++){
            Distance[i][j] = G->arcs[i][j];
            if(i != j)Source[i][j] = j;
            else Source[i][j] = -1;
        }
    }
    //算法主体
    for(int k = 0; k < G->vexnum; k++){
        for(int i = 0; i < G->vexnum; i++){
            for(int j = 0; j < G->vexnum; j++){
                if(Distance[i][k] + Distance[k][j] < Distance[i][j]){
                    Distance[i][j] = Distance[i][k] + Distance[k][j];
                    Source[i][j] = Source[i][k];
                }
            }
        }
    }
    //打印距离矩阵
    printf("Distance Matrix:\n");
    for(int i = 0; i < G->vexnum; i++){
        for(int j = 0; j < G->vexnum; j++){
            printf("%5d", Distance[i][j]);
        }
        printf("\n");
    }
    //打印路径矩阵
    printf("Source Matrix:\n");
    for(int i = 0; i < G->vexnum; i++){
        for(int j = 0; j < G->vexnum; j++){
            printf("%5d", Source[i][j]);
        }
        printf("\n");
    }
    //释放空间
    for(int i = 0; i < G->vexnum; i++){
        free(Distance[i]);
        free(Source[i]);
    }
    free(Distance);
    free(Source);
}
