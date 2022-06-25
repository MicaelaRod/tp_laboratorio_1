/*
 * calculos.c
 *
 *  Created on: 11 abr. 2022
 *      Author: micar
 */
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

//a
int realizarDescuento(float numero, float* final){

	int todoOk =0;
	float descuento;

	if(numero > 0 && final != NULL){


		descuento = numero * 0.1;

		*final = numero - descuento;

		todoOk =1;
	}

	return todoOk;
}
//b
int realizarAumento(float numero, float* final){

	int todoOk =0;
	float aumento;

	if(final != NULL && numero > 0){


	aumento = numero * 0.25;

	*final = numero + aumento;

	todoOk = 1;

	}

	return todoOk;
}
//c
float transformarPesos(float pesos){

	float bitCoin;

	bitCoin = (float) pesos / 4606954.55;

	return bitCoin;
}

//d

int mostrarPrecioUnitario(float km, float precio, float* precioUnidad){

	int todoOk = 0;

	if(km >= 0 && precio > 0 && precioUnidad != NULL){

		*precioUnidad = (float) precio/km;


		todoOk = 1;
	}


	return todoOk;
}

//e

int diferenciaPrecio(float latam, float aerolineas, float* final){

	int todoOk = 0;

	if(latam >= 0 && aerolineas >= 0 && final != NULL){

		if(latam > aerolineas){
			*final = latam - aerolineas;
		}
		else{
			*final = aerolineas - latam;
		}
		todoOk = 1;
	}

	return todoOk;
}
