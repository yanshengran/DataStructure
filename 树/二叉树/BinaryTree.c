//
//  BinaryTree.c
//  BinaryTree
//
//  Created by 颜圣燃 on 2021/1/27.
//

#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
struct TreeNode{
    ElementType element;
    Node left;
    Node right;
};
BinaryTree InitBiTree(ElementType X){
    BinaryTree BT = (BinaryTree)malloc(sizeof(struct TreeNode));
    BT->element = X;
    BT->left = NULL;
    BT->right = NULL;
    return BT;
}
BinaryTree MakeEmpty(BinaryTree T){
    if(T != NULL){
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}
Node Find(ElementType X, BinaryTree T){
    if(T == NULL)return NULL;
    if(X < T->element)return Find(X, T->left);
    if(X > T->element)return Find(X, T->right);
    else return T;
}
Node FindMin(BinaryTree T){
    if(T == NULL)return NULL;
    while(T->left != NULL){
        T = T->left;
    }return T;
}
Node FindMax(BinaryTree T){
    if(T == NULL)return NULL;
    while(T->right != NULL){
        T = T->right;
    }return T;
}
BinaryTree Insert(ElementType X, BinaryTree T){
    if(T == NULL){
        T = (BinaryTree)malloc(sizeof(struct TreeNode));
        if(T == NULL){printf("动态内存申请失败！");}
        T->element = X;
        T->left = NULL;
        T->right = NULL;
    }
    else if(X > T->element)T->right = Insert(X, T->right);
    else if(X < T->element) T->left = Insert(X, T->left);
    return T;
}
BinaryTree Delete(ElementType X, BinaryTree T){
    Node temp;
    if(T == NULL){printf("未找到元素\n");}
    else if(X < T->element)T->left = Delete(X, T->left);
    else if(X > T->element)T->right = Delete(X, T->right);
    else{
        /*若待删除的节点有两个子节点则用其右子树中最小的数据代替
         该节点的数据并递归的删除那个节点**/
        if(T->left && T->right){
            temp = FindMin(T->right);
            T->element = temp->element;
            T->right = Delete(temp->element, T->right);
        }else{//一个子节点或没有子节点的情况
            temp = T;
            if(T->right == NULL){
                T = T->right;
            }else if(T->left == NULL){
                T = T->left;
            }
            free(temp);
        }
    }
    return T;
}
void PreOrderTraversal(BinaryTree T){
    if(T == NULL)return;
    printf("%d ", T->element);
    PreOrderTraversal(T->left);
    PreOrderTraversal(T->right);
}
void PostOrderTraversal(BinaryTree T){
    if(T == NULL)return;
    PostOrderTraversal(T->left);
    PostOrderTraversal(T->right);
    printf("%d ", T->element);
}
void InOrderTraversal(BinaryTree T){
    if(T == NULL)return;
    InOrderTraversal(T->left);
    printf("%d ", T->element);
    InOrderTraversal(T->right);
}
