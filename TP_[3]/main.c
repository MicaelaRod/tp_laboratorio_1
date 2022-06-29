#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "validaciones.h"
#include "parser.h"

int main()
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros = ll_newLinkedList();
    int option;
    int flagCarga = 0;
    int flagAlta = 0;
    int flagGuardado = 0;

    do{
        option = iniciarMenu();

        switch(option)
        {
            case 1:
            	if(flagCarga == 0)
            	{
					if(controller_loadFromText("data.csv",listaPasajeros) == -1)
					{
						printf("\nNo se pudo abrir el archivo... \n\n");
						system("pause");

					}
					else
					{
						printf("\nSe cargaron los datos con exito.\n\n");
						flagCarga = 1;
						system("pause");
					}
            	}
            	else
            	{
            		printf("\nNo puede realizar dos cargas.\n\n");
					system("pause");
            	}
                break;
            case 2:
            	if(flagCarga == 0)
            	{
					if(controller_loadFromBinary("data.bin", listaPasajeros) == -1)
					{
						printf("No se pudo abrir el archivo \n");
						system("pause");
					}
					else
					{
						printf("\nSe cargaron los datos con exito.\n\n");
						flagCarga = 1;
						system("pause");
					}
            	}
            	else
            	{
            		printf("\nNo puede realizar dos cargas.\n\n");
					system("pause");
            	}
                break;
                break;
            case 3:
            	if(controller_addPassenger(listaPasajeros) == -1)
            	{
            		printf("\nError al dar alta.\n\n");
					system("pause");
            	}
            	else
            	{
            		printf("\nAlta exitosa.\n\n");
            		flagAlta = 1;
					system("pause");
            	}
                break;
            case 4:
            	if(flagCarga == 1 || flagAlta == 1)
				{
            		if(!controller_editPassenger(listaPasajeros))
            		{
            			printf("\nPasajero modificado con exito.\n\n");
            			system("pause");
            		}

				}
            	else
            	{
            		printf("\nDebe cargar los datos o dar de alta algun pasajero antes de poder modificar.\n\n");
            		system("pause");
            	}
                break;
            case 5:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
					if(!controller_removePassenger(listaPasajeros))
					{
						printf("\nEl pasajero ha sido eliminado.\n\n");
						system("pause");
					}
            	}
            	else
            	{
            		printf("\nBaja cancelada.\n\n");
            		system("pause");
            	}
                break;
            case 6:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
            		if(controller_ListPassenger(listaPasajeros) == -1)
            		{
            			printf("\nNo hay pasajeros.\n\n");
            			system("pause");
            		}
            	}
            	else
            	{
            		printf("\nNo puede listar los pasajeros sin antes haber dado algun alta o haber cargado los archivos.\n\n");
            		system("pause");
            	}
                break;
            case 7:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
            		if(controller_sortPassenger(listaPasajeros) == -1)
            		{
            			printf("\nNo hay pasajeros para ordenar.\n\n");
            			system("pause");
            		}
            	}
            	else
            	{
            		printf("\nNo puede ordenar los pasajeros sin antes haber dado algun alta o haber cargado los archivos.\n\n");
            		system("pause");
            	}
                break;
            case 8:
            	if(flagCarga == 1)
            	{
            		if(controller_saveAsText("data.csv", listaPasajeros) == -1)
            		{
            			printf("\nNo se guardo el archivo.\n\n");
            			system("pause");
            		}
            		else
            		{
            			flagGuardado = 1;
            		}
            	}
            	else
            	{
            		printf("\nNo puede guardar sin haber realizado una carga de archivos.\n\n");
            		system("pause");
            	}
                break;
            case 9:
            	if(flagCarga == 1)
            	{
            		if(controller_saveAsBinary("data.bin", listaPasajeros) == -1)
            		{
            			printf("\nNo se pudo realizar el guardado del archivo.\n\n");
            			system("pause");
            		}
            		else
            		{
            			flagGuardado = 1;
            		}
            	}
            	else
            	{
            		printf("\nNo puede guardar sin haber realizado una carga de archivos.\n\n");
            		system("pause");
            	}
                break;
            case 10:
            	if((flagCarga == 0 && flagAlta == 0) || flagGuardado == 1)
				{

					if(!verificarRespuesta())
					{
						option = -1;
					}
					else
					{
						ll_deleteLinkedList(listaPasajeros);
					}
            	}
            	else
            	{
            		printf("\nDebe guardar antes de salir\n\n");
            		option = -1;
            		system("pause");

            	}
                break;
        }

    }while(option != 10);






    return 0;
}
