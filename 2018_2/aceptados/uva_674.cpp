#include <bits/stdc++.h>

/*Codigo extraido de https://github.com/oneillcode/Youtube-Tutorials/blob/master/Dynamic%20Programming/CoinChange.java

Se adapto para c++

*/
using namespace std;
//Vector monedas de menor a mayor
vector<int> monedas ={1,5,10,25,50};



int opcionesParaCambio(int monto){
  int totalCombinaciones =0;
  vector<int> tabla(monto+1);

  //Valor inicial en 0 para hacer de caso base y construir el resto de los valores
  tabla[0] = 1;

  //Iterar cada una de las monedas
  for (int j = 0; j < monedas.size(); j++) {
    int monedaActual = monedas[j];

    for (int i = 1; i <= monto; i++) {
        if(monedaActual <= i){
          /*Si la moneda actual es menor o igual que el monto, el valor de las combinaciones posibles para el vuelto
          con las monedas que se han revisado sera igual al valor que habia antes de combinaciones mas las combinaciones aportadas por  la moneda nueva

          Esto se hace sumando el contenido de la celda i - moneda actual, siendo i el monto que esta siendo considerado*/
          tabla[i] += tabla[i-monedaActual];
        }
    }
  }
  return tabla[monto];


}


int main(){
    int money;
    while (cin >> money)
    {
        cout << opcionesParaCambio(money) << endl;
    }
    return 0;
}
