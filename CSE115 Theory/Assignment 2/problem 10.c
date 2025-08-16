#include <stdio.h>
#include <string.h>
int main(){

    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            str[i] = '%';
        }
    }
    printf("%s", str);

    return 0;
}
