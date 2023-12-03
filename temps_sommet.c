#include "header.h"

float *temps_sommet(float *tab, int src, float tmp) {

    tab[src] = tmp;


    return tab; // Retourne le pointeur vers le premier élément du tableau
}