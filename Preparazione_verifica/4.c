/*Esercizio:
Traccia:
Realizza un algoritmo che ricevute 5 stringhe, determina quali
presentano delle doppie e verifica se sono sono state inserite due stringhe uguali.

1. Banana
2. Mela
3. Banana
4. Scacco
5. Tetto

Stringhi con doppie: Scacco - Tetto
Esistono stringhe duplicate (1. Banana - 3 Banana)
*/

#include<stdio.h>
#include<stdlib.h>

#define RIGHE 5
#define COLONNE 10

void doppie(char[][COLONNE]);

int main(){
    char m[RIGHE][COLONNE];
    printf("inserisci 5 stringhe: ");
    for(int i=0; i<RIGHE;i++){
        scanf("%s", m[i]);
    }
    doppie(m);

}

void doppie(char m[RIGHE][COLONNE]){
    int flag;
    for(int i=0; i<RIGHE;i++){
        flag=0;
        for(int j=0; j<RIGHE;j++){
            if(j>0){
                if(m[i][j] == m[i][j-1]){
                    flag=1;
                }
            }
        }
        if(flag){
            printf("\nLA PAROLA %s HA DOPPIE", m[i]);  
        }else{
            printf("\nLA PAROLA %s NON HA DOPPIE", m[i]);
        } 
    }
}