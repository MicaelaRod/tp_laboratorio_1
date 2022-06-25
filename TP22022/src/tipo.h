
#ifndef TIPO_H_
#define TIPO_H_

typedef struct{

	int id;
	char descripcion[20];


}eTipo;

int cargarDescripcionT(eTipo tipos[],int tam,int idTipo,char descripcion[]);


int mostrarTipos(eTipo tipos[], int tam);




#endif /* TIPO_H_ */
