//
//  main.c
//  HuffmanTree
//
//  Created by yanshengran on 2021/2/3.
//
#include "HuffmanTree.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n = 8;
    int weights[] = {5,29,7,8,14,23,3,11};
    HuffmanTree HT;
    CreateHuffmanTree(&HT, n, weights);
    printf("is HT == NULL %d\n", HT == NULL);
    PrintStructArray(&HT, 8);
    printf("\n");
    char** ret = CreateHuffmanCode(&HT, 8);
    for(int i = 0; i < 8; i++){
        printf("code = %s\n",ret[i]);
    }
    return 0;
}
