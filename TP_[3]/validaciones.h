

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>

int tomarEntero (int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos);
int tomarString(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int intentos);
short verificarRespuesta (void);
int tomarFlotante (float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos);
int tomarIntComoTexto (char *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos);
int validarFlycode(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int intentos);
int tomarFloatComoTexto(char* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos);
int incrementarPasajerosId();
int iniciarMenu (void);
int subMenuInformar(void);
int esNumerica (char* cadena);
int esFlotante (char* cadena);
int esNombre(char* cadena,int longitud);
int esFlycode(char* cadena,int longitud);

#endif /* VALIDACIONES_H_ */
