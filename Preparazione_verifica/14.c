/*
Creare un programma C che gestisca un vettore di MASSIMO 10 stringhe in maniera dinamica. Il programma deve presentare all'avvio due cose:
1. le 10 stringhe presenti nel vettore.
2. un menu a tre voci:
	1. Inserisci
	2. Estrai
	3. USCITA

funzionalità:
1. Se vi è posto disponibile il programma richiede la stringa da inserire e la inserisce in ordine alfabetico crescente.
2. il programma richiede la posizione da liberare (oppure la stringa da estrarre), quindi la toglie dal vettore.
3. il programma termina.*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int insert(char*, int);
void ordina(char*);

int main(){
    int scelta;
    char m[10][10];
    int cnt=0;

    do{
        printf("1. inserire stringa.\n2.libera posizione.\n3.USCITA.");
        scanf("%d", &scelta);
        fflush(stdin);
        printf("matrice:\n");

        for(int i=0; i<10; i++){
            printf("%s\n", m[i]);
        }

        if(scelta == 1){
            printf("%d", cnt);
            if(cnt==9){
                printf("numero massimo di stringhe:");
            }else{
                cnt=insert(*m, 0);
                for(int i=0; i<10; i++){
                    ordina(m[i]);
                }
            }
        }else if(scelta == 2){

        }
        }while(scelta != 3);
}


int insert(char* mat, int cnt){
    if(cnt==9){
        printf("numero massimo di stringhe:");
    }else{
        int scelta=0;
        printf("\ninserisci la stringa: ");
        scanf("%s", mat+(cnt*10));
        fflush(stdin);
        printf("\nse vuoi inserisne un altra digita 1 altrimenti digita 0:");
        scanf("%d", &scelta);
        if(scelta){
            insert(mat, cnt+1);
        }else{ 
            return cnt;
        }
    }
}

void ordina(char* mat){
    int j;
    for(int i=0, j=i+1; i<10; i++, j++){
        if(strcmp(mat+(i*10) , mat+(j*10))>0){
            char temp[10];
            strcpy(temp, mat+(i*10));
            strcpy(mat+(i*10), mat+(j*10));
            strcpy(mat+(j*10), temp);
        }
        printf("%d", i);
    }
}

//non finito
