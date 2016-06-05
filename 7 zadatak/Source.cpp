#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#define MAX 100
typedef struct at {
	int element;
	struct at*slijed;
}atom;
typedef struct {
	atom*vrh;
}Stog;

void init_stog(Stog*stog) {
	stog->vrh = NULL;
}
int dodaj(int element, Stog *stog) {
	atom *novi;
	if (!(novi = (atom*)malloc(sizeof(atom)))) {
		printf("GRESKA!!");
		return 0;
	}
	novi->element = element;
	novi->slijed = stog->vrh;
	stog->vrh = novi;
	return 1;
}
int main() {
	int i = 0, a;
	Stog *stog;
	stog = (Stog*)malloc(sizeof(Stog));
	init_stog(stog);
	srand((unsigned)time(NULL));
	while (i<MAX) {
		a = rand() % INT_MAX;
		dodaj(a, stog);
		printf("%d. %d\n",++i, (stog->vrh)->element);
	}
	return 0;
	
}