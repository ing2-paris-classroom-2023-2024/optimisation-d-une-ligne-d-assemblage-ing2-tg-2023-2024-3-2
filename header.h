//
// Created by lucie on 02/12/2023.
//

/////////////////////////////     NOS SOURCES     ////////////////////////
/*
 * Pert : https://codes-sources.commentcamarche.net/source/38498-chemin-critique-par-la-methode-pert
 *
 * Welsh & Powell : https://www.geeksforgeeks.org/welsh-powell-graph-colouring-algorithm/
 *
 * encore et toujours ces fameux pointeurs, apprendreX.com   stackOverflow
*/
///////////////////////////////////////////////////////////////////////////

#ifndef LIGNE_HEADER_H
#define LIGNE_HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Graphe {
    int nb_de_sommets;
    float **adjMatrice;
};

void init_graphe_prec(struct Graphe *G_prec, int nb_de_sommets);
void init_graphe_exclu(struct Graphe *G_exclu, int nb_de_sommets);

void ajouter_arete_prec(struct Graphe *G_prec, int source, int destination);
void ajouter_arete_exclu(struct Graphe *G_exclu, int source, int destination);

int couleur_dispo(struct Graphe *G_exclu, int s, float temps_cycle, float *compteur_temps, const float tmp_ind_actuel,int couleur, int *compteur, int *col);

float *temps_sommet(float *tab, int src, float tmp);

void degre(struct Graphe *G_exclu, int *tab);

void welsh_powell(struct Graphe *G_exclu, int *degre, const float *tab_temps, float tmp_c);

void precedence(struct Graphe *G_prec, const float *tab_temps, float tmp_c);


int main();

#endif //LIGNE_HEADER_H
