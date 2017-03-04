/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   moviedatabase.h
 * Author: tiberiusimionvoicu
 *
 * Created on 27 October 2016, 16:14
 */

#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H
#ifdef __cplusplus
extern "C" {
#endif
#include "film.h"
    typedef struct ModbNode
    {
        Film *movie;
        
       struct ModbNode *next;
    } Node ;
    //check whether should be const
    void insert(Node *root ,Film *movie);
    
    void addMovies(Node *root ,FILE *fp);
    
    void printMovies(FILE *fp,Node *root);
    
    
    Film *nthMovie (int(*get)(const Film* ),Film **array);
    
    Film **searchMovie(char*(*get)(const Film*),char *search, int nr, Node *root);
    
    void eraseMovies(Node *root,char*(*get)(const Film*),char *info);
    
    Film *getnMovie(Node *root, int nr);
    
    //to do
    void freeDB(Node *root);
    void highestMovie(Node *root);
    void shortestTitle(Node *root);
    
/*****************************************************************************

Function   : sortList

Parameters  : Node* root - pointer to a linked list root.

Returns     : none
 
Description : Sorts the elements of a linked list structure into ascending
              order, using the bubble sort algorithm (not very efficient).

 *****************************************************************************/    
    void sortList(Node *root,int (*compare)(int,int), int (*get)(const Film*));
    int descending(int,int);
    int ascending(int,int);
   
    
    
/*****************************************************************************

Function   : countMovies

Parameters  : Node* root - pointer to a linked list root.

Returns     : int - number of elements comprising the list.
 
Description : Determines the number of structs currently stored in a
              linked list structure.

 *****************************************************************************/    
    int countMovies(Node *root);
    
    Node *extractDB(Node *root,char*(*get)(const Film*),char *search);

#ifdef __cplusplus
}
#endif

#endif /* MOVIEDATABASE_H */

