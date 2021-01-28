int getVal(char ch){
    switch(ch){
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
    return 0;
}
int romanToInt(char * s){
    int i = 0, sum = 0;
    bool judge = 0;
    while(s[i+1] != '\0'){
        if(getVal(s[i+1]) > getVal(s[i])){
            sum+=(getVal(s[i+1]) - getVal(s[i]));
            i+=2;
            judge = 1;
            if(s[i] == '\0')break;
            else judge = 0;
        }else{
            sum+=getVal(s[i]);
            i++;
            judge = 0;
        }
    }
    if(judge == 0)sum+=getVal(s[i]);
    return sum;
}
