#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
//LABORATOR 8 - SIRURI DE CARACTERE

//PROB 3.2

/*
V1__________

char* subsir(char* destinatie, const char* sursa, int pozitie, int n)
{
    if(pozitie >= strlen(sursa)) destinatie[0]='\0';
    else
    {
        strncpy(destinatie, sursa+pozitie, n);
        destinatie[n]='\0';
    }
    return destinatie;
}

int main()
{
    int n, poz;
    char s[N], d[N];
    printf("Sirul din care extragem: \n");
    fgets(s, N, stdin);
    printf("nr caractere de extras=\n");
    scanf("%d", &n);
    printf("de pe pozitia=\n");
    scanf("%d", &poz);

    printf("Subsirul: %s\n", subsir(d, s, poz, n));
    printf("Lungimea: %d", strlen(d));
    return 0;
}
*/

//V2__________
/*
int* citeste(int *pn)
{
    printf("Nr. elem=");
    scanf("%d", pn);
    int* a;
    a=calloc(*pn, sizeof(int));
    if(a==NULL)
    {
        printf("Memorie insuficienta");
        exit(1);
    }
    int i;
    for(i=0; i<*pn; i++)
        scanf("%d",&a[i]); //sau a+i
    return a;
}

int min(int a, int b)
{
    if(a>b) return b;
        else return a;
}

void subsir(int* destinatie, const int* sursa, int pozitie, int n, int ns, int *pnd)
{
    if(pozitie >= ns) *pnd=0;
    else
    {
        *pnd=min(n, ns-pozitie);
        memcpy(destinatie, sursa+pozitie,*pnd*sizeof(int));
    }
}

void afisare(int b[],int n)
 {
    int i;
    printf("Elementele multimii sunt:\n");
    for(i=0;i<n;i++)
        printf("%d <=> %d \n",i, b[i]);
 }

int main()
{
    int *a, *b;
    int n, poz, m, nr; //m nr elem a, n nr elem b
    a=citeste(&m);

    printf("nr caractere de extras=\n");
    scanf("%d", &n);
    printf("de pe pozitia=\n");
    scanf("%d", &poz);

    b=calloc(n, sizeof(int));
    if(b==NULL)
    {
        printf("Memorie insuficienta");
        exit(1);
    }

    printf("Subsirul:\n");
    subsir(b, a, poz, n, m, &nr);
    afisare(b, nr);
    return 0;
}
*/

//PROB 3 - INSERARE
//V. sir caractere.
/*
char* insereaza(char *dest, const char *sursa, int poz) //in dest inseram sirul sursa
{
    if(poz< strlen(dest))
    {
       //v1 char aux[strlen(dest)-poz+1];
       //v1 strcpy(aux, dest+poz);
       //v1 strcpy(dest+poz, sursa);
       //v1 strcat(dest, aux); //concatenez la destinatie pe aux
       //v2:
       ///strcpy(dest+poz+strlen(sursa), dest+poz); //sau in loc de strcpy folosim:
       memmove(dest+poz+strlen(sursa), dest+poz, strlen(dest)-poz+1);
       //pt ca strcpy nu functioneaza bine in orice situatie
       strncpy(dest+poz, sursa, strlen(sursa));
    }
    else if(poz=strlen(dest))
            strcat(dest, sursa);
    return dest;
}

int main()
{
    int n, poz;
    char s[N], d[N];
    printf("Sirul pe care il inseram: \n");
    gets(s);
    printf("Sirul in care inseram(destinatie): \n");
    fgets(d, N, stdin);
    //printf("nr caractere de inserat=\n");
    //scanf("%d", &n);
    printf("inserare pe pozitia=\n");
    scanf("%d", &poz);

    printf("Destinatie: %s\n", insereaza(d, s, poz));
    return 0;
}
*/

//PROB 4

char* sterge(char *s, int poz, int n)
{
    if(poz < strlen(s))
    {
        if(poz+n >= strlen(s))
            s[poz]='\0';
        else
            memmove(s+poz, s+poz+n, strlen(s)-poz-n+1);
    }
    return s;
}

int main()
{
    int n, poz;
    char s[N];
    printf("Sirul este: \n");
    gets(s);
    printf("Cate caractere stergem: \n");
    scanf("%d", &n);
    printf("de pe pozitia=\n");
    scanf("%d", &poz);

    printf("Sirul dupa stergere: %s\n", sterge(s, poz, n));
    return 0;
}
