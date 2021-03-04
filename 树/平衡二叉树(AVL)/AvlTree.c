//
//  AvlTree.c
//  AvlTree
//
//  Created by 颜圣燃 on 2021/2/21.
//

#include "AvlTree.h"
#include <stdlib.h>
struct AvlNode{
    ElementType Element;
    AvlTree left;
    AvlTree right;
    int Height;
};
int max(int a, int b){
    if(a > b)return a;
    else return b;
}
static int Height(Position P){
    if(P == NULL)return -1;
    else return P->Height;
}
AvlTree Insert(ElementType X, AvlTree T){
    if(T == NULL){ //若T是一个空节点则创建一个新的节点
        T = malloc(sizeof(struct AvlNode));
        if(T == NULL)return NULL;
        else{
            T->Element = X;
            T->right = T->left = NULL;
        }
    }else{
        if(X < T->Element){
            T->left = Insert(X, T->left);
            if(Height(T->left) - Height(T->right) == 2){
                if(X < T->left->Element) //LL
                    T = LLRotate(T);
                else T = LRRotate(T); //LR
            }
        }else if(X > T->Element){
            T->right = Insert(X, T->right);
            if(Height(T->right) - Height(T->left) == 2){
                if(X > T->right->Element) //RR
                    T = RRRotate(T);
                else T = RLRotate(T); //RL
            }
        }
        /**若X与T的Element值相等，不进行任何操作*/
    }
    T->Height = max(Height(T->left), Height(T->right)) + 1;
    return T;
}
//单旋转
static Position LLRotate(Position A){
    Position B;
    B = A->left;
    A->left = B->right;
    B->right = A;
    A->Height = max(Height(A->left), Height(A->right)) + 1;
    B->Height = max(Height(B->left), A->Height) + 1;
    return B;
}
static Position RRRotate(Position A){
    Position B;
    B = A->right;
    A->right = B->left;
    B->left = A;
    A->Height = max(Height(A->left), Height(A->right)) + 1;
    B->Height = max(Height(B->right), A->Height) + 1;
    return B;
}
//双旋转
static Position LRRotate(Position A){
    A->left = RRRotate(A->left);
    return LLRotate(A);
}
static Position RLRotate(Position A){
    A->right = LLRotate(A->right);
    return RRRotate(A);
}
