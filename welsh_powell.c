//
// Created by lucie on 02/12/2023.
//


#include "header.h"


// Fonction qui applique l'algorithme de Welsh-Powell
void welsh_powell(struct Graphe *G, int *degre, const float *tab_temps, float tmp_c) {

    int color = 1;
    int cpt[MAX_SOMMETS] = {0};
    float* cpt_tmp_station = (float*)malloc(G->nb_de_sommets * sizeof(int));
    for (int i = 1; i < G->nb_de_sommets +1 ; i++) {
        cpt_tmp_station[i] = 0;
    }


    int max_deg = -1; // Degré maximal des sommets
    int max_ind = -1; // Indice du sommet de degré maximal
    for (int i = 0; i < G->nb_de_sommets ; i++) {
        col[i] = -1; // On initialise les couleurs à -1
        if (degre[i] > max_deg) {
            max_deg = degre[i]; // On met à jour le degré maximal
            max_ind = i; // On met à jour l'indice du sommet de degré maximal
        }
    }

    int nb_col = 0; // Nombre de couleurs utilisées

    while (max_deg > -1) { // Tant qu'il reste des sommets non colorés


        for (int i = 1; i < 10 ; i++) {
            printf("%f, ", cpt_tmp_station[i]);
        }

        col[max_ind] = couleur_dispo(G, max_ind, color, cpt); // On colore le sommet de degré maximal avec la première couleur disponibl




        // Mettez à jour le tableau de cpt_tmp_station
        printf(" \n \n La tache %d est dans la station %d. \n Son temps est de : %0.2f \n", max_ind, col[max_ind], tab_temps[max_ind] );
        cpt_tmp_station[col[max_ind]] += tab_temps[max_ind] ;


        if (cpt_tmp_station[col[max_ind]] > tmp_c) {

            cpt_tmp_station[col[max_ind]] = cpt_tmp_station[col[max_ind]] - tab_temps[max_ind];

            color = color + 2;
            cpt[color] = cpt[color] + 2;
        }



        if (col[max_ind] > nb_col) {
            nb_col = col[max_ind]; // On met à jour le nombre de couleurs utilisées
        }

        degre[max_ind] = -1; // On marque le sommet comme coloré
        max_deg = -1; // On réinitialise le degré maximal
        for (int i = 1; i < G->nb_de_sommets +1 ; i++) {
            if (degre[i] > max_deg) {
                max_deg = degre[i]; // On met à jour le degré maximal
                max_ind = i; // On met à jour l'indice du sommet de degré maximal
            }
        }
    }
    printf("\nNombre de stations minimum : %d\n", nb_col);

    printf("\n ****************    Repartition des taches par station :    *************** \n");


    printf("\nTache -> Station\n");
    for (int i = 1 ; i < G->nb_de_sommets +1 ; i++) {
        printf("  %d   ->   %d \n", i , col[i]);
    }

    //print tab compteur
    for (int i = 0; i < nb_col; i++) {
        printf("\n*****    Somme des temps des taches dans la station  %d  ******\n",  i + 1);
        printf("                               %0.2f\n", cpt_tmp_station[i+1]);
    }

    free(cpt_tmp_station);
}