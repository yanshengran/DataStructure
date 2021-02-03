//
//  HuffmanTree.h
//  HuffmanTree
//
//  Created by yanshengran on 2021/2/3.
//

#ifndef HuffmanTree_h
#define HuffmanTree_h

#include <stdio.h>
struct HTNode;
typedef struct HTNode* HuffmanTree;
void CreateHuffmanTree(HuffmanTree* HT, int n, int* weights);
void PrintStructArray(HuffmanTree* HT, int n);
void Select(HuffmanTree* HT, int* min_idx, int* nmin_idx, int size);
#endif /* HuffmanTree_h */
