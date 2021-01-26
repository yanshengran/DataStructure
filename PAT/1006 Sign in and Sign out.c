int main(int argc, const char * argv[]) {
    int T;
    char in[20];
    char out[20];
    int in_time = 86400;
    int out_time = 0, time1 = 0, time2 = 0;
    char ID[20];
    char t1[9];
    char t2[9];
    scanf("%d",&T);
    while(T){
        scanf("%s",ID);
        scanf("%s",t1);
        scanf("%s",t2);
        for(int i = 0; t1[i] != '\0'; i++){
            //计算时间秒数
            if(i == 0){
                time1 += (t1[i]-'0')*36000;
                time2 += (t2[i]-'0')*36000;
            }if(i == 1){
                time1 += (t1[i]-'0')*3600;
                time2 += (t2[i]-'0')*3600;
            }if(i == 3){
                time1 += (t1[i]-'0')*600;
                time2 += (t2[i]-'0')*600;
            }if(i == 4){
                time1 += (t1[i]-'0')*60;
                time2 += (t2[i]-'0')*60;
            }if(i == 6){
                time1 += (t1[i]-'0')*10;
                time2 += (t2[i]-'0')*10;
            }if(i == 7){
                time1 += (t1[i]-'0');
                time2 += (t2[i]-'0');
            }
        }
        if(time1 < in_time){
            in_time = time1;
            strcpy(in, ID);
        }if(time2 > out_time){
            out_time = time2;
            strcpy(out, ID);
        }
        time1 = 0;
        time2 = 0;
        T--;
    }
    printf("%s %s",in,out);
    return 0;
}

