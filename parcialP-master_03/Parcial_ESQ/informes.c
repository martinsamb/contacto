#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquestas.h"
#include "Musicos.h"
#include "Instrumentos.h"
#include "informes.h"

/** \brief Lista los elementos de dos arrays vinculados
* \param arrayA Musicos Array de Musicos
* \param arrayB Instrumentos Array de Instrumentos
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarMusicos(Musicos arrayA[], Instrumentos arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty!=1)
            {
                instrumentos_buscarID(arrayB,sizeJ,arrayA[i].idInstrumentos,&j);


                printf("\n ID: %d  \nNombre: %s \nApellido: %s \nEdad: %d  \nNombre instrumento: %s \nTipo instrumento: ",
                       arrayA[i].idUnico,
                       arrayA[i].nombre,
                       arrayA[i].apellido,
                       arrayA[i].edad,
                       arrayB[j].nombre);
                        if(arrayB[j].tipo==1)
                            printf("Cuerdas");
                        else if(arrayB[j].tipo==2)
                            printf("Viento-madera");
                        else if(arrayB[j].tipo==3)
                            printf("Viento-metal");
                        else if(arrayB[j].tipo==4)
                            printf("Percusion");
                        else
                            printf("Desconocido");

            }
        }
        retorno=0;
    }
    return retorno;
}

int cantidad_tipos_orquesta (Orquestas* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorSinfonica=0;
    int contadorFilarmonica=0;
    int contadorCamara=0;

    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==0)
            {
                switch (arrayOrquesta[i].tipo)
                {
                case 1:
                    contadorSinfonica++;
                    break;
                case 2:
                    contadorFilarmonica++;
                    break;
                case 3:
                    contadorCamara++;
                    break;
                }
            }
        }
        printf ("\nCantidad de orquestas sinfonicas: %d",contadorSinfonica);
        printf ("\nCantidad de orquestas filarmonicas: %d",contadorFilarmonica);
        printf ("\nCantidad de orquestas camara: %d",contadorCamara);
        retorno=0;
    }
    return retorno;
}

int cantidad_tipos_orquesta_y_nombres (Orquestas* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorSinfonica=0;
    int contadorFilarmonica=0;
    int contadorCamara=0;

    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==0)
            {
                switch (arrayOrquesta[i].tipo)
                {
                case 1:
                    contadorSinfonica++;
                    printf ("\nSINFONICA : Nombre de orquesta: %s",arrayOrquesta[i].nombre);
                    break;
                case 2:
                    contadorFilarmonica++;
                    printf ("\nFILARMONICA : Nombre de orquesta: %s",arrayOrquesta[i].nombre);
                    break;
                case 3:
                    printf ("\nCAMARA : Nombre de orquesta: %s",arrayOrquesta[i].nombre);
                    contadorCamara++;
                    break;
                }
            }
        }
        printf ("\nCantidad de orquestas sinfonicas: %d",contadorSinfonica);
        printf ("\nCantidad de orquestas filarmonicas: %d",contadorFilarmonica);
        printf ("\nCantidad de orquestas camara: %d",contadorCamara);
        retorno=0;
    }
    return retorno;
}

int cantidad_tipos_instrumento (Instrumentos* arrayInstrumento, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int contadorCuerdas=0;
    int contadorVientoMadera=0;
    int contadorVientoMetal=0;
    int contadorPercusion=0;

    if (arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        for (i=0;i<=limiteInstrumento;i++)
        {
            if (arrayInstrumento[i].isEmpty==0)
            {
                switch (arrayInstrumento[i].tipo)
                {
                case 1:
                    contadorCuerdas++;
                    break;
                case 2:
                    contadorVientoMadera++;
                    break;
                case 3:
                    contadorVientoMetal++;
                    break;
                case 4:
                    contadorPercusion++;
                    break;
                }
            }
        }
        printf ("\nCantidad de instrumentos de cuerdas: %d",contadorCuerdas);
        printf ("\nCantidad de instrumentos de viento-madera: %d",contadorVientoMadera);
        printf ("\nCantidad de instrumentos de viento-metal: %d",contadorVientoMetal);
        printf ("\nCantidad de instrumentos de percusion: %d",contadorPercusion);
        retorno=0;
    }
    return retorno;
}

int cantidad_tipos_instrumento_y_nombres (Instrumentos* arrayInstrumento, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int contadorCuerdas=0;
    int contadorVientoMadera=0;
    int contadorVientoMetal=0;
    int contadorPercusion=0;

    if (arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        for (i=0;i<=limiteInstrumento;i++)
        {
            if (arrayInstrumento[i].isEmpty==0)
            {
                switch (arrayInstrumento[i].tipo)
                {
                case 1:
                    contadorCuerdas++;
                    printf ("\nCUERDA- Nombre de instrumento: %s",arrayInstrumento[i].nombre);
                    break;
                case 2:
                    contadorVientoMadera++;
                    printf ("\nVIENTO-MADERA- Nombre de instrumento: %s",arrayInstrumento[i].nombre);
                    break;
                case 3:
                    contadorVientoMetal++;
                    printf ("\nVIENTO-METAL- Nombre de instrumento: %s",arrayInstrumento[i].nombre);
                    break;
                case 4:
                    contadorPercusion++;
                    printf ("\nPERCUSION- Nombre de instrumento: %s",arrayInstrumento[i].nombre);
                    break;
                }
            }
        }
        printf ("\nCantidad de instrumentos de cuerdas: %d",contadorCuerdas);
        printf ("\nCantidad de instrumentos de viento-madera: %d",contadorVientoMadera);
        printf ("\nCantidad de instrumentos de viento-metal: %d",contadorVientoMetal);
        printf ("\nCantidad de instrumentos de percusion: %d",contadorPercusion);
        retorno=0;
    }
    return retorno;
}

int cantidadOrquestas(Orquestas* arrayOrquesta, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorOrquesta=0;
    if (arrayOrquesta!=NULL && limiteOrquesta>0)
    {
        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        printf ("\nLa cantidad de orquestas en total es: %d \n",contadorOrquesta);
        retorno=0;
    }
    return retorno;
}

int cantidadInstrumentos(Instrumentos* arrayInstrumento, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int contadorInstrumento=0;
    if (arrayInstrumento!=NULL && limiteInstrumento>0)
    {
        for (i=0;i<=limiteInstrumento;i++)
        {
            if (arrayInstrumento[i].isEmpty==1)
                continue;
            if (arrayInstrumento[i].isEmpty==0)
            {
                contadorInstrumento++;
            }
        }
        printf ("\nLa cantidad de instrumentos en total es: %d \n",contadorInstrumento);
        retorno=0;
    }
    return retorno;
}

int cantidadMusicos(Musicos* arrayMusico, int limiteMusico)
{
    int retorno=-1;
    int i;
    int contadorMusico=0;
    if (arrayMusico!=NULL && limiteMusico>0)
    {
        for (i=0;i<=limiteMusico;i++)
        {
            if (arrayMusico[i].isEmpty==1)
                continue;
            if (arrayMusico[i].isEmpty==0)
            {
                contadorMusico++;
            }
        }
        printf ("\nLa cantidad de musicos en total es: %d \n",contadorMusico);
        retorno=0;
    }
    return retorno;
}

int promedio_edad_musicos(Musicos* arrayMusicos,int limiteMusicos)
{
    int retorno=-1;
    int i;
    int contador=0;
    int acumulador=0;
    float promedio=0;

    if (arrayMusicos!=NULL && limiteMusicos>0)
    {
        for (i=0;i<=limiteMusicos;i++)
        {
            if (arrayMusicos[i].isEmpty==1)
                continue;
            if (arrayMusicos[i].isEmpty==0)
            {
                acumulador=arrayMusicos[i].edad+acumulador;
                contador++;
            }
        }
        promedio=acumulador/contador;
        printf ("\nEl promedio de la edad de los musicos en todas las orquestas es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}

int promedio_cantidad_musicos_por_orquesta(Musicos* arrayMusico, Orquestas* arrayOrquesta, int limiteMusico, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int contadorMusico=0;
    int contadorOrquesta=0;
    float promedio=0;

    if (arrayMusico!=NULL && arrayOrquesta!=NULL && limiteMusico>0 && limiteOrquesta>0)
    {
        for (i=0;i<=limiteMusico;i++)
        {
            if (arrayMusico[i].isEmpty==1)
                continue;
            if (arrayMusico[i].isEmpty==0)
            {
                contadorMusico++;
            }
        }

        for (i=0;i<=limiteOrquesta;i++)
        {
            if (arrayOrquesta[i].isEmpty==1)
                continue;
            if (arrayOrquesta[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        promedio=contadorMusico/contadorOrquesta;
        printf("\nEl promedio de musicos por orquesta es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}

int musicos_segun_instrumento (Musicos* arrayMusicos, Instrumentos* arrayInstrumento, int limiteMusico, int limiteInstrumento)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;

    if (arrayInstrumento!=NULL && arrayMusicos!= NULL && limiteInstrumento>0 && limiteMusico>0)
    {
        instrumento_print(arrayInstrumento,limiteInstrumento);
        getInt("\nIngrese el id del instrumento para saber que musicos lo utilizan: \n","\nError, id no valido.\n",1,limiteInstrumento,1,&auxId);
        if (instrumentos_buscarID(arrayInstrumento,limiteInstrumento,auxId,&posicion)==0)
        {
            for (i=0;i<=limiteMusico;i++)
            {
                if (arrayMusicos[i].isEmpty==1)
                continue;

                if (arrayMusicos[i].isEmpty==0)
                {
                    if (arrayMusicos[i].idInstrumentos==auxId)
                    {
                        printf ("\nNombre: %s\n Id de musico: %d",arrayMusicos[i].nombre,arrayMusicos[i].idOrquestas);
                    }
                }
            }
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int musicos_segun_orquesta (Musicos* arrayMusicos, Orquestas* arrayOrquesta, int limiteMusico, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;

    if (arrayOrquesta!=NULL && arrayMusicos!= NULL && limiteOrquesta>0 && limiteMusico>0)
    {
        orquesta_print(arrayOrquesta,limiteOrquesta);
        getInt("\nIngrese el id de la orquesta para saber que musicos estan en ella: \n","\nError, id no valido.\n",1,limiteOrquesta,3,&auxId);
        if (orquestas_buscarID(arrayOrquesta,limiteOrquesta,auxId,&posicion)==0)
        {
            for (i=0;i<=limiteMusico;i++)
            {
                if (arrayMusicos[i].isEmpty==1)
                continue;

                if (arrayMusicos[i].isEmpty==0)
                {
                    if (arrayMusicos[i].idOrquestas)
                    {
                        printf ("\nNombre: %s. ",arrayMusicos[i].nombre);
                    }
                }
            }
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int musicos_ordenarDobleCriterio (Musicos* arrayMusico, int limite, int orderFirst, int orderSecond)                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Musicos buffer;
    int flagSwap;

    if(arrayMusico!=NULL && limite>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i<limite-1; i++)
            {
                if (arrayMusico[i].isEmpty==1)
                    continue;
                if (arrayMusico[i].isEmpty==0)
                {
                    if( ((strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) < 0) && orderFirst) ||
                        ((strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre)>0) && !orderFirst) )
                    {

                        buffer = arrayMusico[i];
                        arrayMusico[i] = arrayMusico[i+1];
                        arrayMusico[i+1] = buffer;
                        flagSwap=1;
                    }
                    else if(strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) == 0)
                    {
                        if( ((arrayMusico[i].edad < arrayMusico[i+1].edad) && orderSecond) ||
                           ((arrayMusico[i].edad > arrayMusico[i+1].edad) && !orderSecond) )
                        {

                            buffer = arrayMusico[i];
                            arrayMusico[i] = arrayMusico[i+1];
                            arrayMusico[i+1] = buffer;
                            flagSwap=1;
                        }
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}


/*
int cantidadTipos_orquestas (Orquestas* array[], int size)
{
    int retorno=-1;
    int i;
    int contadorSinfonica=0;
    int contadorFilarmonica=0;
    int contadorCamara=0;

    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==0)
            {
                switch (array[i].tipo)
                {
                case 1:
                    contadorSinfonica++;
                    break;
                case 2:
                    contadorFilarmonica++;
                    break;
                case 3:
                    contadorCamara++;
                    break;
                }
            }
        }
        printf ("\nCantidad de orquestas sinfonicas: %d",contadorSinfonica);
        printf ("\nCantidad de orquestas filarmonicas: %d",contadorFilarmonica);
        printf ("\nCantidad de orquestas camara: %d",contadorCamara);
        retorno=0;
    }
    return retorno;
}

int cantidadTipos_orquestas_nombres (Orquestas* array[], int size)
{
    int retorno=-1;
    int i;
    int contadorSinfonica=0;
    int contadorFilarmonica=0;
    int contadorCamara=0;

    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==0)
            {
                switch (array[i].tipo)
                {
                case 1:
                    contadorSinfonica++;
                    printf ("\nSINFONICA : Nombre de orquesta: %s",array[i].nombre);
                    break;
                case 2:
                    contadorFilarmonica++;
                    printf ("\nFILARMONICA : Nombre de orquesta: %s",array[i].nombre);
                    break;
                case 3:
                    printf ("\nCAMARA : Nombre de orquesta: %s",array[i].nombre);
                    contadorCamara++;
                    break;
                }
            }
        }
        printf ("\nCantidad de orquestas sinfonicas: %d",contadorSinfonica);
        printf ("\nCantidad de orquestas filarmonicas: %d",contadorFilarmonica);
        printf ("\nCantidad de orquestas camara: %d",contadorCamara);
        retorno=0;
    }
    return retorno;
}

int cantidadTipos_instrumentos(Instrumentos* array[], int size)
{
    int retorno=-1;
    int i;
    int contadorCuerdas=0;
    int contadorVientoMadera=0;
    int contadorVientoMetal=0;
    int contadorPercusion=0;

    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==0)
            {
                switch (array[i].tipo)
                {
                case 1:
                    contadorCuerdas++;
                    break;
                case 2:
                    contadorVientoMadera++;
                    break;
                case 3:
                    contadorVientoMetal++;
                    break;
                case 4:
                    contadorPercusion++;
                    break;
                }
            }
        }
        printf ("\nCantidad de instrumentos de cuerdas: %d",contadorCuerdas);
        printf ("\nCantidad de instrumentos de viento-madera: %d",contadorVientoMadera);
        printf ("\nCantidad de instrumentos de viento-metal: %d",contadorVientoMetal);
        printf ("\nCantidad de instrumentos de percusion: %d",contadorPercusion);
        retorno=0;
    }
    return retorno;
}

int cantidadTipos_instrumentos_nombres(Instrumentos* array[], int size)
{
    int retorno=-1;
    int i;
    int contadorCuerdas=0;
    int contadorVientoMadera=0;
    int contadorVientoMetal=0;
    int contadorPercusion=0;

    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==0)
            {
                switch (array[i].tipo)
                {
                case 1:
                    contadorCuerdas++;
                    printf ("\nCUERDA- Nombre de instrumento: %s",array[i].nombre);
                    break;
                case 2:
                    contadorVientoMadera++;
                    printf ("\nVIENTO-MADERA- Nombre de instrumento: %s",array[i].nombre);
                    break;
                case 3:
                    contadorVientoMetal++;
                    printf ("\nVIENTO-METAL- Nombre de instrumento: %s",array[i].nombre);
                    break;
                case 4:
                    contadorPercusion++;
                    printf ("\nPERCUSION- Nombre de instrumento: %s",array[i].nombre);
                    break;
                }
            }
        }
        printf ("\nCantidad de instrumentos de cuerdas: %d",contadorCuerdas);
        printf ("\nCantidad de instrumentos de viento-madera: %d",contadorVientoMadera);
        printf ("\nCantidad de instrumentos de viento-metal: %d",contadorVientoMetal);
        printf ("\nCantidad de instrumentos de percusion: %d",contadorPercusion);
        retorno=0;
    }
    return retorno;
}

int cantidadOrquestas(Orquestas* array[], int size)
{
    int retorno=-1;
    int i;
    int contadorOrquesta=0;
    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==1)
                continue;
            if (array[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        printf ("\nLa cantidad de orquestas en total es: %d \n",contadorOrquesta);
        retorno=0;
    }
    return retorno;
}

int cantidadInstrumentos(Instrumentos* array[], int size)
{
    int retorno=-1;
    int i;
    int contadorInstrumento=0;
    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==1)
                continue;
            if (array[i].isEmpty==0)
            {
                contadorInstrumento++;
            }
        }
        printf ("\nLa cantidad de instrumentos en total es: %d \n",contadorInstrumento);
        retorno=0;
    }
    return retorno;
}

int cantidadMusicos(Musicos* array[], int size)
{
    int retorno=-1;
    int i;
    int contadorMusico=0;
    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==1)
                continue;
            if (array[i].isEmpty==0)
            {
                contadorMusico++;
            }
        }
        printf ("\nLa cantidad de musicos en total es: %d \n",contadorMusico);
        retorno=0;
    }
    return retorno;
}
int promedioEdad_musicos(Musicos* array[],int size)
{
    int retorno=-1;
    int i;
    int contador=0;
    int acumulador=0;
    float promedio=0;

    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==1)
                continue;
            if (array[i].isEmpty==0)
            {
                acumulador=arrayMusicos[i].edad+acumulador;
                contador++;
            }
        }
        promedio=acumulador/contador;
        printf ("\nEl promedio de la edad de los musicos en todas las orquestas es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}

int promedio_musicos_orquesta(Musicos* array[], Orquestas* array[], int sizeM, int sizeO)
{
    int retorno=-1;
    int i;
    int contadorMusico=0;
    int contadorOrquesta=0;
    float promedio=0;

    if (array!=NULL && array!=NULL && sizeM>0 && size0>0)
    {
        for (i=0;i<=sizeM;i++)
        {
            if (array[i].isEmpty==1)
                continue;
            if (array[i].isEmpty==0)
            {
                contadorMusico++;
            }
        }

        for (i=0;i<=sizeO;i++)
        {
            if (array[i].isEmpty==1)
                continue;
            if (array[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        promedio=contadorMusico/contadorOrquesta;
        printf("\nEl promedio de musicos por orquesta es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}
int musicos_instrumentos (Musicos* array[], Instrumentos* array[], int sizeM, int sizeI)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;

    if (array!=NULL && array!= NULL && sizeI>0 && sizeM>0)
    {
        instrumentos_print(array[],size);
        getInt("\nIngrese el id del instrumento para saber que musicos lo utilizan: \n","\nError, id no valido.\n",1,limiteInstrumento,3,&auxId);
        if (instrumento_buscarID(array,sizeI,auxId,&posicion)==0)
        {
            for (i=0;i<=sizeM};i++)
            {
                if (array[i].isEmpty==1)
                continue;

                if (array[i].isEmpty==0)
                {
                    if (array[i].idInstrumentos==auxId)
                    {
                        printf ("\nNombre: %s. Id de musico: %d. ",arrayMusicos[i].nombre,arrayMusicos[i].idMusico);
                    }
                }
            }
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int musicos__orquestas (Musicos* array[], Orquestas* array[], int sizeM, int sizeO)
{
    int retorno=-1;
    int i;
    int auxId;
    int posicion;

    if (array!=NULL && array!= NULL && sizeO>0 && sizeM>0)
    {
        orquestas_print(array,sizeO);
        getInt("\nIngrese el id de la orquesta para saber que musicos estan en ella: \n","\nError, id no valido.\n",1,sizeO,3,&auxId);
        if (orquestas_buscarID(array,sizeO,auxId,&posicion)==0)
        {
            for (i=0;i<=sizeM;i++)
            {
                if (array[i].isEmpty==1)
                continue;

                if (array[i].isEmpty==0)
                {
                    if (array[i].idOrquestas==auxId)
                    {
                        printf ("\nNombre: %s. ",arrayMusicos[i].nombre);
                    }
                }
            }
            retorno=0;
        }else
            printf ("\nNo se encontro este id.\n");
    }
    return retorno;
}

int musicos_ordenarDobleCriterio (Musicos* array[], int size, int orderFirst, int orderSecond)                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Musico buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i<size-1; i++)
            {
                if (array[i].isEmpty==1)
                    continue;
                if (array[i].isEmpty==0)
                {
                    if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                        ((strcmp(array[i].nombre,array[i+1].nombre)>0) && !orderFirst) )
                    {

                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                        flagSwap=1;
                    }
                    else if(strcmp(array[i].nombre,arrayMusico[i+1].nombre) == 0)
                    {
                        if( ((array[i].edad < array[i+1].edad) && orderSecond) ||
                           ((array[i].edad > array[i+1].edad) && !orderSecond) )
                        {

                            buffer = array[i];
                            array[i] = array[i+1];
                            array<[i+1] = buffer;
                            flagSwap=1;
                        }
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}
*/
/////////////////////////////////////////////////////
void MenuInformes()
{
    printf("\n\nMENU INFORMES\n");
    printf("--------------\n");
    printf("1 - CANTIDAD TIPO ORQUESTAS A\n");
    printf("2 - CANTIDAD TIPOS INSTRUMENTOS B\n");
    printf("3 - CANTIDAD DE ORQUESTAS C\n");
    printf("4 - CANTIDAD DE INSTRUMENTOS D\n");
    printf("5 - CANTIDAD DE MUSICOS E\n");
    printf("6 - CANTIDAD TIPO DE ORQUESTAS y NOMBRE F\n");
    printf("7 - CANTIDAD TIPO DE INSTRUMENTOS Y NOMBRE G\n");
    printf("8 - PROMEDIO EDAD MUSICOS H\n");
    printf("9 - PROMEDIO MUSICOS POR ORQUESTAS I\n");
    printf("10 - MUSICOS INSTRUMENTOS J\n");
    printf("11 - MUSICOS ORQUESTAS Q\n");
    printf("12 - MUSICOS DOBLE ORDENAMIENTO L\n");
    printf("13 - SALIR M\n");
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
//////////////////////////////////////////////////////////////






