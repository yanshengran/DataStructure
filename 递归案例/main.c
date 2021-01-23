//
//  main.c
//  Recursion
//
//  Created by 颜圣燃 on 2021/1/22.
//
#include <stdio.h>
void hanoi_move(char src, char dst){
    printf("%c-->%c\n",src,dst);
}
void hanoi(int n, char src, char mid, char dst){
    if(n == 1){
        hanoi_move(src, dst);
        return;
    }
    hanoi(n-1, src, dst, mid);
    hanoi_move(src, dst);
    hanoi(n-1, mid, src, dst);
}
int fact(int n){
    if(n == 0 || n == 1)return 1;
    else return n*fact(n-1);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n",fact(4));
    hanoi(3,'A','B','C');
    return 0;
}
