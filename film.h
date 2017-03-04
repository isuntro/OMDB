/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   film.h
 * Author: tiberiusimionvoicu
 *
 * Created on 27 October 2016, 16:14
 */

#ifndef FILM_H
#define FILM_H
#ifdef __cplusplus
extern "C" {
#endif

    typedef struct FilmStruct {
        char *title; //String title of the movie
        int year; //Int  year movie was made in
        char *agerating; //String age rating || maybe enum 
        char *genre; //String genre of the movie 
        int lenght; //Int lenght of the movie
        float rating; //Int rating of the movie
        char*(*s)(struct FilmStruct*);
    }
    Film;
    char* (*get)(Film*);
    
    /*****************************************************************************

   Function    :  new_film

   Parameters  : char* title
     *                   int year
     *                  char* agerating
     *                  char* genre
     *                  int lenght
     *                  double rating 
 
 
   Returns     :  Film movie* -A pointer to a dynamically allocated Film data Struct

   Description : Allocate memory for the Film struct, and for the three char *
     * members of the struct and initialises the Movie to the data given by 
     * the parameters
  
     *****************************************************************************/
    Film *new_film(char *title, int year, char *rated,
            char *genre, int length, float rating);

        /*****************************************************************************

    Function    : film_getTitle

    Parameters  : const Film *movie - pointer to a Film structure (n.b. const)
 
    Returns     : char * - title

    Description : Accessor method returning the title of a Film struct.
  
     *****************************************************************************/
    static inline char *film_getTitle(const Film *movie) {
        return movie->title;
    }

    /*****************************************************************************

Function    : film_getYear

Parameters  : const Film *movie - pointer to a Film structure (n.b. const)
 
Returns     : int  - year

Description : Accessor method returning the year of a Film struct.
  
     *****************************************************************************/
    static inline int film_getYear(const Film *movie) {
        int x = (movie->year);
        return x;
    }

    /*****************************************************************************

Function    : film_getAge

Parameters  : const Film *movie - pointer to a Film structure (n.b. const)
 
Returns     : char * - age

Description : Accessor method returning the agerating of a Film struct.
  
     *****************************************************************************/
    static inline char *film_getAge(const Film *movie) {
        return movie->agerating;
    }

    /*****************************************************************************

Function    : film_getGenre

Parameters  : const Film *movie - pointer to a Film structure (n.b. const)
 
Returns     : char * - genre

Description : Accessor method returning the genre of a Film struct.
  
     *****************************************************************************/
    static inline char *film_getGenre(const Film *movie) {
        return movie->genre;
    }

    /*****************************************************************************

Function    : film_getLenght

Parameters  : const Film *movie - pointer to a Film structure (n.b. const)
 
Returns     : int  - int

Description : Accessor method returning the year of a Film struct.
  
     *****************************************************************************/
    static inline int film_getLenght(const Film *movie) {
        return movie->lenght;
    }

    /*****************************************************************************

Function    : film_getRating

Parameters  : const Film *movie - pointer to a Film structure (n.b. const)
 
Returns     : float  - rating

Description : Accessor method returning the rating of a Film struct.
  
     *****************************************************************************/
    static inline float film_getRating(const Film *movie) {
        return movie->rating;
    }

    /*****************************************************************************

Function    : film_free

Parameters  : Film * - movie
 
Returns     :  none

Description : Function takes a pointer to a movie and frees dynamically
     allocated  struct members char * (title, agerating, genre) before freeing 
     the actual film so as to ensure no memory is leaked.
  
     *****************************************************************************/
    void film_free(Film *movie);

    /*****************************************************************************

Function    :  printMovie

Parameters  : FILE      *fd     -   file pointer to the output stream
     *              const    *Film  -   pointer to the Film struct    
 
Returns     : void

Description : print a textual representation of a Film(does not modify the film
     * whatsoever.
  
     *****************************************************************************/
    void film_fprint(FILE *fp, Film *movie);

    //maybe add file out function 









#ifdef __cplusplus
}
#endif

#endif /* FILM_H */
/*****************************************************************************

Function    : 

Parameters  : 
 
Returns     : 

Description : 
  
 *****************************************************************************/
