#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000000
#define BMAX 36

int main()
{
    //float a[N];
    //int n, i;

    /* V1
    do
    {
        printf("Nr elem. (<=%d):", N);
        scanf("%d", &n);
        fflush(stdin);
    }while(n<1||n>N);
    */

    //Pt citirea unei functii V2
    /*for(i=0; i<n; i++)
    do{
        fflush(stdin);
        printf("a[%d]=", i);
    }while(scanf("%f",&a[i])<1);
    */


    //3.3 Sa se gaseasca valorile min si max dintr-un sir de numere si sa se afiseze pozitiile lor
    /*
    float a[N];
    int n, i;

    scanf("%d",&n);
    printf("Nr elemente este: %d\n", n);

    printf("\n\n");

    for(i=0; i<n; i++)
        scanf("%f",&a[i]);
    float min=a[0], max=a[0];

    for(i=0; i<n; i++)
        if(a[i]<=min) min=a[i];
            else if (a[i]>=max) max=a[i];

    printf("Pozitiile elem. cu val min este:\n");
    for(i=0; i<n; i++)
        if(a[i]==min) printf("%d ",i);

    printf("\n\n");

    printf("Pozitiile elem. cu val max este:\n");
    for(i=0; i<n; i++)
        if(a[i]==max) printf("%d ",i);
    */


    //3.4 Generarea tuturor nr prime mai mici sau egale ca n
    /*
    char a[N]={0};
    int n,i,j;
    scanf("%d",&n);
    for(i=2; i*i<=n; i++)
        if(a[i]==0)
            for(j=i*i;j<=n;j+=i)
                a[j]=1;
    for(i=2; i<=n; i++)
        if(a[i]==0)
            printf("%d, ",i);
    */


    //3.5 Cel mai mare pp mai mic decat n
    /*
    int n, i;
    scanf("%d", &n);
    for(i=n; i>=0; i--)
        if(sqrt(i)==(int)sqrt(i)) {printf("Cel mai mare p.p. mai mic decat n este %d", i); break;}
    */


    //3.7 Dintr-o baza oarecare in baza 10


    char nr[20];
    int baza, i;
    scanf("%d%*c", &baza);
    printf("Nr in baza %d: ", baza);
    fgets(nr, 20, stdin); //sau gets(nr);
    long long nr10=0;
    for(i=0; (nr[i]!='\0')&& (nr[i]!='\n'); i++) // \n pt ca am citit cu fgets care da un \n la final
    {
        int cifra;
        if(nr[i]>='0'&&nr[i]<='9')
            cifra=nr[i]-'0';
        else
        {
            nr[i]=toupper(nr[i]);  // toupper transforma din litera mica in litera mare
            if(nr[i]>='A' && nr[i]<='Z')
                cifra=nr[i]-'A'+10;
            else {
                    printf("!!!Caracter gresit!!!");
                    return 1;
                 }
        }
        //Am gasit daca e litera sau cifra si l-am transformat in valoarea lui in baza 10
        if(cifra>=baza)
        {
            printf("!!!Cifra gresita!!!: %c", nr[i]);
            return 1;
        }
        nr10=nr10*baza+cifra;
    }
    printf("\nNr in baza 10 este: %d", nr10);



    return 0;

}
