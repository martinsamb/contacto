#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Musicos.h"



/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musicos Array of musicos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musicos_Inicializar(Musicos array[], int size)                                    //cambiar musicos
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musicos_buscarEmpty(Musicos array[], int size, int* posicion)                    //cambiar musicos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musicos_buscarID(Musicos array[], int size, int valorBuscado, int* posicion)                    //cambiar musicos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musicos_alta(Musicos array[],int size,int* contadorID)                          //cambiar prestamos
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musicos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libros
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if(utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)== 0 &&
               utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido)== 0 &&
               utn_getUnsignedInt("\nEdad: ","\nError",1,sizeof(int),1,3,1,&array[posicion].edad) == 0 &&
               utn_getUnsignedInt("\nID Orquestas: ","\nError",1,sizeof(int),1,5,1,&array[posicion].idOrquestas) == 0 &&
               utn_getUnsignedInt("\nID Instrumentos: ","\nError",1,sizeof(int),1,6,1,&array[posicion].idInstrumentos) == 0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;                                                       //campo ID
                array[posicion].isEmpty=0;
                printf("\nID: %d\nNombre: %s\nApellido: $s\nEdad: %d\nID orquestas: %d\nID Instrumentos: %d",
                    array[posicion].idUnico,
                    array[posicion].nombre,
                    array[posicion].apellido,
                    array[posicion].edad,
                    array[posicion].idOrquestas,
                    array[posicion].idInstrumentos);
                retorno=0;
            }
            else
            {
                printf("\nAlta no exitosa");
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_baja(Musicos array[], int sizeArray)                                      //cambiar musicos
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        musicos_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musicos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].edad=0;                                                               //cambiar campo varInt
            array[posicion].idOrquestas=0;
            array[posicion].idInstrumentos=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posicion].apellido,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musicos_bajaValorRepetidoInt(Musicos array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idOrquestas==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].edad=0;                                                               //cambiar campo varInt
                array[i].idOrquestas=0;
                array[i].idInstrumentos=0;                                                             //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo varString
                strcpy(array[i].apellido,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musicos_modificar(Musicos array[], int sizeArray)                                //cambiar musicos
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        musicos_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musicos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {
                MenuMusicosModificacion();
                utn_getUnsignedInt("","\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getUnsignedInt("\nEdad: ","\nError\n",1,sizeof(int),1,3,1,&array[posicion].edad);            //mensaje + cambiar campo varInt
                        break;
                    case 2:
                        utn_getUnsignedInt("\nID Orquesta: ","\nError\n",1,sizeof(int),1,3,1,&array[posicion].idOrquestas);
                        break;
                    case 3:
                        break;

                    default:
                        printf("\nOpcion no valida\n");
                }
            }while(opcion!=3);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musicos_listar(Musicos array[], int size)                      //cambiar musicos
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n---------------------------------------\n");
                printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Edad: %d",
                       array[i].idUnico,
                       array[i].nombre,
                       array[i].apellido,
                       array[i].edad);
        }
        retorno=0;
    }
    return retorno;
}

void musicos_print(Musicos* arrayMusico, int limite)
{
    int i;
    for (i=0;i<=limite;i++)
    {
        if (arrayMusico[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre del musico: %s ",arrayMusico[i].nombre);
            printf ("\nApellido del musico: %s ",arrayMusico[i].apellido);
            printf ("\nEdad del musico: %d ",arrayMusico[i].edad);
            printf ("\nId de instrumento : %d",arrayMusico[i].idInstrumentos);
            //printf ("\nId del musico: %d ",arrayMusico[i].idOrquestas);
            //printf ("\nPosicion: %d ",i);
            //printf ("\nEstado : %d \n",arrayMusico[i].isEmpty);
        }
    }
}

//////////////////////////////////
void MenuMusicos()
{
    printf("\n\nMENU MUSICOS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Modificacion\n");
    printf("3 - Baja\n");
    printf("4 - Listar\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}

void MenuPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - Orquestas\n");
    printf("2 - Musicos\n");
    printf("3 - Instrumentos\n");
    printf("4 - Informes\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
////////////////////////////////////
void MenuMusicosModificacion()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - Edad\n");
    printf("2 - ID Orquesta\n");
    printf("3 - SALIR\n");
    printf("Elija opcion: ");
}

