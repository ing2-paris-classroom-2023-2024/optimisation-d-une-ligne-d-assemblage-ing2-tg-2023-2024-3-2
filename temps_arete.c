//
// Created by lucie on 02/12/2023.
//

#include "header.h"


void temps_arete(struct Graphe *G, int src, float tmp){

    for(int j = 0 ; j <= G->nb_de_sommets ; j++) {

        if (G->adjMatrice[src][j] == 1) {

            printf("\n \n G.adjMatrice[%d][%d]", src, j);
            G->adjMatrice[src][j] = tmp;
            printf("\n source = %d, temps = %0.2f\n ", src, G->adjMatrice[src][j]);

        }

    }
}