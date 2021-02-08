/*2. Realizza una funzione "int matchAnagramma(char*, char*)"
che riceve come parametri due stringhe str1 e str2, la funzione verifica se str2 è un anagramma di str1, ritornando 1 in caso vero e 0 in caso falso.
Str2 è un anagramma di str1 se è una parola formata dalle stesse lettere di str1 ma in ordine diverso (non necessariamente una parola di senso compiuto) .
Es.
str1: OTTO str2: TOTO -> Str2 è un Anagramma.*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int matchAnagramma(char*, char*);
int lenght(char*,int );

int main(){
    char str1[20],str2[20];
    printf("inserisci la stringa numero 1.: ");
    scanf("%s", str1);
    printf("inserisci la stringa numero 2.: ");
    scanf("%s", str2);

    char* p1 = &str1[0];
    char* p2 = &str2[0];

    if(matchAnagramma(p1, p2)){
        printf("ANAGRAMMA");
    }else
        printf("NON ANAGRAMMA");
    
    
}

int matchAnagramma(char* p1, char* p2){
    int dim1=lenght(p1, 0);
    int dim2=lenght(p2, 0);
    char cpy[20];
    int flag=0;

    for(int i=0;i<dim1; i++){
        cpy[i] = *(p1+i);
    }

    for(int i=0;i<dim1; i++){
        for(int j=0; j<dim2; j++){
            if(*(p1+i) == *(p2+j))
                cpy[i]=0;
        }
    }

    for(int i=0;i<dim1; i++){
        if(cpy[i]==0)
            flag++;
    }   
    if(flag==dim1){
        return 1;
    }else
        return 0;
}

int lenght(char* p, int cnt){
    if(*p != '\0'){
        printf("---%c---", *p);
        cnt=cnt+1;
        lenght(p+1, cnt);
    }else{
        return cnt;
    }
}