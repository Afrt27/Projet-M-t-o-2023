#include "triAVL.h"

AVL* createArbre(int nb){                            // This function creates an AVL tree node with an element "nb", sets its left and right child pointers to NULL, and sets the balance factor to 0. 

    AVL* noeud = malloc(sizeof(AVL));               // The function uses "malloc" to dynamically allocate memory for the AVL node and returns a pointer to the newly created node.
    noeud->elmt = nb;
    noeud->filsR = NULL;
    noeud->filsL = NULL;
    noeud->equilibre = 0;
    return noeud;

}


int existeFilsRIGHT(AVL* a){                        // This function "existeFilsDroit" checks if an AVL tree node "a" has a right child. 
    if (a->filsR != NULL){                          //If the right child pointer is not NULL, it returns 0, indicating that there is a right child. 
        return 0;
    }
    else{
        return 1;                                   //If the right child pointer is NULL, it returns 1, indicating that there is no right child.
    }
}

int existeFilsLEFT(AVL* a){                       // Same as the existefilsRight
    if (a->filsL != NULL){
        return 0;
    }
    else{
        return 1;
    }
}

//This function "recherche" performs a search operation in an AVL tree for a node with an element value equal to "e".
//If the current node "a" is NULL, it prints "e n'est pas dans l'abre" ("e is not in the tree") and returns NULL, indicating that the element is not in the tree.
//If the current node's element value is equal to "e", it prints "e est dans l'abre" ("e is in the tree") and returns a pointer to the current node.
//If the current node's element value is less than "e", it calls the function "recherche" recursively on the right child of the current node.
//If the current node's element value is greater than "e", it calls the function "recherche" recursively on the left child of the current node.
//The function returns a pointer to the node with an element value equal to "e" if it exists in the tree, or NULL otherwise.

AVL* research(AVL* a, int e){
    if (a == NULL){
        printf("%d is not in the tree\n", e);
        return NULL;
    }
    if (a->elmt == e){
        printf("%d is in the tree\n", e);
        return a;
    }
    if (a->elmt < e){
       return recherche(a->filsR, e);
    }
    else{
        return recherche(a->filsL, e);
    }
    
}

int min(int a, int b){                      // To return the minimum
	if(a < b){
		return(a);
	}
	else{
		return(b);
	}
}

int max(int a, int b){                  // To return the maximum
	if(a > b){
		return(a);
	}
	else{
		return(a);
	}
}


AVL* insertionAVL(AVL* a, int e, int* h){	/*the pointer reequilibre needs to already point to a variable, which will be able to cross all the loops of the function*/
	if(a == NULL){		                    //check if there is a tree, otherwise create it
		*h = 1;
		return createArbre(e);
	}
	else if( e < a->elmt){                  //check if the value should be placed on the left
		a-> filsL = insertionAVL(a->filsL, e, h);
		*h = -*h;
	}
	else if(e > a->elmt){
		a-> filsR = insertionAVL(a-> filsR, e, h);
	}
	else{
		*h=0;
		return a;
	}
	if (*h != 0 ){
		a->equilibre =a->equilibre + *h;
		if(a->equilibre == 0 ){             //if the equilibrium is zero after modification then there is no change for the next ancestors
			*h = 0;             
		}
		else{
			*h = 1;
		}	
	}
	return a;	        //return the value to move up the call chain.
}


/* 
This function is for removing the minimum element from an AVL tree, 'a'. 
* It sets the removed element value to 'pe' and the height of the modified tree to 'h'. 
* It returns the modified AVL tree after removing the minimum element. 
* The function works by first checking if the left subtree is empty. 
* If it is, the minimum element is at the current node and it is removed, setting the height of the modified tree to -1 and returning the right subtree as the modified AVL tree. 
* If the left subtree is not empty, the function recursively calls itself on the left subtree to find the minimum element and remove it. 
* The balance factor of the nodes is updated along the way, and the height of the modified tree is updated accordingly.
*/

AVL* suppMinAVL(AVL* a, int * h, int * pe){
    AVL* tmp;
    if (a->filsL == NULL){
        *pe = a->elmt;
        *h = -1;
        tmp = a;
        a = a->filsR;
        free(tmp);
        return a;
    }
    else{
        a->filsR = suppMinAVL(a->filsR, h, pe);
        *h = -*h;
    }
    if(*h !=0){
        a->equilibre += *h;
        if(a->equilibre == 0){
            *h = -1;
        }
        else{
            *h = 0;
        }
    }
    return a;
}

/*
This function is removing an element from an AVL tree. It first checks if the tree is empty. 
* If it is, it sets the height of the tree to 1 and returns the tree. 
* If the element to be removed is greater than the current node, it calls the function on the right child. 
* If the element is smaller, it calls the function on the left child. 
* If the element is equal to the current node, it checks if it has a right child. 
* If it does, it replaces the value of the current node with the minimum value in its right subtree, then removes the minimum value. 
* If it doesn't have a right child, it replaces the current node with its left child, frees the memory of the current node, and sets the height of the tree to -1. 
* The height of the tree is then updated based on the balance factor, and the function returns the updated tree.
*/


