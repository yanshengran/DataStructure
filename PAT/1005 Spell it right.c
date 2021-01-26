int main(int argc, const char * argv[]) {
    char s[102];
    int stack[10];
    char numbers[10][6] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int sum = 0;
    scanf("%s",s);
    for(int i = 0; s[i] != '\0'; i++){
        sum += s[i]-'0';
    }//求和
    if(sum == 0)printf("zero");
    int digit = 0, top = 0;
    while(sum != 0){
        digit = sum % 10;
        stack[top] = digit;
        sum /= 10;
        top++;
    }
    top--;
    while(top >= 0){
        if(top != 0)printf("%s ",numbers[stack[top]]);
        else printf("%s",numbers[stack[top]]);
        top--;
    }
    return 0;
}
