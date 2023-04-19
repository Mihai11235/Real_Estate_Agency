#include "oferta.h"
#include "service.h"
#include <stdio.h>
#include "validare.h"
#include <string.h>
#include "vector_dinamic.h"

void adauga_oferta_service(vector_dinamic* v, char* eroare, char* tip, float suprafata, char* adresa, float pret) {
	oferta* o = creeaza_oferta(tip, suprafata, adresa, pret);
	iterator* i = iterator_vector(v);
	for (prim(i); valid(i); urmator(i))
		if (equ(element_iterator(i), o)) {
			strcpy(eroare, "Oferta exista deja in lista!\n");
			distruge_iterator(i);
			distruge_oferta(o);
			return;}

	valideaza_oferta(o, eroare);
	if (strcmp(eroare, "succes!\n") == 0) {
		strcpy(eroare, "Oferta adaugata cu succes!\n");
		adauga_element(v, &o);
	}
	else
		distruge_oferta(o);
}

void actualizeaza_oferta_service(vector_dinamic* v, int poz, char* eroare, char* tip, float suprafata, char* adresa, float pret) {
	oferta* o = creeaza_oferta(tip, suprafata, adresa, pret);

	if (poz >= dim(v)) {
		strcpy(eroare, "Pozitia introdusa nu exista in lista");
		distruge_oferta(o);
		return;
	}

	iterator* i = iterator_vector(v);
	for (prim(i); valid(i); urmator(i))
		if (equ(element_iterator(i), o)) {
			strcpy(eroare, "Oferta exista deja in lista!");
			distruge_oferta(o);
			distruge_iterator(i);
			return;
		}
	valideaza_oferta(o, eroare);
	if (strcmp(eroare, "succes!\n") == 0) {
		sterge_element(v, poz);
		adauga_element(v, &o);
		strcpy(eroare, "Oferta modificata cu succes!\n");
	}
	else
		distruge_oferta(o);
}

void sterge_oferta_service(vector_dinamic* v, int poz, char* eroare) {
	if (poz >= dim(v)) {
		strcpy(eroare, "Pozitia introdusa nu exista in lista");
		return;
	}
	sterge_element(v, poz);
	strcpy(eroare, "Oferta stearsa cu succes!\n");
}

vector_dinamic* sortare_pret_service(vector_dinamic* v) {
	vector_dinamic* vp = copy_list(v);

	for(int i=0; i<vp->n-1; i++)
		for(int j=i+1; j<vp->n; j++)
			if (get_pret(vp->vector[i]) > get_pret(vp->vector[j])) {
				oferta* o = vp->vector[i];
				vp->vector[i] = vp->vector[j];
				vp->vector[j] = o;
			}
	return vp;
}

vector_dinamic* sortare_tip_service(vector_dinamic* v) {
	vector_dinamic* vp = copy_list(v);

	for(int i=0; i<vp->n-1; i++)
		for(int j=i+1; j<vp->n; j++)
			if (strcmp( get_tip(vp->vector[i]) , get_tip(vp->vector[j])) > 0) {
				oferta* o = vp->vector[i];
				vp->vector[i] = vp->vector[j];
				vp->vector[j] = o;
			}
	return vp;
}

vector_dinamic* filtreaza_suprafata_service(vector_dinamic* v, float filtru) {
	vector_dinamic* cv = creeaza_vector(dim(v));

	for (int i = 0; i < dim(v); i++)
	{
		if (get_suprafata(element(v, i)) == filtru) {
			oferta* o = creeaza_oferta(get_tip(element(v, i)), get_suprafata(element(v, i)), get_adresa(element(v, i)), get_pret(element(v, i)));
			adauga_element(cv, &o);
		}
	}

	return cv;
}

vector_dinamic* filtreaza_pret_service(vector_dinamic* v, float filtru) {
	vector_dinamic* cv = creeaza_vector(dim(v));

	for (int i = 0; i < dim(v); i++)
	{
		if (get_pret(element(v, i)) == filtru) {
			oferta* o = creeaza_oferta(get_tip(element(v, i)), get_suprafata(element(v, i)), get_adresa(element(v, i)), get_pret(element(v, i)));
			adauga_element(cv, &o);
		}
	}

	return cv;
}

vector_dinamic* filtreaza_tip_service(vector_dinamic* v, char* filtru) {
	vector_dinamic* cv = creeaza_vector(dim(v));

	for (int i = 0; i < dim(v); i++)
	{
		if (!strcmp(get_tip(element(v, i)) , filtru)) {
			oferta* o = creeaza_oferta(get_tip(element(v, i)), get_suprafata(element(v, i)), get_adresa(element(v, i)), get_pret(element(v, i)));
			adauga_element(cv, &o);
		}
	}

	return cv;
}
