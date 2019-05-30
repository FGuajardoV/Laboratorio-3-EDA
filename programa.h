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
    struct Lista *ant;
} Lista;

typedef struct 
{
    int verticesTotales;
    int aristasTotales;
    int pesosTotal;
    Lista *matrix;
} Matriz;

/********** Prototipos **********/
Matriz * leerArchivo ( char fileName[] );
Matriz * crearMatriz();
Lista * crearLista();
Nodo * crearNodo();