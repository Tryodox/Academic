#include <stdio.h>

int main (){

    int mark;
    printf("Enter mark: ");
    scanf("%d",&mark);

    switch (mark)
    {
    case 93 ... 100:
        printf("A");
        break;
    case 87 ... 92:
        printf("A-");
        break;
    case 80 ... 86:
        printf("B+");
        break;
    case 75 ... 79:
        printf("B");
        break;
    case 70 ... 74:
        printf("B-");
        break;
    case 65 ... 69:
        printf("C");
        break;
    case 60 ... 64:
        printf("D");
        break;
    default:
        printf("F");
        break;
    }

    return 0;
 }
