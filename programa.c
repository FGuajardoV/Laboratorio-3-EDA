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
        Lista * listaAdyacencia;
        int vertices, pesos;

        listaAdyacencia = leerArchivo ( argv[2] );
        vertices = obtenerNumeroVertices ( listaAdyacencia );
    }

    else if ( argc == 1 )
    {
        printf ( "ERROR: Sin parametros de analisis, porfavor vuelva a iniciar el programa.\n" );
    }

    else 
    {
        printf ( "ERROR: Cantidad de parametros incorrecta, porfavor vuelva a iniciar el programa.\n" );
    }

    printf ( "\n\n************************** Fin Programa *************************\n\n" );
}

Lista * leerArchivo ( char fileName[] )
{
    char auxStr[ 256 ];
    FILE * archivo = fopen( fileName, "r" );

    if ( archivo == NULL)
    {
        perror ( "Error al intentar de abrir el archivo... " );
        printf ( "\n\n************************** Fin Programa *************************\n\n" );
        exit ( EXIT_FAILURE );
    }

    Lista * lista;
    Nodo * nodo;
    Lista * auxLista;
    Nodo * auxNodo;

    while ( ( fscanf ( archivo, "%s", auxStr ) ) != EOF )
    { 
        if ( strlen ( auxStr ) == 1 && lista == NULL )
        {
            auxLista = crearLista();
            auxLista -> vertice = atoi ( auxStr );
            lista = auxLista;
        }

        else if ( strlen ( auxStr ) == 1 )
        {
            Lista * aux = auxLista;
            auxLista = crearLista();
            auxLista -> vertice = atoi ( auxStr );
            aux -> sgte = auxLista;
            nodo = NULL;
        }

        else if ( strlen ( auxStr ) == 3 )
        {
            int vertice, peso;
            char delim[] = " ";

            char *ptr = strtok ( auxStr, delim );

            while ( ptr != NULL )
            {
                ptr = strtok ( NULL, delim );
            }

            vertice = auxStr[0] - 48;
            peso = auxStr[2] - 48;

            if ( nodo == NULL )
            {
                nodo = crearNodo ( vertice, peso );
                auxLista -> listaAdyacencia = nodo;
                auxNodo = nodo;
            }

            else 
            {
                Nodo * aux = auxNodo;
                auxNodo = crearNodo ( vertice, peso );
                aux -> sig = auxNodo;
            }
        }
    }

    fclose(archivo);
    return lista;
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
		return lista;
	}

	// En caso contrario se retorna nulo.
	else
    {
		return NULL;
	}

}

Nodo * crearNodo(int v, int p)
{
    // Se pide el espacio de memoria para la estructura.
	Nodo * nodo = ( Nodo * ) malloc ( sizeof ( Nodo ) );

    // Si la asignacion de memoria es exitosa, se inicializan las variables.
	if ( nodo != NULL )
    {
        nodo -> vertice = v;
	    nodo -> peso = p;
		nodo -> sig = NULL;
		return nodo;
	}

	// En caso contrario se retorna nulo.
	else
    {
		return NULL;
	}
}

int obtenerNumeroVertices ( Lista * lista )
{
    int vertices = 0;
    Lista * aux = lista;

    while ( aux != NULL )
    {
        vertices++;
        aux = aux -> sgte;
    }

    return vertices;
}