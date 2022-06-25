
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn.h"
#include "calculos.h"

int main(void) {

	setbuf(stdout,NULL);

	char seguir = 's';
	char confirm;
	int flag1= 0;
	int flag2= 0;
	int flag3 =0;
	float km;
	float precioAerolineas;
	float precioLatam;
	float precioConDescuentoAerolineas;
	float precioConAumentoAerolineas;
	float precioConDescuentoLatam;
	float precioConAumentoLatam;
	float bitCoin;
	float bitCoinL;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciadePrecio;



do{

	switch(menu()){

	case 1:

	km =getFloat("Ingrese los Kilometros\n");
	printf("Los km ingresados son %.2f\n",km);

		flag1 = 1;

		break;

	case 2:

		if(flag1){

		precioAerolineas = getFloat("Ingrese el precio del vuelo Aerolineas\n");
		precioLatam = getFloat("Ingrese el precio del vuelo Latam\n");

		printf("Los precios ingresados fueron %.2f  y  %.2f\n",precioAerolineas,precioLatam);

		flag2=1;

		}
		else{
			printf("Primero ingrese km\n");
		}
			break;


	case 3:

		if(flag2){

		if(realizarDescuento(precioAerolineas,&precioConDescuentoAerolineas)==0){
			printf("Ocurrio un problema\n");
		}

		if(realizarAumento(precioAerolineas,&precioConAumentoAerolineas)==0){
			printf("Ocurrio un problema\n");
		}

		bitCoin = transformarPesos(precioAerolineas);


		if(mostrarPrecioUnitario(km, precioAerolineas, &precioUnitarioAerolineas)==0){
			printf("Ocurrio un problema\n");
		}

		//////

		if(realizarDescuento(precioLatam,&precioConDescuentoLatam)==0){
			printf("Ocurrio un problema\n");
		}

		if(realizarAumento(precioLatam,&precioConAumentoLatam)==0){
			printf("Ocurrio un problema\n");
		}

		if(mostrarPrecioUnitario(km, precioLatam, &precioUnitarioLatam)==0){
			printf("Ocurrio un problema\n");
		}

			bitCoinL = transformarPesos(precioLatam);

	    if(diferenciaPrecio(precioLatam,precioAerolineas, &diferenciadePrecio)==0){
			printf("Ocurrio un problema\n");
		}

		flag3 = 1;

		printf("Calculos realizados\n");
		}
		else if(flag1){
			printf("Primero deberia ingresar el precio de vuelo\n");
		}
		else{
			printf("Primero deberia ingresar los km\n");
		}
			break;
	case 4:
		if(flag3){
		mostrarResultados(km, precioAerolineas,precioConDescuentoAerolineas, precioConAumentoAerolineas, bitCoin,precioUnitarioAerolineas, precioLatam, precioConDescuentoLatam, precioConAumentoLatam, bitCoinL, precioUnitarioLatam,diferenciadePrecio);
		}
		else{
			printf("Hubo un problema\n");
		}
			break;
	case 5:

		km = 7090;
		precioAerolineas = 162965;
		precioLatam = 159339;


		if(realizarDescuento(precioAerolineas,&precioConDescuentoAerolineas)==0){
			printf("Ocurrio un problema\n");
	    }

		if(realizarAumento(precioAerolineas,&precioConAumentoAerolineas)==0){
		    printf("Ocurrio un problema\n");
		}

		bitCoin = transformarPesos(precioAerolineas);


		if(mostrarPrecioUnitario(km, precioAerolineas, &precioUnitarioAerolineas)==0){
			printf("Ocurrio un problema\n");
		}

		if(realizarDescuento(precioLatam,&precioConDescuentoLatam)==0){
			printf("Ocurrio un problema\n");
		}

		if(realizarAumento(precioLatam,&precioConAumentoLatam)==0){
			printf("Ocurrio un problema\n");
		}

		if(mostrarPrecioUnitario(km, precioLatam, &precioUnitarioLatam)==0){
			printf("Ocurrio un problema\n");
		}

			bitCoinL = transformarPesos(precioLatam);

		if(diferenciaPrecio(precioLatam,precioAerolineas, &diferenciadePrecio)==0){
			printf("Ocurrio un problema\n");
		}



	mostrarResultados(km, precioAerolineas,precioConDescuentoAerolineas, precioConAumentoAerolineas, bitCoin,precioUnitarioAerolineas, precioLatam, precioConDescuentoLatam, precioConAumentoLatam, bitCoinL, precioUnitarioLatam,diferenciadePrecio);


			break;
	case 6:
		printf("Seguro que desea salir? s / n\n");
		fflush(stdin);
		scanf("%c",&confirm);

		if(confirm == 's' || confirm == 'S'){

		seguir = 'n';
		}
				break;

	default:
		printf("Opcion invalida\n");
	}

system("pause");



}while(seguir == 's' || seguir == 'S');




	return EXIT_SUCCESS;
}




