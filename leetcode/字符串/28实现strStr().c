int strStr(char * haystack, char * needle){
    int lenh = strlen(haystack);
    int lenn = strlen(needle);
    if(lenn == 0)return 0; //若子串是空串，返回0
    int *next = (int*)malloc(sizeof(int)*lenn);
    int j = 0, k = -1;
    next[j] = k;
    while(j < lenn){
        if(k == -1 || needle[k] == needle[j]){
            k++;
            j++;
            if(j < lenn)next[j] = k;
        }else k = next[k];
    }
    int i = 0;
    j = 0;
    while((i < lenh && j < lenn) || j == -1){
        if(j == -1 || needle[j] == haystack[i]){
            i++;
            j++;
        }else j = next[j];
    }
    if(j == lenn)return i-j;
    else return -1;
}
