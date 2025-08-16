#include <stdio.h>

int main() {
    printf("Enter Height: ");
    int h;
    scanf("%d",&h);
    for(int i=1;i<=h;i++){
        for(int k=h-i;k>=0;k--){
        printf(" ");
        }
        for(int j=1;j<=i;j++){
            if(i%2==1){
                if(j%2==1){
                    printf("%% ");
                } else if(j%2==0){
                    printf("$ ");
                }
            }
            else if(i%2==0){
                if(j%2==1){
                    printf("# ");
                } else if(j%2==0){
                    printf("@ ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
