#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#define MAX 100
typedef struct at {
	int vrh, polje[MAX];
}Stog;
int dodaj(int element, Stog *stog) {
	if (stog->vrh >= MAX - 1)return 0;			// stog je pun! ne moze se dodati jer je staticno polje!
	stog->vrh++;
	stog->polje[stog->vrh] = element;			// nakon pocevanja indeksa dodaj element na tu lokaciju
	return 1;
}

int main() {
	Stog* stog;
	int i = 0, rez = 1, a;
	if (!(stog = (Stog*)malloc(sizeof(Stog)))) {
		puts("Ne mogu alocirati memoriju za program");
		return 1;
	}
	srand((unsigned)time(NULL));
	stog->vrh = -1;
	while (rez) {		// inicijalno dozvoljeno, kad rez vrati 0 , greska u dodaj ili pun tj presao je MAX granicu, onda prekini!
		a = rand() % INT_MAX;
		rez=dodaj(a, stog);
		printf("%d. %d\n", i, a);
		++i;
	}
	return 0;
	
}