#include <stdio.h>
#include <stdlib.h>



int main() {

    FILE* filou=NULL;
    char nomfichier[10];
    printf("fichier\n");
    gets(nomfichier);
    filou=fopen(nomfichier,"r");
    if(filou==NULL)printf("shit\n");
    int ordre, taille;
    int s1, s2;
    fscanf(filou, "%d %d", &ordre, &taille);
    int mat[ordre][ordre];
    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < ordre; ++j) {
            mat[i][j]=0;
        }
    }

    for (int i = 0; i < taille; ++i) {
        fscanf(filou, "%d %d",  &s1, &s2);
        mat[s1][s2]=1;
        mat[s2][s1]=1;
    }

    for (int i = 0; i < ordre; ++i) {
        for (int j = 0; j < ordre; ++j) {
            printf("%3d",mat[i][j]);
        }
    }

    printf("lol\n");



    return 0;
}
