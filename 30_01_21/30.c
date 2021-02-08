#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct book{
    char title[40];
    char author[40];
    //int pages_n;
    //float price;    
    struct book* next;
}Book;

void insertBooks(Book*, char*, char*);
int insertfirstBooks(Book*, char*, char*);
Book* removeBooks(Book*, char*, int*);
void lowerChar(char*);
int findIndex(Book*, char*);
void print(Book*);

int main(){
    int scelta;
    Book* lista;
    int first=0;
    do{
        printf("\nCosa vuoi fare?\n1. INSERISCI LIBRO     2.CERCA PER TITOLO      3.RIMUOVI LIBRO      0.USCITA\n");
        scanf("%d", &scelta);
        fflush(stdin);
        if(scelta == 1){            //INSERIMENTO
            char title[40];
            char author[40];
            printf("Inserisci il titolo: ");
            gets(title);
            printf("Inserisci l'autore: ");
            gets(author);
            if(first==0)
                first=insertfirstBooks(lista, title, author);
            else
                insertBooks(lista, title, author);
            print(lista);
        }else if(scelta==2){        //RICERCA TITOLO
            char str[40];
            printf("Che libro vuoi rimuovere?\n");
            gets(str);
            fflush(stdin);
            lowerChar(str);
            int idx=findIndex(lista,str);
            if(idx >= 0)
                printf("Libro trovato alla posizione %d\n", idx);
            else
                printf("Libro non trovato\n");
                printf("\n");
            print(lista);
        }else if(scelta == 3){      //RICERCA PER TITOLO
            char find[40];
            printf("Che libro vuoi cercare?\n");
            gets(find);
            fflush(stdin);
            lowerChar(find);
            int index = findIndex(lista,find);
            
            if(index >= 0)
                printf("Il libro %s e' presente alla cella %d\n", find,index);
            else
                printf("Nessun libro con questo titolo\n");
                printf("\n");
            print(lista);
        }else if(scelta==3){     //REMOVE
            char rem[40];
            printf("Che libro vuoi rimuovere?\n");
            gets(rem);
            fflush(stdin);
            lowerChar(rem);
            int flag=0;
            removeBooks(lista, rem, &flag);
            if(flag == 1)
                printf("Libro rimosso\n");
            else
                printf("Libro non trovato e quindi non rimosso\n");
                printf("\n");
            print(lista);
        }
        printf("\n---PREMERE PER CONTINUARE---");
        getchar();
        system("CLS");
    } while (scelta != 0);
}

int insertfirstBooks(Book* lista, char* title, char* author){
    strcpy(lista->title,title);
    strcpy(lista->author,author);
    return 1;
}

void insertBooks(Book* lista, char* title, char* author){    //FINITO
    if((lista->next)==NULL){
        Book* newEnd = (Book*)malloc(sizeof(Book));
        strcpy(newEnd->title,title);    
        strcpy(newEnd->author,author);  
        
        newEnd->next = NULL;
        lista->next = newEnd;
    }else
        insertBooks(lista->next, title, author);
}



int findIndex(Book* lista,char* find){      //FINITO
    Book* temp = lista;
    int cnt=0;
    while(temp != NULL){
        if(strcmp(temp->title, find) == 0){
            return cnt;
        }else{
            cnt++;
        }
    }
    return -1;
}

void lowerChar(char* word){     //FINITO
    if(*word != '\0'){
        *word = tolower(*word);
        lowerChar(word + 1);
    }
}

Book* removeBooks(Book* lista,char* rem, int* flag){
    if(lista != NULL){
        if(strcmp(rem,lista->title)==0){       //nel caso sia la prima
			Book* tmp = lista->next;
			free(lista);
            *flag = 1;
			return tmp;
        }else if(strcmp(rem,lista->next->title)==0){    //nel caso sia in mezzo
			lista->next = lista->next->next;
			free(lista->next);
            *flag=1;
            return lista;
        }else if(lista->next->next == NULL){
            lista->next = NULL;
        }
        return removeBooks(lista->next, rem, flag);
    }
    return lista;
}

void print(Book* lista){
    while(lista != NULL){
        printf("\ntitolo: %s", lista->title);
        printf("\nautore: %s", lista->author);
        lista = lista->next;
    }
}

//primi input: ciao pino. secondo: stone robi. output: "" "pino""stone""robi". cancella il titolo ciao