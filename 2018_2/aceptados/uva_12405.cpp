#include <cstdio>

using namespace std;

/*Solucion NO propia
https://problemsolvingnotes.wordpress.com/2012/06/18/uva-12405-scarecrow/
*/
int main(){
    int T,N;
    char s[100]; //String par aalmacenar terreno

    scanf("%d",&T); //Leer Numero casos

    for(int tc = 1;tc <= T;++tc){
        scanf("%d %s",&N,s); //leer el numero de celdas y guardar
        //la linea del campo en el string.

        int ans = 0; // Cantidad inicial de espantapajaros

        for(int i = 0;i < N;){//Recorrer el campo
            if(s[i] == '#') ++i; //Si no es terreno fertil se avanza
            else{
                ++ans; //Sumar un espantapajaros
                i += 3; //Saltarse 3 celdas, debido a que un espantapajaros puede cubrir 3 celdas
                //Avanzar 3 iteraciones
            }
        }
/*La estrategia greedy asume que siempre al poner un espantapajaros cada 3 celdas se tiene un optimo*/
        printf("Case %d: %d\n",tc,ans); //Imprimir resultados
    }

    return 0;
}
