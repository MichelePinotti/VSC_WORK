#include <stdio.h>
#include <stdlib.h>
#include "../library/mylib.c"

int main(){

    Elemento* s = NULL;

    printf("%d\n", head(s));

    s = addToHead(s, 9);
    //printf("%d\n", head(s));
    s = addToHead(s, 6);
    //printf("%d\n", head(s));
    s = addToHead(s, 3);
    //printf("%d\n", head(s));
    addToEnd(s, 10);

    printf("lista prima --> ");
    stampaLista(s);
    printf("\n");
    s = addOrdered(s, 11);
    printf("lista dopo ---> ");
    stampaLista(s);
    printf("\nlunghezza = %d\n", lenght(s));
    int num;
    printf("\binserisci il numero che vuoi trovare:");
    scanf("%d", &num);
    printf("presenza = %d\n", find(s,num));
    printf("\binserisci il numero che vuoi trovare:");
    scanf("%d", &num);
    int cnt=0;
    int idx=findIndex(s,num, &cnt);
    if(cnt==0){
        printf("\nelemento non presente");
    }else{
        printf("\nindice se presente = %d", idx);
    }
    

    return 0;
}