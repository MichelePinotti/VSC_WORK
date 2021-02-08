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



int doppie(int , char* );
int dupli(char);

int main(int argc, char** argv){
    int i;
    for(i=1;i<argc;i++){
        if(doppie(argc, argv[i])){
            printf("\nla stringa numero %d ha delle doppie", i-1);
        }else{
            printf("\nla stringa numero %d non ha delle doppie", i-1);
        }
    }
}

int doppie(int n, char* argv){
    char temp=0;
    if(n<1){
        printf("\nnon ci sono stringhe da analizzare");
    }else if(*argv == '\0'){
          temp = temp;
      }else if(**argv != '\0'){
          if(*argv == temp){
              temp = *argv;
           }
         doppie(n,*(argv+1));
      }
    if(temp > 0){
        return 1;
    }else{
        return 0;
    }
}