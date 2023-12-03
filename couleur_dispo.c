//
// Created by lucie on 02/12/2023.
//

#include "header.h"

// Fonction qui renvoie la première couleur disponible pour un sommet
int couleur_dispo(struct Graphe *G, int s, float temps_cycle, float *compteur_temps, const float* tmp_ind_actuel, int couleur, int* compteur) {

    int ok = 0; // Indicateur de disponibilité


    while (!ok) {
        ok = 1; // On suppose que la couleur est disponible
        printf("\n compteur_temps : %f et temps_cycle : %f ", compteur_temps[couleur], temps_cycle);
        

        for (int i = 0; i < G->nb_de_sommets; i++) {
            if (G->adjMatrice[s][i] == 1 &&
                col[i] == couleur) { // Si le sommet s est adjacent à un sommet de même couleur
                ok = 0; // La couleur n'est pas disponible
                couleur++; // On passe à la couleur suivante
                compteur[couleur]++;
                break;
            }

        }
    }

    return couleur; // On renvoie la première couleur disponible
}