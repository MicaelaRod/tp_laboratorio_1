#include <string.h>
#include "datawarehouse.h"
#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>

char codigosDeVuelo[10] [20] =
       {"Brasil",
		"Chile",
		"Ee.uu",
		"Uruguay",
		"Usuahia",
		"Bolivia",
		"Peru",
		"Paraguay",
		"Canada",
		"China"};

char nombres [10] [20] ={
		"Juan",
		"Pedro",
		"Sofia",
		"Valentina",
		"Micaela",
		"Soledad",
		"Leandro",
		"Benjamin",
		"Matias",
		"Sara"
};

char apellidos [10] [20] ={
		"Rodriguez",
		"Perez",
		"Vargas",
		"Gomez",
		"Rojas",
		"Zacarias",
		"Garofalo",
		"Pozzo",
		"Fernandez",
		"Medina"
};

float precios [10] = {100.65,112.70,134.80,124.25,175.90,187.95,111.87,132.78,124.45,199.56};


int idTipo[10] = {1,3,2,4,1,2,3,2,4,1};

int hardcodear(ePassenger lista[],int tam,int cant,int* pId){

	int contador = -1;

	if(lista != NULL && tam > 0 && cant >=0 && cant <= tam && pId != NULL){
		contador = 0;
		for(int i=0;i<cant;i++){
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].name,nombres[i]);
			strcpy(lista[i].lastName,apellidos[i]);
			lista[i].price = precios[i];
			strcpy(lista[i].flycode,codigosDeVuelo[i]);
			lista[i].idtypePassenger = idTipo[i];
			lista[i].isEmpty = 0;
			contador++;
		}
	}


	return contador;
}



