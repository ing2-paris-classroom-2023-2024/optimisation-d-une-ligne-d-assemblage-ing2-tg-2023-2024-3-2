#include "header.h"

int main() {

    struct Graphe G_prec;
    struct Graphe G_exclu;
    char nom_fichier[50];
    char nom_fichier1[50];


    printf("\n Entrer les contraintes de temps (operations.txt) : \n");
    gets(nom_fichier);

    //gestion du fichier//
    FILE *file_temps = fopen(nom_fichier, "r");

    if (file_temps == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }
    int max_sommet = 0;
    int t1;
    float t2;
    while (fscanf(file_temps, "%d %f", &t1, &t2) != -1) {

        if (t1 > max_sommet) max_sommet = t1;

    }
    printf("Il y a %d taches a effectuer\n", max_sommet);

    rewind(file_temps);

    float *tablo = (float *) malloc(sizeof(float) * max_sommet);
    for (int i = 0; i < max_sommet; ++i) {
        tablo[i] = 0;
    }

    while (fscanf(file_temps, "%d %f", &t1, &t2) != -1) {

        temps_sommet(tablo, t1, t2);


    }


    int nb_de_sommets = max_sommet;
    int source, destination;
    int deg[nb_de_sommets];
    int prec[nb_de_sommets];


    float temps_cycle;
    int i, j;







    ////////////////////////// FICHIER D'EXCLUSION  //////////////////////////////
    printf("\n\n//////////////////////////////////////////////EXCLUSION//////////////////////////////////////////////\n\n\n\n");

    printf("Entrer les contraintes d'exclusions (exclusions.txt) : \n");
    gets(nom_fichier);

    //gestion du fichier//
    FILE *file_exclusion = fopen(nom_fichier, "r");

    if (file_exclusion == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Lire le nombre de sommets à partir du fichier


    init_graphe_exclu(&G_exclu, nb_de_sommets + 1);

    // Lire les arêtes du fichier
    while (fscanf(file_exclusion, "%d %d", &source, &destination) != -1) {
        ajouter_arete_exclu(&G_exclu, source, destination);
        ajouter_arete_exclu(&G_exclu, destination, source); // il faut que les aretes soient reciproques
    }


    fclose(file_exclusion);


    ////////////////////////////    GESTION FICHIER TEMPS   //////////////////////

////////////// POUR EXCLUSION /////////////////


    printf("\n Entrer le temps de cycle (temps_cycle.txt) : \n");
    gets(nom_fichier1);

    //gestion du fichier temps de cycle//
    FILE *file_temps3 = fopen(nom_fichier1, "r");

    if (file_temps3 == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }


    fscanf(file_temps3, "%f", &temps_cycle);

    degre(&G_exclu, deg);

    welsh_powell(&G_exclu, deg, tablo, temps_cycle);


    fclose(file_temps3);


    ////////////////////////// FICHIER DE PRECEDENCE ///////////////////////
    printf("\n\n//////////////////////////////////////////////PRECEDENCE//////////////////////////////////////////////\n\n\n\n");

    printf("Entrer les contraintes de precedence (precedences.txt) : \n");
    gets(nom_fichier);

    //gestion du fichier//
    FILE *file_prec = fopen(nom_fichier, "r");

    if (file_prec == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }





    init_graphe_prec(&G_prec, max_sommet);






    while (fscanf(file_prec, "%d %d", &source, &destination) != -1) {
        ajouter_arete_prec(&G_prec, source, destination);

    }


    fclose(file_prec);






////////////////////////////    GESTION FICHIER TEMPS   //////////////////////

    ////////////// POUR PRECEDENCE /////////////////


    fclose(file_temps);


    precedence(&G_prec, tablo, temps_cycle);

    return EXIT_SUCCESS;
}