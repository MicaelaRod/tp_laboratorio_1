
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "validaciones.h"

/**
 * Guarda espacio en memoria para el dato de tipo Passenger
 * return retorna el puntero que apunta a la direccion de memoria reservada.
 */
Passenger* Passenger_new()
{
	Passenger* pNuevoPasajero = NULL;

	pNuevoPasajero = (Passenger*)malloc(sizeof(Passenger));

	return pNuevoPasajero;
}
/**
 * Setea por completo un nuevo pasajero, conviertiendo sus respectivos datos en lo que corresponda(int, float, etc).
 * param idStr recibe el id como cadena de texto.
 * param nombreStr recibe el nombre como cadena de texto.
 * param apellidoStr recibe el apellido como cadena de texto.
 * param precioStr recibe el precio como cadena de texto.
 * param tipoPasajeroStr recibe el tipo de pasajero como cadena de texto.
 * param codigoDeVueloStr recibe el codigo de vuelo como cadena de texto.
 * param estadoDeVueloStr recibe el estado del vuelo como cadena de texto.
 * return pNuevoPasajero
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr,char* precioStr ,char* tipoPasajeroStr, char* codigoDeVueloStr, char* estadoDeVueloStr)
{
	Passenger* pNuevoPasajero;
	Passenger* pPasajeroAux;
	int idAux;
	float precioAux;
	int tipoPasajeroAux;
	int estadoDeVueloAux;

	pPasajeroAux = Passenger_new();
	pNuevoPasajero = NULL;


	if(pPasajeroAux != NULL)
	{
		idAux = atoi(idStr);
		precioAux = atof(precioStr);
		tipoPasajeroAux = atoi(tipoPasajeroStr);
		estadoDeVueloAux = atoi(estadoDeVueloStr);


		if(!Passenger_setAll(pPasajeroAux, idAux, nombreStr, apellidoStr, precioAux, tipoPasajeroAux, codigoDeVueloStr, estadoDeVueloAux))
		{
			pNuevoPasajero = pPasajeroAux;
		}
		else
		{
			Passenger_delete(pPasajeroAux); //Libero el espacio si falla algo en el seteo.

		}
	}

	return pNuevoPasajero;
}

/**
 * Libera el espacio en memoria de un tipo de dato Passenger.
 * @param this recibe el puntero al espacio en memoria.
 */
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
/**
 * Setea el id en una estructura Passenger.
 * param this recibe el pasajero donde se seteara el id.
 * param id recibe el id que se le asignara
 * return retorna 0 si se pudo realizar el seteo, caso contrario retorna -1.
 */
int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
/**
 * Trae el id de un pasajero y lo pasa por referencia.
 * param this Pasajero de donde se extraera el id.
 * param id lugar donde se guardara el id.
 * return retorna -1 si no pudo traerse el dato o 0 si se pudo.
 */
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
/**
 * Setea el nombre en una estructura Passenger.
 * param this recibe el pasajero donde se seteara el nombre.
 * param nombre recibe el nombre que se le asignara
 * return retorna 0 si se pudo realizar el seteo, caso contrario retorna -1.
 */
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}


	return retorno;
}
/**
 * Trae el nombre de un pasajero y lo pasa por referencia.
 * param this Pasajero de donde se extraera el nombre.
 * param nombre lugar donde se guardara el nombre.
 * return retorna -1 si no pudo traerse el dato o 0 si se pudo.
 */
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

