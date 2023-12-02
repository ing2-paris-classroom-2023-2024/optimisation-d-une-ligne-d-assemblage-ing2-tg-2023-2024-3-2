cmake_minimum_required(VERSION 3.23)
project(LIGNE C)

set(CMAKE_C_STANDARD 99)

add_executable(LIGNE main.c header.h intitialisat_graphe.c ajouter_arete.c couleur_dispo.c welsh_powell.c degre.c precedence.c temps_arete.c lire_fichier.c)
