//
//  DoublyLinkedList.c
//  DataStructure
//  双向链表
//  Created by 颜圣燃 on 2021/1/21.
//

#include "header/DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
struct DoublyNode{
    ElementType element;
    DoublyPosition previous;
    DoublyPosition next;
};
//初始化双向链表
DoublyList initDoublyList(){
    DoublyList L = (DoublyList)malloc(sizeof(struct DoublyNode));
    if(L == NULL)printf("动态内存申请失败\n");
    else{
        L->element = 0;
        L->next = NULL;
        L->previous = NULL;
    }
    return L;
}
//判断链表是否为空
int IsEmpty(DoublyList L){
    return L->next == NULL;
}
//判断是否为最后一个元素
int IsLast(DoublyPosition P){
    return P->next == NULL;
}
//返回链表的第一个节点
DoublyPosition getFirst(DoublyList L){
    return L->next;
}
//返回链表的最后一个元素
DoublyPosition getLast(DoublyList L){
    DoublyPosition P = L->next;
    while(P->next != NULL){
        P = P->next;
    }
    return P;
}
//根据节点值查找节点
DoublyPosition Find(ElementType X, DoublyList L){
    DoublyPosition P = L->next;
    while(P != NULL && P->element != X){
        P = P->next;
    }
    return P;
}
//根据节点值删除节点
void DeleteNode(ElementType X, DoublyList L){
    DoublyPosition P = Find(X,L);
    if(P == NULL){printf("此节点不存在\n"); return;}
    P->previous->next = P->next;
    if(!IsLast(P))P->next->previous = P->previous;
    free(P);
}
//根据节点值返回节点前一个元素
DoublyPosition getPrevious(ElementType X, DoublyList L){
    if(Find(X, L) == NULL){printf("此节点不存在\n");return NULL;}
    else return Find(X, L)->previous;
}
//向链表中插入一个元素
void Insert(ElementType X, DoublyList L, DoublyPosition P){
    DoublyPosition dp = (DoublyPosition)malloc(sizeof(struct DoublyNode));
    dp->element = X;
    dp->next = P->next;
    dp->previous = P;
    if(!IsLast(P))P->next->previous = dp;
    P->next = dp;
}
//删除链表
void DeleteList(DoublyList L){
    DoublyPosition P, temp;
    P = L->next;
    L->next = NULL;
    while(P != NULL){
        temp = P->next;
        free(P);
        P = temp;
    }
}
//打印链表
void printList(DoublyList L){
    DoublyPosition P = L->next;
    int idx = 0;
    while(P!=NULL){
        printf("idx%d->%d\n",idx,P->element);
        idx++;
        P = P->next;
    }
}
