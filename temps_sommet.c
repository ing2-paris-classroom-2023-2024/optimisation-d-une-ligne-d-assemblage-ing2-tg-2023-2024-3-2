//
// Created by thais on 03/12/2023.
//

#include "header.h"

float* temps_sommet(struct Graphe *G, float *tab, int src, float tmp) {

    tab[src] = tmp ;

    return tab; // Retourne le pointeur vers le premier élément du tableau
}