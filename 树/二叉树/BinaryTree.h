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
#endif /* BinaryTree_h */
