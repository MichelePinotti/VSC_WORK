#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int sium;
}Ciao;

typedef struct nodo{
    Ciao value;
    struct nodo* next;
}Nodo;

void pushhead(Nodo** n, int num){
    Nodo* new =(Nodo*)malloc(sizeof(Nodo));
    new->value.sium = num;
    new->next = *(n);
    *n = new;
}

void write(FILE* fpout, Nodo* n){
    fpout = fopen("archivio.bin", "wb");
    while(n != NULL){
        fwrite(n , sizeof(Nodo), 1, fpout);
        n = n->next;
    }
    fclose(fpout);
}

void svuota(Nodo** n){
    while(*n != NULL){
        Nodo* tmp = *n;
        printf("\n%d    %d", *n, tmp);
        *n = (*n)->next;
        free(tmp);
        printf("\n%d    %d", *n, tmp);
        printf("\nfine ciclo");
    }
}

void print(Nodo* n){
    if(n != NULL){
        printf("\n%d", n->value.sium);
        print(n->next);
    }
}

int main(){
    FILE* fpin;
    FILE* fpout;
    Nodo* str = NULL;
    pushhead(&str, 10);
    pushhead(&str, 20);
    pushhead(&str, 30);
    print(str);
    printf("\ncopiatura sul file...");
    write(fpout, str);
    svuota(&str);
    printf("\nfinal");
    print(str);
}