/**
 * Setea el apellido en una estructura Passenger.
 * param this recibe el pasajero donde se seteara el apellido.
 * param apellido recibe el apellido que se le asignara
 * return retorna 0 si se pudo realizar el seteo, caso contrario retorna -1.
 */
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}


	return retorno;
}
/**
 * Trae el apellido de un pasajero y lo pasa por referencia.
 * param this Pasajero de donde se extraera el apellido.
 * param apellido lugar donde se guardara el apellido.
 * return retorna -1 si no pudo traerse el dato o 0 si se pudo.
 */
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}
/**
 * Setea el codigo de vuelo en una estructura Passenger.
 * param this recibe el pasajero donde se seteara el codigo de vuelo.
 * param codigoVuelo recibe el codigo de vuelo que se le asignara
 * return retorna 0 si se pudo realizar el seteo, caso contrario retorna -1.
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}


	return retorno;
}
/**
 * Trae el codigo de vuelo de un pasajero y lo pasa por referencia.
 * param this Pasajero de donde se extraera el codigo de vuelo.
 * param codigoVuelo lugar donde se guardara el codigo de vuelo.
 * return retorna -1 si no pudo traerse el dato o 0 si se pudo.
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
/**
 * Setea el tipo de pasajero en una estructura Passenger.
 * param this recibe el pasajero donde se seteara el tipo de pasajero.
 * param tipoPasajero recibe el tipo de pasajero que se le asignara
 * return retorna 0 si se pudo realizar el seteo, caso contrario retorna -1.
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero >= 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
/**
 * Trae el tipo de pasajero de un pasajero y lo pasa por referencia.
 * param this Pasajero de donde se extraera el tipo de pasajero.
 * param tipoPasajero lugar donde se guardara el tipo de pasajero.
 * return retorna -1 si no pudo traerse el dato o 0 si se pudo.
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
/**
 * Setea el estado de vuelo en una estructura Passenger.
 * @param this recibe el pasajero donde se seteara el estado de vuelo.
 * @param estadoDeVuelo recibe el estado de vuelo que se le asignara
 * @return retorna 0 si se pudo realizar el seteo, caso contrario retorna -1.
 */
int Passenger_setEstadoDeVuelo(Passenger* this,int estadoDeVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoDeVuelo >= 0)
	{
		this->estadoDeVuelo = estadoDeVuelo;
		retorno = 0;
	}

	return retorno;
}
/**
 * Trae el estado de vuelo de un pasajero y lo pasa por referencia.
 * @param this Pasajero de donde se extraera el estado de vuelo.
 * @param estadoDeVuelo lugar donde se guardara el estado de vuelo.
 * @return retorna -1 si no pudo traerse el dato o 0 si se pudo.
 */
int Passenger_getEstadoDeVuelo(Passenger* this,int* estadoDeVuelo)
{
	int retorno = -1;


	if(this != NULL && estadoDeVuelo != NULL)
	{
		*estadoDeVuelo = this->estadoDeVuelo;
		retorno = 0;
	}

	return retorno;
}
/**
 * Setea el precio en una estructura Passenger.
 * @param this recibe el pasajero donde se seteara el precio.
 * @param precio recibe el precio que se le asignara
 * @return retorna 0 si se pudo realizar el seteo, caso contrario retorna -1.
 */
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
/**
 * Trae el precio de un pasajero y lo pasa por referencia.
 * @param this Pasajero de donde se extraera el precio.
 * @param precio lugar donde se guardara el precio.
 * @return retorna -1 si no pudo traerse el dato o 0 si se pudo.
 */
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}
/**
 * Setea todos los datos de una estructura Passenger.
 * @param this recibe la estructura a la que se le hara el seteo.
 * @param id recibe el id que se le asignara
 * @param nombre recibe el nombre que se le asignara
 * @param apellido recibe el apellido que se le asignara
 * @param precio recibe el precio que se le asignara
 * @param tipoPasajero recibe el tipo de pasajero que se le asignara
 * @param codigoDeVuelo recibe el codigo de vuelo que se le asignara
 * @param estadoDeVuelo recibe el estado de vuelo que se le asignara
 * @return devuelve 0 si el seteo salio bien, sino retorna -1.
 */
int Passenger_setAll(Passenger* this, int id,char* nombre, char* apellido,float precio ,int tipoPasajero, char* codigoDeVuelo, int estadoDeVuelo)
{
	int retorno = -1;

	if(this != NULL &&
			!Passenger_setId(this, id) &&
			!Passenger_setNombre(this, nombre) &&
			!Passenger_setApellido(this, apellido) &&
			!Passenger_setPrecio(this, precio) &&
			!Passenger_setTipoPasajero(this, tipoPasajero) &&
			!Passenger_setCodigoVuelo(this, codigoDeVuelo) &&
			!Passenger_setEstadoDeVuelo(this, estadoDeVuelo))
	{
		retorno = 0;
	}


	return retorno;
}
/**
 * Trae todos los datos de una estructura para poder mostrarlos o utilizarlos.
 * @param this recibe la estructura de donde se traeran los datos.
 * @param id  lugar donde se guardara el id
 * @param nombre lugar donde se guardara el nombre
 * @param apellido lugar donde se guardara el apellido
 * @param precio lugar donde se guardara el precio
 * @param tipoPasajero lugar donde se guardara el tipo de pasajero
 * @param codigoDeVuelo lugar donde se guardara el codigo de vuelo
 * @param estadoDeVuelo lugar donde se guardara el estado de vuelo
 * @return retorna -1 si no se pudieron traer los datos o 0 si se pudo.
 */
