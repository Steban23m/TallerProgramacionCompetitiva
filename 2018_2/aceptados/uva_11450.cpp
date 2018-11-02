#include <bits/stdc++.h>

using namespace std;
#define CUT -999999;
vector<vector<int>>prenda_precio(20);
int dp[200][20];
int bestShopOfclothes(int budgetLeft, int currentPiece,int totalclothes){

  if(budgetLeft < 0) return CUT;

  if(dp[budgetLeft][currentPiece] != -12456){
  //  cout << "Sacando de la tabla" << endl;
    return dp[budgetLeft][currentPiece];
  }
  //cout <<"#BestShop budget"<<budgetLeft<<", pieza:"<<currentPiece << endl;
  int moneySpend =CUT;
  int options = prenda_precio[currentPiece].size();
  int temp = CUT;

    if(currentPiece < totalclothes-1){
    //  cout << "Aun no es la ultima pieza de ropa;" << endl;
    //  cout << "Opciones : "<<options<<endl;
      for (int i = 0; i < options; i++) {
        temp = prenda_precio[currentPiece][i]  + bestShopOfclothes(budgetLeft-prenda_precio[currentPiece][i], currentPiece+1, totalclothes);
    //    cout<<"Dinero gastado : " <<temp <<endl;
        if(temp > moneySpend){
      //    cout<<"Mejora lo gastado anterior : " << moneySpend << "menor que " << temp <<endl;
          moneySpend = temp;
        }
    }

    dp[budgetLeft][currentPiece] = moneySpend;
  //  cout << "Retornando pieza ropa: " << currentPiece <<" mejor gasto :" <<moneySpend <<" con pp "<< budgetLeft << endl;
    return moneySpend;
  }
  else{
    //cout <<"ultima prenda" << endl;
    //Ultima prenda, retornar precio de la mejor
    for (int i = 0; i < options; i++) {
    //  cout << "Prenda con coste "<< prenda_precio[currentPiece][i] <<endl;
      if (prenda_precio[currentPiece][i] <= budgetLeft && moneySpend < prenda_precio[currentPiece][i]) {
      //  cout << "Mejora lo gastado y esta dentro de presupuesto" <<endl;
        moneySpend = prenda_precio[currentPiece][i];
      }
    }
  }
  dp[budgetLeft][currentPiece] = moneySpend;
  //cout << "Retornando pieza ropa: " << currentPiece <<" mejor gasto :" <<moneySpend <<" con pp "<< budgetLeft << endl;
  return moneySpend;
}

int main (){

  int testcases;
  int M,C;
  //M: Money
  // C: nro prendas
  int K; //Numero modelos

  cin >> testcases;



  for (int i = 0; i < testcases; i++) {

    for (int j = 0; j < 200; j++) {
          for (int z = 0; z < 20; z++) {
            dp[j][z] = -12456;
          }
    }
    cin >> M;
    cin >> C;

    for (int j = 0; j < C; j++) {
      cin >> K;
    //  cout << " # Prenda: " << j ;
      //cout << " Modelos:" << K << endl;
      for (int k = 0; k < K ; k++) {
        int temp;
        cin >> temp;
        prenda_precio[j].push_back(temp);
        //cout << "Op "<< k<<": " << prenda_precio[j][k] << "|";
      }
    //  cout <<endl;
    }
    int response = bestShopOfclothes(M,0,C);
    if( response <= 0) {
    cout << "no solution"<< endl;
    }
    else {
      cout << response << endl;
    }

    for (int i = 0; i < 20; i++) {
      prenda_precio[i].clear();
    }



  }

  return 0;
}
