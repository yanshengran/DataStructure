//
//  Linked_Stack.h
//  Linked_Stack
//  栈的链表实现
//  Created by yanshengran on 2021/1/21.
//

#ifndef Linked_Stack_h
#define Linked_Stack_h

#include <stdio.h>
struct Node;
typedef struct Node* Stack;
typedef struct Node* PtrToNode;
typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
void printStack(Stack S);
#endif /* Linked_Stack_h */
