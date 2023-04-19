#include "validare.h"
#include "oferta.h"
#include <string.h>
#include<stdio.h>

void valideaza_oferta(oferta* o, char* erori) {
	strcpy(erori, "");
	if (strcmp(get_tip(o), "teren") && strcmp(get_tip(o), "casa") && strcmp(get_tip(o), "apartament"))
		strcat(erori, "Tipul trebuie sa fie una dintre: casa, teren, apartament!\n");

	if (get_suprafata(o) <= 0)
		strcat(erori, "Suprafata trebuie sa fie un numar pozitiv!\n");

	if (get_pret(o) <= 0)
		strcat(erori, "Pretul trebuie sa fie un numar pozitiv!\n");

	if(strlen(erori) == 0)
		strcat(erori, "succes!\n");
}