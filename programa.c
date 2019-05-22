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
        //argv[2] = nombre archivo.
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