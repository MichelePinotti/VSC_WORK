/* Realizzare un programma che acquisita ua matrice di stringhe in ordine casuale, le ordina e le stampa in ordine alfabetico crescente.*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define RIGHE 5
#define COLONNE 10

void ordina(char[][COLONNE]);
void swap(char*, char*);

int main(){
    char m[RIGHE][COLONNE];

    printf("inserisci le stringhe: ");
    for(int i=0; i<RIGHE; i++){
        scanf("%s", m[i]);
    }

    ordina(m);

    printf("\n");
    for(int i=0; i<RIGHE; i++){
        printf("%d--%s\n",i, m[i]);
    }
}

void ordina(char m[][COLONNE]){
    for(int i=0; i<RIGHE-1; i++){
        if(strcmp(m[i], m[i+1])>0)  //se prima piu piccola di seconda returna 1
            swap(m[i],m[i+1]);
    }
}

void swap(char* a, char* b){
    char temp[COLONNE];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}