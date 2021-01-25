char * modifyString(char * s){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == '?'){
            char ch = 'a';
            if(i > 0 && s[i-1] == ch)ch++;
            if(s[i+1]!='\0'){
                if(s[i+1] == ch)ch++;
                if(i > 0 && s[i-1] == ch)ch++;
            }
            s[i] = ch;
        }
        i++;
    }
    return s;
}
