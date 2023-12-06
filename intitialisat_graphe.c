#include "header.h"


void init_graphe_prec(struct Graphe *G_prec, int nb_de_sommets) {
    G_prec->nb_de_sommets = nb_de_sommets;

    G_prec->adjMatrice = (float **) malloc(sizeof(float *) * nb_de_sommets);
    for (int i = 0; i < nb_de_sommets; ++i) {
        G_prec->adjMatrice[i] = (float *) malloc(sizeof(float) * nb_de_sommets);
    }

    for (int i = 0; i < nb_de_sommets; i++) {
        for (int j = 0; j < nb_de_sommets; j++)
            G_prec->adjMatrice[i][j] = 0; // la matrice de nb de sommets par nb de sommets est entierment initialisee a 0
    }

}

void init_graphe_exclu(struct Graphe *G_exclu, int nb_de_sommets) {
    G_exclu->nb_de_sommets = nb_de_sommets;


    G_exclu->adjMatrice = (float **) malloc(sizeof(float *) * nb_de_sommets);
    for (int i = 0; i < nb_de_sommets; ++i) {
        G_exclu->adjMatrice[i] = (float *) malloc(sizeof(float) * nb_de_sommets);
    }

    for (int i = 0; i < nb_de_sommets; i++) {
        for (int j = 0; j < nb_de_sommets; j++)
            G_exclu->adjMatrice[i][j] = 0; // la matrice de nb de sommets par nb de sommets est entierment initialisee a 0
    }
}

// Fonction pour ajouter une arête au graphe
void ajouter_arete_prec(struct Graphe *G_prec, int source, int destination) {
    G_prec->adjMatrice[source][destination] = 1; // lorsqu'un lien est present entre deux sommets (cad adjacents), l'arete est creee    }
}

void ajouter_arete_exclu(struct Graphe *G_exclu, int source, int destination) {
    G_exclu->adjMatrice[source][destination] = 1; // lorsqu'un lien est present entre deux sommets (cad adjacents), l'arete est creee    }
}