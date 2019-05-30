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
Lista * crearLista();
Nodo * crearNodo(int v, int p);
int obtenerNumeroVertices ( Lista * lista );