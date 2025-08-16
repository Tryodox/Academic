//Problem 10
#include <stdio.h>


int sumOf(int n){
    int sum=0;
    for (int i=1;i<n;i++){
        if(i%3==0 || i%5==0){
            sum += i;
        }
    }
    return sum;
}


int main() {
    int n,result;
    scanf("%d",&n);
    result=sumOf(n);
    printf("%d",result);
    return 0;
}
