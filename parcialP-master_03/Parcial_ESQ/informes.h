#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

typedef struct
{
  int contador;
  char auxFecha[9];

}aux_prestamos;




#endif // INFORMES_H_INCLUDED

int Informes_listarMusicos(Musicos arrayA[], Instrumentos arrayB[], int sizeI, int sizeJ);
int cantidad_tipos_orquesta (Orquestas* arrayOrquesta, int limiteOrquesta);
int cantidad_tipos_instrumento (Instrumentos* arrayInstrumento, int limiteInstrumento);
int cantidadOrquestas(Orquestas* arrayOrquesta, int limiteOrquesta);
int cantidadInstrumentos(Instrumentos* arrayInstrumento, int limiteInstrumento);
int cantidadMusicos(Musicos* arrayMusico, int limiteMusico);
int cantidad_tipos_orquesta_y_nombres (Orquestas* arrayOrquesta, int limiteOrquesta);
int cantidad_tipos_instrumento_y_nombres (Instrumentos* arrayInstrumento, int limiteInstrumento);
int promedio_edad_musicos(Musicos* arrayMusicos,int limiteMusicos);
int promedio_cantidad_musicos_por_orquesta(Musicos* arrayMusico, Orquestas* arrayOrquesta, int limiteMusico, int limiteOrquesta);
int musicos_segun_instrumento (Musicos* arrayMusicos, Instrumentos* arrayInstrumento, int limiteMusico, int limiteInstrumento);//instrumento segun orquesta hacer
int musicos_segun_orquesta (Musicos* arrayMusicos, Orquestas* arrayOrquesta, int limiteMusico, int limiteOrquesta);//instrumento segun musico hacer
int musicos_ordenarDobleCriterio (Musicos* arrayMusico, int limite, int orderFirst, int orderSecond);
void MenuInformes();
void MenuOrquestasPrincipal();

