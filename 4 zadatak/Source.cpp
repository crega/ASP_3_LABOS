#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 10
typedef struct at {
	float polje[MAX];
	int ulaz, izlaz;
}red;
void init_red(red*red) {
	for (int i = 0; i < MAX; ++i) {
		red->polje[i] = 0.0;
	}
	red->ulaz = red->izlaz = 0;
}
int Dodaj(float element, red*red) {
	if (((red->ulaz + 1) % MAX) == red->izlaz) return 0; // ako je red pun ne dodaji nista
	red->ulaz++;		// povecaj indeks gdje ces kasnije dodati u red , tj iza zadnjeg vec u redu
	red->ulaz %= MAX;			//
	red->polje[red->ulaz] = element;		// u polje na indeksu 1 poslije zadnjeg dodaj element
	return 1;
}
int Skini(float *element, red*red) {
	if (red->ulaz == red->izlaz) return 0;				// ako je red prazan nemas sto skidati
	red->izlaz++;								// povecaj indeks gdje ce novi pocetak reda pokazati, efektivno
												// smo izbacili prvi iz reda
	red->izlaz %= MAX;							//izracun tog indeksa ovisno o velicini polja
	*element = red->polje[red->izlaz];			//element sada pokazuje na slijedeci u redu tj novi izlaz
	return 1;
}

int main() {
	int n;
	int i;
	float *element;
	red* Red;
	Red = (red*)malloc(sizeof(red));
	if (Red == NULL) {
		puts("GREKSA!!!");
		return 1;
	}
	do {
		printf("Upisi broj manji od %d\n", MAX + 1);
		scanf("%d", &n);
	} while (n<1 || n>MAX);
	init_red(Red);
	for (i = 0; i < n; ++i) {						//inicijalizacija i dodavanje u red
		printf("Upisite %d. element polja\n", i + 1);
		scanf("%f", &Red->polje[i]);
		Dodaj(Red->polje[i], Red);

	}
	element = &Red->polje[0];							//element u redu uvijek pokazuje na onaj koji je prvi dodan tj koji ce prvi izaci iz reda

	puts("Skidanje clanova iz reda");
	while (Red->ulaz != Red->izlaz) {
		printf("%3.3f", *element);
		Skini(element, Red);

	}
	if (Red->ulaz == Red->izlaz) {
		printf("Uspjesno su svi maknuti\n");
		return 0;
	}
	else
	{
		return 1;
	}
}
