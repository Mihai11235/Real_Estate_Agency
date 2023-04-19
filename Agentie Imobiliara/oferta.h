#pragma once

typedef struct {
	char* tip;
	float suprafata;
	char* adresa;
	float pret;
}oferta;

//creeaza oferta
oferta* creeaza_oferta(char*, float, char*, float);

//returneaza tipul ofertei
char* get_tip(oferta *o);

//returneaza suprafata ofertei
float get_suprafata(oferta *o);

//returneaza adresa ofertei
char* get_adresa(oferta *o);

//returneaza pretul ofertei
float get_pret(oferta *o);

//verifica daca 2 oferte sunt egale
int equ(oferta*, oferta*);

//distruge oferta
void distruge_oferta(oferta*);