AVL* suppressionAVL(AVL* a, int e, int* h) {
    AVL* tmp;
    if(a == NULL){
        *h = 1;
        return a;
    }
    else if (e > a->elmt){
        a->filsR = suppressionAVL(a->filsR,e, h);
    }
    else if (e < a->elmt){
        a->filsL = suppressionAVL(a->filsL,e, h);
        *h = -*h;
    }
    else if(existeFilsDroit(a)){
        a->filsR = suppMinAVL(a->filsR, h, &(a->elmt));
    }
    else{
        tmp = a;
        a = a->filsL;
        free(tmp);
        *h = -1;
    }
	if(a == NULL){
		*h = 0;
	}
    if(*h != 0){
        a->equilibre += *h;
        if(a->equilibre == 0){
            *h = 0;
        }
        else{
            *h = 1;
        }
    }
    return a; 
}

/*This function is printing the elements of an AVL tree in infix order. 
 * It uses recursion to traverse the tree. 
 * If the current node is not empty, it first calls the function on the left child, then prints the value of the current node, and finally calls the function on the right child. 
 * This results in printing the values of the nodes in ascending order.
*/

void display_infixe(AVL* a){
    if (a == NULL){
        return;
    }

    display_infixe(a->filsL);
    printf("%d ",a->elmt);
    display_infixe(a->filsR);

}


AVL* rotationLeft(AVL* a){
    AVL* pivot;
    int eq_a, eq_p;
    pivot = a->filsR;
    a->filsR = pivot->filsL;
    pivot->filsR = a;
    eq_a =  a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - max(eq_p, 0) - 1;
    pivot->equilibre = min( min(eq_a-2, eq_a+eq_p-2), eq_p-1 );
    a = pivot;
    return a;
}

AVL* rotationRIGHT(AVL* a){
    AVL* pivot;
    int eq_a, eq_p;
    pivot = a->filsL;
    a->filsL = pivot->filsR;
    pivot->filsR = a;
    eq_a =  a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - min(eq_p, 0) + 1;
    pivot->equilibre = max(max(eq_a+2, eq_a+eq_p+2), eq_p+1);
    a = pivot;
    return a;
}

/*
This function performs a left rotation on an AVL tree. It takes as input a pointer to the root of the tree (a).

The function starts by setting a pointer pivot to the right child of a. 
The right child of a becomes the left child of pivot. 
The current node a becomes the right child of pivot. 
The balance factors of a and pivot are then updated and the pointer to the root of the tree is set to pivot, effectively making it the new root. 
The function then returns the updated root of the tree.
* */


/* This function performs a left-right double rotation on an AVL tree. It takes as input a pointer to the root of the tree (a).

The function first performs a right rotation on the right child of a. 
The result of this right rotation becomes the new right child of a. 
Then, it performs a left rotation on a to balance the tree. 
The function returns the updated root of the tree. 
This double rotation is used to balance the tree when the right subtree of the right child of a is taller than the left subtree of the right child.
*/

AVL* doubleRotationLEFT(AVL* a){
    a->filsD = rotationRIGHT(a->filsD);
    return rotationLEFT(a);
}

AVL* doubleRotationRIGHT(AVL* a){
    a->filsG = rotationLEFT(a->filsG);
    return rotationRIGHT(a);
}

/*This function balances an AVL tree. It takes as input a pointer to the root of the tree (a).

The function checks the balance factor (stored in the equilibre field of each node) of the tree. 
If the balance factor is greater than or equal to 2, it means that the right subtree is taller than the left subtree. 
In this case, the function performs a left rotation or a left-right double rotation on the root node to balance the tree. 
If the balance factor is less than or equal to -2, it means that the left subtree is taller than the right subtree. 
In this case, the function performs a right rotation or a right-left double rotation on the root node to balance the tree.
Finally, the function returns the updated root of the tree. The goal of this function is to maintain the AVL tree property, which requires that the height difference between the left and right subtree of any node should not exceed 1.
*/

AVL* equilibrerAVL(AVL* a){
    if (a->equilibre >= 2){
        if(a->filsR->equilibre >= 0){
            return rotationLEFT(a);
        }
        else{
            return doubleRotationLEFT(a);
        }
	}
    if (a->equilibre <= -2){
        if(a->filsG->equilibre <= 0){
            return rotationRIGHT(a);
        }
        else{
            return doubleRotationRIGHT(a);
        }
    }
    return a;
}
 
//This function opens a file specified as the first argument to the program (argv[1]), and reads the contents of the file line by line.
//It opens the file using fopen and sets the file pointer "fp".
//If the file cannot be opened, it prints "Can't open file" and terminates the function.
//The function then reads the contents of the file line by line using fgets and the buffer "buffer".
//For each line, it uses strtok to extract the values separated by commas or spaces.
//The extracted values are then printed to the console using printf.
//After all lines have been processed, the file is closed using fclose.
//The function returns 0, indicating successful execution.


int main(int argc, char *argv[]){

/*
pArbre a;
a = insertABR(a, 9);
a = insertABR(a, 8);
a = insertABR(a, 14);
a = insertABR(a, 726);
a = insertABR(a, 8046);
a = insertABR(a, 70);
a = insertABR(a, 3);afficher_infixe(a);
*/

char *line ;
size_t len = 0 ;
	//pArbre a = NULL;
	int number;	
    	FILE* fp = fopen(argv[1], "r");

    	if (!fp){
		printf("Can't open file\n");
    	}
 
	while (( getline(&line, &len, fp)) != -1) {
	
	number = atoi(line);
	printf("%d \n", number) ;
	//a = insertAVL(a,number);
	
	}
	//display_infixe(a);
	fclose(fp);
	return 0; 
}

