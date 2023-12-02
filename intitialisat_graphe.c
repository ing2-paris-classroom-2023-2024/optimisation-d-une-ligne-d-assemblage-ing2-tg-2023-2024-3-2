//
// Created by lucie on 02/12/2023.
//

#include "header.h"

// Fonction pour initialiser le graphe
void init_graphe(struct Graphe *G, int nb_de_sommets) {
    G->nb_de_sommets = nb_de_sommets;

    for (int i = 0; i < nb_de_sommets; i++) {
        for (int j = 0; j < nb_de_sommets; j++)
            G->adjMatrice[i][j] = 0; // la matrice de nb de sommets par nb de sommets est entierment initialisee a 0
    }
}