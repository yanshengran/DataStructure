int reverse(int x){
    long rev = 0;
    while(x != 0){
        rev*=10;
        if(rev<-2147483648 || rev>2147483647)return 0;
        rev += x%10;
        x/=10;
    }
    return rev;
}
