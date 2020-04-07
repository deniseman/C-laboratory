//LABORATOR 6 PART. II


#include <stdio.h>
#include <conio.h>
#include <math.h>

/* Programul L6Ex4.cpp */
/* Programul exemplifica modul de folosire al unei functii ca parametru */
/*
double f(double x)
{
    return (3*x*x +1);
}
double integrala(double a,double b,int n,double(*p)(double x)) // Calculul integralei prin metoda trapezelor
{
    int i;
    double h,s;
    h=(b-a)/n;
    s=((*p)(a)+(*p)(b))/2.0;
    for(i=1;i<n;i++)
        s=s+(*p)(a+i*h);
    s=s*h;
    return s;
}

void main()
{
    double a,b;
    int n;
    char ch; // Citirea intervalului de integrare
    printf("\na=");
    scanf("%lf",&a);
    printf("\nb=");
    scanf("%lf",&b); ch='D';

    while (ch=='D' || ch=='d')
    {
        printf("\nn=");
        scanf("%d",&n);
        printf("\nPentru n=%d Valoarea integralei este %lf",n,
        integrala(a,b,n,f));
        printf("\nApasati o tasta\n");
        getch();
        printf("\nIntroduceti alt n? DA=D/d NU=alt caracter ");
        ch=getch();
    }
}
*/


//EX 5
/*
double f(double x)
{
    return cos(x);
}

double rad(double a, double b, double(*pf)(double))
{
    //apelam doar daca f(a)*f(b)<0
    double m, epsilon=1e-7;
    while(1)
    {
        m=(a+b)/2;
        double val=pf(m); //(*pf)(m)
        if(fabs(val)<epsilon)
            return m;
        if(f(a)*val<0) b=m;
            else a=m;
    }
}
*/
#include <ctype.h>
/*
int main()
{
    double a, b;
    char c;
    do
    {
        printf("a= si b=");
        scanf("%lf %lf", &a, &b);
        if(f(a)*f(b)<0)
        {
            double r=rad(a,b,f);
            printf("Rad: %.10lf\n", r);
        }
        else printf("Nu se aplica \n");
        printf("Continuati? (n-nu, alt caracter-da) ");
        scanf(" %c", &c);  // spatiul -> ca sa stearga newlineul de la citirea lui b sa putem citi un alt caracter
        fflush(stdin); //ca sa pot da mai multe caractere
    }while(tolower(c)!='n'); //trebuie ctype.h
    return 0;
}
*/


// >>>>> DE TESTAT PE PROBLEMA DE SAPTAMANA TRECUTA
/*

int compara(const void *a, const void *b)
{
    return strcmp((char*)a, char(*b));
}

int main ()
{
    qsort(s, n, sizeof(s[0]), strcmp); //sau LMAX+1 in loc de sizeof |||| strcmp - compara

    return 0;
}
*/


//PROB 4 - varianta cu alocare dinamica

#include <string.h>
/*
char **citSiruri(int *pn)
{
    printf("Nr. de siruri: ");
    scanf("%d", pn);
    fflush(stdin);
    printf("Dati %d linii de text:\n", *pn);
    char **a;
    a=calloc(*pn, sizeof(char*));
    if(a==NULL)
    {
        printf("Memorie insuficienta");
        exit(1);
    }
    int i;
    char tmp[150];
    for(i=0; i<*pn; i++)
    {
        gets(tmp);
        a[i]=calloc(strlen(tmp)+1, sizeof(char));
        if(a[i]==NULL) {printf("Mem. insuficienta");}
        strcpy(a[i], tmp);
    }
    return a;
}

void bubbleS(char **s, int n)
{
    int i, sortat=0;
    while(!sortat)
    {
        sortat=1;
        for(i=1;i<n;i++)
        {
            if(strcmp(s[i-1],s[i])>0)
            {
                char *aux;
                aux=s[i-1];
                s[i-1]=s[i];
                s[i]=aux;
                sortat=0;
            }

        }
        n--;
    }
}
//Bubble Sort General pt orice tip de date
void bubbleSG(void *t, int n, int dimEl, int (*comp)(const void*, const void*))
{
    int i, sortat=0;
    while(!sortat)
    {
        sortat=1;
        for(i=1;i<n;i++)
        {
            void *timinus1=(char*)t+(i-1)*dimEl;
            void *ti=(char*)t+i*dimEl;
            if(comp(timinus1, ti)>0)
            {
                char aux[dimEl];
                memcpy(aux, timinus1, dimEl);
                memcpy(timinus1, ti, dimEl);
                memcpy(ti, aux, dimEl);
                sortat=0;
            }
        }
        n--;
    }
}

void elib(char **s, int n)
{
    int i;
    for(i=0; i<n; i++)
        free(s[i]);
    free(s); //elib spatiul alocat pe HEAP
}

void afisSiruri(char** s,int n)
{
    int i;
    printf("Elementele multimii sunt:\n");
    for(i=0;i<n;i++)
        puts(s[i]);
    printf("\n");
}

int compara(const void*a, const void*b)
{
    return strcmp(*((char**)a), *((char**)b));
}

int main()
{
    char **s;
    int n;
    s=citSiruri(&n);
    bubbleSG(s, n, sizeof(char*), compara); //in loc de qsort
    //qsort(s,n, sizeof(char*), compara);
    afisSiruri(s, n);
    elib(s,n); //fct. pt eliberarea spatiului
    return 0;
}
*/

