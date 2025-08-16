//Problem 9
#include <stdio.h>


int sumOfEven(int n){
    int sum=0;
    for (int i=1;i<=n;i++){
        if(i%2==0){
            sum += i;
        }
    }
    return sum;
}


int main() {
    int n,result;
    scanf("%d",&n);
    result=sumOfEven(n);
    printf("%d",result);
    return 0;
}
