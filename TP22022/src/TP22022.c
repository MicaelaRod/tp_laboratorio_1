#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "datawarehouse.h"
#include "utn.h"
#include "tipo.h"


#define TAM 10
#define TAMT 4


int main(void) {
	setbuf(stdout, NULL);

	char seguir = 's';
	char salir;
	int flag1 = 0;
	int nextId = 1000;
	ePassenger lista[TAM];



	eTipo tipos[TAMT] ={
			{1,"1ra clase"},
			{2,"Ejecutiva"},
			{3,"Premium"},
			{4,"Turista"}
	};


	inicializar(lista,TAM);


	hardcodear(lista,TAM,7,&nextId);

	do {
		switch (menu()) {
		case 1:
			addPassengers(lista,TAM,&nextId,tipos,TAMT);
			flag1 = 1;
			break;
		case 2:
			if (flag1) {
				modificar(lista,TAM,tipos,TAMT);
			} else {
				printf("Primero deberia ingresar la opcion 1\n");
			}
			break;
		case 3:
			if (flag1) {
				removePassenger(lista,TAM,tipos,TAMT);
			} else {
				printf("Primero deberia ingresar la opcion 1\n");
			}
			break;
		case 4:
			if (flag1) {

				switch(menuInformar()){
				case 1:
				sortPassengers(lista,TAM,tipos,TAMT);
				printPassengers(lista,TAM,tipos,TAMT);
					break;
				case 2:
				 mostrarPromedioPrecio(lista,TAM);
					break;


				}



			} else {
				printf("Primero deberia ingresar la opcion 1\n");
			}

			break;
		case 5:
			printf("Esta seguro que quiere salir?\n");
			fflush(stdin);
			scanf("%c", &salir);

			if (salir == 's' || salir == 'S') {
				seguir = 'n';
				printf("Usted salio\n");

			} else {
				printf("Sigue en el menu.\n");
			}

			break;

		default:
			printf("Opcion invalida\n");

		}

		system("pause");

	} while (seguir == 's');

	return EXIT_SUCCESS;
}


