#include <bits/stdc++.h>

/*

Codigo extraido de https://tausiq.wordpress.com/2010/07/21/uva-10003-cutting-sticks/
*/


#define N 1000000
using namespace std;

/*Variables Globales*/
int l, n;
int c [50 + 3];
int dp [50 + 3] [50 + 3];

int bktk (int s, int e)
{
//  cout << "s:"<<s<<" e:" <<e<<endl;
  /*
  s:pos inicial que se hace el corte
  e:posicion final en que se hace el corte

  */
    //Costo 0 si no se hace el corte
    if ( s + 1 == e ) return 0;

    //Buscar si el costo de realizar el corte ya esta en tabla de DP
    if ( dp [s] [e] != -1 )
        return dp [s] [e];

    int cost = 0;
    int minimum = INT_MAX;

    /*El costo minimo de realizar el corte s,e es calculado revisando el coste minimo al realizar
    un corte consideranco todas las posiciones posibles entre s y e y sumandole la diferencia entre el coste de realizar el corte en e con
    la diferencia de realizar el corte en s */

    //Si el costo es menor al anterior se almace, obteniendo recursivamente el coste minimo

    for ( int i = s + 1; i < e; i++ ) {
        cost = bktk (s, i) + bktk (i, e) + c [e] - c [s];
        if ( cost < minimum ) minimum = cost;
    }

    return dp [s] [e] = minimum;
}

//Resetea los valores de la matriz
void reset ()
{
    for ( int i = 0; i < 53; i++ ) {
        for ( int j = 0; j < 53; j++ )
            dp [i] [j] = -1;
    }
}

int main ()
{
  //Escanear largo del tronco. Deternerse si es 0 o si ya no hay nada que leer
    while ( scanf ("%d", &l) && l ) {
        scanf ("%d", &n); //Leer Numero de cortes

        //Leer los cortes y almacenarlos
        for ( int i = 1; i <= n; i++ )
            scanf ("%d", &c [i]);

        //Caso base, corte en pos 0 no tiene costo
        c [0] = 0;

        //Asigna al corte N+1 el costo del palo completo
        c [n + 1] = l;

        reset (); // Inicializa la matriz de DP

        /*Llama a la funcion recursiva con el caso inicial de que el corte n+1 resulte con un tronco que empieza en 0 y termina
        en l , representando el palo inicial */
        printf ("The minimum cutting is %d.\n", bktk (0, n + 1));
    }

    return 0;
}