int Passenger_getAll(Passenger* this, int* id, char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoDeVuelo, int* estadoDeVuelo)
{
	int retorno = -1;


	if(this != NULL && !Passenger_getId(this, id) &&
					   !Passenger_getNombre(this, nombre) &&
					   !Passenger_getApellido(this, apellido) &&
					   !Passenger_getPrecio(this, precio) &&
					   !Passenger_getTipoPasajero(this, tipoPasajero) &&
					   !Passenger_getCodigoVuelo(this, codigoDeVuelo) &&
					   !Passenger_getEstadoDeVuelo(this, estadoDeVuelo))
	{
		retorno = 0;
	}


	return retorno;
}
/**
 * Imprime de una forma que sirve para listar todos los pasajeros cuando el controller la llame.
 * param unPasajero pasajero del que se imprimiran los datos.
 * return retorna -1 si no se pudo imprimir o 0 si se pudo.
 */
int Passenger_print(Passenger* unPasajero)
{
	int id=3;
	char nombre[50];
	char apellido[50];
	float precio;
	int idTipoPasajero;
	char tipoDePasajero[50];
	int idEstadoDeVuelo;
	char estadoDeVuelo[50];
	char codigoDeVuelo[10];


	int retorno = -1;


	if(!Passenger_getAll(unPasajero, &id, nombre, apellido, &precio, &idTipoPasajero, codigoDeVuelo, &idEstadoDeVuelo))
	{
		convertirIdEnDescripcionEstadoDeVuelo(idEstadoDeVuelo, estadoDeVuelo);
		convertirIdEnDescripcionTipoDePasajero(idTipoPasajero, tipoDePasajero);
		printf("|%-7d|%-15s|%-15s|%-10.2f|%-16s |%-14s |%-15s|\n", id, nombre, apellido, precio, tipoDePasajero, codigoDeVuelo, estadoDeVuelo);
		printf("------------------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}

	return retorno;
}
/**
 * Imprime un solompasajero
 * @param unPasajero pasajero a imprimir
 * @return retorna -1 si no se pudo imprimir o 0 si se pudo.
 */
int Passenger_printOne(Passenger* unPasajero)
{
	int id=3;
	char nombre[50];
	char apellido[50];
	float precio;
	int idTipoPasajero;
	char tipoDePasajero[50];
	int idEstadoDeVuelo;
	char estadoDeVuelo[50];
	char codigoDeVuelo[10];


	int retorno = -1;


	if(!Passenger_getAll(unPasajero, &id, nombre, apellido, &precio, &idTipoPasajero, codigoDeVuelo, &idEstadoDeVuelo))
	{
		convertirIdEnDescripcionEstadoDeVuelo(idEstadoDeVuelo, estadoDeVuelo);
		convertirIdEnDescripcionTipoDePasajero(idTipoPasajero, tipoDePasajero);
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("|id\t|Nombre\t\t|Apellido\t|Precio\t   |Tipo De Pasajero |Codigo De Vuelo|Estado de Vuelo|\n");
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("|%-7d|%-15s|%-15s|%-10.2f|%-16s |%-14s |%-15s|\n", id, nombre, apellido, precio, tipoDePasajero, codigoDeVuelo, estadoDeVuelo);
		printf("------------------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}

	return retorno;
}
/**
 * Convierte la cadena de texto que viene del .csv como tipo de pasajero en un id para poder utilizarlo mas facilmente.
 * @param texto recibe el texto que se quiere pasa a id.
 * @param idCorrespondiente devuelve por referencia el id corespondiente al texto que llegue.
 * @return retorna -1 si no se pudo hacer la conversion y 0 si se pudo.
 */
int convertirDescripcionEnIdTipoDePasajero(char* texto, char* idCorrespondiente)
{
	int retorno = -1;

	if(texto != NULL && idCorrespondiente != NULL)
	{
		if(strcmp(texto, "EconomyClass")== 0)
		{
			itoa(1, idCorrespondiente, 10);
			retorno =  0;
		}
		else
		{
			if(strcmp(texto, "ExecutiveClass")== 0)
			{
				itoa(2, idCorrespondiente, 10);
				retorno =  0;
			}
			else
			{
				if(strcmp(texto, "FirstClass")== 0)
				{
					itoa(3, idCorrespondiente, 10);
					retorno =  0;
				}
			}
		}
	}

	return retorno;
}
/**
 * Convierte la cadena de texto que viene del .csv como estado de vuelo en un id para poder utilizarlo mas facilmente.
 * @param texto recibe el texto que se quiere pasa a id.
 * @param idCorrespondiente devuelve por referencia el id corespondiente al texto que llegue.
 * @return retorna -1 si no se pudo hacer la conversion y 0 si se pudo.
 */
int convertirDescripcionEnIdEstadoDeVuelo(char* texto, char* idCorrespondiente)
{
	int retorno;

	if(texto != NULL && idCorrespondiente != NULL)
		{
			if(strcmp(texto, "Aterrizado")== 0)
			{
				itoa(1, idCorrespondiente, 10);
				retorno =  0;
			}
			else
			{
				if(strcmp(texto, "Demorado")== 0)
				{
					itoa(2, idCorrespondiente, 10);
					retorno =  0;

				}
				else
				{
					if(strcmp(texto, "En Horario")== 0)
					{
						itoa(3, idCorrespondiente, 10);
						retorno =  0;
					}
					else
					{
						if(strcmp(texto, "En Vuelo")== 0)
						{
							itoa(4, idCorrespondiente, 10);
							retorno =  0;
						}
					}
				}
			}
		}


	return retorno;
}
/**
 * Convierte un id en texto dependiento al tipo de vuelo que le corresponda.
 * @param id recibe id a convertir en texto.
 * @param descripcionCorrespondiente devuelve por referencia el tipo de vuelo correspondite al id.
 * @return retorna -1 si no se pudo hacer la conversion y 0 si se pudo.
 */
int convertirIdEnDescripcionTipoDePasajero(int id, char* descripcionCorrespondiente)
{
	int retorno = -1;

	if(id > 0 && descripcionCorrespondiente != NULL)
	{
		switch(id)
		{
		case 1:
			strcpy(descripcionCorrespondiente, "EconomyClass");
			retorno = 0;
			break;
		case 2:
			strcpy(descripcionCorrespondiente, "ExecutiveClass");

			retorno = 0;
			break;
		case 3:
			strcpy(descripcionCorrespondiente, "FirstClass");

			retorno = 0;
			break;
		}
	}

	return retorno;
}
/**
 * Convierte un id en texto dependiento al estado de vuelo que le corresponda.
 * @param id recibe id a convertir en texto.
 * @param descripcionCorrespondiente devuelve por referencia el estado de vuelo correspondite al id.
 * @return retorna -1 si no se pudo hacer la conversion y 0 si se pudo.
 */
int convertirIdEnDescripcionEstadoDeVuelo(int id, char* descripcionCorrespondiente)
{
	int retorno = -1;

	if(id > 0 && descripcionCorrespondiente != NULL)
	{
		switch(id)
		{
		case 1:
			strcpy(descripcionCorrespondiente, "Aterrizado");

			retorno = 0;
			break;
		case 2:
			strcpy(descripcionCorrespondiente, "Demorado");

			retorno = 0;
			break;
		case 3:
			strcpy(descripcionCorrespondiente, "En Horario");
			retorno = 0;
			break;
		case 4:
			strcpy(descripcionCorrespondiente, "En Vuelo");
			retorno = 0;
			break;
		}
	}

	return retorno;
}
/**
 * Lista los tipos de pasajero disponibles con sus ids.
 * @pre
 * @post
 */
void listarTiposDePasajero()
{
	printf("\n-----------------------------------------");
	printf("\n|Numero\t|\tTipo De Pasajero\t|\n");
	printf("-----------------------------------------");
	printf("\n|   1\t|\tEconomyClass\t\t|");
	printf("\n|   2\t|\tExecutiveClass\t\t|");
	printf("\n|   3\t|\tFirstClass\t\t|\n");
	printf("-----------------------------------------\n");

}
/**
 * Lista los estados de vuelo disponibles con sus ids.
 * @pre
 * @post
 */
void listarEstadosDeVuelo()
{
	printf("\n-----------------------------------------");
	printf("\n|Numero\t|\tEstados De Vuelo\t|\n");
	printf("-----------------------------------------");
	printf("\n|   1\t|\tAterrizado\t\t|");
	printf("\n|   2\t|\tDemorado\t\t|");
	printf("\n|   3\t|\tEn Horario\t\t|");
	printf("\n|   4\t|\tEn Vuelo\t\t|\n");
	printf("-----------------------------------------\n");

}
/**
 * Crea un pasajero pidiendo todos losd datos necesarios
 * @param idActualizado recibe el nuevo id (que esta guardado en el .csv) para el pasajero.
 * @return retorna el nuevo pasajero si se pudo crear, sino NULL.
 */
Passenger* crearPasajero (char* idActualizado)
{
	Passenger* nuevoPasajero = NULL;
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[50];
	char auxTipoDePasajero[50];
	char auxCodigoVuelo[50];
	char auxEstadoVuelo[50];


	if(!tomarString(auxNombre, 28, "\nIngrese el nombre del pasajero: ", "ERROR. \n", 3))
	{
		if(!tomarString(auxApellido, 28, "\nIngrese el apellido del pasajero: ", "ERROR.\n", 3))
		{
			if(!tomarFloatComoTexto(auxPrecio, "\nIngrese el costo del viaje($10000-$500000): $", "ERROR.\n", 10000, 500000, 3))
			{
				listarTiposDePasajero();
				if(!tomarIntComoTexto(auxTipoDePasajero, "Ingrese el numero de tipo de pasajero: ", "ERROR.\n", 1, 3, 3))
				{
					if(!validarFlycode(auxCodigoVuelo, 7, "Ingrese el codigo de vuelo(max 7 caracteres): ", "ERROR.\n", 3))
					{
						listarEstadosDeVuelo();
						if(!tomarIntComoTexto(auxEstadoVuelo, "Ingrese el numero de tipo de pasajero: ", "ERROR.\n", 1, 4, 3))
						{
							nuevoPasajero = Passenger_newParametros(idActualizado, auxNombre, auxApellido, auxPrecio, auxTipoDePasajero, auxCodigoVuelo, auxEstadoVuelo);
						}
					}
				}
			}
		}
	}


	return nuevoPasajero;
}
/**
 * Copia un pasajero en otro.
 * @param pPasajeroDestino Pasajero donde se copiara el pasajero.
 * @param pPasajeroOrigen Pasajero que sera copiado.
 * @return devuelve 0 si se pudo realizar la copia, sino -1.
 */
int copiarPasajero(Passenger* pPasajeroDestino, Passenger* pPasajeroOrigen)
{
	int retorno = -1;

	if(pPasajeroDestino != NULL && pPasajeroOrigen != NULL)
	{
		if(!Passenger_setAll(pPasajeroDestino, pPasajeroOrigen->id, pPasajeroOrigen->nombre, pPasajeroOrigen->apellido, pPasajeroOrigen->precio, pPasajeroOrigen->tipoPasajero, pPasajeroOrigen->codigoVuelo, pPasajeroOrigen->estadoDeVuelo))
		{
			retorno = 0;
		}
	}

	return retorno;
}
/**
 * Busca un Pasajero en la LinkedList a partir de su id
 * @param pArrayListPassenger Recibe la linked list.
 * @param idAEncontrar recibe el id a buscar.
 * @return	devuelve -1 si no se pudo encontrar o 0 si se pudo.
 */
int buscarPasajeroPorId(LinkedList* pArrayListPassenger, int idAEncontrar)
{
	Passenger * pPasajero;
	int len;
	int auxId;
	int retorno = -1;

	len = ll_len(pArrayListPassenger);

	for(int i = 0; i < len; i++)
	{
		pPasajero = (Passenger*)ll_get(pArrayListPassenger,i);

		if(!Passenger_getId(pPasajero, &auxId))
		{
			if(auxId == idAEncontrar)
			{
				retorno = i;
				break;
			}
		}
	}


	return retorno;
}
/**
 * Permite editar los datos de un pasajero.
 * @param pPasajeroAModificar Recibe el pasajero a modificar.
 * @return retorna -1 si no se pudo realizar la modificacion, caso contrario retorna 0.
 */
int Passenger_edit (Passenger* pPasajeroAModificar)
{
	int retorno = -1;
	Passenger* pPasajeroAux;
	int opcionMenu;
	int flagCambios = 0;
	char auxApellido[50];
	char auxNombre[50];
	float auxPrecio;
	int auxTipoDePasajero;
	char auxCodigoVuelo[50];
	int auxEstadoVuelo;

	if(pPasajeroAModificar != NULL)
	{
		pPasajeroAux = Passenger_new();
		if(pPasajeroAux != NULL)
		{
			copiarPasajero(pPasajeroAux, pPasajeroAModificar);
			do{
				opcionMenu = Passenger_subMenuEditar();

				switch(opcionMenu)
				{
				case 1:
					if(!tomarString(auxNombre, 28, "\nIngrese el nombre que desea: ", "ERROR. Ingreso no valido.\n", 3))
					{
						Passenger_setNombre(pPasajeroAux, auxNombre);
						flagCambios = 1;
					}
					break;
				case 2:
					if(!tomarString(auxApellido, 28, "\nIngrese el apellido que desea: ", "ERROR. Ingreso no valido.\n", 3))
					{
						Passenger_setApellido(pPasajeroAux, auxApellido);
						flagCambios = 1;
					}
					break;
				case 3:
					if(!tomarFlotante(&auxPrecio, "\nIngrese el precio que desea($10000-$500000): $", "ERROR. Ingreso no valido.\n", 10000, 500000, 3))
					{
						Passenger_setPrecio(pPasajeroAux, auxPrecio);
						flagCambios = 1;
					}
					break;
				case 4:
					if(!tomarEntero(&auxTipoDePasajero, "\nIngrese el numero de tipo de pasajero: ", "ERROR.Ingreso no valido.\n", 1, 3, 3))
					{
						Passenger_setTipoPasajero(pPasajeroAux, auxTipoDePasajero);
						flagCambios = 1;
					}
					break;
				case 5:
					if(!validarFlycode(auxCodigoVuelo, 7, "Ingrese el codigo de vuelo(max 7 caracteres): ", "ERROR.\n", 3))
					{
						Passenger_setCodigoVuelo(pPasajeroAux, auxCodigoVuelo);
						flagCambios = 1;
					}
					break;
				case 6:
					if(!tomarEntero(&auxEstadoVuelo, "Ingrese el numero de tipo de pasajero: \n", "ERROR.\n", 1, 4, 3))
					{
						flagCambios = 1;
						Passenger_setEstadoDeVuelo(pPasajeroAux, auxEstadoVuelo);
					}
					break;
				case 7:
					if(flagCambios == 1)
					{
						printf("Pasajero sin cambios:\n");
						Passenger_printOne(pPasajeroAModificar);
						printf("Pasajero con cambios:\n");
						Passenger_printOne(pPasajeroAux);
						printf("\nQuiere guardar cambios?");
						if(verificarRespuesta())
						{
							copiarPasajero(pPasajeroAModificar, pPasajeroAux);
							retorno = 0;
						}

						Passenger_delete(pPasajeroAux);

					}
					break;
				}

			}while(opcionMenu != 7);

		}
	}


	return retorno;
}
/**
 * Despliega el submenu con las opciones para editar.
 * @return retorna la opcion elegida por el usuario.
 */
int Passenger_subMenuEditar(void)
{
	int opcion;
	system("cls");
	printf("MENU EDITAR:\n\n");
	printf("1. Modificar nombre.  \n");
	printf("2. Modificar apellido.\n");
	printf("3. Modificar precio.\n");
	printf("4. Modificar el tipo de pasajero.\n");
	printf("5. Modificar el codigo de vuelo.\n");
	printf("6. Modificar el estado del vuelo.\n");
	printf("7. SALIR\n");

	tomarEntero(&opcion, "\nElija una opcion: ", "\nOpcion ingresada no valida. ", 1, 7, 3);

	system("cls");

	return opcion;
}
/**
 * Despliega el submenu con las opciones para ordenar.
 * @return retorna la opcion elegida por el usuario.
 */
int Passenger_subMenuOrdenar(void)
{
	int opcion;
	system("cls");
	printf("MENU ORDENAR:\n\n");
	printf("1. Ordenar por Id.  \n");
	printf("2. Ordenar por nombre.\n");
	printf("3. Ordenar por apellido.\n");
	printf("4. Ordenar por precio.\n");
	printf("5. Ordenar por el tipo de pasajero.\n");
	printf("6. Ordenar por codigo de vuelo.\n");
	printf("7. Ordenar por el estado del vuelo.\n");
	printf("8. SALIR\n");

	tomarEntero(&opcion, "\nElija una opcion: ", "\nOpcion no valida. ", 1, 8, 3);

	system("cls");

	return opcion;
}
/**
 * Ordena los pasajeros por diferentes criterios.
 * @param pArrayListPassenger recibe la linkedList
 * @param opcion recibe la opcion de orden que elija el usuario.
 * @return devuelve 0 si la lista fue ordenada, sino 0.
 */
int Passenger_sort(LinkedList* pArrayListPassenger , int opcion)
{
	int retorno = -1;
	int ordenamiento;

	switch(opcion)
	{
	case 1:
		if(!tomarEntero(&ordenamiento, "0-Orden Descendente\n1-Orden Ascendente\nOrden: ", "ERROR. Ingreso no valido", 0, 1, 3))
		{
			printf("Ordenando Lista...\n");
			ll_sort(pArrayListPassenger, Passenger_compareById, ordenamiento);
			printf("\nLista ordenada con exito\n\n");
			system("pause");
			retorno = 0;
		}
		break;
	case 2:
		if(!tomarEntero(&ordenamiento, "0-Orden Descendente\n1-Orden Ascendente\nOrden: ", "ERROR. Ingreso no valido", 0, 1, 3))
		{
			printf("Ordenando Lista...\n");
			ll_sort(pArrayListPassenger, Passenger_compareByNombre, ordenamiento);
			printf("\nLista ordenada con exito\n\n");
			system("pause");
			retorno = 0;
		}
		break;
	case 3:
		if(!tomarEntero(&ordenamiento, "0-Orden Descendente\n1-Orden Ascendente\nOrden: ", "ERROR. Ingreso no valido", 0, 1, 3))
		{
			printf("Ordenando Lista...\n");
			ll_sort(pArrayListPassenger, Passenger_compareByApellido, ordenamiento);
			printf("\nLista ordenada con exito\n\n");
			system("pause");
			retorno = 0;
		}
		break;
	case 4:
		if(!tomarEntero(&ordenamiento, "0-Orden Descendente\n1-Orden Ascendente\nOrden: ", "ERROR. Ingreso no valido", 0, 1, 3))
		{
			printf("Ordenando Lista\n");
			ll_sort(pArrayListPassenger, Passenger_compareByPrecio, ordenamiento);
			printf("\nLista ordenada \n\n");
			system("pause");
			retorno = 0;
		}
		break;
	case 5:
		if(!tomarEntero(&ordenamiento, "0-Orden Descendente\n1-Orden Ascendente\nOrden: ", "ERROR. Ingreso no valido", 0, 1, 3))
		{
			printf("Ordenando Lista\n");
			ll_sort(pArrayListPassenger, Passenger_compareByTipoDePasajero, ordenamiento);
			printf("\nLista ordenada\n\n");
			system("pause");
			retorno = 0;
		}
		break;
	case 6:
		if(!tomarEntero(&ordenamiento, "0-Orden Descendente\n1-Orden Ascendente\nOrden: ", "ERROR. Ingreso no valido", 0, 1, 3))
		{
			printf("Ordenando Lista\n");
			ll_sort(pArrayListPassenger, Passenger_compareByCodigoDeVuelo, ordenamiento);
			printf("\nLista ordenada\n\n");
			system("pause");
			retorno = 0;
		}
		break;
	case 7:
		if(!tomarEntero(&ordenamiento, "0-Orden Descendente\n1-Orden Ascendente\nOrden: ", "ERROR. Ingreso no valido", 0, 1, 3))
		{
			printf("Ordenando Lista\n");
			ll_sort(pArrayListPassenger, Passenger_compareByEstadoDeVuelo, ordenamiento);
			printf("\nLista ordenada\n\n");
			system("pause");
			retorno = 0;
		}
		break;
	case 8:
		printf("Vuelve al menu\n");
		system("pause");
		break;
	}

	return retorno;

}
/**
 * Compara dos pasajeros mediate id.
 * @param primerPasajero puntero a void
 * @param segundoPasajero puntero a void
 * @return retorna el resutado de la comparacion.
 */
int Passenger_compareById(void* primerPasajero, void* segundoPasajero)
{
	int resultadoComparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	int idDelPrimero;
	int idDelSegundo;

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		Passenger_getId(pPrimerPasajero, &idDelPrimero);
		Passenger_getId(pSegundoPasajero, &idDelSegundo);

		if(idDelSegundo < idDelPrimero)
		{
			resultadoComparacion = 1;
		}
		else
		{
			if(idDelSegundo > idDelPrimero)
			{
				resultadoComparacion = -1;
			}
		}

	}

	return resultadoComparacion;
}
/**
 * Compara dos pasajeros mediate el nombre.
 * @param primerPasajero puntero a void
 * @param segundoPasajero puntero a void
 * @return retorna el resutado de la comparacion.
 */
int Passenger_compareByNombre(void* primerPasajero, void* segundoPasajero)
{
	int resultadoComparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	char nombreDelPrimero[130];
	char nombreDelSegundo[130];

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		Passenger_getNombre(pPrimerPasajero, nombreDelPrimero);
		Passenger_getNombre(pSegundoPasajero, nombreDelSegundo);

		resultadoComparacion = strcmp(nombreDelPrimero, nombreDelSegundo);
	}

	return resultadoComparacion;
}
/**
 * Compara dos pasajeros mediate el apellido.
 * @param primerPasajero puntero a void
 * @param segundoPasajero puntero a void
 * @return retorna el resutado de la comparacion.
 */
int Passenger_compareByApellido(void* primerPasajero, void* segundoPasajero)
{
	int resultadoComparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	char apellidoDelPrimero[130];
	char apellidoDelSegundo[130];

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		Passenger_getApellido(pPrimerPasajero, apellidoDelPrimero);
		Passenger_getApellido(pSegundoPasajero, apellidoDelSegundo);

		resultadoComparacion = strcmp(apellidoDelPrimero, apellidoDelSegundo);
	}

	return resultadoComparacion;
}
/**
 * Compara dos pasajeros mediate el precio.
 * @param primerPasajero puntero a void
 * @param segundoPasajero puntero a void
 * @return retorna el resutado de la comparacion.
 */
int Passenger_compareByPrecio(void* primerPasajero, void* segundoPasajero)
{
	int resultadoComparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	float precioDelPrimero;
	float precioDelSegundo;

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		Passenger_getPrecio(pPrimerPasajero, &precioDelPrimero);
		Passenger_getPrecio(pSegundoPasajero, &precioDelSegundo);

		if(precioDelSegundo < precioDelPrimero)
		{
			resultadoComparacion = 1;
		}
		else
		{
			if(precioDelSegundo > precioDelPrimero)
			{
				resultadoComparacion = -1;
			}
		}

	}

	return resultadoComparacion;
}
/**
 * Compara dos pasajeros mediate el tipo de pasajero que sean.
 * @param primerPasajero puntero a void
 * @param segundoPasajero puntero a void
 * @return retorna el resutado de la comparacion.
 */
