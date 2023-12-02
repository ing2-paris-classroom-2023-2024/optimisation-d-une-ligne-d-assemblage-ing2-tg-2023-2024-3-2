//
// Created by lucie on 02/12/2023.
//


#include "header.h"

/*

// Fonction qui applique l'algorithme de Welsh-Powell
void welsh_powell(t_graphe * le_graphe, int *degre) {

    int col [45];

    int max_deg = -1; // Degré maximal des sommets
    int max_ind = -1; // Indice du sommet de degré maximal
    for (int i = 0; i < le_graphe->ordre ; i++) {
        col[i] = -1; // On initialise les couleurs à -1
        if (degre[i] > max_deg) {
            max_deg = degre[i]; // On met à jour le degré maximal
            max_ind = i; // On met à jour l'indice du sommet de degré maximal
        }
    }


    int nb_col = 0; // Nombre de couleurs utilisées
    while (max_deg > -1) { // Tant qu'il reste des sommets non colorés
        col[max_ind] = couleur_dispo(G, max_ind); // On colore le sommet de degré maximal avec la première couleur disponible
        if (col[max_ind] > nb_col) {
            nb_col = col[max_ind]; // On met à jour le nombre de couleurs utilisées
        }
        degre[max_ind] = -1; // On marque le sommet comme coloré
        max_deg = -1; // On réinitialise le degré maximal
        for (int i = 0; i < G->nb_de_sommets ; i++) {
            if (degre[i] > max_deg) {
                max_deg = degre[i]; // On met à jour le degré maximal
                max_ind = i; // On met à jour l'indice du sommet de degré maximal
            }
        }
    }
    printf("Nombre de couleurs utilisees : %d\n", nb_col);
    printf("Couleurs des sommets : \n");
    for (int i = 0; i < G->nb_de_sommets ; i++) {
        printf("Sommet %d : couleur %d\n", i+1, col[i]);
    }
}
*/