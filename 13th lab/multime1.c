#include <stdio.h>
#include <stdlib.h>
#include "multime.h"

void citMultime(FILE *pf, TipMultime *pM)
{
    int n;
    fscanf(pf, "%d", &n);
    if(n<=0)
    {
        printf("Nr. elem. invalid!!: %d", n);
        exit(1);
    }
    pM->a=calloc(n, sizeof(int));  // in loc de (*pm).a
    if(pM->a==NULL)
    {
        printf("Memorie insuficienta!!");
        exit(1);
    }
    int i, aux=n;
    pM->n=0;
    for(i=0; i<n; i++)
        do{
            fscanf(pf, "%d", &pM->a[i]);
            if(!apartine(pM->a[i], *pM))
            {
                pM->n++; //creste nr de elemente ale multimii
                break;
            }
            n--; //o sa avem cu un element mai putin de citit
        }while(1); //in do while trebuie sa citeasca un element care sa fie distinct de toate celelalte
    if(pM->n <aux)
    {
        int *a=realloc(pM->a, pM->n*sizeof(int)); //pM->n*sizeof(int)=nr elem*dimensiunea unui element
        if(a!=NULL)
            pM->a=a;
    } //parte auxiliara pt examen ^^^
}

int apartine(int x, TipMultime M)
{
    int i;
    for(i=0; i<M.n; i++)
        if(x==M.a[i])  //sau daca esti smecher si vrei pointeri x==*(M.a+i)
            return 1;
    return 0;
}pP->a

void reuniune(TipMultime M, TipMultime N, TipMultime *pP)
{
    int n=M.n+N.n; //numarul maxim de elemente pe care il poate avea reuniunea
    //variabila "n" o putem denumi oricum, nu are legatura cu n de la M.n
    pP->a=calloc(n, sizeof(int)); //
    if(pP->a==NULL)
    {
        printf("Memorie insuficienta!!");
        exit(1);
    }
    int i;
    for(i=0; i<n; i++)
        pP->a[i]=M.a[i];
    pP->n=M.n;
    for(i=0; i<N.n; i++)
        if(!apartine(N.a[i], M))
        {
            pP->a[pP->n]=N.a[i]; //pP->a[pP->n] urmatorul element
            pP->n++;
        }
    if(pP->n <n)
    {
        int *a=realloc(pP->a, pP->n*sizeof(int)); //pM->n*sizeof(int)=nr elem*dimensiunea unui element
        if(a!=NULL)
            pP->a=a;
    }
}

void afisMultime(TipMultime C)
{
     int i;
     for(i=0; i<C.n; i++)
        printf("%d ",C.a[i]);
    printf("\n");
}

void elib(TipMultime M)
{
    free(M.a);
}

void intersectie(TipMultime M, TipMultime N, TipMultime* pP)
{
    int n; //o putem denumi oricum, nu are legatura cu n de la M.n
    if(M.n>N.n) n=N.n;
        else n=M.n;
    pP->a=calloc(n, sizeof(int)); //
    if(pP->a==NULL)
    {
        printf("Memorie insuficienta!!");
        exit(1);
    }
    int i;
    int q=0;
    for(i=0; i<N.n; i++)
        if(apartine(N.a[i], M))
        {
            pP->a[q]=N.a[i]; //pP->a[pP->n] urmatorul element
            q++;
        }
    pP->n=q;
    if(pP->n <n)
    {
        int *a=realloc(pP->a, pP->n*sizeof(int)); //pM->n*sizeof(int)=nr elem*dimensiunea unui element
        if(a!=NULL)
            pP->a=a;
    }
}


