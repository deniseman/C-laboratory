#include <stdio.h>
#include "multime.h"

//FIS MULTIME.C

void citMult(int M[], int *pn)
{
    printf("Nr. elem. (<=%d): ", NMAX);
    scanf("%d", pn);
    printf("Elem. mult.: \n");
    int i;
    for(i=0; i<*pn; i++)
        do{
            printf("[%d]: ", i);
            scanf("%d", &M[i]);
            if(!apartine(M[i], M, i))  //fct apartine o facem noi, e prin lab 4->5->6 undeva
                break;
        }while(1);
}


void reuniune(int M[], int m, int N[], int n, int P[], int *pp) //pp=pointer nr elem multime p
{
    int i;
    for(i=0; i<m; i++)
        P[i]=M[i];
    *pp=m;
    for(i=0; i<n; i++)
        if(!apartine(N[i], M, m)) //nu apartine N[i] multimii M
        {
            P[*pp]=N[i];
            (*pp)++;
        }

}

void afisMult(int C[], int p)
{
     int i;
     for(i=0; i<p; i++)
    {
            printf("%d ",C[i]);
            printf("\n");
    }
}

int apartine(int x, int a[], int n)
{
     int i;
     for(i=0; i<n; i++)
        if(a[i]==x) return 1;
     return 0;
}

void inclusa(int M[], int m, int N[], int n)
{
    int i;
    for(i=0; i<m; i++)
        if(!apartine(M[i], N, m))
            return 0;
    return 1;
}

void egale(int M[], int m, int N[], int n)
{
    //daca au acelasi nr de elem si una este inclusa in cealalta
    if(m==n&& inclusa(M, m, N, n)) return 1;
    return 0;
}



