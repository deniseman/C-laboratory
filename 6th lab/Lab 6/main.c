#include <stdio.h>
#include <stdlib.h>
#include <string.h> //pt strcmp
#define N 10
#define LMAX 100

//LABORATOR 6

//(=-2-=) Sortare
/*
float* citeste(int *pn, char c)
{
    printf("Nr. elem=");
    scanf("%d", pn);
    float* a;
    a=calloc(*pn, sizeof(float));
    if(a==NULL)
    {
        printf("Memorie insuficienta");
        exit(1);
    }
    int i;
    for(i=0; i<*pn; i++)
    {
        printf("%c[%d]=",c,i);
        scanf("%f",&a[i]); //sau a+i
    }
    return a;
}

void bubbleSort(float a[], int n)
{
    int i, sortat=0;
    while(!sortat)
    {
        sortat=1;
        for(i=1;i<n;i++)
        {
            if(a[i-1]>a[i])
            {
                schimba(&a[i-1],&a[i]);
                //float aux=a[i-1];
                //a[i-1]=a[i];
                //a[i]=aux;
            }
            sortat=0;
        }
        n--;
    }
}

void afis(float a[],int n)
{
    int i;
    printf("Elementele multimii sunt:\n");
    for(i=0;i<n;i++)
        printf("a[%d]=%f \n",i, a[i]);
    printf("\n");
}

void schimba(float* b,float* c)
{
    float aux=*b;
    *b=*c;
    *c=aux;
}

int main()
{

    float *a;
    int n;
    a=citeste(&n,'a');
    bubbleSort(a,n);
    afis(a,n);
    free(a);
    return 0;
}
*/


//(=-3-=) Interclasare a 2 vectori
/*

float* citeste(int *pn, char c)
{
    printf("Nr. elem=");
    scanf("%d", pn);
    float* a;
    a=calloc(*pn, sizeof(float));
    if(a==NULL)
    {
        printf("Memorie insuficienta");
        exit(1);
    }
    int i;
    for(i=0; i<*pn; i++)
    {
        printf("%c[%d]=",c,i);
        scanf("%f",&a[i]); //sau a+i
    }
    return a;
}

float* interclasare(float a[], int na, float b[], int nb, int *pnc)
{
    float *c;
    c=calloc(na+nb, sizeof(float));
    if(c==NULL)
    {
        printf("Memorie insuficienta");
        exit(1);
    }
    *pnc=na+nb;
    int nc=0;
    int i=0, j=0;
    while(i<na&&j<nb)
    {
        if(a[i]<=b[j])
            c[nc]=a[i++]; // SAU c[nc]=a[i]; i++;
            else
                c[nc]=b[j++];
        nc++;
    }
    for( ; i<na; i++) // ^ porneste de la i cat a ramas de mai sus
        c[nc++]=a[i];
    //sau cu while
    while (j<nb)
        c[nc++]=b[j++];
    return c;
}

void afis(float c[],int nc)
{
    int i;
    printf("Elementele multimii sunt:\n");
    for(i=0;i<nc;i++)
        printf("c[%d]=%f \n",i, c[i]);
    printf("\n");
}

int main()
{
    float *a, *b, *c;
    int na, nb, nc;
    a=citeste(&na, 'a');
    b=citeste(&nb, 'b');
    c=interclasare(a, na, b, nb, &nc);
    afis(c, nc);
    free(a);
    free(b);
    free(c);
}
*/



//(=-4-=)
/*
void citesteSiruri(char s[][LMAX+1], int *pn)
{
    printf("Nr. siruri = ");
    scanf("%d", pn);
    fflush(stdin);
    int i;
    for(i=0; i<*pn; i++)
        gets(s[i]);
}

void bubble(char s[][LMAX+1], int n)
{
    int i, sortat=0;
    while(!sortat)
    {
        sortat=1;
        for(i=1; i<n; i++)
            if(strcmp(s[i-1],s[i])>0)
            {
                char aux[LMAX+1];
                strcpy(aux, s[i-1]);
                strcpy(s[i-1], s[i]);
                strcpy(s[i], aux);
                sortat=0;
            }
        n--;
    }
}

void afisSiruri(char s[][LMAX+1],int n)
{
    int i;
    printf("Elementele multimii sunt:\n");
    for(i=0;i<n;i++)
        puts(s[i]);
    printf("\n");
}


int main()
{
    char s[N][LMAX+1];
    int n;
    citesteSiruri(s, &n);
    bubble(s, n);
    afisSiruri(s, n);
    return 0;
}
*/
