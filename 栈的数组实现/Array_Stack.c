//
//  Array_Stack.c
//  Array_Stack
//  栈的数组实现
//  Created by yanshengran on 2021/1/21.
//

#include "Array_Stack.h"
#include <stdio.h>
#include <stdlib.h>
#define EmptyTOS (-1)
#define MinStackSize (5)

struct ArrayStack{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};
//判断是否为空栈
int IsEmpty(Stack S){
    return S->TopOfStack == EmptyTOS;
}
//判断栈是否已满
int IsFull(Stack S){
    return S->TopOfStack == S->Capacity-1;
}
//构造栈
Stack CreateStack(int MaxElements){
    Stack S;
    if(MaxElements < MinStackSize){printf("Stack size is too small!\n");return NULL;}
    S = (Stack)malloc(sizeof(struct ArrayStack));
    if(S == NULL){
        printf("动态内存申请失败！\n");
        return NULL;
    }
    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if(S->Array == NULL){
        printf("动态内存申请失败\n");
        return NULL;
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}
//清空栈
void MakeEmpty(Stack S){
    S->TopOfStack = EmptyTOS;
}
//销毁栈
void DisposeStack(Stack S){
    if(S != NULL){
        free(S->Array);
        free(S);
    }
}
//压栈
void Push(ElementType X, Stack S){
    if(!IsFull(S)){
        S->TopOfStack++;
        S->Array[S->TopOfStack] = X;
    }else printf("栈已满！\n");
}
//取出栈顶元素
ElementType Top(Stack S){
    if(IsEmpty(S)){printf("这是空栈\n");return 0;}
    else return S->Array[S->TopOfStack];
}
//出栈
void Pop(Stack S){
    if(IsEmpty(S)){printf("这是空栈\n");}
    else S->TopOfStack--;
}
//取出栈顶元素并删除
ElementType TopAndPop(Stack S){
    if(IsEmpty(S)){printf("这是空栈\n");return 0;}
    else return S->Array[S->TopOfStack--];
}
//打印栈
void printStack(Stack S){
    if(IsEmpty(S)){printf("这是空栈\n");return;}
    else{
        int idx = 0, i = S->TopOfStack;
        while(i >= 0){
            printf("idx%d->%d\n",idx,S->Array[i]);
            i--;
            idx++;
        }
    }
}
