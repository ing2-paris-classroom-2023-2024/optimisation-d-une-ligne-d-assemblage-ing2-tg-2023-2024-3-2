//
// Created by lucie on 02/12/2023.
//

#include "header.h"

t_graphe * lire_fichier(char nomfichier[63]) {

    t_graphe * nouveau_graphe = malloc(sizeof (t_graphe));

    char ligne[64];
    int compteur_lignes = 0;

    /// Lecture des exclusions ou des précédences
    FILE * pf = fopen(nomfichier, "r");

    if (pf == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    // Compter la taille du graphe
    while (fgets(ligne, 63, pf)) {

        compteur_lignes = compteur_lignes + 1;
    }

    rewind(pf);

    // On alloue notre tableau d'aretes
    nouveau_graphe->taille = compteur_lignes;
    nouveau_graphe->tab_arete = malloc(compteur_lignes * sizeof (t_arete));

    // On remplit le tableau d'aretes
    for (int i=0; i<nouveau_graphe->taille; i++) {

        fscanf(pf, "%d %d", &nouveau_graphe->tab_arete[i].sommet1.numero, &nouveau_graphe->tab_arete[i].sommet2.numero);

    }

    fclose(pf);










    /// Lecture des opérations
    pf = fopen("temps.txt", "r");

    if (pf == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    compteur_lignes = 0;

    // Compter la taille du graphe
    while (fgets(ligne, 63, pf)) {

        compteur_lignes = compteur_lignes + 1;
    }

    rewind(pf);

    // On alloue notre tableau d'aretes
    nouveau_graphe->ordre = compteur_lignes;
    nouveau_graphe->tab_sommets = malloc(compteur_lignes * sizeof (t_arete));

    // On remplit le tableau d'aretes
    for (int i=0; i<nouveau_graphe->ordre; i++) {

        fscanf(pf, "%d %f", &nouveau_graphe->tab_sommets[i].numero, &nouveau_graphe->tab_sommets[i].temps_execution);

    }

    fclose(pf);











    /// Lecture du temps de cycle
    pf = fopen("temps_cycle.txt", "r");

    if (pf == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(pf, "%d", &nouveau_graphe->temps_cycle);

    fclose(pf);

    return nouveau_graphe;
}