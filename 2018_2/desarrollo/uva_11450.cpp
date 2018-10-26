#include <bits/stdc++.h>

using namespace std;
int main (){

  int testcases;
  int M,C;
  //M: Money
  // C: nro prendas
  int K; //Numero modelos

  cin >> testcases;
  int prenda_precio[20][20];

  for (int i = 0; i < testcases; i++) {
    cin >> M;
    cin >> C;

    for (int j = 0; j < C; j++) {
      cin >> K;
      for (int k = 0; k < K ; k++) {
        int temp;
        cin >> temp;
        prenda_precio[j][k] = temp;
      }
    }

    for (size_t i = 0; i < count; i++) {
      for (int j = 0; j < count; i++) {
        /* code */
      }
    }

  }

  return 0;
}
