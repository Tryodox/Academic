#include <stdio.h>

int factrl(int n){
    int product=1;
    for(int i=1;i<=n;i++){
        product=product*i;
    }
    return product;
}

int main() {
    int n,result;
    scanf("%d",&n);
    result =factrl(n);
    printf("%d",result);
    return 0;
}
