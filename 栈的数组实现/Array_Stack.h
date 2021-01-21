//
//  Array_Stack.h
//  Array_Stack
//  栈的数组实现
//  Created by yanshengran on 2021/1/21.
//

#ifndef Array_Stack_h
#define Array_Stack_h

#include <stdio.h>
struct ArrayStack;
typedef struct ArrayStack* Stack;
typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);
void printStack(Stack S);
#endif /* Array_Stack_h */
