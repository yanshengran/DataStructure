bool isPalindrome(int x){
    bool judge = true;
    if(x < 0)return false;
    if(x == 0)return true;
    int stack[101], digit = 0, top = 0, i = 0;
    while(x != 0){
        digit = x%10;
        stack[top] = digit;
        top++;
        x /= 10;
    }
    top--;
    while(i <= top/2){
        if(stack[i] != stack[top-i])judge = false;
        i++;
    }
    return judge;
}
