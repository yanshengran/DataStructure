//
//  DoublyLinkedList.h
//  DataStructure
//  双向链表
//  Created by yanshengran on 2021/1/21.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <stdio.h>

struct DoublyNode;
typedef struct DoublyNode* DoublyList;
typedef struct DoublyNode* DoublyPosition;
typedef int ElementType;

DoublyList initDoublyList(void); //初始化一个双向链表
int IsEmpty(DoublyList L); //检查链表是否为空
int IsLast(DoublyPosition P); //查看节点是否为链表的最后一个元素
DoublyPosition getFirst(DoublyList L); //返回链表的第一个元素
DoublyPosition getLast(DoublyList L); //返回链表的最后一个元素
DoublyPosition Find(ElementType X, DoublyList L); //根据节点值返回节点指针
void DeleteNode(ElementType X, DoublyList L); //根据节点值删除节点
DoublyPosition getPrevious(ElementType X, DoublyList L); //根据节点值找到前一个节点
void Insert(ElementType X, DoublyList L, DoublyPosition P); //向链表中插入一个元素
void DeleteList(DoublyList L); //删除链表
void printList(DoublyList L); //打印链表

#endif /* DoublyLinkedList_h */
