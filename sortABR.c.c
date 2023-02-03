#include "triABR.h"



/*This function creates an AVL tree node with an element nb and returns a pointer to this node. 
The function uses dynamic memory allocation to allocate memory for a new node of type Arbre (stored in the pointer noeud). 
Then, it sets the value of the element in the node to nb, and initializes the left and right pointers of the node to NULL, indicating that there are no children for this node. 
The function returns the pointer to the newly created node.
*/

pArbre createArbre(int nb){
    pArbre noeud = malloc(sizeof(Arbre));
    noeud->elmt = nb;                   //This function takes a pointer a to an AVL tree node and returns the element stored in that node. 
    noeud->filsR = NULL;                //It simply accesses the elmt field of the node pointed to by a and returns its value.
    noeud->filsL = NULL;
    return noeud;

}

int element(pArbre a){                 //This function checks if a given AVL tree node a is empty (i.e., NULL). 
    return a->elmt;                    //It returns 0 if the node is empty and 1 if it is not. 
}                                      //If the pointer a is NULL, it means that the node is empty and the function returns 0. 
                                        //Otherwise, the function returns 1, indicating that the node is not empty.

int isVide(pArbre a){
    if (a == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

/*This is a function written in C that checks if a binary tree node is a leaf node. 
The function takes as input a pointer to the root of the binary tree node, represented by the structure "pArbre".
The function uses an if-else statement to determine if the node is a leaf node or not. 
If both the left child and right child pointers of the node are equal to NULL (indicating that there are no child nodes), then the function returns 0, indicating that the node is a leaf node. 
If either the left or right child pointer is not equal to NULL, then the function returns 1, indicating that the node is not a leaf node.
*/

int isFeuille(pArbre a){
    if (a->filsR == NULL && a->filsL == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

/*This is a function written in C that checks if a binary tree node has a right child. 
 The function takes as input a pointer to the root of the binary tree node, represented by the structure "pArbre".
The function uses an if-else statement to determine if the node has a right child. 
If the right child pointer of the node is not equal to NULL (indicating that there is a right child), then the function returns 0, indicating that the node has a right child. 
If the right child pointer is equal to NULL, then the function returns 1, indicating that the node does not have a right child.
*/

int existeFilsRIGHT(pArbre a){
    if (a->filsR != NULL){
        return 0;
    }
    else{
        return 1;
    }
}

/*This is a function written in C that checks if a binary tree node has a left child. 
The function takes as input a pointer to the root of the binary tree node, represented by the structure "pArbre".
The function uses an if-else statement to determine if the node has a left child. 
If the left child pointer of the node is not equal to NULL (indicating that there is a left child), then the function returns 0, indicating that the node has a left child. 
If the left child pointer is equal to NULL, then the function returns 1, indicating that the node does not have a left child.
*/

int existeFilsLEFT(pArbre a){
    if (a->filsL != NULL){
        return 0;
    }
    else{
        return 1;
    }
}

/*The function "ajouterFilsGauche" takes as input a binary tree "a" and an integer "e". 
It creates a new node with the integer value "e" using the "creerArbre" function, and sets it as the left child of the input tree "a". 
Finally, it returns the input tree "a".
*/

pArbre addFilsLEFT(pArbre a, int e){
    pArbre noeud = createArbre(e);
    a->filsG = noeud;
    return a;
}

/*This is a function written in C that adds a right child to a binary tree node. The function takes as input a pointer to the root of the binary tree node, represented by the structure "pArbre" and an integer value "e".
The function starts by creating a new binary tree node with the value "e" using the "creerArbre" function, which is not shown in the code snippet.
Then, the right child pointer of the input node "a" is set to the newly created node "noeud". Finally, the function returns the updated input node "a".
This function modifies the binary tree structure by adding a right child to the input node, with the value "e".
*/

pArbre addFilsRIGHT(pArbre a, int e){
    pArbre noeud = createArbre(e);
    a->filsR = noeud;
    return a;
}

/*The function "recherche" is a recursive function that searches for an integer "e" in a binary tree "a". 
It returns the node containing the integer if it exists in the tree.
It checks if the input tree is NULL, and if so, it prints a message indicating that the integer "e" is not in the tree and returns NULL.
If the current node's value is equal to "e", the function prints a message indicating that the integer is in the tree and returns the node.
Otherwise, if the current node's value is less than "e", the function calls itself with the right child of the current node as input. 
If the current node's value is greater than "e", the function calls itself with the left child of the current node as input.
The function continues searching recursively in the subtrees until the integer is found or all the nodes have been checked.
*/

pArbre research(pArbre a, int e){
    if (a == NULL){
        printf("%d is not in the tree \n", e);
        return NULL;
    }
    if (a->elmt == e){
        printf("%d is in the tree\n", e);
        return a;
    }
    if (a->elmt < e){
       return research(a->filsR, e);
    }
    else{
        return research(a->filsL, e);
    }
    
}

/*The function "insertABR" inserts an integer "e" into a binary search tree "a".
It checks if the input tree is NULL and if so, it creates a new node with the integer value "e" using the "creerArbre" function and returns the newly created node.
Otherwise, if the integer "e" is less than the current node's value, the function recursively calls itself with the left child of the current node as input. 
If the integer "e" is greater than the current node's value, the function recursively calls itself with the right child of the current node as input.
In this way, the function finds the correct place to insert the new node in the binary search tree and returns the updated tree.
*/

pArbre inserttree(pArbre a, int e){
    if (a == NULL){
        return createArbre(e);
    }
    if(e < element(a)){
        a->filsL = inserttree(a->filsL, e);
    }
    else if(e > element(a)){
        a->filsR = inserttree(a->filsR, e);
    }
    return a;
}

/*The function "suppMax" removes the node with the maximum value from a binary search tree "a" and returns the updated tree. 
It also returns the value of the removed node through the "pelmt" pointer.
It first checks if the current node has a right child, and if so, it calls itself recursively with the right child as input.
If there is no right child, the function sets the value of "pelmt" to be the value of the current node, frees the current node, and returns the left child of the current node as the updated tree. 
This way, the node with the maximum value is removed from the tree.
*/

pArbre suppMax(pArbre a,int * pelmt){
    pArbre tmp;
    if (existeFilsDroit(a)){
        a->filsR = suppMax(a->filsL, pelmt);
    }
    else{
    *pelmt = element(a);
    tmp = a;
    a = a->filsR;
    free(tmp);
    }
    return a;
}

/*
The function "display_infixe" is a recursive function that displays the elements of a binary tree "a" in infix order.
It first calls itself with the left child of the current node as input, then it prints the value of the current node, and finally, it calls itself with the right child of the current node as input.
In this way, the function visits all the nodes of the tree in the order "left child", "current node", "right child", producing an infix order display of the elements of the binary tree.  
 */ 

void display_infixe(pArbre a){
    if (a == NULL){
        return 0;
    }
    display_infixe(a->filsL);
    printf("%d ",a->elmt);
    display_infixe(a->filsR);

}




void nb_noeud1(pArbre a, int* nb_noeud){            //The function "nb_noeud1" is a recursive function that counts the number of nodes in a binary tree "a". It takes a binary tree "a" and an integer pointer "nb_noeud" as input.

    if (a == NULL){                                 //The function starts by checking if the binary tree "a" is empty, if it is then it returns. If the binary tree is not empty, then it first recursively calls itself on the left child of "a", then increments the integer pointed by "nb_noeud" by 1, and finally recursively calls itself on the right child of "a".
        return;
    }
    nb_noeud1(a->filsL, nb_noeud);
    *nb_noeud +=1;
    nb_noeud1(a->filsR, nb_noeud);                  //In the end, the integer pointed by "nb_noeud" will have the number of nodes in the binary tree "a".

}

int main(int argc, char *argv[]){               //This function is the main function of a program that reads integers from a CSV file passed as an argument to the program, and inserts them into an AVL tree. 

/*
pArbre a;
a = inserttree(a, 9);
a = inserttree(a, 8);
a = inserttree(a, 14);
a = inserttree(a, 726);
a = inserttree(a, 8046);
a = inserttree(a, 70);
a = inserttree(a, 3);display_infixe(a);
*/

char *line ;
size_t len = 0 ;
ssize_t read ;

	pArbre a = NULL;
	int number;	
    	FILE* fp = fopen(argv[1], "r");         //The file is opened using the fopen function and read using the fgets function. 

    	if (!fp){
		printf("Can't open file\n");
    	}
 
	while (( getline(&line, &len, fp)) != -1) {
	
	number = atoi(line);                        //The atoi function is used to convert the read string into an integer. 
	printf("%d \n", number) ;
	//a = inserttree(a,number);                 //The integers are then inserted into the AVL tree by calling the insertABR function. 
	
	}
	//display_infixe(a);
	fclose(fp);                                 //Finally, the file is closed using the fclose function and the program returns 0.
	return 0; 
}