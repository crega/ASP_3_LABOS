#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct at {				//svaki element preko liste koji pokazuje na onaj koji je nakon
	double element;
	struct at* slijed;
}cvor;
typedef struct atom {		// svaki taj cvor mora biti vezan sa ulazom/izlazom
	cvor*ulaz;
	cvor *izlaz;
}Red;

void init_red(Red*red) {
	red->ulaz = red->izlaz = NULL;
}
int DodajuRed_listom(double element, Red*red) {
	cvor*novi;
	if (!(novi=(cvor*)malloc(sizeof(cvor)))) {
		return 0;
	}
	novi->element = element;
	if (!(red->izlaz))	// prazan red, dodaj na pocetak  tj ako je red->izlaz ==NULL komplement toga je istina
	{
		red->izlaz = novi;
	}
	else {								// ako ne onda dodaj iza zadnjeg dodanog
		(red->ulaz)->slijed = novi;
	}
	red->ulaz = novi;					//zapamti zadnjeg radi svakog novog poziva
	return 1;

}
int main() {
	int i,n;
	cvor* broj;
	Red*red;
	red = (Red*)malloc(sizeof(Red));
	broj = (cvor*)malloc(sizeof(cvor));
	init_red(red);
	do {
		puts("Upisi broj manji od 11");
		scanf("%d", &n);
	} while (n< 1 || n>11);
	for (i = 0; i < n; ++i) {
		printf("Upisite %d element u red", i + 1);
		scanf("%lf", &(broj->element));
		DodajuRed_listom(broj->element, red);
	}
	printf("U redu je ovakvo stanje\n");
	while (red->izlaz !=red->ulaz) {		 				//dok ne dodes do kraja ispisuj
		printf("%3.1f je na %p lokaciji, nakon njega je %f koji je na lokaciji %p\n",
			(red->izlaz)->element,						
			red->izlaz,
			((red->izlaz)->slijed->element),
			(red->izlaz)->slijed);

			red->izlaz = (red->izlaz)->slijed;			// uvijet napredovanja petlje
		
	}
	return 0;
}