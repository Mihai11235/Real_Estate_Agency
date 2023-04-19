#include "vector_dinamic.h"
#include<malloc.h>

vector_dinamic* creeaza_vector(int cap) {
	vector_dinamic* v = (vector_dinamic*)malloc(sizeof(vector_dinamic));
	if (v) {
		v->cap = cap;
		v->n = 0;
		v->vector = (oferta**)malloc(cap * sizeof(oferta*));
	}
	return v;
}

void adauga_element(vector_dinamic* v, oferta** o) {
	if (v->n == v->cap)
		redim(v);
	v->vector[((v)->n)++] = *o;
}

void sterge_element(vector_dinamic* v, int poz) {
	distruge_oferta(v->vector[poz]);
	for (int i = poz; i < v->n-1; i++)
		v->vector[i] = v->vector[i + 1];
	v->n--;
}

int dim(vector_dinamic* v) {
	return v->n;
}

oferta* element(vector_dinamic* v, int i) {
	return v->vector[i];
}

vector_dinamic* copy_list(vector_dinamic* v) {
	vector_dinamic* vp = creeaza_vector(dim(v));
	for (int i = 0; i < v->n; i++)
		vp->vector[i] = creeaza_oferta(get_tip(v->vector[i]), get_suprafata(v->vector[i]), get_adresa(v->vector[i]), get_pret(v->vector[i]));
	vp->n = v->n;
	return vp;
}

void redim(vector_dinamic* v) {
	oferta** p = (oferta**)malloc(v->cap * 2 * sizeof(oferta*));
	if (p) {
		for (int i = 0; i < v->n; i++)
			p[i] = v->vector[i];

		free(v->vector);
		v->vector = p;
		v->cap *= 2;
	}
}

void distruge(vector_dinamic* v) {
	for (int i = 0; i < dim(v); i++)
		distruge_oferta(v->vector[i]);
	free(v->vector);
	free(v);
}

iterator* iterator_vector(vector_dinamic* v) {
	return creeaza_iterator(v);
}

iterator* creeaza_iterator(vector_dinamic* v) {
	iterator* i = (iterator*)malloc(sizeof(iterator));
	if (i) {
		i->v = v;
		i->curent = 0;
	}
	return i;
}

void prim(iterator* i) {
	i->curent = 0;
}

int valid(iterator* i) {
	if(i->curent < dim(i->v))
		return 1;
	distruge_iterator(i);
	return 0;
	
}

void urmator(iterator* i) {
	i->curent++;
}

void distruge_iterator(iterator* i) {
	free(i);
}

oferta* element_iterator(iterator* i) {
	return i->v->vector[i->curent];
	//return element(i->v, i->curent);
}

