//
//  Array_Queue.c
//  Array_Queue
//  队列的数组实现
//  Created by yanshengran on 2021/1/22.
//

#include "Array_Queue.h"
#include <stdio.h>
#include <stdlib.h>

struct QueueRecord{
    int Capacity; //队列的最大容量
    int Front; //队前
    int Rear; //队尾
    int Size; //队列当前大小
    ElementType *Array;
};
//检查队列是否为空
int IsEmpty(Queue Q){
    return Q->Size == 0;
}
//检查队列是否已满
int IsFull(Queue Q){
    return Q->Size == Q->Capacity;
}
//构造一个空队列
Queue CreateQueue(int MaxElements){
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if(Q == NULL){
        printf("动态内存申请失败！\n");
        return NULL;
    }
    Q->Array = (ElementType*)malloc(sizeof(ElementType)*Q->Capacity);
    if(Q->Array == NULL){
        printf("动态内存申请失败！\n");
        return NULL;
    }
    Q->Front = 1;
    Q->Rear = 0;
    Q->Size = 0;
    Q->Capacity = MaxElements;
    return Q;
}
//清空队列
void MakeEmpty(Queue Q){
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}
//入队
void Enqueue(ElementType X, Queue Q){
    if(IsFull(Q)){
        printf("队列已满！\n");
    }else{
        Q->Size++;
        Q->Rear = (Q->Rear+1)%(Q->Capacity);
        Q->Array[Q->Rear] = X;
    }
}
//取出队前元素
ElementType Front(Queue Q){
    if(IsEmpty(Q)){
        printf("队列已空\n");
        return -1;
    }else{
        return Q->Array[Q->Front];
    }
}
//出队
void Dequeue(Queue Q){
    if(IsEmpty(Q)){
        printf("队列已空\n");
    }else{
        Q->Size--;
        Q->Front = (Q->Front+1)%(Q->Capacity);
    }
}
//出队并返回队前元素
ElementType FrontAndDequeue(Queue Q){
    if(IsEmpty(Q)){
        printf("队列已空！\n");
        return -1;
    }else{
        Q->Size--;
        ElementType ret = Q->Array[Q->Front];
        Q->Front = (Q->Front+1)%(Q->Capacity);
        return ret;
    }
}
