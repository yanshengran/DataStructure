#include <stdlib.h>
#include <stdio.h>
int main(){
    int a = 0;
    int b = 0;
    scanf("%d%d",&a,&b);
    int sum = a+b;
    int frontfront = sum/1000000;
    int front = (sum%1000000)/1000;
    int last = sum%1000;
    if(frontfront != 0){
        printf("%d,",frontfront);
        if(front > 100){
            if(last < 0){
                last *= -1;
            }
            if(last > 100){
                printf("%d,%d",front,last);
            }
            if(last < 100 && last >= 10){
                printf("%d,%d%d",front,0,last);
            }
            if(last < 10){
                printf("%d,%d%d%d",front,0,0,last);
            }
        }
        if(front < 100 && front >= 10){
            if(last < 0){
                last *= -1;
            }
            if(last > 100){
                printf("%d%d,%d",0,front,last);
            }
            if(last < 100 && last >= 10){
                printf("%d%d,%d%d",0,front,0,last);
            }
            if(last < 10){
                printf("%d%d,%d%d%d",0,front,0,0,last);
            }
        }
        if(front < 10){
            if(last < 0){
                last *= -1;
            }
            if(last > 100){
                printf("%d%d%d,%d",0,0,front,last);
            }
            if(last < 100 && last >= 10){
                printf("%d%d%d,%d%d",0,0,front,0,last);
            }
            if(last < 10){
                printf("%d%d%d,%d%d%d",0,0,front,0,0,last);
            }
        }
    }
    else{
        if(front != 0){
            if(last < 0){
                last *= -1;
            }
            if(last > 100){
                printf("%d,%d",front,last);
            }
            if(last < 100 && last >= 10){
                printf("%d,%d%d",front,0,last);
            }
            if(last < 10){
                printf("%d,%d%d%d",front,0,0,last);
            }
        }else{
            printf("%d",sum);
        }
    }
}
