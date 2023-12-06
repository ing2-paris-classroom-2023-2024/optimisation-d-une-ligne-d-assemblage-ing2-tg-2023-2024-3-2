#include "header.h"


void precedence(struct Graphe *G_prec, const float *tab_temps, float tmp_c) {

    int cpt[G_prec->nb_de_sommets];
    int cpt_pred_max[G_prec->nb_de_sommets];
    int num_station[G_prec->nb_de_sommets];
    float *cpt_tmp_station = (float *) malloc(G_prec->nb_de_sommets * sizeof(int));


    for (int i = 1; i < G_prec->nb_de_sommets + 1; i++) {
        cpt_tmp_station[i] = 0;
    }






    for (int k = 1; k < G_prec->nb_de_sommets + 1; k++) {
        cpt[k] = 0;
        cpt_pred_max[k] = 0;
    }


    int min_deg = -1; // Degré maximal des sommets
    int max_ind = -1; // Indice du sommet de degré maximal



    for (int i = 0; i < G_prec->nb_de_sommets; i++) {

        for (int j = 1; j < G_prec->nb_de_sommets + 1; j++) {

            if (G_prec->adjMatrice[i][j] == 1) {

                cpt[j] = cpt[i] + 1;


                if (cpt[j] > cpt_pred_max[j]) {
                    cpt_pred_max[j] = cpt[j];
                }
            }
        }
    }

    for (int j = 0; j < G_prec->nb_de_sommets; ++j) {


        min_deg = cpt_pred_max[j]; // On met à jour le degré maximal
        max_ind = j; // On met à jour l'indice du sommet de degré maximal


        cpt_tmp_station[j] += tab_temps[max_ind];

    }


    int max_pred = 0;
    for (int i = 1; i < G_prec->nb_de_sommets; ++i) {

        if (cpt_pred_max[i] > max_pred)
            max_pred = cpt_pred_max[i];

    }


    int tab_taille_station[max_pred];

    for (int i = 0; i < max_pred; ++i) {
        tab_taille_station[i] = 0;
    }

    for (int i = 0; i < G_prec->nb_de_sommets; ++i) {
        for (int j = 0; j < max_pred; ++j) {
            if (cpt_pred_max[i] == j)tab_taille_station[j]++;
        }
    }


    int tab_tache_station[G_prec->nb_de_sommets][G_prec->nb_de_sommets];
    float tab_temp_station[G_prec->nb_de_sommets];

    for (int i = 0; i < G_prec->nb_de_sommets; ++i) {
        tab_temp_station[i] = 0;
        for (int j = 0; j < G_prec->nb_de_sommets; ++j) {
            tab_tache_station[i][j] = 0;
        }

    }


    float temp1 = 0, temp2 = 0;
    int indice = 1;
    int k = 0;

    for (int i = 0; i < G_prec->nb_de_sommets + 1; ++i) {
        temp1 = tab_temp_station[indice];
        temp2 = tab_temps[i];




        if (temp1 + temp2 > tmp_c) {

            indice++;


        }
        k++;

        tab_temp_station[indice] += temp2;
        tab_tache_station[indice][k] = i;

    }


    int cpt_station=0;
    for (int i = 0; i < G_prec->nb_de_sommets+1; ++i) {
        // Utiliser un indicateur pour savoir si la ligne a un "1"
        int a_un = 0;

        for (int j = 0; j < G_prec->nb_de_sommets+1; ++j) {
            if (tab_tache_station[i][j] != 0) {
                a_un = 1;
                break; // Si on trouve un "1", sortir de la boucle interne
            }
        }

        // Si la ligne a un "1", incrémenter le compteur
        if (a_un == 1) {
            cpt_station++;
        }
    }

    int taille_station[cpt_station];
    for (int i = 0; i < cpt_station; ++i) {
        taille_station[i]=0;
    }
    for (int i = 0; i < G_prec->nb_de_sommets; ++i) {
        for (int j = 0; j < G_prec->nb_de_sommets; ++j) {
            if(tab_tache_station[i][j] != 0){
                taille_station[i]++;
            }
        }
    }



    float provisoir_counter=0;
    for (int i = 1; i < cpt_station; ++i) {
        printf("\n############### station %d ###############\n\nListe de taches:\n", i);
        for (int j = 0; j < G_prec->nb_de_sommets; ++j) {
            if(tab_tache_station[i][j] != 0){
                printf("%d, ",tab_tache_station[i][j]);
                provisoir_counter+=tab_temps[tab_tache_station[i][j]];
            }

        }
        printf("\nTemps total: %.2f\n", provisoir_counter);
        provisoir_counter=0;
        printf("\n");
    }


}