#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    int arr[n];
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    int max = INT_MIN;
    int EvenCount = 0, OddCount = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
        EvenCount++;
        }
    else if (arr[i]%2==1){
        OddCount++;
    }
    if(arr[i]>max){
        max = arr[i];
        }
    }
    printf("Reversed: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[n-1-i]);
    }
    printf("\nMAX: %d\n",max);
    printf("Even Count: %d\n",EvenCount);
    printf("Odd Count: %d\n",OddCount);
     
return 0;
}
