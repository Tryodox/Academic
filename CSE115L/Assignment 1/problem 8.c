#include <stdio.h>

int main (){

    int n;
    printf("Enter series length: ");
    scanf("%d",&n);
    float sumOSeries = 0;
    float sum = 0;
    for(int i=1;i<=n;i++){ 
        sum += (1.0/i);
        sumOSeries += sum;
    }
    printf("Sum of Series: %.4f",sumOSeries);

    return 0;
 }
