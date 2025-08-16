#include <stdio.h>
#include <math.h>

int secondLarge (int a,int b,int c);

int main(){

    int a,b,c,largest2,result;
    printf("Enter 3 integer values: ");
    scanf("%d %d %d",&a,&b,&c);
    largest2 = secondLarge(a,b,c);
    result = pow(2,largest2);
    printf("Output: %d\n",largest2);
    printf("Result: %d",result);
    return 0;

}

int secondLarge (int a,int b,int c){
    int result;
    if(a>b&&a<c || a>c&&a<b){
        result = a;
    } else if (b>a&&b<c || b>c&&b<a){
        result = b;
    } else if (c>a&&c<b || c>b&&c<a){
        result = c;
    }
    return result;
}
