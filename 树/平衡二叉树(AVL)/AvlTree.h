//
//  AvlTree.h
//  AvlTree
//
//  Created by 颜圣燃 on 2021/2/21.
//

#ifndef AvlTree_h
#define AvlTree_h

#include <stdio.h>
struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;
typedef int ElementType;

static int Height(Position P);
AvlTree Insert(ElementType X, AvlTree);
static Position LLRotate(Position A);
static Position RRRotate(Position A);
static Position LRRotate(Position A);
static Position RLRotate(Position A);
#endif /* AvlTree_h */
