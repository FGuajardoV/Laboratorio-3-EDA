#include "programa.h"

// Funcion principal del programa, la cual ejecuta las dos funciones principales.
int main( int argc, char* argv[] )
{
    printf ( "\n\n************************ Inicio Programa ************************\n\n" );
    // Para esta parte del codigo, tenemos que el usuario ingresara parametros junto a la ejecucion
    //del programa, para la primera funcionalidad tenemos los siguientes parametros:
    //argv[2] = cantidad de vertices.
    //argv[3] = cantidad de aristas.
    //argv[4] = grafo con (0) o sin (1) ciclos.
    //argv[5] = grafo regular (0) o no regular (1).
    //argv[6] = grado max grafo.
    //argv[7] = grado min grafo.
    //argv[8] = suma total pesos.
    if ( argc == 9 && ( atoi ( argv[ 1 ] ) == 1 ) )
    {
        
        printf ( "Completada la generacion, revise el archivo 'grafo.out'" );
    }

    // Para esta parte del codigo, para la segunda funcionalidad tenemos los siguientes parametros:
    //argv[2] = nombre del archivo donde se encuentra el grafo.
    else if ( argc == 3 &&  ( atoi ( argv[ 1 ] ) == 2 ) )
    {
        Lista * listaAdyacencia;
        int vertices, aristas = 0, ciclos = 0, regular, gradoMax, gradoMin, pesos = 0, conexo = 0;
        
        // Se crea la lista a partir de la funcion leerArchivo
        listaAdyacencia = leerArchivo ( argv[ 2 ] );

        // A continuacion se obtienen los valores a ingresar en la funcion de escritura del output
        vertices = obtenerNumeroVertices ( listaAdyacencia );
        //aristas =
        //ciclos =
        regular = grafoRegular ( listaAdyacencia );
        gradoMax = obtenerGradoMaximo ( listaAdyacencia );
        gradoMin = obtenerGradoMinimo ( listaAdyacencia );
        //pesos =
        //conexo =
        
        // Por medio de la funcion escribirArchivo, se crea un archivo output con los parametros
        //solicitados.
        escribirArchivo ( vertices, aristas, ciclos, regular, gradoMax, gradoMin, pesos, conexo);
        printf ( "Completado el analisis, revise el archivo 'parametros.out'" );
        liberarMemoria ( listaAdyacencia );
    }

    // Si hay errores con la cantidad de parametros ingresados por consola, se le informara al
    //usuario.
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

// Funcion que leera el archivo ingresado por el usuario, para rescatar el grafo que este presenta
//y almacenarlo en el TDA.
Lista * leerArchivo ( char fileName[] )
{
    //Se usa un auxiliar para poder leer las lineas de string dentro del archivo.
    char auxStr[ 512 ];
    FILE * archivo = fopen( fileName, "r" );

    // Si ocurre un problema al leer el archivo, este problema se le informara al usuario.
    if ( archivo == NULL)
    {
        perror ( "Error al intentar de abrir el archivo... " );
        printf ( "\n\n************************** Fin Programa *************************\n\n" );
        exit ( EXIT_FAILURE );
    }

    // Se crean auxiliares para no perder el nodo que se esta completando en el momento
    //en el caso especifico de la lista, es para no perder la cabecera.
    Lista * lista;
    Nodo * nodo;
    Lista * auxLista;
    Nodo * auxNodo;

    // Se lee el archivo hasta que no haya mas strings, esta funcion lee el string hasta el primer 
    //espacio. 
    while ( ( fscanf ( archivo, "%s", auxStr ) ) != EOF )
    { 
        // Si el largo corresponde a un 1, este es un vertice, por lo cual, si el puntero a la 
        //cabecera de la lista enlazada esta vacio (NULL) este vertice sera cabecera de la lista
        //de adyacencia.
        if ( strlen ( auxStr ) == 1 && lista == NULL )
        {
            auxLista = crearLista();
            auxLista -> vertice = atoi ( auxStr );
            lista = auxLista;
        }

        // Al no estar vacia la cabecera, se procede a cambiar el nodo que se analiza, siempre
        //procurando guardar el primero, para no perder la lista
        else if ( strlen ( auxStr ) == 1 )
        {
            Lista * aux = auxLista;
            auxLista = crearLista();
            auxLista -> vertice = atoi ( auxStr );
            aux -> sgte = auxLista;
            nodo = NULL;
        }

        // Si el largo es 3, es porque es la arista, o sea, esta separado por una coma el vertice
        //al cual llega y el peso de esta arista.
        else if ( strlen ( auxStr ) == 3 )
        {
            int vertice, peso;
            // Se usa el delimitador vacio para separar el elemento: (v , p)
            char delim[] = ",";
            // Funcion de la libreria string.h
            char *ptr = strtok ( auxStr, delim );

            // Debe de ser llamado muchas veces para lograr separar el string.
            while ( ptr != NULL )
            {
                ptr = strtok ( NULL, delim );
            }
            // Luego, nos entregara los datos en ascii, por lo que se transforman a Integer
            vertice = auxStr[0] - 48;
            peso = auxStr[2] - 48;

            // Para almacenar el nodo, si el vertice de la lista no tiene lista de aristas, este 
            //nodo sera el inicial.
            if ( nodo == NULL )
            {
                nodo = crearNodo ( vertice, peso );
                auxLista -> listaAdyacencia = nodo;
                auxNodo = nodo;
            }
            // Sino, se agrega a la lista
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

// Funcion encargada de escribir los parametros en el archivo output,
void escribirArchivo (int v, int a, int c, int r, int max, int min, int p, int conexo)
{   
    // Se crean los strings auxiliares para almacenar la trasnformacion de Integer a Str para 
    //poder escribir en el archivo.
    char vC[ 256 ], maxC[ 256 ], aC[ 256 ], cC[ 256 ], rC[ 256 ], minC[ 256 ], pC[ 256 ], conexoC[ 256 ];
    // Se crea un nuevo archivo para poder escribir en el.
    FILE * output = fopen( "parametros.out", "w");
    
    // Se transforma el Integer a Str.
    sprintf ( vC, "%d\n", v );
    // Se escribe en el archivo.
    fputs ( vC, output );

    sprintf ( aC, "%d\n", a );
    fputs ( aC, output );

    sprintf ( cC, "%d\n", c );
    fputs ( cC, output );

    sprintf ( rC, "%d\n", r );
    fputs ( rC, output );

    sprintf ( maxC, "%d\n", max );
    fputs ( maxC, output );

    sprintf ( minC, "%d\n", min );
    fputs ( minC, output );

    sprintf ( pC, "%d\n", p );
    fputs ( pC, output );

    sprintf ( conexoC, "%d\n", conexo );
    fputs ( conexoC, output );

    // Se cierra el archivo para liberar la memoria.
    fclose ( output );
}

// Funcion que crea el TDA Lista.
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

// Funcion que crea el TDA Nodo. Con los datos iniciales del vertice y el peso.
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

// Funcion que retorna el numero de vertices presentes en un grafo. 
int obtenerNumeroVertices ( Lista * lista )
{
    int vertices = 0; // Si el grafo esta vacio retornara 0
    Lista * aux = lista;

    // Recorre la lista enlazada, sumando por cada elemento que encuentre uno al contador, puesto
    //que el grafo se representa con lista enlazada de lista enlazadas, la lista "superior" posee 
    //los vertices de este grafo, por lo cual solo basta con contarlos.
    while ( aux != NULL )
    {
        vertices++;
        aux = aux -> sgte;
    }

    return vertices;
}

// Funcion que busca el vertice que posea mas "conexiones".
int obtenerGradoMaximo ( Lista * lista )
{
    // Iniciamos con -1 para encontrar el mayor.
    int gradoMax = -1;
    int auxGrado = 0;
    Lista * auxLista = lista;
    Nodo * auxNodo;

    // Como el TDA esta formado de listas de listas, se realiza un ciclo doble para lograr 
    //analizar todos sus elementos
    while ( auxLista != NULL )
    {
        auxNodo = auxLista -> listaAdyacencia;

        if ( auxNodo == NULL )
            return 0;

        while ( auxNodo != NULL )
        {
            auxGrado++;
            auxNodo = auxNodo -> sig;
        }

        // Se busca el vertice que posea mas "conexiones".
        if ( auxGrado > gradoMax )
            gradoMax = auxGrado;
        
        auxGrado = 0;
        auxLista = auxLista -> sgte;
    }   
    return gradoMax;
}

// Al igual que la funcion anterior, se busca un extremo, en este caso el que tenga menores 
//"conexiones".
int obtenerGradoMinimo ( Lista * lista)
{
    //Iniciamos con un numero grande para buscar el menos al comparar.
    int gradoMin = 10000000000000;
    int auxGrado = 0;
    Lista * auxLista = lista;
    Nodo * auxNodo;

    while ( auxLista != NULL )
    {
        auxNodo = auxLista -> listaAdyacencia;

        if ( auxNodo == NULL )
            return 0;

        while ( auxNodo != NULL )
        {
            auxGrado++;
            auxNodo = auxNodo -> sig;
        }

        if ( auxGrado < gradoMin )
            gradoMin = auxGrado;
        
        auxGrado = 0;
        auxLista = auxLista -> sgte;
    }   
    return gradoMin;
}

// Un grafo regular es aquel que posee el mismo peso en todas sus aristas, esta funcion se encarga
//de verificar esta cualidad.
int grafoRegular ( Lista * lista )
{
    Lista * auxLista = lista;
    Nodo * auxNodo;
    // Bajo el supuesto que los pesos no pueden ser negativos.
    int auxData = -12; 

    // Se recorre de la misma forma, al ser un "arreglo bidimensional".
    while ( auxLista != NULL )
    {
        auxNodo = auxLista -> listaAdyacencia;

        while ( auxNodo != NULL )
        {   
            // Se almacena el peso de la primera arista para comparar con el resto.
            if ( auxData == -12 )
                auxData = auxNodo -> peso;
            // A la primera diferencia retorna negativo.
            if ( auxData != auxNodo -> peso )
                return 0;
            
            auxNodo = auxNodo -> sig; 
        }
        auxLista = auxLista -> sgte;
    }

    return 1;
}

// Funcion que libera la memoria de la lista enlazada, nodo por nodo, y por cada nodo, borra la 
//lista que se encuentra en el.
void liberarMemoria (Lista * lista )
{
    while ( lista != NULL )
    {
        Nodo * nodo = lista -> listaAdyacencia;

        while ( nodo != NULL )
        {
            // Se cambia la cabecera, para no perder el resto de la lista.
            Nodo * auxiliarN = nodo -> sig;
            free ( nodo );
            nodo = auxiliarN;
        }

        // Se cambia la cabecera, para no perder el resto de la lista.
        Lista * auxiliarL = lista -> sgte;
        free ( lista );
        lista = auxiliarL;
    }
}