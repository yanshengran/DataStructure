char * generateTheString(int n){
    char *ret = (char*)malloc(sizeof(char)*(n+1));
    if(n%2 == 0)
    {
        for(int i = 0; i < n-1; i++){
            ret[i] = 'a';
        }
        ret[n-1] = 'b';
    }else{
        for(int i = 0; i < n; i++){
            ret[i] = 'a';
        }
    }
    ret[n] = '\0';
    return ret;
}
