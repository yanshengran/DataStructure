//
//  HuffmanTree.c
//  HuffmanTree
//
//  Created by yanshengran on 2021/2/3.
//

#include "HuffmanTree.h"
#include <stdio.h>
#include <stdlib.h>

struct HTNode{
    int weight;
    int parent, lch, rch;
};
void CreateHuffmanTree(HuffmanTree* HT, int n, int* weights){//这里传入了一个结构体指针数组
    if(n <= 1)return;
    *HT = (HuffmanTree)malloc(sizeof(struct HTNode)*(2*n-1));
    HuffmanTree P = *HT;
    for(int i = 0; i < 2*n-1; i++){
        (P+i)->lch = -1;
        (P+i)->rch = -1;
        (P+i)->parent = -1;
    }
    for(int i = 0; i < n; i++){
        (P+i)->weight = weights[i];
    }
    int min_idx = 0, nmin_idx = 0;
    for(int i = n; i < 2*n-1; i++){
        Select(HT, &min_idx, &nmin_idx, i);
        (P+i)->lch = min_idx;
        (P+i)->rch = nmin_idx;
        (P+i)->weight = (P+min_idx)->weight + (P+nmin_idx)->weight;
        (P+min_idx)->parent = i;
        (P+nmin_idx)->parent = i;
    }
}
/**
 WARNING: address of stack memory associated with local variable  returned
 警告原因：把局部变量的地址作为返回值，局部变量的地址是位于栈区的，函数结束后
 这个地址中的数据将失去意义，可以为局部变量的数组添加static修饰符，但是使用static
 修饰后的数组的长度就必须是定长。
 */
void PrintStructArray(HuffmanTree* HT, int n){
    /**
        参数说明：
        HT：一个指向哈夫曼树结构体指针的指针
        n：构造前的节点数
     */
    HuffmanTree P = *HT;
    for(int i = 0; i < 2*n-1; i++){
        printf("%d ",(P+i)->weight);
    }
}
void Select(HuffmanTree* HT, int* min_idx, int* nmin_idx, int size){//选出两个最小的下标
    /**
     参数说明：
     HT：一个指向哈夫曼树结构体指针的指针
     min_idx：最小元素的下标
     nmin_idx：第二小元素的下标
     size：构造前的节点数
     */
    HuffmanTree p = *HT;
    *min_idx = 0;
    *nmin_idx = 0;
    int min = 2147483647;
    int nmin = min;
    for(int i = 0; i < size; i++){
        if((p+i)->weight < min && (p+i)->parent == -1){
            min = (p+i)->weight;
            *min_idx = i;
        }
    }
    for(int i = 0; i < size; i++){
        if((p+i)->weight < nmin && (p+i)->parent == -1 && i != *min_idx ){
            nmin = (p+i)->weight;
            *nmin_idx = i;
        }
    }
}
char** CreateHuffmanCode(HuffmanTree* HT, int n){
    /**
     构建哈夫曼编码
     */
    char** HC = malloc(sizeof(char*)*(n));
    char* cd = (char*)malloc(sizeof(char)*n);
    cd[n-1] = '\0';
    HuffmanTree P = *HT;
    for(int i = 0; i < n; i++){
        int start = n-1, c = i, f = (P+i)->parent;
        while(f != -1){
            start--;
            if((P+f)->lch == c)cd[start] = '0';
            else cd[start] = '1';
            c = f;
            f = (P+f)->parent;
        }
        HC[i] = (char*)malloc(sizeof(char)*(n-start));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
    return HC;
}
