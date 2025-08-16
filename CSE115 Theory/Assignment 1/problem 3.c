//Problem 3
#include <stdio.h>

void PalindromeOrNo(int num){
    int original,digit,reversed=0;
    original = num;
    while(num!=0){
        digit=num%10;
        num=num/10;
        reversed = reversed + digit ;
        if(num!=0){
            reversed*=10;
            }
    }if(original==reversed){
        printf("Palindrome");
    } else{
        printf("Not Palindrome");
    }
}

int main() {
    int num;
    scanf("%d",&num);
    PalindromeOrNo(num);
    return 0;
}
