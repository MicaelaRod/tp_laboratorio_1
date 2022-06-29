

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoDeVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr,char* precioStr ,char* tipoPasajeroStr, char* codigoDeVueloStr, char* estadoDeVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setAll(Passenger* this, int id,char* nombre, char* apellido,float precio ,int tipoPasajero, char* codigoDeVuelo, int estadoDeVuelo);
int Passenger_getAll(Passenger* this, int* id, char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoDeVuelo, int* estadoDeVuelo);

Passenger* crearPasajero (char* idActualizado);
int copiarPasajero(Passenger* pPasajeroDestino, Passenger* pPasajeroOrigen);
int buscarPasajeroPorId(LinkedList* pArrayListPassenger, int idAEncontrar);
int Passenger_edit (Passenger* pPasajeroAModificar);

int Passenger_printOne(Passenger* unPasajero);
int Passenger_print(Passenger* unPasajero);
int Passenger_sort(LinkedList* pArrayListPassenger , int opcion);

int convertirDescripcionEnIdTipoDePasajero(char* texto, char* idCorrespondiente);
int convertirDescripcionEnIdEstadoDeVuelo(char* texto, char* idCorrespondiente);
int convertirIdEnDescripcionTipoDePasajero(int id, char* descripcionCorrespondiente);
int convertirIdEnDescripcionEstadoDeVuelo(int id, char* descripcionCorrespondiente);

int Passenger_compareByEstadoDeVuelo(void* primerPasajero, void* segundoPasajero);
int Passenger_compareByCodigoDeVuelo(void* primerPasajero, void* segundoPasajero);
int Passenger_compareByTipoDePasajero(void* primerPasajero, void* segundoPasajero);
int Passenger_compareByPrecio(void* primerPasajero, void* segundoPasajero);
int Passenger_compareByApellido(void* primerPasajero, void* segundoPasajero);
int Passenger_compareByNombre(void* primerPasajero, void* segundoPasajero);
int Passenger_compareById(void* primerPasajero, void* segundoPasajero);


int Passenger_subMenuEditar(void);
void listarEstadosDeVuelo();
void listarTiposDePasajero();
int Passenger_subMenuOrdenar(void);

#endif /* PASSENGER_H_ */
