#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
    int j=1;
    printf("%c", *(*(argv + 1) + j));
}
