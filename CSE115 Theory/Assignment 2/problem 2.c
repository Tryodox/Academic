#include <stdio.h>

void rotate (int arr[3][3],int rotated[3][3],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            rotated[j][size-i-1] = arr[i][j];
        }
    }
}

int main (){

    int rowcol = 3;
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rotated[3][3];

    rotate(arr,rotated,3);
    for(int i=0;i<rowcol;i++){
        for(int j=0;j<rowcol;j++){
            printf("%d ",rotated[i][j]);
        }
        printf("\n");
    }


    return 0;
 }
