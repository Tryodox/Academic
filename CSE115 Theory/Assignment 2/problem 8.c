#include <stdio.h> 
void mergeSortArr (int size1,int size2,int arr1[],int arr2[],int merged[]){ 
    int k = 0;
    for (int i = 0; i < size1; i++){
        merged[k] = arr1[i]; k++; 
        }
    for (int i = 0; i < size2; i++) { 
        merged[k] = arr2[i]; k++; 
        } 
    int temp; 
    int size = size1 +size2; 
    for(int i=0;i<size;i++){ 
        for(int j=0;j<size;j++){ 
            if(merged[i]<merged[j]){ 
                temp = merged[i]; 
                merged[i] = merged[j]; 
                merged[j] = temp; } 
            } 
        } 
    } 
int main(){ 
    int arr1[] = {5, 2, 9};
    int arr2[] = {8, 1, 6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int merged[size1 + size2];

    mergeSortArr(size1, size2, arr1, arr2, merged);

    printf("Merged and sorted array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
