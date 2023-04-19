#include <stdio.h>
#include "ui.h"
#include "service.h"
#include "vector_dinamic.h"
#include <malloc.h>
#include "oferta.h"
#include <stdlib.h>
#include "functii.h"
#include <assert.h>

void menu() {
	printf("1) Adauga oferta\n");
	printf("2) Actualizeaza oferta\n");
	printf("3) Sterge oferta\n");
	printf("4) Vizualizare oferte ordonate dupa pret\n");
	printf("5) Vizualizare oferte ordonate dupa tip\n");
	printf("6) Filtreaza oferta dupa suprafata\n");
	printf("7) Filtreaza oferta dupa pret\n");
	printf("8) Filtreaza oferta dupa tip\n");
	printf("9) Afiseaza toate ofertele\n");
	printf("0) Exit\n");
}

void printeaza_oferte_ui(vector_dinamic* v) {
	iterator* i = iterator_vector(v);

	int poz = 0, ok = 0;
	for (prim(i); valid(i); urmator(i)) {
		ok = 1;
		oferta* o = element_iterator(i);
		printf("%d) %s %f %s %f\n",poz++ , get_tip(o), get_suprafata(o), get_adresa(o), get_pret(o));
	}
	if (!ok)
		printf("Nu exista oferte adaugate!\n");
}

void adauga_oferta_ui(vector_dinamic* v) {
	char tip[50];
	char suprafata_c[50];
	char adresa[50];
	char pret_c[50];

	
	printf("Introduceti tipul: ");
	assert(scanf("%s", tip)>0);
	printf("Introduceti suprafata: ");
	assert(scanf("%s", suprafata_c)>0);
	printf("Introduceti adresa: ");
	assert(scanf("%s", adresa)>0);
	printf("Introduceti pretul: ");
	assert(scanf("%s", pret_c)>0);

	float suprafata, pret;
	float err = string_to_float(suprafata_c);
	
	if (err == -1) {
		printf("Suprafata trebuie sa fie float!");
		return;
	}
	else
		suprafata = err;

	err = string_to_float(pret_c);
	if (err == -1) {
		printf("Pretul trebuie sa fie float!");
		return;
	}
	else
		pret = err;
	
	char* eroare = (char*)malloc(400 * sizeof(char));
	adauga_oferta_service(v, eroare, tip, suprafata, adresa, pret);
	printf("%s", eroare);
	free(eroare);
}

void actualizeaza_oferta_ui(vector_dinamic* v) {
	char tip[50];
	char suprafata_c[50];
	char adresa[50];
	char pret_c[50];

	int poz;
	printf("Introduceti pozitia din lista a ofertei pe care doriti sa o actualizati: ");
	assert(scanf("%d", &poz)>0);
	printf("Introduceti tipul: ");
	assert(scanf("%s", tip)>0);
	printf("Introduceti suprafata: ");
	assert(scanf("%s", suprafata_c)>0);
	printf("Introduceti adresa: ");
	assert(scanf("%s", adresa)>0);
	printf("Introduceti pretul: ");
	assert(scanf("%s", pret_c)>0);

	float suprafata, pret;
	float err = string_to_float(suprafata_c);

	if (err == -1) {
		printf("Suprafata trebuie sa fie float!");
		return;
	}
	else
		suprafata = err;

	err = string_to_float(pret_c);
	if (err == -1) {
		printf("Pretul trebuie sa fie float!");
		return;
	}
	else
		pret = err;

	char* eroare = (char*)malloc(400 * sizeof(char));
	actualizeaza_oferta_service(v, poz, eroare, tip, suprafata, adresa, pret);
	printf("%s", eroare);
	free(eroare);
}

void sterge_oferta_ui(vector_dinamic* v) {
	int poz;
	printf("Introduceti pozitia din lista a ofertei pe care doriti sa o actualizati: ");
	assert(scanf("%d", &poz)>0);


	char* eroare = (char*)malloc(400 * sizeof(char));
	sterge_oferta_service(v, poz, eroare);
	printf("%s", eroare);
	free(eroare);
}

void sortare_pret_ui(vector_dinamic* v) {
	vector_dinamic* vp = sortare_pret_service(v);
	int poz = 0;
	for (int i = 0; i < vp->n; i++) {
		oferta* o = element(vp, i);
		printf("%d) %s %f %s %f\n", poz++, get_tip(o), get_suprafata(o), get_adresa(o), get_pret(o));
	}
	distruge(vp);
}

void sortare_tip_ui(vector_dinamic* v) {
	vector_dinamic* vt = sortare_tip_service(v);
	int poz = 0;
	for (int i = 0; i < vt->n; i++) {
		oferta* o = element(vt, i);
		printf("%d) %s %f %s %f\n", poz++, get_tip(o), get_suprafata(o), get_adresa(o), get_pret(o));
	}
	distruge(vt);
}

void filtrare_suprafata_ui(vector_dinamic* v) {
	float filtru;
	printf("Introduceti suprafata: ");
	assert(scanf("%f", &filtru));
	

	vector_dinamic* cv = filtreaza_suprafata_service(v, filtru);
	int poz = 0;
	for (int i = 0; i < cv->n; i++) {
		oferta* o = element(cv, i);
		printf("%d) %s %f %s %f\n", poz++, get_tip(o), get_suprafata(o), get_adresa(o), get_pret(o));
	}
	distruge(cv);
}

void filtrare_pret_ui(vector_dinamic* v) {
	float filtru;
	printf("Introduceti pretul: ");
	assert(scanf("%f", &filtru));
	

	vector_dinamic* cv = filtreaza_pret_service(v, filtru);
	int poz = 0;
	for (int i = 0; i < cv->n; i++) {
		oferta* o = element(cv, i);
		printf("%d) %s %f %s %f\n", poz++, get_tip(o), get_suprafata(o), get_adresa(o), get_pret(o));
	}
	distruge(cv);
}

void filtrare_tip_ui(vector_dinamic* v) {
	char filtru[20];
	printf("Introduceti tipul: ");
	assert(scanf("%s", filtru));
	

	vector_dinamic* cv = filtreaza_tip_service(v, filtru);
	int poz = 0;
	for (int i = 0; i < cv->n; i++) {
		oferta* o = element(cv, i);
		printf("%d) %s %f %s %f\n", poz++, get_tip(o), get_suprafata(o), get_adresa(o), get_pret(o));
	}
	distruge(cv);
}

void run() {
	vector_dinamic* v = creeaza_vector(1);
	while (1) {
		system("cls");
		menu();
		int comanda;
		printf("Introduceti comanda: ");
		scanf("%d", &comanda);

		if (comanda == 1) {
			adauga_oferta_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 2) {
			actualizeaza_oferta_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 3) {
			sterge_oferta_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 4) {
			sortare_pret_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 5) {
			sortare_tip_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 6) {
			filtrare_suprafata_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 7) {
			filtrare_pret_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 8) {
			filtrare_tip_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 9) {
			printeaza_oferte_ui(v);
			printf("\n");
			system("pause");
		}
		else if (comanda == 0) {
			distruge(v);
			return;
		}
		else {
			printf("Comanda invalida!\n");
			system("pause");
		}
	}
}