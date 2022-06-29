#ifndef __CONTROLLER_H_
#define __CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int encontrarUltimoId(char* path, char* id);
int incrementarId(char* id);
int actualizarId(char* path, char* id);
int guardarComoBinario(FILE* pArchivo, LinkedList* pArrayListPassenger);
int guardarComoTexto (FILE* pArchivo, LinkedList* pArrayListPassenger);


#endif /*CONTROLLER_H_*/
