/*Codigo extraido de https://www.pwzxxm.com/2016/uva-108/     */


#include<iostream>
#include<algorithm>
#define maxn 100+5
using namespace std;
int v, N, sum[maxn][maxn] = {0};

void solve() {
    int MaxSum = -200;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = i; k <= N; k++) {
                for (int l = j; l <= N; l++) {
                  /*Teniendo ya calculada la tabla de memoizacion del paso previo,
                    Se calculan, utilizando 4 loops.

                    En este caso se van restando la suma de las submatrices cuyo valor no se está considerando.
                    Se resta: - suma del subarray por arriba del considerando
                     - suma del subarray que está a la izquierda.

                     Finalmente se vuelve a sumar aquella sección que se borró 2 veces en las restas anteriores.

                  */
                    //Se queda con el maximo entre el ya encontrado y la suma del sub array visitado
                    MaxSum = max(MaxSum, sum[k][l]-sum[i-1][l]-sum[k][j-1]+sum[i-1][j-1]);
                }
            }
        }
    }
    cout << MaxSum << endl;
}

int main() {
    while(cin >> N) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> v;
                /* A medida que lee los valores del input se va calculando
                la tabla de memoizacion considerando el sub arreglo superior, el subarreglo a
                la izquierda y restando la parte en que se superponen, que se estaria sumando 2
                veces.
                La tabla guarda la suma de todos los subarray que parten en la esquina superior izquierda
                 */
            //     cout << "v: "<<v<<endl;

              //   cout << "sum[i-1][j]: "<<sum[i-1][j]<<endl;
              //  cout << "sum[i][j-1]: "<<sum[i][j-1]<<endl;
              //  cout << "sum[i-1][j-1]: "<<sum[i][j-1]<<endl;
                sum[i][j] = v+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];

            //    cout << "Nuevo sum[i][j]: "<<sum[i][j]<<endl;
            }
        }

        solve();
    }

    return 0;
}
