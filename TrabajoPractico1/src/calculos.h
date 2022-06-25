/*
 * calculos.h
 *
 *  Created on: 11 abr. 2022
 *      Author: micar
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * \brief realiza un descuento del 10%
 * \param numero , valor a descontar
 * \param puntero a float
 * \return 0 si sale mal o 1 si sale bien
 */
int realizarDescuento(float numero, float* final);


/**
 * \brief Realiza un aumento del 25%
 * \param numero valor a aumentas
 * \param  puntero a float
 * \return 0 si sale todo mal y 1 si sale bien
 */
int realizarAumento(float numero, float* final);



/**
 * \brief convierte pesos a bitcoin
 * \param pesos valor a convertir
 * \return float valor en bitcoin
 */
float transformarPesos(float pesos);




/**
 * \brief hace la division entre el precio y los kilometros
 * \param km valor a dividir
 * \param precio valor a dividir
 * \param puntero a float
 * \return 0 si sale mal o 1 si sale bien
 */
int mostrarPrecioUnitario(float km, float precio, float* precioUnidad);




/**
 * \brief hace la resta entre los precios para sacar la diferencia
 * \param latam valor a restar
 * \param aerolineas valor a restar
 * \return 0 si sale mal o 1 si sale bien
 */
int diferenciaPrecio(float latam, float aerolineas,float* final);

#endif /* CALCULOS_H_ */
