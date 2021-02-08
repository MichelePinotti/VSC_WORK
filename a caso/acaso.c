#include <stdio.h>
#include <stdlib.h>

//data una stringa mettila in ordine alfabetico
void prova(int*);

#define RIGHE 5
#define COLONNE 10

int main(){
    int a=43;
    int b=55;
    int* c;

printf("prova", );
   /*printf("%d\n%d\n%d\n", a, b, c);
    printf("\n\n%d\n%d\n%d\n", a, b, *c);*/

    prova(c);
}

void prova(int* x){
    int cnt=0;
    int a[4]={1265,1,2,3};
    x = &a[0];
    while(cnt < 3){
        printf("%d", *x);
        *x = *x + 1;
        cnt++;
    }
}