int Passenger_compareByTipoDePasajero(void* primerPasajero, void* segundoPasajero)
{
	int resultadoComparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	int tipoDelPrimero;
	int tipoDelSegundo;

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		Passenger_getTipoPasajero(pPrimerPasajero, &tipoDelPrimero);
		Passenger_getTipoPasajero(pSegundoPasajero, &tipoDelSegundo);

		if(tipoDelSegundo < tipoDelPrimero)
		{
			resultadoComparacion = 1;
		}
		else
		{
			if(tipoDelSegundo > tipoDelPrimero)
			{
				resultadoComparacion = -1;
			}
		}

	}

	return resultadoComparacion;
}
/**
 * Compara dos pasajeros mediate el codigo de vuelo que posean.
 * @param primerPasajero puntero a void
 * @param segundoPasajero puntero a void
 * @return retorna el resutado de la comparacion.
 */
int Passenger_compareByCodigoDeVuelo(void* primerPasajero, void* segundoPasajero)
{
	int resultadoComparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	char codigoDelPrimero[130];
	char codigoDelSegundo[130];

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		Passenger_getCodigoVuelo(pPrimerPasajero, codigoDelPrimero);
		Passenger_getCodigoVuelo(pSegundoPasajero, codigoDelSegundo);

		resultadoComparacion = strcmp(codigoDelPrimero, codigoDelSegundo);
	}

	return resultadoComparacion;
}
/**
 * Compara dos pasajeros mediate el estado de vuelo que posean.
 * @param primerPasajero puntero a void
 * @param segundoPasajero puntero a void
 * @return retorna el resutado de la comparacion.
 */
int Passenger_compareByEstadoDeVuelo(void* primerPasajero, void* segundoPasajero)
{
	int resultadoComparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	int estadoDelPrimero;
	int estadoDelSegundo;

	if(primerPasajero != NULL && segundoPasajero != NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		Passenger_getEstadoDeVuelo(pPrimerPasajero, &estadoDelPrimero);
		Passenger_getEstadoDeVuelo(pSegundoPasajero, &estadoDelSegundo);

		if(estadoDelSegundo < estadoDelPrimero)
		{
			resultadoComparacion = 1;
		}
		else
		{
			if(estadoDelSegundo > estadoDelPrimero)
			{
				resultadoComparacion = -1;
			}
		}

	}

	return resultadoComparacion;
}



