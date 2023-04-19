#pragma once
#include "vector_dinamic.h"

//valideaza si adauga oferta
void adauga_oferta_service(vector_dinamic* ,char* , char*, float, char*, float);

//valideaza si actualizeaza oferta
void actualizeaza_oferta_service(vector_dinamic*, int, char*, char*, float, char*, float);

//sterge oferta
void sterge_oferta_service(vector_dinamic*, int, char*);

//sorteaza ofertele dupa pret
vector_dinamic* sortare_pret_service(vector_dinamic*);

//sorteaza ofertele dupa tip
vector_dinamic* sortare_tip_service(vector_dinamic*);

//filtreaza ofertele dupa suprafata
vector_dinamic* filtreaza_suprafata_service(vector_dinamic*, float);

//filtreaza ofertele dupa pret
vector_dinamic* filtreaza_pret_service(vector_dinamic*, float);

//filtreaza ofertele dupa tip
vector_dinamic* filtreaza_tip_service(vector_dinamic*, char*);
