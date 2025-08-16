//Problem 6
#include <stdio.h>

int gcd(int a,int b){
    int rem;
    for (;;){
        rem = a%b;
        if(rem==0){
            return b;
        } else {
            a=b;
            b=rem;
        }
    }
}
int main() {
    int a,b,result;
    scanf("%d %d",&a,&b);
    result=gcd(a,b);
    printf("%d",result);
    return 0;
}
