//
//  linkedList.c
//  DataStructure
//
//  Created by yanshengran on 2021/1/20.
//

#include "header/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
struct Node{
    ElementType Element;
    Position Next;
};
//链表初始化
List initList(){
    List l = (List)malloc(sizeof(struct Node));
    l->Element = 0;
    l->Next = NULL;
    return l;
}
//判断链表是否为空
int IsEmpty(List L){
    return L->Next == NULL;
}
//判断节点是否是最后一个元素
int IsLast(Position P, List L){
    return P->Next == NULL;
}
//返回链表的第一个元素
Position getFirst(List L){
    return L->Next;
}
//返回链表的最后一个元素
Position getLast(List L){
    Position p = L;
    while(p->Next != NULL){
        p = p->Next;
    }
    return p;
}
//根据节点值返回节点指针
Position Find(ElementType X, List L){
    Position p;
    p = L->Next;
    while(p != NULL && p->Element != X){
        p = p->Next;
    }
    return p;
}
//根据节点值找到节点的前一个元素
Position FindPrevious(ElementType X, List L){
    Position p;
    p = L;
    while(p->Next!=NULL && p->Next->Element != X){
        p = p->Next;
    }
    return p;
}
//根据节点值删除节点
void Delete(ElementType X, List L){
    Position p, temp;
    p = FindPrevious(X, L);
    temp = p->Next;
    p->Next = temp->Next;
}
//插入节点
void Insert(ElementType X, List L, Position p){
    Position temp;
    temp = (Position)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("动态内存申请失败\n");
        return;
    }
    temp->Element = X;
    temp->Next = p->Next;
    p->Next = temp;
}
//删除列表
void DeleteList(List L){
    Position p, temp;
    p = L->Next;
    L->Next = NULL;
    while(p!=NULL){
        temp = p->Next;
        free(p);
        p = temp;
    }
}
//打印单链表
void printList(List L){
    Position p = L->Next;
    int idx = 0;
    while(p!=NULL){
        printf("idx%d->%d\n",idx,p->Element);
        idx++;
        p = p->Next;
    }
}
