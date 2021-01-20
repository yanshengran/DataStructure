//
//  linkedList.h
//  数据结构
//  单链表的定义
//  Created by yanshengran on 2021/1/20.
//

#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List; //表头节点的指针
typedef PtrToNode Position;
typedef int ElementType;

List initList(void);//初始化一个单链表
int IsEmpty(List L);//判断链表是否为空
int IsLast(Position P, List L);//判断节点是否为最后一个元素
Position getFirst(List L);//返回链表的第一个元素
Position getLast(List L);//返回链表的最后一个元素
Position Find(ElementType X, List L);//根据值查找链表节点
void Delete(ElementType X, List L);//根据节点值删除节点
Position FindPrevious(ElementType X, List L);//根据值找到前一个节点
void Insert(ElementType X, List L, Position P);//在指定位置插入节点
void DeleteList(List L);//删除链表
void printList(List L);//打印单链表
Position Advance(Position P);
ElementType Retrieve(Position P);
#endif /* linkedList_h */
