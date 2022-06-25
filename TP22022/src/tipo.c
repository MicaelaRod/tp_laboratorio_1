#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"

int cargarDescripcionT(eTipo tipos[],int tam,int idTipo,char descripcion[]){
	int todoOk =0;

	if(tipos != NULL && tam>0 && descripcion != NULL){

		for(int i=0;i<tam;i++){
			if(tipos[i].id == idTipo){
				strcpy(descripcion,tipos[i].descripcion);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}

int mostrarTipos(eTipo tipos[], int tam) {

	int todoOk = 0;

	if (tipos != NULL && tam > 0) {

		printf("***Tipos***\n");

		printf("-----------------------------\n");

		printf("   ID     DESCRIPCION\n");

		printf("------------------------------\n");

		for (int i = 0; i < tam; i++) {

			printf("  %d    %-10s\n", tipos[i].id,
					tipos[i].descripcion);

		}

		todoOk = 1;
	}

	return todoOk;
}

