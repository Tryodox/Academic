#include <stdio.h>
#include <limits.h>

int main (){

    int size;
    printf("Enter array size: ");
    scanf("%d",&size);
    int arr[size];

    for(int i =0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int x = INT_MIN;
    int LIScount = 0;
    for(int i=0;i<size;i++){
        if(arr[i]>x){
            x = arr[i];
            LIScount++;
        }
    }
    
    printf("%d",LIScount);

    return 0;
 }
