//
//  BinaryTree.h
//  BinaryTree
//
//  Created by yanshengran on 2021/1/27.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
struct TreeNode;
typedef struct TreeNode* BinaryTree;
typedef struct TreeNode* Node;
typedef int ElementType;

BinaryTree InitBiTree(ElementType X);
BinaryTree MakeEmpty(BinaryTree T);//清空二叉树
Node Find(ElementType X, BinaryTree T);
Node FindMin(BinaryTree T);
Node FindMax(BinaryTree T);
BinaryTree Insert(ElementType X, BinaryTree T);
BinaryTree Delete(ElementType X, BinaryTree T);
void PreOrderTraversal(BinaryTree T);
void PostOrderTraversal(BinaryTree T);
void InOrderTraversal(BinaryTree T);
void InOrderTraversalStack(BinaryTree T);//二叉树遍历的非递归实现
void LevelTraversal(BinaryTree T);//二叉树的层次遍历
BinaryTree CreateBiTreeByString(char* str, int* idx); //根据先序遍历字符串创建二叉树
BinaryTree BiTreeCpy(BinaryTree T1);//二叉树的复制
#endif /* BinaryTree_h */
