#include "header.h"


void degre(struct Graphe *G_exclu, int *tab) {

    for (int i = 0; i <= G_exclu->nb_de_sommets - 1; i++) {
        int cpt = 0;
        for (int j = 0; j <= G_exclu->nb_de_sommets - 1; j++) {
            if (G_exclu->adjMatrice[i][j] == 1) {
                cpt += 1;
            }
        }
        tab[i] = cpt;


    }

}