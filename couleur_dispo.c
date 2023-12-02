//
// Created by lucie on 02/12/2023.
//

#include "header.h"

/*
// Fonction qui renvoie la première couleur disponible pour un sommet
int couleur_dispo(struct Graphe *G, int s) {
    int couleur = 1; // On commence par la couleur 1
    int ok = 0; // Indicateur de disponibilité
    int cpt[MAX_SOMMETS] = {0};

    while (!ok) {
        ok = 1; // On suppose que la couleur est disponible

        for (int i = 0; i < G->nb_de_sommets; i++) {
            if (G->adjMatrice[s][i] == 1 && col[i] == couleur) { // Si le sommet s est adjacent à un sommet de même couleur
                while(cpt[couleur] < 30) {
                    ok = 0; // La couleur n'est pas disponible
                    couleur++; // On passe à la couleur suivante
                    printf("on passe à la coul suivante");
                    cpt[couleur]++;
                    break;
                }
            }
        }
        printf("\n on passe a la couleur suivante, cpt[%d] = %d", couleur, cpt[couleur]);

    }
    return couleur; // On renvoie la première couleur disponible
}

*/