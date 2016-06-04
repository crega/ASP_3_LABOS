#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct at {
	int element;
	struct at *next;
}cvor;

int upisNaKraj(cvor**glava, cvor**rep, int *broj) {
	cvor*p;//nema free jer gubis reference za sljedeci poziv!!!!
	if (!(p = (cvor*)malloc(sizeof(cvor)))) {
		puts("Greska kod alokacije memorije");
		return 0;
	}

	p->element = *broj;
	p->next = NULL;// novododani mora uvijek imati next NULL
	if (*glava == NULL) {// ako je lista prazna onda ce i kraj i poc biti jednaki
		*glava = p;
		*rep = p;
	}
	{		// ako ne onda shihtaj stari pod u lijevo i novi stavi na kraj
		(*rep)->next = p;// stari p pokazuje na novi p
		*rep = (*rep)->next;// novi p pokazuje na sljedeci tj null;
	}
	return 1;
}
void ispis(cvor**glava,cvor**rep) {
	cvor *p;
	int i = 0;
	p = *glava;
	while (p != NULL) {
		printf("%d podatak u listi je %d koji je na adresi %p a pokazuje na %p\n",
			++i, p->element, p, p->next);
		p = p->next;
	}
	
}
int main() {
	int a, n, t, broj;
	cvor *glava = NULL;
	cvor*rep = NULL;
	
	do {
		puts("Upisite broj manji od 11");
		scanf("%d", &n);
	} while (n < 1 || n>10);
	for (int i = 0; i < n; ++i) {
		printf("Upisite %d podatak koji cu dodati u listu\n ", i + 1);
		scanf("%d", &broj);

		t = upisNaKraj(&glava,&rep, &broj);
		if (!t) {
			printf("Nisam mogao upisati %d podatak u listu\n", i + 1);
			return 1;
		}
	}
	ispis(&glava,&rep);
	return 0;
}
