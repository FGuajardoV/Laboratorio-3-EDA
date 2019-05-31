#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/********** Estructuras **********/
typedef struct Nodo
{
    int vertice;
    int peso;
    struct Nodo *sig;
} Nodo;

typedef struct Lista
{
    int vertice;
    Nodo *listaAdyacencia;
    struct Lista *sgte;
} Lista;


/********** Prototipos **********/
Lista * leerArchivo ( char fileName[] );
void escribirArchivo (int v, int a, int c, int r, int max, int min, int p, int conexo);
Lista * crearLista();
Nodo * crearNodo(int v, int p);
int obtenerNumeroVertices ( Lista * lista );
int obtenerGradoMaximo ( Lista * lista );
int obtenerGradoMinimo ( Lista * lista );
int grafoRegular ( Lista * lista);
void liberarMemoria ( Lista * lista );