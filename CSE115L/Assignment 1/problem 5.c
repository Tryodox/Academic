#include <stdio.h>
#include <math.h>

int isPrime (int num){

    if (num < 2) 
        return 0;
    for(int i=2;i<sqrt(num);i++){
        if(num%i==0){
            return 0;
        }
    }

    return 1;
}

int main (){

    int primeNumCount = 0;

    printf("Prime Numbers: ");

    for(int i=50;i<=300;i++){
        int x = isPrime(i);
        if (x == 1){
            primeNumCount++;
            printf("%d ", i);
        }
    }
    
    printf("Total Prime Numbers: %d", primeNumCount);

    return 0;
 }
