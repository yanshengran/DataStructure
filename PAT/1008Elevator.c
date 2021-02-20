#include <stdio.h>
#include <stdlib.h>
int main(){
    int N, cur = 0, next, time = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &next);
        if(next > cur)time += (next - cur)*6;
        else if(next < cur)time += (cur - next)*4;
        else time += 0;
        time += 5;
        cur = next;
    }
    printf("%d", time);
    return 0;
}
