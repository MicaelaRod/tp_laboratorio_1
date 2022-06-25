
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"


int getString(char cadena[], int tam, char *mensaje) {

	int todoOk = 0;

	if (cadena != NULL && tam > 0) {

		char auxCad[100]; //para validarlo

		puts(mensaje);

		fflush(stdin);

		gets(auxCad);

		while (strlen(auxCad) > tam) { //entro al bucle si esta mal ingresado el nombre

			printf("Nombre muy largo. Reingrese nombre\n");

			fflush(stdin);

			gets(auxCad);

		}

		strcpy(cadena, auxCad);

		todoOk = 1;
	}

	return todoOk;
}

char getChar(char* mensaje,char* mensajeError,char parametro1,char parametro2)
{
    char x;

    puts(mensaje);
    fflush(stdin);
    scanf("%c",&x);

    while(x != parametro1 && x != parametro2){

    	puts(mensajeError);
		fflush(stdin);
		scanf("%c", &x);

    }

    return x;
}

int getInt(char* mensaje, char* mensajeError,int maximo, int minimo)
{
    int numero;

    puts(mensaje);
    scanf("%d",&numero);

    while(numero > maximo || numero < minimo){

    	puts(mensajeError);
    	scanf("%d",&numero);

    }

    return numero;
}

float getFloat(char* mensaje, char* mensajeError,float maximo, float minimo)
{
    float numero;

    puts(mensaje);
    scanf("%f",&numero);

    while(numero > maximo || numero < minimo){

    	puts(mensajeError);
    	scanf("%f",&numero);

    }

    return numero;
}

