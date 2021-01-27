char* compressString(char* S){

    char *ret = (char*)malloc(sizeof(char)*57500);
    int i = 0, cnt = 0, j = 0, top = 0;
    int stack[10];
    char current;
    while(S[i] != '\0'){
        current = S[i];
        ret[j] = current;
        j++;
        while(S[i] == current){
            cnt++;
            i++;
        }
        while(cnt != 0){
        stack[top] = cnt%10;
        cnt/=10;
        top++;
        }top--;
        while(top >= 0){
            ret[j] = stack[top] + '0';
            j++;
            top--;
        }
        top = 0;
        cnt = 0;
    }
    ret[j] = '\0';
    if(j >= i)return S;
    else return ret;
}
