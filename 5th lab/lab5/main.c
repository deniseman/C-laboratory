#include <stdio.h>
#include <stdlib.h>
#define GRAD_MAX 10
#define N 50


/* 5.2 - radacini polinom
int CitestePolinom(int coef_polinom[])
 {
    int gr;
    int i;
    printf("Grad polinom (<=%d): ", GRAD_MAX);
    scanf("%d", &gr);
    printf("\nCoeficientii:\n");
    for(i=gr; i>=0; i--)
        {
            printf("a[%d]=", i);

            scanf("%d", &coef_polinom[i]);
        }
    return gr;
 }

 void AfisRadInt(int coef_polinom[], int gr)
 {
     int nr_radacini=0, i=0, ai, divizor;
     printf("Radacinile polinomului: ");
     while(coef_polinom[i]==0&&i<=gr)
        i++;
     if(i>0){
        printf("0 ");
        nr_radacini++;
     }
     if(i<=gr){
        ai=coef_polinom[i]<0?-coef_polinom[i]:coef_polinom[i];
        for(divizor=1; divizor<=ai; divizor++)
        if(coef_polinom[i]%divizor==0){
            if(val_polinom(divizor, gr, coef_polinom)==0){
                printf("%d ", divizor);
                nr_radacini++;
            }
            if(val_polinom(-divizor, gr, coef_polinom)==0){
                printf("%d ", -divizor);
                nr_radacini++;
            }
        }
        if(nr_radacini==0) printf("nu sunt\n");
     }
     else
        printf("Exista o infinitate\n");
 }

 int val_polinom(int x,int n, int coef_polinom[])
 {
    int i;
    int v=0;
    for(i=n;i>=0;i--)
        v=v*x+coef_polinom[i];
    return v;
 }



int main()
{
    int coef_polinom[GRAD_MAX+1];
    int grad;
    grad=CitestePolinom(coef_polinom);
    AfisRadInt(coef_polinom, grad);

    return 0;
}
//______________________________________________________________
*/


// PROBLEMA 5.3
/*
int citesteRel(int R[][2])
 {
    int n, i;
    printf("Nr elem ale rel (<=%d) ", N);
    scanf("%d", &n);
    printf("\nElem relatiei: \n");
    for(i=0; i<n; i++)
        {
            printf("Relatie[%d]=", i);

            scanf("%d%d", &R[i][0], &R[i][1]);
        }
    return n;
 }

 int detMultime(int R[][2], int n, int M[])
 {
     int m=0, i, j;
     for(i=0; i<n; i++)
        for(j=0; j<=1; j++)
        {
            if(!exista(R[i][j], M, m))
            {
                M[m]=R[i][j];
                m++;
            }
        }
    return m;
 }

 int exista(int x, int a[], int n)
 {
     int i;
     for(i=0; i<n; i++)
        if(a[i]==x) return 1;
     return 0;
 }

 int reflexiva(int R[][2], int n, int M[], int m)
 {
     int i;
     for(i=0; i<m; i++)
        if(!exista_relatie(M[i],M[i], R, n))
            return 0;
    return 1;
 }

 int exista_relatie(int x, int y, int R[][2], int n)
 {
     int i;
     for(i=0; i<n; i++)
        if(R[i][0]==x&&R[i][1]==y)
            return 1;
     return 0;
 }

void afis(int M[],int m)
 {
    int i;
    printf("Elementele multimii M sunt:\n");
    for(i=0;i<m;i++)
        printf("M[%d]=%d \n",i, M[i]);
    printf("\n");
 }

 int simetrica(int R[][2], int n)
 {
     int i;
     for(i=0; i<n; i++)
        if(!exista_relatie(R[i][1],R[i][0],R,n))
            return 0;
     return 1;
 }

 int tranzitiva(int R[][2], int n)
 {
     int i, j;
     for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(R[i][1]==R[j][0])
                if(!exista_relatie(R[i][0],R[j][1],R,n))
                    return 0;
     return 1;
 }

int main()
{
    int n, R[N][2], M[2*N], m; //m = nr elem multime M
    n=citesteRel(R);
    m=detMultime(R,n,M);
    afis(M,m);
    int r, s, t;
    r=reflexiva(R, n, M, m);
    s=simetrica(R, n);  // avem nevoie doar de relatie
    r=tranzitiva(R, n); // -||-
    if(s) printf("Simetrica \n");
    if(r) printf("Reflexiva \n");
    if(t) printf("Tranzitiva \n");
    if(s&&r&&t) printf("Relatie de echivalenta\n");
    return 0;
}
*/


//_______________________________________________________
//PROBLEMA 5.11 DAR CU NR INTREGI

int citeste(int a[], char nume)
{
    int n, i;
    printf("Nr elem (<=%d): ", N);
    scanf("%d", &n);
    printf("\nElementele lui %c sunt: \n", nume);
    for(i=0; i<n; i++)
    {
        printf("%c[%d]=", nume, i);
        scanf("%d", &a[i]);
    }
}

int cauta(int a[], int n, int b[], int m)
{
    int poz=-1, i=0, j;
    while(poz<0 && i<=n-m)
    {
        for(j=0; j<m; j++)
            if(a[i+j]!=b[j]) break;

        if(j==m)
            poz=i;
        i++;
    }
}

int main()
{
    int a[N], n, b[N], m, i, j;
    n=citeste(a, 'a');
    m=citeste(b, 'b');
    int poz=cauta(a, n, b, m);
    if(poz<0)
        printf("Nu exista sirul b in sirul a\n");
    else
        printf("b e in a pe poz %d\n", poz);
    return 0;
}
