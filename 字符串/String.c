//
//  String.c
//  myString
//
//  Created by 颜圣燃 on 2021/1/23.
//
#define MAXLEN 255
#include "String.h"
#include <stdlib.h>
#include <stdlib.h>
struct String{
    char *ch;
    int len;
};
// 构造字符串
SString StrAssign(char *chars){
    SString S = (SString)malloc(sizeof(struct String));
    if(S == NULL){printf("动态内存申请失败");return NULL;}
    //计算chars的长度
    int i = 0;
    while(chars[i] != '\0'){
        i++;
    }
    printf("%d\n",i);
    S->ch = (char*)malloc(sizeof(char)*i);
    if(S->ch == NULL){printf("动态内存申请失败");return NULL;}
    for(int j = 0; j<i; j++){
        S->ch[j] = chars[j];
    }
    S->ch[i] = '\0';  //不要忘记这个\0 !
    S->len = i;
    return S;
}
// 打印字符串
void PrintStr(SString S){
    printf("%s\n",S->ch);
}
// 返回字符串长度
int StrLength(SString S){
    return S->len;
}
// 比较字符串
int StrCompare(SString S1, SString S2){
    int i = 0;
    while(S1->ch[i] == S2->ch[i] && i < S1->len)i++;
    return S1->ch[i]-S2->ch[i];
}
//清空一个字符串
void ClearString(SString S){
    free(S->ch);
    S->len = 0;
}
//字符串的拼接
SString StrConcat(SString S1, SString S2){
    SString S = (SString)malloc(sizeof(struct String));
    if(S == NULL){printf("动态内存申请失败");return NULL;}
    S->ch = (char*)malloc(sizeof(char)*(S1->len + S2->len));
    if(S->ch == NULL){printf("动态内存申请失败");return NULL;}
    int i = 0, j = 0;
    while(i < S1->len){S->ch[i] = S1->ch[i];i++;}
    while(j < S2->len){S->ch[i] = S2->ch[j];i++;j++;}
    S->len = S1->len + S2->len;
    return S;
}
//返回从下标为idx开始长度为len的子串
SString SubString(SString S, int idx, int len){
    SString S1 = (SString)malloc(sizeof(struct String));
    if(S1 == NULL){printf("动态内存申请失败");return NULL;}
    S1->ch = (char*)malloc(sizeof(char)*len);
    if(S1->ch == NULL){printf("动态内存申请失败");return NULL;}
    int i = idx, j = 0;
    while(i < S->len && i < idx+len){
        S1->ch[j] = S->ch[i];
        S1->len++;
        i++;
        j++;
    }
    return S1;
}
