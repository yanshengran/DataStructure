char * sortString(char * s){
    char* ret = (char*)malloc(sizeof(char)*501);
    int len = strlen(s), j = 0, cnt = 0,idx = 0;
    while(cnt != len){
        char min = '{';
        char start = 'a'-1;
        int i = 0;
        while(1){
            char tep = min;
            idx = 0;
            for(i = 0; i < len; ++i){
                if(s[i] != '9' && s[i] < min && s[i] > start){
                    min = s[i];idx = i;
            }
        }
        if(tep == min)break;
        else {
            s[idx] = '9';
            cnt++;
            start = min;
            ret[j] = min;
            j++;
            min = '{';
            if(cnt == len)break;
        }
    }
        char max = 'a'-1;
        char end = 'z'+1;
        while(1){
            char tep = max;
            idx = 0;
            for(i = 0; i < len; ++i){
                if(s[i] != '9' && s[i] > max && s[i] < end){
                    max = s[i];idx = i;
            }
        }
        if(tep == max)break;
        else{
            s[idx] = '9';
            cnt++;
            end = max;
            ret[j] = max;
            j++;
            max = 'a'-1;
            if(cnt == len)break;
        }
    }
    }
    ret[j] = '\0';
    return ret;
}
