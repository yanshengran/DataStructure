//
//  Array_Queue.h
//  Array_Queue
//  队列的数组实现
//  Created by yanshengran on 2021/1/22.
//

#ifndef Array_Queue_h
#define Array_Queue_h

#include <stdio.h>
struct QueueRecord;
typedef struct QueueRecord* Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif /* Array_Queue_h */
