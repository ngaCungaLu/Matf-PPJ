#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


#include"vektor.h"


cvor* novi(double n){
	cvor* pom = malloc(sizeof(cvor));
	if (pom == NULL) {
		fprintf(stderr, "Neuspela alokacija\n");
		exit(EXIT_FAILURE);
	}
	pom->sled = NULL;
	pom->vrednost = n;
	return pom;
}

cvor* dodaj_na_kraj(cvor* lista, double n){
	
	if (lista == NULL) lista = novi(n);
	else{
		cvor *pom = lista;
		while (pom->sled != NULL) pom = pom->sled;

		pom->sled = novi(n);
	}
	return lista;
}

int duz(cvor* lista){
	int i=0;
	cvor* l = lista;

	while (l!=NULL){
		i++;
		l=l->sled;
	}
	return i;
}


cvor* saberi(cvor* l1, cvor* l2){
	cvor* pom = NULL;
	while (l1 != NULL){
		pom = dodaj_na_kraj(pom, l1->vrednost + l2->vrednost);
		l1=l1->sled;
		l2=l2->sled;
	}
	return pom;
}

cvor* oduzmi(cvor* l1, cvor* l2){
	cvor* pom = NULL;
	while (l1 != NULL){
		pom = dodaj_na_kraj(pom, l1->vrednost - l2->vrednost);
		l1=l1->sled;
		l2=l2->sled;
	}
	return pom;
}

cvor* mnozi(cvor* lista, double n){
	
	cvor* pom = lista;
	while(pom!=NULL){
		pom->vrednost = pom->vrednost*n;
		pom = pom->sled;
	}
	return lista;
}

double skalarni_p(cvor* l1, cvor* l2){
	double s=0;
	while(l1 !=  NULL){
		s+= l1->vrednost*l2->vrednost;
		l1=l1->sled;
		l2=l2->sled;
	}
	return s;
}

double norma(cvor* l1){
	cvor* pom = l1;
	double s=0;
	while(pom!=NULL){
		s += pom->vrednost*pom->vrednost;
		pom=pom->sled;
	}

	return sqrt(s);

}

//TODO : implementiraj tacan ugao

double nadji_ugao(cvor* l1, cvor* l2){
	
	double k = skalarni_p(l1, l2)/(norma(l1) * norma(l2));

	return acos(k);
	
}

//klasa ekvivalencije

void klasa(cvor* l1, cvor* l2){
	double k = l2->vrednost / l1->vrednost;


	cvor* pom1 = l1;
	cvor* pom2 = l1;

	while(pom1!=NULL){
		
		if ((pom1->vrednost*k == pom2->vrednost)) {
			printf("False\n");
			break;
		}
		else{
			pom1=pom1->sled;
			pom2=pom2->sled;
		}
	}
	if (pom1 == NULL) printf("True\n");
}











void ispisi(cvor* lista){
	
	printf("<");
	cvor* pom = lista;
	while (pom->sled != NULL){
		printf("%.2lf, ", pom->vrednost);
		pom = pom->sled;
	}
	printf("%.2lf>\n", pom->vrednost);
}

















