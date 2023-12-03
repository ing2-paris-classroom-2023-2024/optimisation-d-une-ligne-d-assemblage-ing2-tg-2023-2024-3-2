#include "header.h"


int couleur_dispo(struct Graphe *G_exclu, int s, float temps_cycle, float *compteur_temps, const float tmp_ind_actuel,
                  int couleur, int *compteur, int *col) {

    int ok = 0; // Indicateur de disponibilité


    while (!ok) {
        ok = 1; // On suppose que la couleur est disponible
        //printf("\n compteur_temps : %f et temps_cycle : %f ", compteur_temps[couleur], temps_cycle);




        for (int i = 0; i < G_exclu->nb_de_sommets; i++) {
            if (G_exclu->adjMatrice[s][i] == 1 &&
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