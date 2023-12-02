//
// Created by lucie on 02/12/2023.
//

#ifndef LIGNE_HEADER_H
#define LIGNE_HEADER_H
#endif //LIGNE_HEADER_H

#include <stdio.h>
#include <stdlib.h>



#define MAX_SOMMETS 40


/********** variable globale ***********/
// Tableau des couleurs des sommets
int col[MAX_SOMMETS];




/************* STRUCTURE *************/

// Tableau des couleurs des sommets
int col[MAX_SOMMETS];


struct Graphe {
    int nb_de_sommets;
    float adjMatrice[MAX_SOMMETS][MAX_SOMMETS];
};





/*************** sous-prog *****************/
void init_graphe(struct Graphe *G, int nb_de_sommets);
void ajouter_arete(struct Graphe *G, int source, int destination);
int couleur_dispo(struct Graphe *G, int s);
void welsh_powell(struct Graphe *G, int *degre);
void degre(struct Graphe *G, int *tab);
void precedence(struct Graphe *G, int *tab);
void temps_arete(struct Graphe *G, int src, float tmp);




