//
//  hanoi_3.c
//  Recursion
//  三柱汉诺塔的递归实现
//  Created by yanshengran on 2021/1/22.
//
#include <stdio.h>
void hanoi_move(char src, char dst){
    printf("%c-->%c\n",src,dst);
}
void hanoi(int n, char src, char mid, char dst){ //src表示刚开始所有圆盘所在的柱子
    if(n == 1){ //递归的出口，如果只有一个圆盘直接移至目标柱
        hanoi_move(src, dst);
        return;
    }
    //若n不等于1，将其余n-1个圆盘借助目标柱移动至中间柱
    hanoi(n-1, src, dst, mid);
    //将第n个圆盘移动至目标柱
    hanoi_move(src, dst);
    //将剩余的n-1个圆盘借助源柱移动至目标柱
    hanoi(n-1, mid, src, dst);
}
int main(int argc, const char * argv[]) {
    // 测试函数
    hanoi(3,'A','B','C');
    return 0;
}
