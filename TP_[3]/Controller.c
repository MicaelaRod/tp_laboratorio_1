#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* recibe la ruta del archivo por referencia.
 * \param pArrayListPassenger LinkedList* recibe la linkedList por referencia.
 * \return int retorna -1 si no se pudo hacer la carga, y si se pudo retorna 0
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int retorno = -1;


	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			retorno = parser_PassengerFromText(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
		}
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char* recibe la ruta del archivo por referencia.
 * \param pArrayListPassenger LinkedList* recibe la linkedList por referencia.
 * \return int retorna -1 si no se pudo hacer la carga, y si se pudo retorna 0
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int retorno = -1;


	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo != NULL)
		{
			retorno = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
		}
	}

    return retorno;
}

/**
 * Agrega un pasajero a la linkedList
 * param pArrayListPassenger recibe la linkedList por referencia.
 * return retorna -1 si no se pudo agregar, y si se pudo retorna 0
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pNuevoPasajero;
	int retorno = -1;
	char idActualizado[20];

	if(pArrayListPassenger != NULL)
	{
		if(!encontrarUltimoId("ultimoId.csv", idActualizado))
		{
			pNuevoPasajero = crearPasajero(idActualizado);
			if(pNuevoPasajero != NULL)
			{
				if(!ll_add(pArrayListPassenger, pNuevoPasajero))
				{
					incrementarId(idActualizado);
					actualizarId("ultimoId.csv", idActualizado);
					retorno = 0;
				}
				else
				{
					Passenger_delete(pNuevoPasajero);
				}
			}
		}
	}



    return retorno;
}

/**
 * Edita los datos de un pasajero de la linkedList
 * param pArrayListPassenger recibe la linkedList por referencia.
 * return retorna -1 si no se pudo modificar, y si se pudo retorna 0.
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pPasajeroAModificar;
	int idDelPasajero = 999;
	int indiceDelPasajero;
	int retorno=-1;


	if(!ll_isEmpty(pArrayListPassenger) && pArrayListPassenger != NULL)
	{
		if(!tomarEntero(&idDelPasajero, "\nIngrese el ID del pasajero a modificar: ", "ERROR.", 1, 10000, 3))
		{
			indiceDelPasajero = buscarPasajeroPorId(pArrayListPassenger, idDelPasajero);
			if(indiceDelPasajero != -1)
			{
				pPasajeroAModificar = (Passenger*) ll_get(pArrayListPassenger, indiceDelPasajero);
				Passenger_printOne(pPasajeroAModificar);
				retorno = Passenger_edit(pPasajeroAModificar);

			}
			else
			{
				printf("El id no existe.\n");
				system("pause");
			}
		}
	}


    return retorno;
}

/**
 * Remueve un pasajero de la LinkedList.
 * param pArrayListPassenger recibe la linkedList por referencia.
 * return retorna -1 si no se pudo eliminar, y si se pudo retorna 0
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pPasajeroAEliminar;
	int idDelPasajero;
	int indiceDelPasajero;
	int retorno;

	retorno = -1;

	if(!ll_isEmpty(pArrayListPassenger) && pArrayListPassenger != NULL)
	{
		if(!tomarEntero(&idDelPasajero, "\nIngrese el ID del pasajero a eliminar: ", "ERROR.", 1, 10000, 3))
		{
			indiceDelPasajero = buscarPasajeroPorId(pArrayListPassenger, idDelPasajero);
			if(indiceDelPasajero != -1)
			{
				pPasajeroAEliminar = (Passenger*) ll_get(pArrayListPassenger, indiceDelPasajero);
				Passenger_printOne(pPasajeroAEliminar);
				printf("Dara la baja del pasajero\n");
				if(verificarRespuesta())
				{
					ll_remove(pArrayListPassenger, indiceDelPasajero);
					Passenger_delete(pPasajeroAEliminar);
					retorno = 0;
				}
			}
			else
			{
				printf("\nEl id ingresado no existe.\n\n");
				system("pause");
			}
		}
	}


    return retorno;
}

/**
 * Lista todos los pasajeros de la linkedList.
 * param pArrayListPassenger recibe la linkedList por referencia.
 * return retorna -1 si no se pudo listar, y si se pudo retorna 0
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* UnPasajero;
	int longitud;
	int retorno = -1;

	longitud = ll_len(pArrayListPassenger);

    if(pArrayListPassenger != NULL && longitud > 0)
    {
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("|id\t|Nombre\t\t|Apellido\t|Precio\t   |Tipo De Pasajero |Codigo De Vuelo|Estado de Vuelo|\n");
		printf("------------------------------------------------------------------------------------------------------\n");

		for(int i=0; i < longitud; i++)
		{
			UnPasajero = (Passenger*)ll_get(pArrayListPassenger, i);

			Passenger_print(UnPasajero);
		}

		retorno = 0;
    }

    return retorno;

}


/**
 * Ordena los pasajeros de la LinkedList por el criterio seleccionado.
 * param pArrayListPassenger recibe la linkedList por referencia.
 * return retorna -1 si no se pudo ordenar, y si se pudo retorna 0
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int opcion;

	if(pArrayListPassenger != NULL)
	{
		opcion = Passenger_subMenuOrdenar();

		retorno = Passenger_sort(pArrayListPassenger, opcion);
	}


    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList* recibe la linkedList por referencia.
 * \return int retorna -1 si no se pudo guardar, y si se pudo retorna 0.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{

	int retorno = -1;
	FILE* pArchivo;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL)
		{
			retorno= guardarComoTexto(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
		}
	}


    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList* recibe la linkedList por referencia.
 * \return int retorna -1 si no se pudo guardar, y si se pudo retorna 0.
 */
