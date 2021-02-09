<<<<<<< HEAD
/*Traccia:
Creare un programma C che gestisca una matrice di MASSIMO 10 stringhe in maniera dinamica. Il programma deve presentare all'avvio due cose:
1. le 10 stringhe presenti nel vettore.
2. un menu a tre voci:
	1. Inserisci
	2. Estrai
	3. USCITA*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define COLONNE 20
int RIGHE = 0;

void ordina(char*, char*);
void swap(char *, char *);
void matPrt(char *, char *);
void estrai(char * );
int main(){
    int scelta;

    do{
        printf("Quante stringhe vuoi inserire:");
        scanf("%d", &RIGHE);
        fflush(stdin);
        system("CLS");
    }while(RIGHE>10 && RIGHE<=0);

    char mat[RIGHE][COLONNE];

    do{
        printf("1. Inserisci \n2. Estrai \n3. USCITA\n");
        scanf("%d", &scelta);
        fflush(stdin);

        if(scelta == 1){
            for(int i = 0; i < RIGHE; i++){
                printf("Stringa numero %d: ", i);
                scanf("%s", mat + i);
                fflush(stdin);

                if(i != 0) 
                    ordina(*(mat+i), *mat); //mat[0]
            }

            matPrt(*(mat), *(mat + RIGHE - 1));

        }else if(scelta == 2){
            int indice;
            printf("Quale stringa vuoi cancellare?\n");
            scanf("%d",&indice);
            fflush(stdin);
            estrai(*(mat+indice));
            matPrt(*(mat), *(mat + RIGHE - 1));
        }
    }while(scelta>0 && scelta<3);
}

void ordina(char* par, char* ind){  
    if(par-COLONNE >= ind){
        if(strcmp(par, par-COLONNE) < 0)
            swap(par, par-COLONNE);
        ordina(par-COLONNE, ind);
    }
}

void estrai(char* mat){
    for(int i=0 ; *(mat+1) != '\0'; i++){
        *(mat+i) = '$';
    }
}

void swap(char* a, char* b){
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void matPrt(char* mat, char* last){     //stampa una matrice
    printf("\n");
    if(mat <= last){
        printf("%s", mat);
        matPrt(mat+COLONNE, last);
    }
=======
/*Traccia:
Creare un programma C che gestisca una matrice di MASSIMO 10 stringhe in maniera dinamica. Il programma deve presentare all'avvio due cose:
1. le 10 stringhe presenti nel vettore.
2. un menu a tre voci:
	1. Inserisci
	2. Estrai
	3. USCITA*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define COLONNE 20
int RIGHE = 0;

void ordina(char*, char*);
void swap(char *, char *);
void matPrt(char *, char *);
void estrai(char * );
int main(){
    int scelta;

    do{
        printf("Quante stringhe vuoi inserire:");
        scanf("%d", &RIGHE);
        fflush(stdin);
        system("CLS");
    }while(RIGHE>10 && RIGHE<=0);

    char mat[RIGHE][COLONNE];

    do{
        printf("1. Inserisci \n2. Estrai \n3. USCITA\n");
        scanf("%d", &scelta);
        fflush(stdin);

        if(scelta == 1){
            for(int i = 0; i < RIGHE; i++){
                printf("Stringa numero %d: ", i);
                scanf("%s", mat + i);
                fflush(stdin);

                if(i != 0) 
                    ordina(*(mat+i), *mat); //mat[0]
            }

            matPrt(*(mat), *(mat + RIGHE - 1));

        }else if(scelta == 2){
            int indice;
            printf("Quale stringa vuoi cancellare?\n");
            scanf("%d",&indice);
            fflush(stdin);
            estrai(*(mat+indice));
            matPrt(*(mat), *(mat + RIGHE - 1));
        }
    }while(scelta>0 && scelta<3);
}

void ordina(char* par, char* ind){  
    if(par-COLONNE >= ind){
        if(strcmp(par, par-COLONNE) < 0)
            swap(par, par-COLONNE);
        ordina(par-COLONNE, ind);
    }
}

void estrai(char* mat){
    for(int i=0 ; *(mat+1) != '\0'; i++){
        *(mat+i) = '$';
    }
}

void swap(char* a, char* b){
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void matPrt(char* mat, char* last){     //stampa una matrice
    printf("\n");
    if(mat <= last){
        printf("%s", mat);
        matPrt(mat+COLONNE, last);
    }
>>>>>>> 3bb886a2fa30b0b290ecdbe03fb4a04612cf4b9b
}