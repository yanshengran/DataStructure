//
//  String.h
//  myString
//
//  Created by yanshengran on 2021/1/23.
//

#ifndef String_h
#define String_h

#include <stdio.h>
struct String;
typedef struct String* SString;

SString StrAssign(char *chars);//根据字符数组生成一个字符串
void PrintStr(SString S);//打印字符串
int StrLength(SString S);//返回字符串长度
int StrCompare(SString S1, SString S2);//比较两个字符串
void ClearString(SString S); //清空一个字符串
SString StrConcat(SString S1, SString S2); //字符串拼接
SString SubString(SString S, int idx, int len); //返回从下标为idx开始长度为len的子串

#endif /* String_h */
