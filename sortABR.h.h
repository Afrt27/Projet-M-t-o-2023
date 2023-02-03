#define TRIABR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Arbre{
    int elmt;
    struct Arbre* filsD; 
    struct Arbre* filsG; 
}Arbre;

typedef Arbre * pArbre;

pArbre createArbre(int nb);

int element(pArbre a);

int isVide(pArbre a);

int isFeuille(pArbre a);

int exitseFilsRIGHT(pArbre a);

int exitseFilsLEFT(pArbre a);

pArbre addFilsLEFT(pArbre a, int e);

pArbre addFilsRIGHT(pArbre a, int e);

pArbre research(pArbre a, int e);

pArbre inserttree(pArbre a, int e);

pArbre suppMax(pArbre a,int * pelmt);

void display_infixe(pArbre a);

