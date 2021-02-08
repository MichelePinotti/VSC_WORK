typedef struct elemento{
    int value;
    struct elemento* next;
}Elemento;

int head(Elemento* );
Elemento* tail(Elemento* );
Elemento* addToHead(Elemento* , int );
void addToEnd(Elemento*, int );
Elemento* addOrdered(Elemento*, int);
int find(Elemento*, int);
int findIndex(Elemento*, int, int*);
Elemento* rimuovi(Elemento*, int);
int lenght(Elemento*);
void stampaLista(Elemento* );
void stampaListaRev(Elemento* );