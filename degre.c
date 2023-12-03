//
// Created by lucie on 02/12/2023.
//

#include "header.h"

void degre(struct Graphe *G, int *tab){

    for (int i = 0; i <= G->nb_de_sommets -1 ; i++) {
        int cpt = 0 ;
        for (int j = 0; j <= G->nb_de_sommets -1 ; j++) {
            if(G->adjMatrice[i][j] == 1) {
                cpt += 1;
            }
        }
        tab[i] = cpt ;
    }

}