/*

Realizzare un programma che memorizzi un elenco di persone, ogni persona è identificata da Cognome, 
Nome e data di nascita. La data è però a sua volta suddivisa in anno, mese, giorno, ed è una struttura interna quella generale Persona.
Realizzare:
1. inserimento di una persona.
2. Lista di tutte le persone e relative date di nascita.
3. Ricerca per cognome o per anno di nascita.

*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

typedef struct{
    int giorno;
    int mese;
    int anno;
}Data;

typedef struct{
    char nome[15];
    char cognome[15];
    Data nascita;
}Persona;

void insert(Persona*);
void show_list(Persona*, int, int );
void search(Persona*, char);

int main(){
    Persona* p;
    int scelta, cnt = 0;
    
    do{
        /*for (int i = 0; i < cnt; i++)
            printf("____%s %s %d %d %d____\n", (p+i)->nome, (p+i)->cognome, (p+i)->nascita.giorno, (p+i)->nascita.mese, (p+i)->nascita.anno);*/
        printf("1.INSERIMENTO DI UNA PERSONA\n2.VISUALIZZA LISTA\n3.RICERCA PER COGNOME O ANNO\n0.USCITA\n");
        scanf("%d", &scelta);
        if(scelta == 1){
            cnt++;
            if(cnt==1)
                p = (Persona*)malloc(cnt * sizeof(Persona));
            else
                p = (Persona*)realloc(p, cnt * sizeof(Persona));
            insert(p+cnt-1);        //-1 perchè deve partire dall'inizio
            printf("%s %s %d %d %d\n", (p+cnt-1)->nome, (p+cnt-1)->cognome, (p+cnt-1)->nascita.giorno, (p+cnt-1)->nascita.mese, (p+cnt-1)->nascita.anno);
        }else if(scelta == 2){
            show_list(p, cnt, 0);
        }else if(scelta == 3){
            search()
        }
    }while(scelta != 0);
}

void insert(Persona* p){
    printf("inserisci il nome: ");
    scanf("%s", p->nome);
    fflush(stdin);

    printf("inserisci il cognome: ");
    scanf("%s", p->cognome);
    fflush(stdin);

    printf("inserisci giorno di nascita: ");
    scanf("%d", &p->nascita.giorno);
    fflush(stdin);

    printf("inserisci mese di nascita: ");
    scanf("%d", &p->nascita.mese);
    fflush(stdin);

    printf("inserisci anno di nascita:");
    scanf("%d", &p->nascita.anno);
    fflush(stdin);
}

void show_list(Persona* p,int cnt, int i){
    if(i<cnt){
        printf("nome: %s , data: %d/%d/%d\n", p->nome, p->nascita.giorno, p->nascita.mese, p->nascita.anno); 
        show_list(p+1, cnt, i+1);
    }
}
