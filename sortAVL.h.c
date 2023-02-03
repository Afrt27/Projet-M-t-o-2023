#define TRIAVL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <libcsv.h>

typedef struct AVL{
	int equilibre;
	int elmt;
	struct AVL* filsD;
	struct AVL* filsG;
}AVL;


AVL* createArbre(int nb);

int existeFilsRIGHT(AVL* a);

int existeFilsLEFT(AVL* a);

AVL* research(AVL* a, int e);

int min(int a, int b);

int max(int a, int b);

AVL* insertionAVL(AVL* a, int e, int* h);

AVL* suppMinAVL(AVL* a, int * h, int * pe);

AVL* suppressionAVL(AVL* a, int e, int* h);

void display_infixe(AVL* a);

AVL* rotationLEFT(AVL* a);

AVL* rotationRIGHT(AVL* a);

AVL* doubleRotationLEFT(AVL* a);

AVL* doubleRotationRIGHT(AVL* a);

AVL* equilibrerAVL(AVL* a);


