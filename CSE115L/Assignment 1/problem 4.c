#include <stdio.h>

int main (){

    int sum = 0;
    int arr[]={10,20,40,30,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    float avg = sum/n;
    float med;
    if (n%2==0){
        med = (arr[n/2] + arr[(n/2)-1]) / 2;
    }
    else if (n%2==1){
        med = arr[(n-1)/2];
    }

    printf("Average: %.2f\n",avg);
    printf("Median: %.2f",med);
    

    return 0;
 }
