
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "tipo.h"


int menu() {

	int opcion;

	printf("ABM:\n");
	printf("1.Alta\n");
	printf("2.Modificar\n");
	printf("3.Baja\n");
	printf("4.Informar\n");
	printf("5.Salir\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}


int menuModificar() {

	int opcion;
	printf("1.Nombre\n");
	printf("2.Apellido\n");
	printf("3.Precio\n");
	printf("4.Tipo de pasajero\n");
	printf("5.Codigo de vuelo\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int modificar(ePassenger lista[], int tam,eTipo tipos[],int tamT) {
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	char auxCadena2[20];
	char auxCadena[20];
	float auxFloat;
	int auxInt;

	if (lista != NULL && tam > 0) {

		printf("Modificacion:\n");

		printf("Ingrese ID ");

		scanf("%d", &id);

		indice = findPassengerById(lista, tam, id);

		if (indice == -1) {
			printf("El ID: %d no esta en el sistema\n", id);
		} else {
			mostrarUno(lista[indice],tipos,tamT);
			printf("\n");
			printf("Confirma modificacion? \n");
			fflush(stdin);
			scanf("%c",&confirma);

			if(confirma == 's' || confirma == 'S'){

			switch( menuModificar()){

			case 1:
				getString(auxCadena, 51 , "Ingrese nombre del pasajero");
				strcpy(lista[indice].name,auxCadena);
				break;

			case 2:
				getString(auxCadena, 51 , "Ingrese apellido del pasajero");
				strcpy(lista[indice].lastName,auxCadena);

				break;
			case 3:
				auxFloat = getFloat("Ingrese Precio del vuelo, de 100 a 1000", "Reingrese precio\n",1000, 100);
				lista[indice].price = auxFloat;
				break;
			case 4:

				mostrarTipos(tipos,tamT);
				auxInt  = getInt("Ingrese id Tipo","Error, reingrese id",4, 1);
				lista[indice].idtypePassenger = auxInt;
				break;
			case 5:
				getString(auxCadena2, 10 , "Ingrese FlyCode");
				strcpy(lista[indice].flycode,auxCadena2);
				break;


			default:
				printf("Opcion invalida\n");
			}


			todoOk = 1;
			}
			else{
				printf("Modificacion cancelada\n");
			}
		}

	}
	return todoOk;
}

int removePassenger(ePassenger lista[], int tam,eTipo tipos[],int tamT) {

	int todoOk = 0;
	int indice;
	int id;
	char confirma;

	if (lista != NULL && tam > 0) {

		printf("Baja:\n");

		printf("Ingrese ID ");

		scanf("%d", &id);

		indice = findPassengerById(lista, tam, id);

		if (indice == -1) {
			printf("El ID: %d no esta en el sistema\n", id);
		} else {
			mostrarUno(lista[indice],tipos,tamT);
			printf("\n");
			printf("Confirma baja? ");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's' || confirma == 'S') {
				lista[indice].isEmpty = 1;
				printf("Baja exitosa!!\n");
				todoOk = 1;
			} else {
				printf("Baja cancelada\n");
			}
		}

	}
	return todoOk;
}

int findPassengerById(ePassenger lista[], int tam, int ID) {

	int retorno = -1;

	if (lista != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {

			if (lista[i].isEmpty == 0 && lista[i].id == ID) {

				retorno = i;

				break;
			}
		}
	}
	return retorno;
}

int printPassengers(ePassenger lista[],int tam,eTipo tipos[],int tamT){
	int todoOk = 0;
	int flag = 1;

	if (lista != NULL && tam > 0) {

		printf("Listado de Pasajeros:\n");
		printf(
				"--------------------------------------------------------------------------------\n");
		printf(
				"  ID     Nombre    Apellido          Precio      FlyCode    Tipo De pasajero \n");
		printf(
				"--------------------------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++) {

			if(lista[i].isEmpty ==0){ //muestra solo los que estan cargados!!
			mostrarUno(lista[i],tipos,tamT);
			flag = 0;
			printf("\n");
			}

		}

		if(flag){
			printf("No hay pasajeros para mostrar\n");
		}

		todoOk = 1;
	}
	return todoOk;
}

void mostrarUno(ePassenger usuario,eTipo lista[],int tam){

	char descripcionT[20];

	cargarDescripcionT(lista,tam,usuario.idtypePassenger,descripcionT);

	printf("  %d     %-10s%-10s       %5.2f       %-10s    %-10s ",
				usuario.id,
				usuario.name,
				usuario.lastName,
				usuario.price,
				usuario.flycode,
				descripcionT

				);
}

int addPassengers(ePassenger lista[], int tam, int* id,eTipo tipos[],int tamT) {

	int todoOk = 0;
	int indice;
	ePassenger aux;

	if (lista != NULL && tam > 0) {

		indice = buscarLibre(lista,tam);

		if(indice == -1){
			printf("No se encuentra lugar para realizar el alta\n");
		}
		else{

			aux.id = *id;
			(*id)++;

			getString(aux.name, 51 , "Ingrese nombre");

			getString(aux.lastName, 51 , "Ingrese apellido");

		    aux.price =getFloat("Ingrese Precio del vuelo, de 100 a 1000", "Reingrese Precio\n",1000, 100);

		    getString(aux.flycode, 11 , "Ingrese FlyCode (Lugares de destino)");

		    mostrarTipos(tipos,tamT);
		    aux.idtypePassenger = getInt("Ingrese id Tipo","Error, reingrese id",4, 1);
		    aux.isEmpty = 0;



		    printf("Alta exitosa!!\n");

		    lista[indice] = aux;


		todoOk = 1;
		}
	}

	return todoOk;
}

int buscarLibre(ePassenger lista[], int tam) {

	int retorno = -1;

	if (lista != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {

			if (lista[i].isEmpty) {

				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int inicializar(ePassenger lista[], int tam) {
	int todoOk = 0;

	if (lista != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			lista[i].isEmpty = 1;
		}

		todoOk = 1;
	}
	return todoOk;
}

///////////////////////////////////////////////////////////INFORMAR///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int menuInformar() {

	int opcion;

	printf("Informar:\n");
	printf("1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
	printf("2.Total y promedio de los precios de los pasajes,y cuántos pasajeros superan el precio promedio.\n");
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;
}




int sortPassengers(ePassenger lista[], int tam, eTipo tipos[], int tamT)
{

   int todoOk = 0;
   ePassenger aux;
   char tipoI[20];
   char tipoJ[20];

    if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0){

    for(int i=0;i<tam-1;i++) {

        for(int j=i+1;j<tam;j++){

        	cargarDescripcionT(tipos,tamT,lista[i].idtypePassenger,tipoI);
        	cargarDescripcionT(tipos,tamT,lista[j].idtypePassenger,tipoJ);

            if(strcmp(tipoI,tipoJ)>0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
            else
            {
                 if((strcmp(tipoI,tipoJ)==0)&&strcmp(lista[i].lastName,lista[j].lastName))
                {
                    aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
                }
            }
        }
    }
    todoOk = 1;
    }

    return todoOk;
}




float mostrarPromedioPrecio(ePassenger lista[], int tam) {

	int todoOk = 0;
	int contador = 0;
	int contador2 = 0;
	float acum = 0;
	float promedio;
	int flag = 1;

	if (lista != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {

			if (lista[i].isEmpty == 0) { //muestra solo los que estan cargados!!

				acum += lista[i].price;

				contador++;

				printf("\n");
			}

		}

		if (contador != 0) {

			promedio = (float) acum / contador;
			printf("El promedio de puntaje de los precios es %.2f\n", promedio);
		} else {
			printf("No hay pasajeros\n");
		}

		for (int i = 0; i < tam; i++) {

			if (lista[i].isEmpty == 0) {
				if (flag == 1 || lista[i].price > promedio) {

					contador2++;

					flag = 0;

				}
			}

		}

		if (contador != 0) {
			printf("Los pasajeros que superan el precio promedio son %d\n",
					contador2);

		} else {
			printf("No hay pasajeros que superen ese precio\n");
		}
todoOk = 1;
	}
	return todoOk;

}





