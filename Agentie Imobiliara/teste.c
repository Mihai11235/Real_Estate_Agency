#pragma once
#include "teste.h"
#include <assert.h>
#include "oferta.h"
#include <string.h>
#include <stdlib.h>
#include "vector_dinamic.h"
#include "service.h"
#include "validare.h"
#include <math.h>
#include <stdio.h>


void ruleaza_toate_testele() {
	ruleaza_teste_domain();
	ruleaza_teste_validare();
	ruleaza_teste_TAD();
	ruleaza_teste_service();
}

void ruleaza_teste_domain() {
	oferta* o;
	o = creeaza_oferta("casa", 100, "Aleea Lalelelor", 70000);
	assert(strcmp(get_adresa(o), "Aleea Lalelelor") == 0);
	assert(strcmp(get_tip(o), "casa") == 0);
	assert(fabs(get_suprafata(o) - 100)<0.0001);
	assert(fabs(get_pret(o) - 70000) < 0.0001);

	oferta* o2 = creeaza_oferta("casa", 100, "Aleea Lalelelor", 70000);
	assert(equ(o, o2));

	oferta* o3 = creeaza_oferta("casa", 90, "Aleea Lalelelor", 70000);
	assert(!equ(o, o3));
	distruge_oferta(o);
	distruge_oferta(o2);
	distruge_oferta(o3);
}

void ruleaza_teste_validare() {
	oferta* o = creeaza_oferta("ok", -1, "Aleea Lalelelor", -10);
	char* erori = (char*)malloc(200 * sizeof(char));
	if (erori) {
		valideaza_oferta(o, erori);
		assert(!strcmp(erori, "Tipul trebuie sa fie una dintre: casa, teren, apartament!\nSuprafata trebuie sa fie un numar pozitiv!\nPretul trebuie sa fie un numar pozitiv!\n"));
	}
	distruge_oferta(o);
	free(erori);
}
void ruleaza_teste_TAD() {
	vector_dinamic* v = creeaza_vector(1);

	oferta* o = creeaza_oferta("casa", 100, "Aleea Lalelelor", 70000);
	adauga_element(v, &o);
	assert(dim(v) == 1);

	oferta* o2 = creeaza_oferta("casa", 500, "Aleea Lalelelor", 50000);
	adauga_element(v, &o2);
	
	oferta* o3 = creeaza_oferta("casa", 30, "Aleea Lalelelor", 60000);
	adauga_element(v, &o3);

	assert(dim(v) == 3);

	sterge_element(v, 1);
	assert(dim(v) == 2);
	distruge(v);
}

void ruleaza_teste_service() {
	oferta* o = creeaza_oferta("casa", 100, "Aleea Lalelelor", 70000);
	vector_dinamic* v = creeaza_vector(1);
	char* erori = (char*)malloc(200*sizeof(char));
	if (erori) {
		adauga_oferta_service(v, erori, "ok", -100, "okk", -70000);
		assert(!strcmp(erori, "Tipul trebuie sa fie una dintre: casa, teren, apartament!\nSuprafata trebuie sa fie un numar pozitiv!\nPretul trebuie sa fie un numar pozitiv!\n"));

		adauga_oferta_service(v, erori, "casa", 100, "Aleea Lalelelor", 70000);
		assert(equ(element(v, 0), o));
		assert(!strcmp(erori, "Oferta adaugata cu succes!\n"));

		adauga_oferta_service(v, erori, "casa", 100, "Aleea Lalelelor", 70000);
		assert(!strcmp(erori, "Oferta exista deja in lista!\n"));

		actualizeaza_oferta_service(v, 10, erori, "teren", 100, "Aleea Lalelelor", 70000);
		assert(!strcmp(erori, "Pozitia introdusa nu exista in lista"));


		actualizeaza_oferta_service(v, 0, erori, "casa", 100, "Aleea Lalelelor", 70000);
		assert(!strcmp(erori, "Oferta exista deja in lista!"));

		actualizeaza_oferta_service(v, 0, erori, "teren", 100, "Aleea Lalelelor", 70000);
		assert(!strcmp(erori, "Oferta modificata cu succes!\n"));

		sterge_oferta_service(v, 1, erori);
		assert(!strcmp(erori, "Pozitia introdusa nu exista in lista"));

		actualizeaza_oferta_service(v, 0, erori, "ok", -100, "okk", -70000);
		assert(!strcmp(erori, "Tipul trebuie sa fie una dintre: casa, teren, apartament!\nSuprafata trebuie sa fie un numar pozitiv!\nPretul trebuie sa fie un numar pozitiv!\n"));

		sterge_oferta_service(v, 0, erori);
		assert(!strcmp(erori, "Oferta stearsa cu succes!\n"));

		adauga_oferta_service(v, erori, "teren", 100, "okk", 40000);
		adauga_oferta_service(v, erori, "casa", 30, "Aleea Lalelelor", 40000);
		adauga_oferta_service(v, erori, "apartament", 30, "Aleea Lalelelor", 60000);
		adauga_oferta_service(v, erori, "casa", 30, "Aleea Lalelelor", 50000);
		adauga_oferta_service(v, erori, "apartament", 50, "Aleea Lalelelor", 40000);

		vector_dinamic* vp = sortare_pret_service(v);
		//printf("%f", get_pret(element(vp,4)));
		assert(fabs(get_pret(element(vp, 0)) - 40000) < 0.0001);
		assert(fabs(get_pret(element(vp, 1)) - 40000) < 0.0001);
		assert(fabs(get_pret(element(vp, 2)) - 40000) < 0.0001);
		assert(fabs(get_pret(element(vp, 3)) - 50000) < 0.0001);
		assert(fabs(get_pret(element(vp, 4)) - 60000) < 0.0001);

		distruge(vp);

		vp = sortare_tip_service(v);
		assert(!strcmp(get_tip(element(vp, 0)), "apartament"));
		assert(!strcmp(get_tip(element(vp, 1)), "apartament"));
		assert(!strcmp(get_tip(element(vp, 2)), "casa"));
		assert(!strcmp(get_tip(element(vp, 3)), "casa"));
		assert(!strcmp(get_tip(element(vp, 4)), "teren"));

		distruge(vp);

		vp = filtreaza_suprafata_service(v, 30);
		assert(fabs(get_suprafata(vp->vector[0]) - 30)<0.0001);
		assert(fabs(get_suprafata(vp->vector[1]) - 30)<0.0001);
		assert(fabs(get_suprafata(vp->vector[2]) - 30)<0.0001);

		distruge(vp);

		vp = filtreaza_pret_service(v, 40000);
		assert(fabs(get_pret(vp->vector[0]) - 40000)<0.0001);
		assert(fabs(get_pret(vp->vector[1]) - 40000)<0.0001);
		assert(fabs(get_pret(vp->vector[2]) - 40000)<0.0001);

		distruge(vp);

		vp = filtreaza_tip_service(v, "apartament");
		assert(!strcmp(get_tip(vp->vector[0]), "apartament"));
		assert(!strcmp(get_tip(vp->vector[1]), "apartament"));
		
		distruge(vp);
	}

	distruge_oferta(o);
	distruge(v);
	free(erori);
}


