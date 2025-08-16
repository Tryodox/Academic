#include <stdio.h>

int sumOfDigits(int num){
    int digit,sum=0;
    if (num<0){
        num=-num;
    }
    while(num!=0){
        digit=num%10;
        num=num/10;
        sum=sum+digit;
    }  return sum;
}

int main() {
    int num,digit,sum;
    scanf("%d",&num);
    sum = sumOfDigits(num);
    printf("%d",sum);

    return 0;
}
