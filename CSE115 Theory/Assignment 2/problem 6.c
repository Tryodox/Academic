#include <stdio.h>
#include <string.h>
int main(){

    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    for(int i=0;str[i]!='\0';i++){
        int repeat = 0;
        for(int j=0;str[j]!='\0';j++){
            if(i!=j && str[i]==str[j]){
                repeat = 1;
            }
        }
        if(repeat==0){
            printf("%c",str[i]);
            return 0;
        }
    }
    
    return 0;
}
