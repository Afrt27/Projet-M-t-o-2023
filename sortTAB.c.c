#include "triTAB.h"
 
void permuter(int *a, int *b) {                             // is used to exchange two variables/swap them
   int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void triRapid(int tab[], int first, int last) {             //Create a fast sorting alogorithm to sort the csv data but the function that adapts the csv file to c is missing, we did not succeed
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}

int main() {                                                        // the hand that starts the sorting
    int tab[100], nbr, i;
  
    printf("\n enter the total number of elements :  ");
    scanf("%d", &nbr);
    
    printf("\n enter the elements :  ");
    for(i = 0; i < nbr; i++)
        scanf("%d", &tab[i]);
    
    triRapid(tab, 0, nbr - 1);
    
    printf("\n Sorting Table : ");
    for(i = 0; i < nbr; i++)  {
        printf(" %4d", tab[i]);
    }
    printf("\n");
    return 0;
}