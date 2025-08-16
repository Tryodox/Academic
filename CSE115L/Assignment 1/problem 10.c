#include <stdio.h>

int main() {
    printf("Enter Height: ");
    int h;
    scanf("%d",&h);
    if(h>9){
        printf("Height cant be above 9");
        return -1;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=h+1-i;j++){
            printf("[%d%d] ",i,j);
        }
        int spaceCount = ((i - 1) * 2 - 1)*5;
        if(spaceCount<0){
            spaceCount = 0;
        }
        for(int j=1;j<=spaceCount;j++){
            printf(" ");
        }
        for(int j=h+1-i;j>=1;j--){
            if (i == 1 && j == h) {
                continue;                
            }
            printf("[%d%d] ",i,j);
        }
        printf("\n");
    }
    return 0;
}
