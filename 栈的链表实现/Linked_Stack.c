//
//  Linked_Stack.c
//  Linked_Stack
//  栈的链表实现
//  Created by yanshengran on 2021/1/21.
//

#include "Linked_Stack.h"
#include <stdio.h>
#include <stdlib.h>
struct Node{
    ElementType element;
    PtrToNode Next;
};
//检查栈是否为空
int IsEmpty(Stack S){
    return S->Next == NULL;
}
//创建一个空栈
Stack CreateStack(void){
    Stack S = (Stack)malloc(sizeof(struct Node));
    if(S == NULL){printf("动态内存申请失败！\n");return NULL;}
    S->Next = NULL;
    S->element = 0;
    return S;
}
//清空栈
void MakeEmpty(Stack S){
    S->Next = NULL;
}
//压栈
void Push(ElementType X, Stack S){
    PtrToNode n = (PtrToNode)malloc(sizeof(struct Node));
    if(n == NULL){printf("动态内存申请失败！\n");return;}
    n->element = X;
    n->Next = S->Next;
    S->Next = n;
}
//返回栈顶元素
ElementType Top(Stack S){
    if(S->Next == NULL){printf("这是空栈！\n");return 0;}
    else return S->Next->element;
}
//出栈
void Pop(Stack S){
    if(S->Next == NULL){printf("这是空栈！\n");return;}
    else{
        PtrToNode n = S->Next;
        S->Next = S->Next->Next;
        free(n);
    }
}
//打印栈
void printStack(Stack S){
    PtrToNode n = S->Next;
    int idx = 0;
    while(n != NULL){
        printf("idx%d->%d\n",idx,n->element);
        idx++;
        n = n->Next;
    }
}
