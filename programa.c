#include "programa.h"

int main( int argc, char* argv[] )
{
    printf ( "\n\n************************ Inicio Programa ************************\n\n" );

    if ( argc == 9 && strcmp ( argv[1], "0" ) )
    {
        //argv[2] = cantidad de vertices.
        //argv[3] = cantidad de aristas.
        //argv[4] = grafo con (0) o sin (1) ciclos.
        //argv[5] = grafo regular (0) o no regular (1).
        //argv[6] = grado max grafo.
        //argv[7] = grado min grafo.
        //argv[8] = suma total pesos.
    }

    else if ( argc == 3 && strcmp ( argv[1], "1" ) )
    {
        Matriz * matriz;

        matriz = leerArchivo ( argv[2] );
    }

    else if ( argc == 1 )
    {
        printf("ERROR: Sin parametros de analisis, porfavor vuelva a iniciar el programa.\n");
    }

    else 
    {
        printf("ERROR: Cantidad de parametros incorrecta, porfavor vuelva a iniciar el programa.\n");
    }

    printf ( "\n\n************************** Fin Programa *************************\n\n" );
}

Matriz * leerArchivo ( char fileName[] )
{
    int vertices = 0;
    int aristas = 0;
    int pesos = 0;
    Matriz * matriz = crearMatriz(); 
    FILE * archivo = fopen( fileName, "r" );

    if ( archivo == NULL)
    {
        perror ( "Error al intentar de abrir el archivo... " );
        printf ( "\n\n************************** Fin Programa *************************\n\n" );
        exit ( EXIT_FAILURE );
    }

    fclose(archivo);

    matriz -> verticesTotales = vertices;
    matriz -> aristasTotales = aristas;
    matriz -> pesosTotal = pesos;
    return matriz;
}

Matriz * crearMatriz()
{
    // Se pide el espacio de memoria para la estructura.
	Matriz * matriz = ( Matriz * ) malloc ( sizeof ( Matriz ) );

	// Si la asignacion de memoria es exitosa, se inicializan las variables.
	if ( matriz != NULL )
    {
	    matriz -> verticesTotales = 0;
        matriz -> aristasTotales = 0;
        matriz -> pesosTotal = 0;
        matriz -> matrix = NULL;
        return matriz;
	}

	// En caso contrario se retorna nulo.
	else
    {
		return NULL;
	}
}

Lista * crearLista()
{
    // Se pide el espacio de memoria para la estructura.
	Lista * lista = ( Lista * ) malloc ( sizeof ( Lista ) );

    // Si la asignacion de memoria es exitosa, se inicializan las variables.
	if ( lista != NULL )
    {
        lista -> vertice = 0;
	    lista -> listaAdyacencia = NULL;
		lista -> sgte = NULL;
        lista -> ant = NULL;
		return lista;
	}

	// En caso contrario se retorna nulo.
	else
    {
		return NULL;
	}

}

Nodo * crearNodo()
{
    // Se pide el espacio de memoria para la estructura.
	Nodo * nodo = ( Nodo * ) malloc ( sizeof ( Nodo ) );

    // Si la asignacion de memoria es exitosa, se inicializan las variables.
	if ( nodo != NULL )
    {
        nodo -> vertice = 0;
	    nodo -> peso = 0;
		nodo -> sig = NULL;
		return nodo;
	}

	// En caso contrario se retorna nulo.
	else
    {
		return NULL;
	}
}