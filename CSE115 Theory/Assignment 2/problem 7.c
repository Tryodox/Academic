#include <stdio.h>

void reverseRows (int r,int c,int arr[r][c],int rev[r][c]){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            rev[i][j]=arr[i][c-1-j];
        }
    }
}
int main(){

    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int rev[2][3];

    reverseRows(2, 3, arr, rev);

    printf("Reversed rows:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", rev[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
