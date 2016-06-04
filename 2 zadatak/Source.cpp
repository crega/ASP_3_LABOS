#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct at {
	char niz[41];
	struct at *next;
}cvor;
int upisNaPoc(cvor **glava, char *niz) {
	cvor *p;//nema free jer gubis reference za sljedeci poziv!!!!
	if (!(p = (cvor*)malloc(1 * sizeof(cvor)))) {
		puts("Greska kod alokacije memorije!");
		return 0;
	}
	strcpy(p->niz, niz);
	p->next = *glava;	//ubaci ispred adrese na koju pokazuje glava
	*glava = p;			//glava sada pokazuje na taj ubaceni clan
	
	return 1;

}
void ispis(cvor **glava) {
	cvor *p;
	int i = 1;

	if (!(p = (cvor*)malloc(sizeof(cvor)))) {
		puts("Greska kod alokacije mjesta!\nPOKUSAJTE PONOVO");
		exit(1);
	}
	p = *glava;
	while (p != NULL) {
		printf("Na %d. mjestu se nalazi %s koji sa adrese %p pokazuje na %p\n\n", i, p->niz, p, p->next);
		++i;
		p = p->next;
	}
}
int main() {
	int a, n, t;
	cvor *glava = NULL;
	char niz[41];
	do {
		puts("Upisite broj manji od 11");
		scanf("%d", &n);
	} while (n < 1 || n>10);
	for (int i = 0; i < n; ++i) {
		printf("Upisite %d podatak koji cu dodati u listu\n ", i + 1);
		scanf("%s", niz);

		t = upisNaPoc(&glava, niz);
		if (!t) {
			printf("Nisam mogao upisati %d podatak u listu\n", i + 1);
			return 1;
		}
	}
	ispis(&glava);
	return 0;
}
