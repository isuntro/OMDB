/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tiberiusimionvoicu
 *
 * Created on 25 October 2016, 23:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "film.h"
#include "moviedatabase.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Node *root = NULL;
    root = malloc(sizeof(Node));
    Film *movie;
    FILE *input;
    input = fopen("films.txt","r");
    addMovies(root,input);
    sortList(root,descending,film_getYear);
    printMovies(stdout,root);
    Node *rootNoire;
    rootNoire = extractDB(root,film_getGenre,"Film-Noir");
    sortList(rootNoire,ascending,film_getLenght);
 
    
    Node *rootSci;
    rootSci = extractDB(root,film_getGenre,"Sci-Fi");
    sortList(rootSci,ascending,film_getLenght);
    printf("3 Longest film-noire is :");
    film_fprint(stdout,getnMovie(rootNoire,3));
    printf("10th Highest rated sci-fi is : ");
    film_fprint(stdout,getnMovie(rootSci,10));
    
    highestMovie(root);
    shortestTitle(root);
    eraseMovies(root,film_getAge, "R");
    printf("\nNumber of Movies in the DB is :  %d",countMovies(root));
    free(rootSci);
    free(rootNoire);
    free(root);
    fclose(input);
    return (EXIT_SUCCESS);
}

