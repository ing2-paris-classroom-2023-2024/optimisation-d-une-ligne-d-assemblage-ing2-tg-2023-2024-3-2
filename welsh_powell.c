#include "header.h"



void welsh_powell(struct Graphe *G_exclu, int *degre, const float *tab_temps, float tmp_c) {


    int color = 1;
    int col[G_exclu->nb_de_sommets];
    int cpt[G_exclu->nb_de_sommets];
    for (int i = 0; i < G_exclu->nb_de_sommets; ++i) {
        cpt[i] = 0;
    }

    float *cpt_tmp_station = (float *) malloc((G_exclu->nb_de_sommets + 1) * sizeof(int));

    for (int i = 0; i < G_exclu->nb_de_sommets; i++) {
        cpt_tmp_station[i] = 0;
    }


    int max_deg = -1; // Degré maximal des sommets
    int max_ind = -1; // Indice du sommet de degré maximal

    for (int i = 0; i < G_exclu->nb_de_sommets; i++) {

        col[i] = -1; // On initialise les couleurs à -1
        if (degre[i] > max_deg) {

            max_deg = degre[i]; // On met à jour le degré maximal
            max_ind = i; // On met à jour l'indice du sommet de degré maximal
        }
    }

    int nb_col = 0; // Nombre de couleurs utilisées

    while (max_deg > -1) { // Tant qu'il reste des sommets non colorés




        col[max_ind] = couleur_dispo(G_exclu, max_ind, tmp_c, cpt_tmp_station, *tab_temps, color, cpt,
                                     col); // On colore le sommet de degré maximal avec la première couleur disponibl




        // Mettez à jour le tableau de cpt_tmp_station
        //printf(" \n \n cpt_tmp_station[%d : %d] = %0.2f \n", max_ind, col[max_ind], tab_temps[max_ind]);
        cpt_tmp_station[col[max_ind]] += tab_temps[max_ind];


        if (cpt_tmp_station[col[max_ind]] > tmp_c) {


            cpt_tmp_station[col[max_ind]] = cpt_tmp_station[col[max_ind]] - tab_temps[max_ind];


            col[max_ind] = col[max_ind] + 2;

            cpt_tmp_station[col[max_ind]] = cpt_tmp_station[col[max_ind]] + tab_temps[max_ind];

            color++;
            cpt[color]++;
        }


        if (col[max_ind] > nb_col) {
            nb_col = col[max_ind]; // On met à jour le nombre de couleurs utilisées
        }

        degre[max_ind] = -1; // On marque le sommet comme coloré
        max_deg = -1; // On réinitialise le degré maximal
        for (int i = 0; i < G_exclu->nb_de_sommets; i++) {
            if (degre[i] > max_deg) {
                max_deg = degre[i]; // On met à jour le degré maximal
                max_ind = i; // On met à jour l'indice du sommet de degré maximal
            }
        }
    }
    printf("\nNombre de stations necessaires : %d\n", nb_col);

    int **tab_affichage_sommet__station;
    tab_affichage_sommet__station = (int **) malloc(sizeof(int *) * nb_col);
    int tab_taille_station[nb_col];

    for (int i = 0; i < nb_col; ++i) {
        tab_taille_station[i] = 0;
    }

    for (int i = 0; i < G_exclu->nb_de_sommets; ++i) {
        for (int j = 0; j < nb_col; ++j) {
            if (col[i] == j)
                tab_taille_station[j]++;
        }
    }


    for (int i = 0; i < nb_col; ++i) {
        tab_affichage_sommet__station[i] = (int *) malloc(sizeof(int) * tab_taille_station[i]);
    }

    for (int i = 0; i < nb_col; ++i) {
        for (int j = 0; j < tab_taille_station[i]; ++j) {
            tab_affichage_sommet__station[i][j] = 0;
        }
    }

    for (int i = 0; i < nb_col; ++i) {
        for (int j = 0; j < tab_taille_station[i]; ++j) {
            for (int k = 0; k < G_exclu->nb_de_sommets; ++k) {
                if (col[k] == i) {
                    tab_affichage_sommet__station[i][j] = k;
                    j++;
                }
            }
        }
    }


    for (int i = 1; i < nb_col; ++i) {
        printf("############### station %d ###############\n\nListe de taches:", i);
        for (int j = 0; j < tab_taille_station[i]; ++j) {
            printf("%d, ", tab_affichage_sommet__station[i][j]);

        }
        printf("\nTemps total: %.2f", cpt_tmp_station[i]);


        printf("\b\n\n");
    }

    free(cpt_tmp_station);
}