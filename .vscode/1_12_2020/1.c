
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*1. Realizzare un programma che acquisita ua matrice di stringhe in ordine casuale, 
     le ordina e le stampa in ordine alfabetico crescente.

[0]zibibbo
[1]casa
[2]dado
[3]libro

[0]casa
[1]dado
[2]libro
[3]zibibbo

strcmp(st1, st2)
strcpy(st1,st2)*/

#define RIGHE 5
#define COLONNE 20

void ordina(char [][COLONNE]);

int main(){
    char mat[RIGHE][COLONNE];

    for(int i=0; i<RIGHE; i++){
            printf("inserisci stringa:");
            scanf("%s",mat[i]);
    }
    ordina(mat);

}

void ordina(char mat[][COLONNE] ){
    int i=0;
    char temp[COLONNE];
    for(i=0; i<(RIGHE);i++){
        for(int j=i+1; j<(RIGHE);j++){
            printf("prova\n");
            if(strcmp(mat[i], mat[j])>0){
                printf("prova2\n");
                strcpy( temp, mat[i]);
                strcpy( mat[i], mat[j]);
                strcpy( mat[j], temp);
            }
        }
    }
    printf("stringa:");
    for( i=0; i<RIGHE; i++){
            printf("%s",mat[i]);
            printf("\n");
    }
}