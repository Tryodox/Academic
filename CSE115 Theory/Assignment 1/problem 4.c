//Problem 4
#include <stdio.h>

void fibonacciSeries(int n){
int first=0,second=1,next=0;
    for (int i=1;i<=n;i++){
        if (i==1){
            printf("%d",first);
        } else if(i==2){
            printf("% d",second);
        } else{
            next = first+second;
            first = second;
            second = next;
            printf(" %d",next);
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    fibonacciSeries(n);

    return 0;
}
