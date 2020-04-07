#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define PI 3.1415

typedef struct
{
    float partea_reala, partea_imaginara;
}TComplex;


void citLin(char *s, int nr) //nr=nr maxim de caract pe care le citeste
{
    fgets(s, nr, stdin);
    int n=strlen(s);
    if(s[n-1]=='\n')
        s[n-1]='\0'; //punem sfarsit de sir in loc de new line
}
/*
//PROB 2

void creeaza(const char *numeFis)
{
    FILE *pf;  //FILE definita in stdio.h
    pf=fopen(numeFis, "w"); //w=daca nu exista fisierul in creeaza,
                            //daca exista il deschide si ii sterge continutul
    if(pf==NULL)
    {
        perror(numeFis); //<- afiseaza textul pe care il dau ca parametru
        exit(-69);
    }
    char s[N]; //tablou de caractere in care citesc
//V2   while(1)
//     {
//         if(fgets(s,N,stdin)==NULL)
//             break;
//         if(s[0]=='\0') break;
//         fputs(s,pf);
//     }
    while(fgets(s,N,stdin)!=NULL) //citesc linii pana nu mai sunt
        fputs(s, pf);
        // ca sa ne oprim din citit dam CTRL+Z si ENTER
    fclose(pf);
}
void afiseaza(const char *numeFis)
{
    FILE *pf;
    pf=fopen(numeFis, "r"); //fisierul ar trebui sa existe deja
    if(pf==NULL)
    {
        perror(numeFis);
        exit(-69);
    }
    char s[N];
    int i=1;
    printf("%2d. ",i++);
    while(fgets(s,N,pf)!=NULL)
    {
        printf("%s", s);
        if(s[strlen(s)-1]=='\n')
            printf("%2d. ",i++);
    }
    fclose(pf);
}

int main()
{
    char numeFis[15];
    printf("Nume fisier: ");
    citLin(numeFis,15);
    creeaza(numeFis);
    afiseaza(numeFis);

    return 0;
}



// PROB 3

void creeaza(const char *numeFis)
{
    FILE *pf;  //FILE definita in stdio.h
    pf=fopen(numeFis, "w"); //w=daca nu exista fisierul in creeaza,
                            //daca exista il deschide si ii sterge continutul
    if(pf==NULL)
    {
        perror(numeFis); //<- afiseaza textul pe care il dau ca parametru
        exit(-69);
    }
    int n;
    printf("Nr. de numere complexe= ");
    scanf("%d", &n);
    TComplex nr;
    double modul, argument;
    int i;
    for(i=0; i<n; i++)
    {
        printf("[%d]: ", i);
        scanf("%f%f", &nr.partea_reala, &nr.partea_imaginara);
        modul=sqrt(nr.partea_reala*nr.partea_reala+nr.partea_imaginara*nr.partea_imaginara);
        argument= atan2(nr.partea_imaginara, nr.partea_reala);
        fprintf(pf, "%f %f %lf %lf\n", nr.partea_reala, nr.partea_imaginara, modul, argument);
    }
    fclose(pf);

}

void afiseaza(const char *numeFis)
{
    FILE *pf;
    pf=fopen(numeFis, "r");
    if(pf==NULL)
    {
        perror(numeFis);
        exit(-69);
    }
    TComplex nr;
    double modul, argument;
    int i=1;
    while(fscanf(pf, "%f%f%lf%lf", &nr.partea_reala, &nr.partea_imaginara, &modul, &argument)==4)
    {
        printf("%d) %.2f+ %.2fi ", i++, nr.partea_reala, nr.partea_imaginara);
        printf("-> modulul= %lf <-> argumentul= %lf\n", modul, argument/PI*180);
    }
}

int main()
{
    char numeFis[15];
    printf("Nume fisier: ");
    citLin(numeFis,15);
    creeaza(numeFis);
    afiseaza(numeFis);

    return 0;
}
*/



//PROB 4


void concatenare(const char *numeRez, int n)
{
    FILE *pr, *pf;  //pr pointer fisier rezultat
    pr=fopen(numeRez, "w");
    if(pr==NULL)
    {
        perror(numeRez);
        exit(-69);
    }
    int i;
    char numeFis[15];
    for(i=0; i<n; i++)
    {
        strcpy(numeFis, "fis"); //fis0,1,2,.... .txt
        char aux[5];
        itoa(i, aux, 10);
        strcat(numeFis, aux);
        strcat(numeFis, ".txt");
        pf=fopen(numeFis, "r");
        if(pf==NULL)
        {
            perror(numeFis);
            exit(-69);
        }
        float f;
        while(fscanf(pf, "%f", &f)==1)
            fprintf(pr, "%f ", f);
        fprintf(pr, "\n");
        fclose(pf);
    }
    fclose(pr);
}

void afiseaza(const char *numeFis)
{
    FILE *pf;
    pf=fopen(numeFis, "r"); //fisierul ar trebui sa existe deja
    if(pf==NULL)
    {
        perror(numeFis);
        exit(-69);
    }
    char s[N];
    int i=1;
    printf("%2d. ",i++);
    while(fgets(s,N,pf)!=NULL)
    {
        printf("%s", s);
        if(s[strlen(s)-1]=='\n')
            printf("%2d. ",i++);
    }
    fclose(pf);
}


int main()
{
    int n;
    char numeRez[]="rez.txt";
    printf("Nr fisiere= ");
    scanf("%d", &n);
    concatenare (numeRez, n);
    afiseaza(numeRez);
    return 0;
}
