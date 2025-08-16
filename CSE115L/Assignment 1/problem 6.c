#include <stdio.h>

int isPerfect (int num){

    int sumOfDivs = 0;    
    for(int i=1;i<num;i++){
        if(num%i == 0){
            sumOfDivs += i;
        }
    }
    if (sumOfDivs == num){
        return 1;
    }
    

    return 0;
}

int main (){

    int perfectNumCount = 0;

    printf("Perfect Numbers: ");

    for(int i=1;i<=750;i++){
        int x = isPerfect(i);
        if (x == 1){
            perfectNumCount++;
            printf("%d ", i);
        }
    }
    
    printf("\nTotal Perfect Numbers: %d", perfectNumCount);

    return 0;
 }
