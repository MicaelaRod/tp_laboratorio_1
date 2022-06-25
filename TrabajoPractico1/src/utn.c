
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int menu(){

		int opcion;

		system("cls");
	printf(" 1. Ingresar kilometros\n ");
	printf(" 2. Ingresar precio de vuelos\n ");
	printf(" 3. Calcular todos los costos\n");
	printf("	  	a) Tarjeta de debito\n");
	printf("		b) Tarjeta de credito\n");
	printf("		c) Bitcoin\n");
	printf("		d) Mostrar precio por km\n");
	printf("		e) Mostrar diferencia de precio ingresada\n");
	printf(" 4. Informar resultados\n");
	printf("		Latam:\n");
	printf("		a) Precio con tarjeta de debito\n");
	printf("		b) Precio con tarjeta de credito\n");
	printf("		c) Precio pagando con bitcoin\n");
	printf("		d) Precio unitario\n");
	printf("		Aerolineas:\n");
	printf("		a) Precio con tarjeta de debito\n");
	printf("		b) Precio con tarjeta de credito\n");
	printf("		c) Precio pagando con bitcoin\n");
	printf("		d) Precio unitario\n");
	printf("La diferencia de precio es :\n");
	printf(" 5. Carga forzada de datos\n");
	printf(" 6. Salir\n");

	printf("Indique opcion\n");

	fflush(stdin);

	scanf("%d", &opcion);

		return opcion;
	}
float getFloat(char* mensaje)
{
    float numero;

    puts(mensaje);
    scanf("%f",&numero);

    return numero;
}


void mostrarResultados(float km,float precioAerolineas,float precioConDescuentoAerolineas,float precioConAumentoAerolineas,float bitCoin,float precioUnitarioAerolineas,float precioLatam,float precioConDescuentoLatam,float precioConAumentoLatam,float bitCoinL,float precioUnitarioLatam,float diferenciadePrecio){

	        printf("\n\nKM ingresados :%.2fkm\n",km);
			printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
			printf("El precio final del descuento de Aerolineas es: $%.2f\n",precioConDescuentoAerolineas);
			printf("El precio final del aumento de Aerolineas es: $%.2f\n",precioConAumentoAerolineas);
			printf("Precio pagando con bitCoin: %f BTC\n",bitCoin);
			printf("Precio unitario : $%.2f\n\n",precioUnitarioAerolineas);


			printf("Precio Latam: $%.2f\n",precioLatam);
			printf("El precio final del descuento de Latam es: $%.2f\n",precioConDescuentoLatam);
			printf("El precio final del aumento de Latam es: $%.2f\n",precioConAumentoLatam);
			printf("Precio pagando con bitCoin: %f BTC\n",bitCoinL);
			printf("Precio unitario : $%.2f\n",precioUnitarioLatam);
			printf("La diferencia de precio es: %.2f\n",diferenciadePrecio);

}
