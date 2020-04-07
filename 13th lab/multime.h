#ifndef MULTIME_H_INCLUDED
#define MULTIME_H_INCLUDED

typedef struct
{
    int n;
    int *a;
}TipMultime;

void citMultime(FILE *, TipMultime *);
int apartine(int, TipMultime);
void afisMultime(TipMultime);
void reuniune(TipMultime, TipMultime, TipMultime*);
void intersectie(TipMultime, TipMultime, TipMultime*);
void diferenta(TipMultime, TipMultime, TipMultime*);
void elib(TipMultime);
int inclusa(TipMultime, TipMultime);
int egale(TipMultime, TipMultime);

#endif // MULTIME_H_INCLUDED
