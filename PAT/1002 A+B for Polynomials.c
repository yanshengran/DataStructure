#include <stdio.h>
#include <stdlib.h>
const int MAXSIZE = 1001;
int main(){
    double a[MAXSIZE];
    for(int i = 0; i < MAXSIZE; i++){
        a[i] = 0;
    }
    int t = 0;
    int pos;
    int count = 0;
    double coef;
    scanf("%d",&t);
    for(int i = 0; i<t; i++){
        pos = 0;
        coef = 0;
        scanf(" %d %lf",&pos, &coef);
        a[pos] += coef;
        
    }
    scanf("%d",&t);
    for(int i = 0; i<t; i++){
        pos = 0;
        coef = 0;
        scanf("%d %lf",&pos, &coef);
        a[pos] += coef;
    }
    for(int j = 0; j < MAXSIZE; j++){
        if(a[j]!=0)count++;
    }
    printf("%d",count);
    for(int j = MAXSIZE-1; j>=0;j--){
        if(a[j]!=0)printf(" %d %.1lf",j,a[j]);
    }
    return 0;
}

