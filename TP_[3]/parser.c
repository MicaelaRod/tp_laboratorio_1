#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "validaciones.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListPassenger LinkedList* recibe por referencia la linked list
 * \return int retorna -1 si no se pudo hacer el parseo, y si se pudo retorna 0
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	char id[100];
	char nombre[100];
	char apellido[100];
	char precio[100];
	char tipoDePasjero[100];
	char codigoVuelo[100];
	char estadoDeVuelo[100];
	char auxIdTipo[100];
	char auxIdEstado[100];
	Passenger* unPasajero;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoDePasjero,estadoDeVuelo);


		while(!feof(pFile))
		{

			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoDePasjero,estadoDeVuelo) == 7 &&
																 esNumerica(id) &&
																 esNombre(nombre, strlen(nombre)) &&
																 esNombre(apellido, strlen(apellido))&&
																 esFlotante(precio)&&
																 !convertirDescripcionEnIdTipoDePasajero(tipoDePasjero, auxIdTipo)&&
																 esNumerica(auxIdTipo)&&
																 !convertirDescripcionEnIdEstadoDeVuelo(estadoDeVuelo, auxIdEstado)&&
																 esNumerica(auxIdEstado)&&
							 									 esFlycode(codigoVuelo, strlen(codigoVuelo)))
			{

				unPasajero = Passenger_newParametros(id, nombre, apellido, precio, auxIdTipo, codigoVuelo, auxIdEstado);
				if(unPasajero != NULL)
				{

					if(ll_add(pArrayListPassenger, unPasajero) != -1)
					{
						retorno = 0;
					}
					else
					{
						Passenger_delete(unPasajero);

					}
				}
			}
		}
	}


    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListPassenger LinkedList* recibe por referencia la linked list
 * \return int retorna -1 si no se pudo hacer el parseo, y si se pudo retorna 0
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* unPasajero;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
			while(!feof(pFile))
			{
				unPasajero = Passenger_new();

				if(unPasajero != NULL && fread(unPasajero, sizeof(Passenger), 1, pFile) == 1)
				{
					if(ll_add(pArrayListPassenger, unPasajero) != -1)
					{
						retorno = 0;
					}
					else
					{
						Passenger_delete(unPasajero);
					}
				}
			}
	}


    return retorno;
}
