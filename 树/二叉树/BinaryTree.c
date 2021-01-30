//
//  BinaryTree.c
//  BinaryTree
//
//  Created by yanshengran on 2021/1/27.
//

#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
struct TreeNode{
    ElementType element;
    Node left;
    Node right;
};
BinaryTree InitBiTree(ElementType X){//初始化一个二叉树
    BinaryTree BT = (BinaryTree)malloc(sizeof(struct TreeNode));
    BT->element = X;
    BT->left = NULL;
    BT->right = NULL;
    return BT;
}
BinaryTree MakeEmpty(BinaryTree T){//清空一个二叉树
    if(T != NULL){
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}
Node Find(ElementType X, BinaryTree T){//根据值返回二叉树的节点
    if(T == NULL)return NULL;
    if(X < T->element)return Find(X, T->left);
    if(X > T->element)return Find(X, T->right);
    else return T;
}
Node FindMin(BinaryTree T){//找到二叉树的最小节点
    if(T == NULL)return NULL;
    while(T->left != NULL){
        T = T->left;
    }return T;
}
Node FindMax(BinaryTree T){//找到二叉树的最大节点
    if(T == NULL)return NULL;
    while(T->right != NULL){
        T = T->right;
    }return T;
}
BinaryTree Insert(ElementType X, BinaryTree T){//向一棵二叉树中插入元素
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
BinaryTree Delete(ElementType X, BinaryTree T){//删除一个节点
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
void PreOrderTraversal(BinaryTree T){//前序遍历
    if(T == NULL)return;
    printf("%d ", T->element);
    PreOrderTraversal(T->left);
    PreOrderTraversal(T->right);
}
void PostOrderTraversal(BinaryTree T){//后序遍历
    if(T == NULL)return;
    PostOrderTraversal(T->left);
    PostOrderTraversal(T->right);
    printf("%d ", T->element);
}
void InOrderTraversal(BinaryTree T){//中序遍历
    if(T == NULL)return;
    InOrderTraversal(T->left);
    printf("%d ", T->element);
    InOrderTraversal(T->right);
}
void InOrderTraversalStack(BinaryTree T){//中序遍历的非递归实现
    Node Stack[100];
    int top = -1;
    BinaryTree P = T;
    while(P || top != -1){
        if(P){top++; Stack[top] = P; P = P->left;}
        else{
            printf("%d ", Stack[top]->element);
            P = Stack[top]->right;
            top--;
        }
    }
}
void LevelTraversal(BinaryTree T){//二叉树的层次遍历
    Node Queue[100];
    int front = 0, rear = 0;
    Queue[rear] = T;
    rear = (rear+1)%100;
    while(!(rear == front)){
        printf("%d ",Queue[front]->element);
        if(Queue[front]->left != NULL){
            Queue[rear] = Queue[front]->left;
            rear = (rear+1)%100;
        }
        if(Queue[front]->right != NULL){
            Queue[rear] = Queue[front]->right;
            rear = (rear+1)%100;
        }
        front = (front+1)%100;
    }
}
BinaryTree CreateBiTreeByString(char* str, int* idx){//通过前序遍历字符串构造二叉树
    if(str[*idx] != '#'){
        BinaryTree Node = (BinaryTree)malloc(sizeof(struct TreeNode));
        Node->element = str[*idx] - '0';
        (*idx)++;
        Node->left = CreateBiTreeByString(str, idx);
        (*idx)++;
        Node->right = CreateBiTreeByString(str, idx);
        return Node;
    }else return NULL;
}
BinaryTree BiTreeCpy(BinaryTree T1){//二叉树的复制
    if(T1 == NULL)return NULL;
    BinaryTree ret = (BinaryTree)malloc(sizeof(struct TreeNode));
    ret->element = T1->element;
    ret->left = BiTreeCpy(T1->left);
    ret->right = BiTreeCpy(T1->right);
    return ret;
}
