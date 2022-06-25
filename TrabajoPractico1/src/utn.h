/*
 * utn.h
 *
 *  Created on: 10 abr. 2022
 *      Author: micar
 */

#ifndef UTN_H_
#define UTN_H_


/**
 * \brief muestra un menu y pide el ingreso de una opcion
 * \param void
 * \return int opcion ingresada
 */
int menu();



/**
 * \brief pide un numero flotante
 * \param puntero a char
 * \return float numero ingresado
 */
float getFloat(char* mensaje);




/**
 * \brief  muestra los resultados de las operaciones
 * \param km precio a mostar
 * \param precioAerolineas precio a mostrar
 * \param precioConDescuentoAerolineas
 * \return void
 */
void mostrarResultados(float km,float precioAerolineas,float precioConDescuentoAerolineas,float precioConAumentoAerolineas,float bitCoin,float precioUnitarioAerolineas,float precioLatam,float precioConDescuentoLatam,float precioConAumentoLatam,float bitCoinL,float precioUnitarioLatam,float diferenciadePrecio);

#endif /* UTN_H_ */
