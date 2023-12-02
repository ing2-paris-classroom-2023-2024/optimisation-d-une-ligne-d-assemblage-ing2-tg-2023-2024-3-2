#include "header.h"


int main() {

    /************* initialisation des variables ***************/
    struct Graphe G ;
    char nom_fichier[50] ;
    int nb_de_sommets ;
    int source, destination;
    int deg[MAX_SOMMETS];
    int prec[MAX_SOMMETS];
    float temps;
    int i, j ;


    ////////////////////////// FICHIER D'EXCLUSION  //////////////////////////////

    printf("Entrer les contraintes d'exclusions (exclusion.txt) : \n");
    gets(nom_fichier);

    //gestion du fichier//
    FILE *file_exclusion = fopen(nom_fichier, "r");

    if (file_exclusion == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Lire le nombre de sommets à partir du fichier
    fscanf(file_exclusion, "%d", &nb_de_sommets);
    printf("nombre de sommets : %d \n", nb_de_sommets);

    init_graphe(&G, nb_de_sommets);

    // Lire les arêtes du fichier
    while (fscanf(file_exclusion, "%d %d", &source, &destination) != -1) {

        ajouter_arete(&G, source, destination);
        ajouter_arete(&G, destination, source); // il faut que les aretes soient reciproques

    }

    degre(&G, deg);
    welsh_powell(&G, deg); // On applique l'algorithme de Welsh-Powell

    fclose(file_exclusion);
    fflush(file_exclusion);






    ////////////////////////// FICHIER DE PRECEDENCE ///////////////////////

    printf("Entrer les contraintes de precedence (prec.txt) : \n");

    gets(nom_fichier);

    //gestion du fichier//
    FILE *file_prec = fopen(nom_fichier, "r");

    if (file_prec == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Lire le nombre de sommets à partir du fichier
    fscanf(file_prec, "%d", &nb_de_sommets);
    printf("nombre de sommets : %d \n", nb_de_sommets);

    init_graphe(&G, nb_de_sommets);

    // Lire les arêtes du fichier
    while (fscanf(file_prec, "%d %d", &source, &destination) != -1) {

        ajouter_arete(&G, source, destination);

    }

    fclose(file_prec);
    fflush(file_prec);


    printf("\n\naffichage de la matrice :\n");
    for (i = 0; i <= G.nb_de_sommets -1 ; i++) {
        for (j = 0; j <= G.nb_de_sommets -1 ; j++) {
            printf("%0.0f ", G.adjMatrice[i][j]);
        }
        printf("\n");
    }


    precedence(&G, prec);




    ////////////////////////////    GESTION FICHIER TEMPS   //////////////////////

    printf("\n Entrer les contraintes de temps (temps.txt) : \n");
    gets(nom_fichier);

    //gestion du fichier//
    FILE *file_temps = fopen(nom_fichier, "r");

    if (file_temps == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Lire les temps du fichier
    while (fscanf(file_temps, "%d %f", &source, &temps) != -1) {
        temps_arete(&G, source, temps);
    }

    fclose(file_temps);
    fflush(file_temps);

    return EXIT_SUCCESS;
}