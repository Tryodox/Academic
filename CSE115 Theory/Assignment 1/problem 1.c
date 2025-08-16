//Problem 1
#include <stdio.h>

void PrimeOrNot(int num){
    if (num<=1){
        printf("Not Prime");
        return;
    }
    for(int i=2;i<num;i++){
        if(num%i==0){
            printf("Not Prime");
            return;
        }
    } printf("Prime");
}

int main() {
    int num;
    scanf("%d",&num);
    PrimeOrNot(num);

    return 0;
}
