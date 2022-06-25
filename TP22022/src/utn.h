
#ifndef UTN_H_
#define UTN_H_

int getString(char cadena[], int tam, char *mensaje);
char getChar(char* mensaje,char* mensajeError,char parametro1,char parametro2);
int getInt(char* mensaje, char* mensajeError,int maximo, int minimo);
float getFloat(char* mensaje, char* mensajeError,float maximo, float minimo);

#endif /* UTN_H_ */
