#pragma once
#include "oferta.h"

typedef struct {
	int cap;
	int n;
	oferta** vector;
}vector_dinamic;

typedef struct {
	vector_dinamic* v;
	int curent;
 }iterator;

//creeaza lista
vector_dinamic* creeaza_vector(int);

//adauga oferta in lista
void adauga_element(vector_dinamic*, oferta**);

//sterge oferta din lista
void sterge_element(vector_dinamic*, int);

//returneaza dimensiunea listei
int dim(vector_dinamic*);

//returneaza oferta de pe o anumita pozitie din lista
oferta* element(vector_dinamic*, int);

//copiaza lista(deep copy)
vector_dinamic* copy_list(vector_dinamic*);

//redimensioneaza lista
void redim(vector_dinamic*);

//distruge lista
void distruge(vector_dinamic*);

//creeaza iteratorul
iterator* iterator_vector(vector_dinamic*);

//creeaza iteratorul
iterator* creeaza_iterator(vector_dinamic*);

//duce iteratorul la prima pozitie din lista
void prim(iterator*);

//verifica daca iteratorul e valid
int valid(iterator*);

//duce iteratorul pe pozitia urmatoare in lista
void urmator(iterator*);

//returneaza elementul la care se afla iteratorul
oferta* element_iterator(iterator*);

//distruge iteratorul
void distruge_iterator(iterator*);