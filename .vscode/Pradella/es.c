


#include<stdio.h>
#include<stdlib.h>

int verifyPalindroma(char*, int);
int matchAnagramma(char*, char*, int, int);

int main(){
    int dim,dim1;
    int scelta;
   
        printf("inserisci la dimensione della parola che vuoi inserire:");
        scanf("%d", &dim);
        fflush(stdin);

        char s[dim];
        
        printf("inserisci stringa:");
        scanf("%s", s);
        fflush(stdin);

        if(verifyPalindroma(s, dim)){
            printf("la stringa E' palindroma");
        }else{
            printf("la stringa NON E' palindroma");
        }
    
        printf("\ninserisci la dimensione della seconda parola che vuoi inserire:");
        scanf("%d", &dim1);
        fflush(stdin);
        char s1[dim1];
        printf("inserisci stringa:");
        scanf("%s", s1);
        fflush(stdin);

        if(matchAnagramma(s , s1 , dim, dim1)){
            printf("le parole sono anagrammi");
        }else{
            printf("\nle parole non sono anagrammi");
        }
    }



/*1. Realizza una funzione "int verifyPalindroma(char*)"
che riceve come parametro una stringa (singola parola) e restituisce:
- 0 se la stringa NON è palindroma
- 1 se la stringa E' palindroma
Una stringa è palindroma se letta da sinistra verso destra e da destra verso sinistra, risulta uguale.
Es.
- RADAR è palindroma
- OTTO è palindroma
- EFFE è palindroma.*/

int verifyPalindroma(char* s, int dim){
    int flag=0;
    char copy[dim];
    int i,j;
    for(i=0;i<dim;i++){
        *(copy+i)=*(s+i);
    }
    for(i=0,j=dim-2;i<dim-1 && j>=0;i++, j--){
        if(*(s+i)==*(copy+j)){
            flag = 1;
        }
    }


    return flag;
}


/*2. Realizza una funzione "int matchAnagramma(char*, char*)"
che riceve come parametri due stringhe str1 e str2, la funzione verifica se str2 è un anagramma di str1, ritornando 1 in caso vero e 0 in caso falso.
Str2 è un anagramma di str1 se è una parola formata dalle stesse lettere di str1 ma in ordine diverso (non necessariamente una parola di senso compiuto) .
Es.
str1: OTTO str2: TOTO -> Str2 è un Anagramma.*/

int matchAnagramma(char* s, char* s1, int dim, int dim1){
    int i,j;
    int flag=0;
    for(i=0;i<dim-2;i++){    
        for(j=0;j<dim1-2;j++){
            if(s[i] == s1[j])
                s1[j] = 0;
        }
    }

    for(j=0;j<dim1-2;j++){
        if(s[i] == '0')
            flag++;
    }
    if(flag)
        return 1;
    else 
        return 0;
}