/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "moviedatabase.h"
#include "film.h"
#include <string.h>

void insert(Node *root ,Film *movie)
{
    Node *current = root;
    while((current->next )!= NULL)
    {
        current = current->next;
    }
    current->next = (Node*)malloc(sizeof(Node));
    current->next->movie = movie;
    current->next->next = NULL;
}

void addMovies(Node *root ,FILE *fp)
{
    root->next = NULL;
    if (fp == NULL)
    {
        printf("File IN ERROR in Film Fileinput");
        exit(EXIT_FAILURE);
    }
    Film *x;
    
    char line[200];  
    //tidy up use loop
    while ((fgets(line,sizeof(line),fp)) != NULL)
    {
        char *title = strtok(line,"\"");
        int year = atoi(strtok(NULL,"\",\n"));
        char *age = strtok(NULL,"\",\n");
        char *genre = strtok(NULL,"\",\n");
        int lenght = atoi(strtok(NULL,"\",\n"));
        float rating = atof(strtok(NULL,"\",\n"));
        x = new_film(title,year,age,genre,lenght,rating);
        insert(root, x);
    }
}
void printMovies(FILE *fp,Node *root)
{
    Node *current = root;
    while((current->next) != NULL)
    {
        current = current->next;
        film_fprint(fp, current->movie);
    }
}
Film **searchMovie(char*(*get)(const Film*),char *search, int nr, Node *root)
{
    Film *movie;
    int i = 0;
    Node *current = root->next;
    Film** filmArr = malloc((nr)*sizeof(Film*));
    while(current ->next!= NULL && i < nr+1) 
    {
        current = current->next;
        if (strstr(get(current->movie),search) != NULL){
            filmArr[i] = current->movie;
            i++;
        }
    }
    return filmArr;
}
Film *nthMovie (int (*get)(const Film*),Film **array){
    int i = 1;
    Film *movie = array[0];
    while(array[i]){
        if(get(movie) < get(array[i])){
            movie = array[i];
        }
        i++;
    }
    free(array);
    return movie;
}
void eraseMovies(Node *root,char*(*get)(const Film*) ,char *info)
{
    Node *current = root->next;
    Node *previous = root;
    
    while(current->next != NULL){
        if(strcmp(get(current->movie),info) == 0){
            previous->next = current->next;
            film_free(current->movie);
            free(current);
            current = previous->next;
        }
        else{
            previous = previous->next;
            current = current->next;
        }
    }
    // special case for last item in the list
    if(strcmp(get(current->movie),info) == 0){
        previous->next = NULL;
        film_free(current->movie);
        free(current);
    }
}

int ascending(int a, int b){
    return a>b;
}
int descending(int a, int b){
    return a<b;
}
void sortList(Node *root,int (*compare)(int,int) ,int (*get)(const Film*)){
    
    Node *previous = root->next;
    Node *current = root->next->next;
    Film *tempmovie;
    
    while(current != NULL){
        while(previous != current){
            if(compare(get(current->movie),get(previous->movie))){//<
                tempmovie = previous->movie;
                previous->movie = current->movie;
                current->movie = tempmovie;
            }
            previous = previous->next;
        }
        previous = root->next;
        current = current->next;
    }
}

int countMovies(Node *root){
    Node *current = root;
    int count = 0;
    while(current->next != NULL){
        count++;
        current = current->next;
    }
    return(count);
}
Node *extractDB(Node *root,char*(*get)(const Film*),char *search){
    Node *current = root->next;
    Node *newRoot = (Node*)malloc(sizeof(Node));
    newRoot->next = NULL;
    while(current->next!= NULL){
        if(strstr(get(current->movie),search) != NULL){
            insert(newRoot,current->movie);
        }
        current = current->next;
    }
    return newRoot;
}
Film *getnMovie(Node *root, int nr){
    int i=0;
    Node *current = root->next;
    while(current->next!=NULL && i<nr){
        current = current->next;
        i++;
    }
    return current->movie;
}
void freeDB(Node *root){
    Node *current = root->next->next;
    Node *previous = root->next;
    while(current->next->next!=NULL){
        film_free(previous->movie);
        free(previous);
        previous = current;
        current = current->next;
    }
}
void highestMovie(Node *root){
    Film *movie = root->next->movie;
    Node *current =root->next;
    while(current->next!=NULL){
        if (film_getRating(current->movie) > film_getRating(movie)){
            movie = current->movie;
        }
        current=current->next;
    }
    film_fprint(stdout,movie);
}
void shortestTitle(Node *root){
    Film *movie = root->next->movie;
    Node *current =root->next;
    while(current->next!=NULL){
        if (strlen(film_getTitle(current->movie)) < strlen(film_getTitle(movie))){
            movie = current->movie;
        }
        current=current->next;
    }
    film_fprint(stdout,movie);
}