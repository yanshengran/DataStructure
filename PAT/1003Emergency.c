#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 0x3f3f3f
int main(){
    int N, M, C1, C2;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    int* visited = (int*)malloc(sizeof(int)*N); //储存节点是否已访问过的信息
    for(int i = 0; i < N; i++)visited[i] = 0;
    int* peopleNum = (int*)malloc(sizeof(int)*N); //储存每个节点含有的人数
    for(int i = 0; i < N; i++)scanf("%d", &peopleNum[i]);
    int* Dist = (int*)malloc(sizeof(int)*N); //储存每个节点最短距离的数组
    for(int i = 0; i < N; i++)Dist[i] = MAXLEN;
    int** ADjM = (int**)malloc(sizeof(int*)*N); //邻接矩阵
    for(int i = 0; i < N; i++)ADjM[i] = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ADjM[i][j] = MAXLEN;
        }
    }
    int c1, c2, l, cur = C1;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &c1,&c2,&l);
        ADjM[c1][c2] = ADjM[c2][c1] = l;
    }
    int* num = (int*)malloc(sizeof(int)*N); //到达每个节点后可搜寻到的最大人数
    int* lnum = (int*)malloc(sizeof(int)*N); //到达每个节点的最短路径条数
    for(int i = 0; i < N; i++){
        num[i] = 0;
        lnum[i] = 0;
    }
    Dist[cur] = 0;
    visited[cur] = 1;
    num[cur] = peopleNum[cur];
    lnum[cur] = 1;
    //Dijkstra
    for(int vexnum = 0; vexnum < N; vexnum++){
        //update
        for(int i = 0; i < N; i++){
            if((visited[i] == 0) && (ADjM[cur][i] != MAXLEN)){
                if(ADjM[cur][i] + Dist[cur] < Dist[i])
                {
                    Dist[i] = ADjM[cur][i] + Dist[cur];
                    num[i] = peopleNum[i] + num[cur]; //更新节点人数
                    lnum[i] = lnum[cur]; //更新路径数量
                }else if(ADjM[cur][i] + Dist[cur] == Dist[i]){
                    lnum[i] = lnum[i] + lnum[cur]; //更新路径数量
                    if(num[cur] + peopleNum[i] > num[i])
                        num[i] = num[cur] + peopleNum[i]; //保留人数的最大值
                }
            }
        }
        //scan
        int Min = MAXLEN, add = -1;
        for(int i = 0; i < N; i++){
            if(visited[i] == 0 && Dist[i] < Min){
                Min = Dist[i];
                add = i;
            }
        }
        //add
        if(add == -1)break;
        visited[add] = 1;
        cur = add;
    }
    printf("%d %d",lnum[C2], num[C2]);
    free(visited);
    free(peopleNum);
    free(num);
    free(lnum);
    free(Dist);
    for(int i = 0; i < N; i++)free(ADjM[i]);
    free(ADjM);
    return 0;
}
