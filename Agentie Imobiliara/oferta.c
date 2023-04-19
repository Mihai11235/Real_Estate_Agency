#include "oferta.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
oferta* creeaza_oferta(char* tip, float suprafata, char* adresa, float pret) {
	oferta* o = (oferta*)malloc(sizeof(oferta));

	if (o) {
		o->tip = (char*)malloc((strlen(tip) + 1) * sizeof(char));
		strcpy(o->tip, tip);

		o->adresa = (char*)malloc((strlen(adresa) + 1) * sizeof(char));
		strcpy(o->adresa, adresa);

		o->suprafata = suprafata;
		o->pret = pret;
	}
	return o;
}

char* get_tip(oferta* o) {
	return o->tip;
}

float get_suprafata(oferta* o) {
	return o->suprafata;
}

char* get_adresa(oferta* o) {
	return o->adresa;
}

float get_pret(oferta* o) {
	return o->pret;
}

int equ(oferta* o1, oferta* o2) {
	if (fabs(o1->pret - o2->pret) < 0.0001 && fabs(o1->suprafata - o2->suprafata) < 0.0001 && \
		!strcmp(o1->tip, o2->tip) && !strcmp(o1->adresa, o2->adresa))
		return 1;
	return 0;
}

void distruge_oferta(oferta* o) {
	free(o->tip);
	free(o->adresa);
	free(o);
}
