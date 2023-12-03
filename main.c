#include "header.h"

int main() {

    struct Graphe G ;
    char nom_fichier[50] ;
    char nom_fichier1[50] ;
    int nb_de_sommets ;
    int source, destination;
    int deg[MAX_SOMMETS];
    int prec[MAX_SOMMETS];
    float* tablo = (float*)malloc(G.nb_de_sommets * sizeof(int)); ;
    float temps = 0 ;
    float temps_cycle ;
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



    fclose(file_exclusion);
    fflush(file_exclusion);

    ////////////////////////////    GESTION FICHIER TEMPS   //////////////////////

////////////// POUR EXCLUSION /////////////////

    printf("\n Entrer les contraintes de temps (temps.txt) : \n");
    gets(nom_fichier);


    //gestion du fichier temps pour exclusion//
    FILE *file_temps2 = fopen(nom_fichier, "r");

    if (file_temps2 == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    printf("\n Entrer le temps de cycle (temps_cycle.txt) : \n");
    gets(nom_fichier1);

    //gestion du fichier temps de cycle//
    FILE *file_temps3 = fopen(nom_fichier1, "r");

    if (file_temps3 == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Lire les temps des fichiers
    while (fscanf(file_temps2, "%d %f", &source, &temps) != -1) {
        temps_sommet(&G, tablo, source, temps);
    }

    fscanf(file_temps3, "%f", &temps_cycle);

    degre(&G, deg);

    welsh_powell(&G, deg, tablo, temps_cycle);

    fclose(file_temps2);
    fflush(file_temps2);

    fclose(file_temps3);
    fflush(file_temps3);

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


    precedence(&G, prec);


////////////////////////////    GESTION FICHIER TEMPS   //////////////////////

    ////////////// POUR PRECEDENCE /////////////////

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



/*
int main(){

    char fichier_exclusion[63];
    char fichier_precedence[63];


    t_graphe * mon_graphe = NULL;

    printf("Entrer les contraintes d'exclusions (exclusion.txt) : \n");
    scanf("%s", fichier_exclusion);

    printf("Entrer les contraintes de precedence (prec.txt) : \n");
    scanf("%s", fichier_precedence);



    printf("******************** EXCLUSION : ***********************\n");

    mon_graphe = lire_fichier(fichier_exclusion);

    for (int i = 0; i < mon_graphe->taille; ++i) {

        printf("%d %d\n", mon_graphe->tab_arete[i].sommet1.numero, mon_graphe->tab_arete[i].sommet2.numero);

    }




    printf("******************** PRECEDENCE : ***********************\n");

    mon_graphe = lire_fichier(fichier_precedence);

    for (int i = 0; i < mon_graphe->taille; ++i) {

        printf("%d %d\n", mon_graphe->tab_arete[i].sommet1.numero, mon_graphe->tab_arete[i].sommet2.numero);

    }


    return EXIT_SUCCESS;
}
*/


