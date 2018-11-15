#include <bits/stdc++.h>


using namespace std;

vector<int> coins={50,25,10,5,1};
int dptable[7489+1];
set<vector<int>> optionsToGiveChange;
int pruebasinfuturo=0;
int coinChange(int monto, vector<int> coinsUsed){
  ////cout <<"Coin Change :"<<monto<<endl;
  if(monto == 0){

    //cout <<"El monto se acabo(Retorna 1)"<<endl;
    //cout <<"Coins Used:";
    for (auto m: coinsUsed) {
      //cout<<" "<<m<<" ";
    }
    sort(coinsUsed.begin(),coinsUsed.end());
    optionsToGiveChange.insert(coinsUsed);

    //cout <<endl;
    pruebasinfuturo++;
    return 1;
  }

  //Monecas 50,25,10,5,1
  int formasDarCambio=0;

  if(dptable[monto] != -78965){
    //cout << "Cantidad de monedas estaba en tabla"<< endl;
    return dptable[monto];
  }
  else{
    for (auto moneda:coins) {
      //cout <<"Revisar monto "<<monto<<" con moneda "<<moneda<<endl;
      if (moneda <= monto) {
        //cout <<"Calculando posibilidades" << endl;
        //cout << "Llamando coinchange ("<<monto<<"-"<<moneda<<")"<<endl;
        coinsUsed.push_back(moneda);
        int temp = coinChange(monto - moneda,coinsUsed);
        coinsUsed.erase(coinsUsed.end()-1);
        formasDarCambio += temp;
        //cout <<"Sumando "<<temp<<" a formas cambio para monto "<<monto<<". Nuevo valor :"<<formasDarCambio<<endl;

      }
      else{
        //cout <<"No se puede dar cambio con esa moneda("<<moneda<<")"<<endl;
      }
    }
    //cout <<"Escribiendo en tabla [monto]: "<< formasDarCambio<<endl;
  //  dptable[monto] = formasDarCambio;
  }
  for (int i = 0; i < 7489+1; i++) {
    if(dptable[i]!= -78965){
      //cout << "Monto "<<i<< " -> "<< dptable[i]<<endl;
    }
  }
  return formasDarCambio;

}
int main(){

  vector<int> dummy;
  for (int j = 0; j < 7489+1; j++) {
    dptable[j] = -78965;
  }


  int monto;

  while (cin>>monto) {
    //cout << "Leido Monto : "<<monto<<endl;
    coinChange(monto,dummy);
    //cout <<"WOLOLO:" <<coinChange(monto,dummy) << endl;
    //cout<<"Prueba sin futuro"<<pruebasinfuturo<<"|"<<endl;
    cout <<optionsToGiveChange.size()<<endl;
    pruebasinfuturo=0;


    auto it = optionsToGiveChange.begin();

    while (it != optionsToGiveChange.end()) {
      vector<int> temp = *(it);
      for (auto i :temp) {
        //cout << " "<<i <<" ";
      }
      //cout << endl;
      ++it;
    }
    optionsToGiveChange.clear();
  }

  return 0;
}
