#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#define M 100
struct at {
	int sifra;
	struct at*slijed;
};
typedef struct at blok;
int adresa(int broj) {
	return broj % 97;
}
void isprazni(blok*tablica[]) {					//inicijalno ocisti tablicu
	for (int i = 0; i < M; ++i) {
		tablica[i] = NULL;
	}

}
int hashaj(blok*tablica[], blok* element) {				//prima polje pokazivaca i element koji zeli dodati
	int adr;
	
	adr = adresa(element->sifra);		//izracunaj adresu
	element->slijed = tablica[adr];		
	tablica[adr] = element;
	return 1;

}
int main() {
	blok *tablica[M];
	blok *element; 
	
	int broj;
	srand((unsigned)time(NULL));
	//isprazni(&tablica[0]);
	for (int i = 0; i < M; ++i) {
		broj = rand();
		element = (blok*)malloc(sizeof(blok));
		element->sifra = broj;
		if (!hashaj(&tablica[0], element)) {
			puts("Ne mogu dodati u tablicu");
			return 1;
		}


	}
	/*for (int i = 0; i < M; ++i) {
		printf("%d\n", tablica[i]->sifra);
	}*/
}