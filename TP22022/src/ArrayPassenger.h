
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "tipo.h"

typedef struct {
	int id;
	char name[51]; //nombre
	char lastName[51]; //apellido
	float price; //precio
	char flycode[10]; //codigo de vuelo
	int idtypePassenger; //id tipo de pasajero
	int statusFlight;
	int isEmpty;
} ePassenger;;

int inicializar(ePassenger lista[],int tam);
int buscarLibre(ePassenger lista[],int tam);
int addPassengers(ePassenger lista[],int tam, int* id,eTipo tipos[],int tamT);
void mostrarUno(ePassenger usuario,eTipo lista[],int tam);
int printPassengers(ePassenger lista[],int tam,eTipo tipos[],int tamT);
int findPassengerById(ePassenger lista[], int tam, int ID);
int removePassenger(ePassenger lista[],int tam,eTipo tipos[],int tamT);
int modificar(ePassenger lista[],int tam,eTipo tipos[],int tamT);
int menu();
int getString(char cadena[], int tam, char *mensaje);
char getChar(char* mensaje,char* mensajeError,char parametro1,char parametro2);
int getInt(char* mensaje, char* mensajeError,int maximo, int minimo);
float getFloat(char* mensaje, char* mensajeError,float maximo, float minimo);
int menuModificar();

///////////////////////////////////////////////INFORMAR///////////////////////////////////
int menuInformar();
int sortPassengers(ePassenger lista[], int tam, eTipo tipos[], int tamT);
float mostrarPromedioPrecio(ePassenger lista[],int tam);




#endif /* ARRAYPASSENGER_H_ */
