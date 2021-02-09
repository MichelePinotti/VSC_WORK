<<<<<<< HEAD
/*
    Realizzare un programma che permetta di:
    1. Inserire un un nuovo libro nell'elenco (1 libro per volta e MAX 20 LIBRI). fatto
    2. Ricercare un libro per titolo.
    3. Ricercare un libro per fascia di prezzo p_min<=x<=p_max (es. 5.50 <-> 10.99).
    0. USCITA
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char title[40];
    char author[40];
    int pages_n;
    float price;    
}book;

void insertBooks(book[], int, int*);
int findBooksTitle(book[], int, char*, int*);
void findBooksPrice(book[], int, int*, float, float, int*);
void lowerChar(char *);

int main(){
    const int SIZE = 20;
    int cntInsert = 0, scelta;
    book bookCase_t[SIZE];
    do{
        printf("Cosa vuoi fare?\n1. INSERISCI LIBRO     2.CERCA PER TITOLO      3.CERCA PER PREZZO      0.USCITA\n");
        scanf("%d", &scelta);
        fflush(stdin);
        if(scelta == 1){            //INSERIMENTO
            insertBooks(bookCase_t, SIZE, &cntInsert);
            printf("\n");
        }else if(scelta == 2){      //RICERCA PER TITOLO
            char find[SIZE];
            int cntTitle = 0;
            printf("Che libro vuoi cercare?\n");
            gets(find);
            fflush(stdin);
            lowerChar(find);

            if(findBooksTitle(bookCase_t, SIZE, find, &cntTitle) == 1)
                printf("Il libro %s e' presente alla posizione %d\n", find, cntTitle);
            else
                printf("Nessun libro con questo titolo\n");
            printf("\n");
        }else if(scelta==3){        //RICERCA PREZZO
            int cntPrice=0, found=0;
            float priceMin, priceMax;
            printf("Inserisci range prezzo\nInserisci il minore e poi il maggiore\n");
            scanf("%f%f", &priceMin, &priceMax);
            findBooksPrice(bookCase_t, SIZE, &cntPrice, priceMin, priceMax, &found);
            if(found == 0)
                printf("Nessun libro in questa fascia di prezzo\n");
            printf("\n");
        }
        printf("---PREMERE PER CONTINUARE---");
        getchar();
        system("CLS");
    } while (scelta != 0);
}

void insertBooks(book bookCase[], int SIZE, int* cnt){
    if(*cnt < SIZE){
        printf("Inserisci titolo del libro: ");
        gets(bookCase[*cnt].title);
        fflush(stdin);
        lowerChar(bookCase[*cnt].title);

        printf("Inserisci autore del libro: ");
        gets(bookCase[*cnt].author);
        fflush(stdin);
        lowerChar(bookCase[*cnt].author);
        
        printf("Inserisci numero pagine del libro: ");
        scanf("%d", &bookCase[*cnt].pages_n);
        fflush(stdin);
        
        printf("Inserisci prezzo del libro: ");
        scanf("%f", &bookCase[*cnt].price);
        fflush(stdin);

        *cnt = *cnt + 1;    

        int choice;
        printf("\nVuoi aggiungere un libro?\n1.SI   0.NO\n");
        scanf("%d", &choice);
        fflush(stdin);
        if(choice == 1)
            insertBooks(bookCase, SIZE, cnt);
    }
}

int findBooksTitle(book bookCase[], int SIZE, char* find, int *cnt){
    if(*cnt < SIZE){
        if(strcmp(bookCase[*cnt].title, find) == 0){
            return 1;
        }else{
            *cnt = *cnt + 1;
            return findBooksTitle(bookCase, SIZE, find, cnt);
        }
    }
    return 0;
}

void findBooksPrice(book bookCase[], int SIZE, int *cnt, float min, float max, int* flag){
    if(*cnt < SIZE){
        if(bookCase[*cnt].price >= min && bookCase[*cnt].price <= max){
            printf("Il libro %s rientra nella fascia di prezzo scelta\n", bookCase[*cnt].title);
            *flag = *flag + 1;
        }
        *cnt = *cnt + 1;
        findBooksPrice(bookCase, SIZE, cnt, min, max, flag);
    }
}

void lowerChar(char* word){
    if(*word != '\0'){
        *word = tolower(*word);
        lowerChar(word + 1);
    }
=======
/*
    Realizzare un programma che permetta di:
    1. Inserire un un nuovo libro nell'elenco (1 libro per volta e MAX 20 LIBRI). fatto
    2. Ricercare un libro per titolo.
    3. Ricercare un libro per fascia di prezzo p_min<=x<=p_max (es. 5.50 <-> 10.99).
    0. USCITA
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char title[40];
    char author[40];
    int pages_n;
    float price;    
}book;

void insertBooks(book[], int, int*);
int findBooksTitle(book[], int, char*, int*);
void findBooksPrice(book[], int, int*, float, float, int*);
void lowerChar(char *);

int main(){
    const int SIZE = 20;
    int cntInsert = 0, scelta;
    book bookCase_t[SIZE];
    do{
        printf("Cosa vuoi fare?\n1. INSERISCI LIBRO     2.CERCA PER TITOLO      3.CERCA PER PREZZO      0.USCITA\n");
        scanf("%d", &scelta);
        fflush(stdin);
        if(scelta == 1){            //INSERIMENTO
            insertBooks(bookCase_t, SIZE, &cntInsert);
            printf("\n");
        }else if(scelta == 2){      //RICERCA PER TITOLO
            char find[SIZE];
            int cntTitle = 0;
            printf("Che libro vuoi cercare?\n");
            gets(find);
            fflush(stdin);
            lowerChar(find);

            if(findBooksTitle(bookCase_t, SIZE, find, &cntTitle) == 1)
                printf("Il libro %s e' presente alla posizione %d\n", find, cntTitle);
            else
                printf("Nessun libro con questo titolo\n");
            printf("\n");
        }else if(scelta==3){        //RICERCA PREZZO
            int cntPrice=0, found=0;
            float priceMin, priceMax;
            printf("Inserisci range prezzo\nInserisci il minore e poi il maggiore\n");
            scanf("%f%f", &priceMin, &priceMax);
            findBooksPrice(bookCase_t, SIZE, &cntPrice, priceMin, priceMax, &found);
            if(found == 0)
                printf("Nessun libro in questa fascia di prezzo\n");
            printf("\n");
        }
        printf("---PREMERE PER CONTINUARE---");
        getchar();
        system("CLS");
    } while (scelta != 0);
}

void insertBooks(book bookCase[], int SIZE, int* cnt){
    if(*cnt < SIZE){
        printf("Inserisci titolo del libro: ");
        gets(bookCase[*cnt].title);
        fflush(stdin);
        lowerChar(bookCase[*cnt].title);

        printf("Inserisci autore del libro: ");
        gets(bookCase[*cnt].author);
        fflush(stdin);
        lowerChar(bookCase[*cnt].author);
        
        printf("Inserisci numero pagine del libro: ");
        scanf("%d", &bookCase[*cnt].pages_n);
        fflush(stdin);
        
        printf("Inserisci prezzo del libro: ");
        scanf("%f", &bookCase[*cnt].price);
        fflush(stdin);

        *cnt = *cnt + 1;    

        int choice;
        printf("\nVuoi aggiungere un libro?\n1.SI   0.NO\n");
        scanf("%d", &choice);
        fflush(stdin);
        if(choice == 1)
            insertBooks(bookCase, SIZE, cnt);
    }
}

int findBooksTitle(book bookCase[], int SIZE, char* find, int *cnt){
    if(*cnt < SIZE){
        if(strcmp(bookCase[*cnt].title, find) == 0){
            return 1;
        }else{
            *cnt = *cnt + 1;
            return findBooksTitle(bookCase, SIZE, find, cnt);
        }
    }
    return 0;
}

void findBooksPrice(book bookCase[], int SIZE, int *cnt, float min, float max, int* flag){
    if(*cnt < SIZE){
        if(bookCase[*cnt].price >= min && bookCase[*cnt].price <= max){
            printf("Il libro %s rientra nella fascia di prezzo scelta\n", bookCase[*cnt].title);
            *flag = *flag + 1;
        }
        *cnt = *cnt + 1;
        findBooksPrice(bookCase, SIZE, cnt, min, max, flag);
    }
}

void lowerChar(char* word){
    if(*word != '\0'){
        *word = tolower(*word);
        lowerChar(word + 1);
    }
>>>>>>> 3bb886a2fa30b0b290ecdbe03fb4a04612cf4b9b
}