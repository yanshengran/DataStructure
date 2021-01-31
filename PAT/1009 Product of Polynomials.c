#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int expA = 0, expB = 0, i = 0, idx = 0, cnt = 0;
    float A[1001], B[1001], ret[2001];
    for(int j = 0; j < 1001; j++)A[j] = 0;
    for(int j = 0; j < 1001; j++)B[j] = 0;
    for(int j = 0; j < 2001; j++)ret[j] = 0;
    scanf("%d", &expA);
    while(i < expA){
        scanf("%d", &idx);
        scanf("%f", &A[idx]);
        i++;
    }
    i = 0;
    scanf("%d", &expB);
    while(i < expB){
        scanf("%d", &idx);
        scanf("%f", &B[idx]);
        i++;
    }
    for(int j = 0; j < 1001; j++){
        for(int k = 0; k < 1001; k++){
            ret[j+k] += A[j]*B[k];
        }
    }
    for(int j = 0; j < 2001; j++)if(ret[j] != 0)cnt++;
    printf("%d", cnt);
    for(int j = 2000; j >=0; j--){
        if(ret[j] != 0.0){
            printf(" %d", j);
            printf(" %.1f", ret[j]);
        }
    }
    return 0;
}