int guardarComoTexto (FILE* pArchivo, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int longitud;
	Passenger* pPasajero;
	int idAGuardar;
	char nombreAGuardar[130];
	char apellidoAGuardar[130];
	float precioAGuardar;
	int tipoDePasajeroAGuardar;
	char codigoVueloAGuardar[10];
	int estadoDeVueloAGuardar;

	longitud = ll_len(pArrayListPassenger);

	if(pArchivo != NULL && pArrayListPassenger != NULL)
	{
		fprintf(pArchivo, "id,name,lastname,price,flycode,typePassenger,statusFlight");
		for(int i = 0; i < longitud; i++)
		{
			pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(!Passenger_getAll(pPasajero, &idAGuardar, nombreAGuardar, apellidoAGuardar, &precioAGuardar, &tipoDePasajeroAGuardar, codigoVueloAGuardar, &estadoDeVueloAGuardar) && fprintf(pArchivo,"%d,%s,%s,%f,%d,%s,%d,\n", idAGuardar, nombreAGuardar, apellidoAGuardar, precioAGuardar, tipoDePasajeroAGuardar, codigoVueloAGuardar, estadoDeVueloAGuardar))
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char* recibe la ruta del archivo por referencia.
 * \param pArrayListPassenger LinkedList* recibe la linkedList por referencia.
 * \return int retorna -1 si no se pudo guardar, y si se pudo retorna 0.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int retorno;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "wb");

		if (pArchivo != NULL)
		{
			retorno = guardarComoBinario(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
		}
	}
    return retorno;


    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char* recibe la ruta del archivo por referencia.
 * \param pArrayListPassenger LinkedList* recibe la linkedList por referencia.
 * \return int retorna -1 si no se pudo guardar, y si se pudo retorna 0.
 *
 */
int guardarComoBinario(FILE* pArchivo, LinkedList* pArrayListPassenger)
{
	int retorno= -1;
	int len;
	Passenger* pPasajero;

	len = ll_len(pArrayListPassenger);

	if (pArchivo != NULL && pArrayListPassenger != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{

			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			fwrite(pPasajero, sizeof(Passenger), 1, pArchivo);

		}

		retorno = 0;
	}

	return retorno;
}

/**
 * Buscar el ultimo id en un archivo.csv para asignarlo a los nuevos pasajeros de alta.
 * param path recibe la ruta del archivo donde esta el utlimo id por referencia.
 * param id Pasa el id por referencia en modo cadena de texto.
 * return retorna -1 si no pudo encontrar el id, si puede retorna 0.
 */
int encontrarUltimoId(char* path, char* id)
{
	int retorno = -1;
	FILE* pArchivo = NULL;


	if(path != NULL && id != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			fscanf(pArchivo, "%[^\n]\n", id);
			retorno = 0;
			fclose(pArchivo);
		}
	}

	return retorno;
}
/**
 * Incrementa el id que le llegue por referencia(modo cadena de texto).
 * param id
 * return retorna -1 si no se pudo hacer el incremento o retorna 0 si pudo.
 */
int incrementarId(char* id)
{
	int retorno = -1;
	int idAumentar;

	if(id != NULL)
	{
		idAumentar = atoi(id);
		idAumentar++;
		itoa(idAumentar, id, 10);
		retorno = 0;
	}

	return retorno;
}

/**
 * Actualiza el id del documento .csv.
 * param path recibe la ruta del archivo donde esta el utlimo id por referencia.
 * param id recibe el nuevo id a guardar.
 * return retorna 0 si pudo actualizarlo o -1 si no fue posible.
 */
int actualizarId(char* path, char* id)
{
	int retorno=-1;
	FILE* pArchivo;

	if(path != NULL)
	{
		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			fprintf(pArchivo, "%s\n", id);
			retorno = 0;
			fclose(pArchivo);
		}
	}

	return retorno;
}




