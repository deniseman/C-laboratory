#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 500
//PROBLEMA 2.

//Ca sa fie polinom trebuie ca H>n<(x)=2xH>n-1<-2(n-1)(H>n-2<)(x) <- polinom de grad n in x
//H>0<(x)=1
//H>1<(x)=2x
/*
float Hermite(int n, float x)
{
    if (n==0) return 1;
        else if (n==1) return 2*x;
            else return (2*x*Hermite(n-1, x)-2*(n-1)*Hermite(n-2, x));
}

int main()
{
    int n;
     float x;
    scanf("%d%f", &n, &x);
    printf("%f", Hermite(n, x));
    return 0;
}
*/

//PROB 3 - Turnurile din Hanoi
/*
char a,b,c;
int n;

void Hanoi(int n,char a,char b, char c)
{
    if(n==1) printf("%c -> %c\n", a, b);
        else
        {
            Hanoi(n-1,a,c,b);
            printf("%c -> %c\n", a, b);
            Hanoi(n-1,c,b,a);
        }
}

void main()
{
    printf("n=");
    scanf("%d", &n);
    Hanoi(n,'A','B','C');
}
*/

//PROB 4

/*
void invers(int n)
{
    if(n<=0) return;
    char s[20];
    scanf("%s", s);
    invers(n-1);
    printf("%s\n", s);
}


int main()
{
    int n;
    printf("n=");
    scanf("%d", &n);
    invers(n);
    return 0;
}
*/


typedef struct
{
    char c;
    int frecv;
}FrecvCar;

void insereaza(char x, int j, FrecvCar t[], int *pn)
{
    int i;
    for(i=*pn-1; i>=j; i--)
        t[i+1]=t[i];
    t[j].c=x;
    t[j].frecv=1;
    (*pn)++; //crestem nr de elem pt ca am mai adaugat unul
}

int cautBinara(char x, FrecvCar t[], int s, int d)
{
    if(s>d) return s; //nu am gasit
    int m=s+(d-s)/2; //m=mijl
    if(t[m].c==x) return m;
    if(t[m].c>x) return cautBinara(x, t, s, m-1);
    //else
    return cautBinara(x,t,m+1, d);
}

int cauta(char x, FrecvCar t[], int n)
{
    return cautBinara(x, t, 0, n-1); //caut intre 0 si n-1;
}

void constrTablou(char *s, FrecvCar t[], int *pn)
{
    int i;
    for(i=0; s[i]!='\0'; i++)
    {
        char x=tolower(s[i]);
        if(isalnum(x))
        {
            int j=cauta(x, t, *pn);
            if(t[j].c==x) //am gasit x
                t[j].frecv++;
            else
                insereaza(x, j, t, pn);
        }
    }
}



int main()
{
    FrecvCar t[36];
    int n=0;
    char s[N];
    printf("Textul:\n");
    fgets(s, N, stdin);
    constrTablou(s, t, &n);
    afis(t, n); //MAI TREBUIE SCRISA FUNCTIA DE AFISARE
    return 0;
}

