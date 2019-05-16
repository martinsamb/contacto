#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Prestamos.h"
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array autores Array of autores
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int autores_Inicializar(Autores array[], int size)                                    //cambiar autores
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
* \param array autores Array de autores
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int autores_buscarEmpty(Autores array[], int size, int* posicion)                    //cambiar autores
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
* \param array autores Array de autores
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autores_buscarID(Autores array[], int size, int valorBuscado, int* posicion)                    //cambiar autores
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



//String
/** \brief Busca un string en un array
* \param array autores Array de autores
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autores_buscarString(Autores array[], int size, char* valorBuscado, int* indice)                    //cambiar autores
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array autores Array de autores
* \param size int Tama�o del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int autores_alta(Autores array[], int size, int* contadorID)                          //cambiar autores
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(autores_buscarEmpty(array,size,&posicion)==-1)                          //cambiar autores
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
                       //mensaje + cambiar campo varInt
                      //mensaje + cambiar campo varFloat
            utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("Apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);                 //mensaje + cambiar campo apellido
            printf("ID: %d\n nombre: %s\n apellido: %s",
                   array[posicion].idUnico,
                   array[posicion].nombre,
                   array[posicion].apellido);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array autores Array de autores
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autores_baja(Autores array[], int sizeArray)                                      //cambiar autores
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(autores_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id                                                             //cambiar campo varI//cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array autores Array de autores
* \param size int Tama�o del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autores_bajaValorRepetidoInt(Autores array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                                                                           //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array autores Array de autores
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int autores_modificar(Autores array[], int sizeArray)                                //cambiar autores
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(autores_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       MenuAutoresModificacion();

                utn_getUnsignedInt("","\nError",1,sizeof(int),1,3,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getName("Nombre: ","\nError\n",1,TEXT_SIZE,1,array[posicion].nombre);//mensaje + cambiar campo varInt
                        break;
                    case 2:
                        utn_getTexto("Apellido: ","\nError\n",1,TEXT_SIZE,1,array[posicion].apellido);//mensaje + cambiar campo varFloat
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
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array autores Array de autores
* \param size int Tama�o del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array autores Array de autores
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int autores_listar(Autores array[], int size)                      //cambiar autores
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
                printf("\n ID Autor: %d\nnombre: %s\n apellido: %s",
                       array[i].idUnico,
                       array[i].nombre,
                       array[i].apellido);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array autores Array de autores
* \param size int Tama�o del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int autores_ordenar(Autores array[],int size)
{
   int i,j;
   int retorno;
   Autores buffer;

   for(i = 0;i < size-1;i++)
   {
       for(j =i+1;j < size-1;j++)
       {
           if(strcmp(array[i].apellido,array[j].apellido)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
           }
           else if(strcmp(array[i].nombre,array[j].nombre)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
           }
       }
   }
   return retorno;
}

void autores_mock(Autores arrayAutores[], int size,int *contadorId)                      //cambiar autores
{
    //*******************************************************************
    int aux = 0;
    arrayAutores[0].idUnico=0;
    arrayAutores[0].isEmpty=0;
    strcpy(arrayAutores[0].apellido,"ccccc");
    strcpy(arrayAutores[0].nombre,"cccc");
    *contadorId =++ aux;

    arrayAutores[1].idUnico=1;
    arrayAutores[1].isEmpty=0;
    strcpy(arrayAutores[1].apellido,"aaaaa");
    strcpy(arrayAutores[1].nombre,"aaaaa");
    *contadorId =++ aux;

    arrayAutores[2].idUnico=2;
    arrayAutores[2].isEmpty=0;
    strcpy(arrayAutores[2].apellido,"bbbbb");
    strcpy(arrayAutores[2].nombre,"cccccc");
    *contadorId =++ aux;

    arrayAutores[3].idUnico=3;
    arrayAutores[3].isEmpty=0;
    strcpy(arrayAutores[3].apellido,"bbbbbb");
    strcpy(arrayAutores[3].nombre,"bbbbb");

}
//////////////////////////////////
void MenuAutores()
{
    printf("\n\nMENU SUBMENU AUTORES\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Listar\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}

void MenuAutoresPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - AUTORES\n");
    printf("2 - LIBROS\n");
    printf("3 - SOCIOS\n");
    printf("4 - PRESTAMOS\n");
    printf("5 - INFORMES\n");
    printf("6 - SALIR\n");
    printf("Elija opcion: ");
}
////////////////////////////////////
void MenuAutoresModificacion()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - Nombre nuevo\n");
    printf("2 - Apellido nuevo\n");
    printf("3 - SALIR\n");

    printf("Elija opcion: ");
}
