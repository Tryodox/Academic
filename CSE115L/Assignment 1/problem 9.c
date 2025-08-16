#include <stdio.h>

int fact (int num){
    if(num==0){
        return 1;
    }
    return num * fact(num-1);
}
int sumOfDigits (int num){
    if(num==0){
        return 0;
    }
    return num%10 + sumOfDigits(num/10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int fac;
    fac = fact(num);
    printf("Factorial: %d\n",fac);
    int sum = sumOfDigits(fac);
    printf("Sum of Digits: %d",sum);

    return 0;
}
