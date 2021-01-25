//注：需要用到String.c中的数据结构
//KMP算法实现的字符串模式匹配 O(n+m)
int IndexKMP(SString S, SString Sub, int pos){
    int i = pos, j = 0;
    int* next = GetNext(Sub);
    while((S->ch[i] != '\0' && Sub->ch[j] != '\0') || j == -1){//这里是为了防止出现字符数组的-1元素访问
        if(j == -1 || S->ch[i] == Sub->ch[j]){
            i++;
            j++;
        }else j = next[j];
    }
    if(Sub->ch[j] == '\0')return i-j;
    else return -1;
}
//求解next数组
int* GetNext(SString Sub){
    if(Sub->len == 0){printf("模式串长度为0");return NULL;}
    int* next = (int*)malloc(sizeof(int)*Sub->len);
    int j = 0, k=-1;
    next[j] = k;
    while(Sub->ch[j] != '\0'){
        if(k == -1 || Sub->ch[k] == Sub->ch[j]){
            j++;
            k++;
            next[j] = k;
        }else k = next[k];
    }
    return next;
}
