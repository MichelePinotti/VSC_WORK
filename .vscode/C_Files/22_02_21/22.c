#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct lista{
    char name[10];
    int priority;
    int time;
    struct lista* next;
}Lista;

/*Lista* pushCoda(Lista* t){
    if(t == NULL){
        Lista* tmp = (Lista*) malloc(sizeof(Lista));
        printf("\nquale e il nome del tuo processo: ");
        scanf("%s", tmp->name);
        printf("\nquanto tempo ha il tuo processo: ");
        scanf("%d", &tmp->time);
        do{
            printf("\nquale priorita ha il tuo processo: ");
            scanf("%d", &tmp->priority);
        }while(tmp->priority > 5 || tmp->priority < 1);
        
        tmp->next = NULL;
        return(tmp);
    }
    else{
        Lista* tmp;
        tmp = t;
        // mi sposto fino all'ultimo nodo.
        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        // alloco un nuovo nodo e assegno il suo indirizzo alla parte next dell'ultimo nodo
        tmp->next = (Lista*) malloc(sizeof(Lista));
        
        // mi sposto il tmp sull'ultimo nodo creato.
        tmp = tmp->next;
        
        // imposto il valore nell'ultimo nodo.
        printf("\nquale e il nome del tuo processo: ");
        scanf("%s", tmp->name);
        printf("\nquanto tempo ha il tuo processo: ");
        scanf("%d", &tmp->time);
        do{
            printf("\nquale priorita ha il tuo processo: ");
            scanf("%d", &tmp->priority);
        }while(tmp->priority > 5 || tmp->priority < 1);
        // !!! metto a null il next dell'ultimo nodo per chiudere la lista.
        tmp->next = NULL;
        return(t);
    }
}*/
Lista* pushCoda(Lista* t){      //inizializzata auto
    if(t == NULL){
        Lista* tmp = (Lista*) malloc(sizeof(Lista));
        strcpy(tmp->name,"pino");
        tmp->time = 50;
        tmp->priority = 3;
        
        tmp->next = NULL;
        return(tmp);
    }
    else{
        Lista* tmp;
        tmp = t;
        // mi sposto fino all'ultimo nodo.
        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        for(int i=0; i<3;i++){
            // alloco un nuovo nodo e assegno il suo indirizzo alla parte next dell'ultimo nodo
            tmp->next = (Lista*) malloc(sizeof(Lista));
            
            // mi sposto il tmp sull'ultimo nodo creato.
            tmp = tmp->next;
            
            // imposto il valore nell'ultimo nodo.
            strcpy(tmp->name,"stone");
            tmp->time = 30 + i;
            tmp->priority = 1 + i;
            // !!! metto a null il next dell'ultimo nodo per chiudere la lista.
            tmp->next = NULL;
        }
        return(t);
    }
}

/*Lista* popFiniti(Lista* t){
    Lista* head=t;
    Lista* end;
    while(t != NULL){       //metto a end l'ultimo nodo
        end=t;
        t=t->next;
    }
    t=head;     //resetto puntatore all'inizio
    printf("\nstampo t: %c", t->name);
    Lista* tmp = t->next;
    if(head->time != 0){
        if(end->time != 0){
            while(tmp != NULL){
                if(tmp->time == 0){
                    t->next = tmp->next;
                    free(tmp);
                }
                t = t->next;
                tmp = tmp->next;
            }
            return head;
            }
        }else{
            while(t->next != NULL){
                t=t->next;
            }
            t->next = NULL;
            free(end);
        }else{
            free(t);
            return tmp;
        }
}*/

void popFiniti(Lista** t, Lista* pop){
    Lista* head = (*t);
    Lista* last;
    while((*t) != NULL){
        last = (*t);
        (*t)=(*t)->next;
    }
    (*t) = head;
    
    if((*t) == pop){
        (*t) = (*t)->next;
        free(pop);
    }else if(last == pop){
        while((*t)->next != pop){    
            (*t) = (*t)->next;
        }printf("\n%d", t);
        (*t)->next = NULL;
        free(pop);
    }else{
        while((*t)->next != pop){      
            (*t) = (*t)->next;
        }
        printf("\nnodo t:%d nodo pop in mezzo: %d", (*t), pop);
        (*t)->next = pop->next;
        free(pop);
    }
}

void stampaLista(Lista** t){
    while((*t) != NULL){
        printf("\nindirizzo: %d nome processo: %s   priorita:%d     tempo:%d\n",(*t), (*t)->name, (*t)->priority, (*t)->time);
        (*t) = (*t)->next;
    }
}

int findPriority(Lista* t){
    int tmp = 0;
    int magg;
    while(t!=NULL){
        if(tmp < t->priority)
            magg = t->priority;   
        t = t->next;
    }
    printf("\n\nmagg: %d",magg);
    return magg;
}

void cicloMacchina(Lista* t, int n){
    Lista* head = t;
    while(t!=NULL){     
        int tmp=findPriority(t);
        
        while(t->priority != tmp){      //funziona
            t = t->next;   
        }
        while(t->time >= 0){     //funziona
            t->time = (t->time) - n;
        }
        popFiniti(&head, t);
        stampaLista(&head);   
        printf("\nfinito un ciclo");    
        
    }
}


int main(){
    Lista* pila = NULL;
    const int ttl;
    printf("\nquanto tempo impieghera ogni ciclo macchina: ");
    scanf("%d", &ttl);

    pila=pushCoda(pila);
    printf("pila 1 inserita");
    pila=pushCoda(pila);
    printf("pila 2 inserita");
    stampaLista(&pila);
    printf("\neseguo ciclo macchina...");
    cicloMacchina(pila,ttl);
}