/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
#include "../testing/inc/main_test.h"
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"



int main(void)
{

	setbuf(stdout,NULL);
	char seguir = 's';


	LinkedList* listaEmpleados = ll_newLinkedList();
	if (listaEmpleados == NULL)
	{
		printf("No se pudo crear el linkedList\n");
		exit(1);
	}

	do
	{
		switch (menu())
		{
		case 1:
			if ( !controller_loadFromText("data.csv", listaEmpleados) )
			{
				printf("ERROR al cargar archivo texto\n");
			}
			break;
		case 2:
			if ( !controller_loadFromBinary("datas.bin", listaEmpleados) )
			{
				printf("ERROR al cargar archivo binario\n");
			}
			break;
		case 3:
			if ( !controller_addEmployee(listaEmpleados) )
			{
				printf("Error al dar de alta empleado!!\n");
			}
			break;
		case 4:
			if ( !controller_editEmployee(listaEmpleados) )
			{
				printf("Error al modificar  empleado\n");
			}
			break;
		case 5:
			if ( !controller_removeEmployee(listaEmpleados) )
			{
				printf("Error en la baja de empleado\n");
			}
			break;
		case 6:
			if ( !controller_ListEmployee(listaEmpleados) )
			{
				printf("Error al listar empleado/s !!!\n");
			}
			break;
		case 7:
			if ( !controller_sortEmployee(listaEmpleados) )
			{
				printf("Error al ordenar  empleados\n");
			}
			break;
		case 8:
			if ( !controller_saveAsText("data.csv", listaEmpleados) )
			{
				printf("Error al guardar archivo de texto\n");
			}

			break;
		case 9:
			if ( !controller_saveAsBinary("data.bin", listaEmpleados) )
			{
				printf("Error al guardar en modo binario!!\n");
			}

			break;

		case 10:
			if(!controller_clearLista(listaEmpleados) )
			{
				printf("Hubo un error al eliminar empleados de la lista!!\n");
			}
			break;

		case 11:
			if(!controller_deleteLista(listaEmpleados) )
			{
				printf("Hubo un error al eliminar la lista de empleados!!\n");
			}
			break;

		case 12:
			if(!controller_crearNuevaLista(listaEmpleados) )
			{
				printf("Hubo un error al crear una lista nueva!!\n");
			}
			break;

		case 13:
			if(!controller_clonarLista(listaEmpleados) )
			{
				printf("Hubo un error al clonar la lista!!\n");
			}
			break;

		case 14:
			if(!controller_removePorIndice(listaEmpleados) )
			{
				printf("Hubo un error al eliminar empleado por el indice elegido!!\n");
			}
			break;


		case 15:
			printf("Ha seleccionado salir\n");
			seguir='n';
			break;
		default:
			printf("Opcion invalida!!\n");
		}
		system("pause");
	}
	while(seguir == 's');


    return 0;
}
