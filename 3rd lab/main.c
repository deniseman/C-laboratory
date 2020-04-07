#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265
#include <math.h>

int main()
{
    /* 3.2
    double x, y, z;
    scanf("%lf %lf", &x, &y);
    printf("%f", pow(x, y));
    */

    /* 3.3
    double a,b;
    scanf("%lf %lf", &a, &b);
    int c=(int)a/b;
    double d = (a/b);
    printf("%d -> imp intreaga\n%lf -> imp reala\n", c, d);
    */

    /* 3.4
    double x;
    scanf("%lf", &x);
    double v=PI/180;
    printf(" cos x=%lf \n sin x=%lf \n tg x=%lf", cos(x*v), sin(x*v), tan(x*v));
    */

    /* 3.5
    int year;
    scanf("%d", &year);
    if(( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ) printf("%d este bisect", year);
        else printf("%d nu este bisect", year);
    */

    /* 3.6
    float x, fx;
    scanf("%f", &x);
    if(x<-2) fx=pow(x, 2)+4*x+4;
        else if (x==-2) fx=0;
            else fx=pow(x,2) + 5*x;
    printf("Valoarea functiei pentru x=%f este %f", x, fx);
    */

    /* 3.7
    double r, g, m, s;
    scanf("%lf", &r);
    g=(r*180)/PI;
    m=60*(g-(int)g);
    s=60*(m-(int)m);
    printf("Unghiul %.2lf din radian in grade este %d  %d  %d ", r, (int)g, (int)m, (int)s);
    */

    printf("Tipul char se repr pe %d octeti ", sizeof(char));




    return 0;
}
