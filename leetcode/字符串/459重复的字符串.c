/*
解法一：朴素枚举法
*/
bool repeatedSubstringPattern(char * s){
     int len = strlen(s);
     for(int i = 1; i*2 <= len; ++i){
         if(len % i == 0){
             bool judge = true;
             for(int j = i; j < len; ++j){
                 if(s[j] != s[j-i]){
                 judge = false;
                 break;
                 }
             }
             if(judge)return true;
         }
     }
     return false;
}
/*
解法二:KMP实现的模式串匹配法
思路：首先将源字符串与自身拼接，去掉第一个与最后一个字符，如果这个字符串
是重复字符串那么将源字符串一定是拼接后的字符串的子串。
*/
bool repeatedSubstringPattern(char * s){
    int n = strlen(s);
    char scat[2*n+1];
    scat[0] = 0;
    strcat(scat,s);
    strcat(scat,s);
    return kmp(scat, s);
}
int kmp(char* S, char* Sub){
    int len = strlen(Sub);
    int lenS = strlen(S);
    //求解next数组
    int* next = (int*)malloc(sizeof(int)*len);
    int j = 0, k = -1;
    next[j] = k;
    while(j < len){
        if(k == -1 || Sub[j] == Sub[k]){
            k++;
            j++;
            if(j < len)next[j] = k;
        }else k = next[k];
    }
    int i = 1;
    j = 0;
    while(j == -1 || (i < lenS - 1 && Sub[j] != '\0')){
        if(j == -1 || S[i] == Sub[j]){
            i++;
            j++;
        }else j = next[j];
    }
    if(Sub[j] == '\0')return 1;
    else return 0;
}
