//
// Created by lucie on 02/12/2023.
//

#ifndef LIGNE_HEADER_H
#define LIGNE_HEADER_H
#endif //LIGNE_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/********* **** STRUCTURE *************/

typedef struct sommet {

    int numero;
    float temps_execution;

} t_sommet;

typedef struct arete {

    t_sommet sommet1;
    t_sommet sommet2;

} t_arete;


typedef struct graphe {

    int ordre; // Nombre de sommets aka taille du tab_sommets
    int taille; // Nombre d'aretes aka taille du tab_arete
    int temps_cycle;
    t_sommet * tab_sommets;
    t_arete * tab_arete;


} t_graphe;



// Sous-prog généraux
t_graphe * lire_fichier(char * nomfichier);






/*


void init_graphe(struct Graphe *G, int nb_de_sommets);
void ajouter_arete(struct Graphe *G, int source, int destination);
int couleur_dispo(struct Graphe *G, int s);
void welsh_powell(struct Graphe *G, int *degre);
void degre(struct Graphe *G, int *tab);
void precedence(struct Graphe *G, int *tab);
void temps_arete(struct Graphe *G, int src, float tmp);
*/