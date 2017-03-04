/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"

Film *new_film(char *title, int year, char *rated, 
                        char *genre, int length, float rating )
    {
        Film *movie = (Film*)malloc(sizeof(Film));
        if(movie){
            // p->name = malloc(strlen(name)+1);
            // strcpy(p->name, name);
            movie->title = strndup(title,strlen(title));
            movie->year = year;
            movie->agerating = strndup(rated,strlen(rated));
            movie->genre = strndup(genre,strlen(genre));
            movie->lenght = length;
            movie->rating = rating;
        }
        return movie;
        
    }
 
void film_free( Film *movie){
    free(movie->title) ;
    free(movie->genre);
    free(movie->agerating);
    free(movie);
}
void film_fprint(FILE *fp, Film *movie){
  
    if (movie != NULL){
        fprintf(fp,"\n%s, %d , %s , %s , %d ,%1.1f  \n",movie->title,movie->year, movie->agerating, movie->genre,
                 movie->lenght, movie->rating);
    }
    else printf("movie is null \n");
}




 

