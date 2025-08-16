#include <stdio.h>

int main (){

    int n,sum = 0;

    int first = 0, second = 1, third = 2;

    printf("Enter length: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        if(i==0){
            printf("%d ",first);
            sum+=first;
        }
        else if(i==1){
            printf("%d ",second);
            sum+=second;
        }
        else if(i==2){
            printf("%d ",third);
            sum+=third;
        }
        else {
            int temp = third;
            third = first + second;
            first = second;
            second = temp;
            sum+=third;
            printf("%d ",third);
        }
    }
    printf("\nOutput sum: %d",sum);

    return 0;
}
