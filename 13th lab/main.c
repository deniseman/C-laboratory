#include <stdio.h>
#include <stdlib.h>
#include "multime.h"

int main()
{
    FILE *pf;
    pf=fopen("date.txt", "r");
    if(pf==NULL)
    {
        perror("date.txt"); //<- la cine se refera eroarea
        exit(1);
    }
    TipMultime A,B,C;
    citMultime(pf, &A);
    citMultime(pf, &B);
    afisMultime(A);
    afisMultime(B);
    fclose(pf);
    reuniune(A, B, &C); //C=reuniunea din A si B
    afisMultime(C);
    elib(C);
    printf("\n\n");
    intersectie(A, B, &C);
    afisMultime(C);
    elib(A); elib(B); elib(C); //eliberare spatiu pentru multimile A, B si C
    //daca mai facem si alte operatii dupa fiecare dam elib(C)
    return 0;
}
