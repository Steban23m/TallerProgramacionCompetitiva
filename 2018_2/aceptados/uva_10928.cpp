#include <bits/stdc++.h>

using namespace std;


int guardarVecinos(string lineaVecinos, vector<int> vecVecinos){
  //cout <<"Vecinos:"<< lineaVecinos <<endl;
  stringstream vec(lineaVecinos);
  string lugar;
  int count=0;
  while(vec >> lugar){
    vecVecinos.push_back(stoi(lugar));
    count++;
  }
  //cout << "Count" <<count<<endl;
  return count;
}

int main (){

  int N,P;

  vector<vector<int>> vecindario(1000);
  vector<int> dondePuedeVivirManuel;
  //Casos de prueba
  cin >> N;

  while(N>0){
    int minVecinos = 1001;
    cin >> P;
    getchar();
    for (int i = 0; i < P; i++) {
    //  cout << i<< endl;

      string temp="";
      while(temp.length()==0)
      getline(cin,temp);
    //  cout << "Vecinos:" << temp <<endl;
      int aux = guardarVecinos(temp, vecindario[i]);
      //cout << "Aux:"<< aux << "MinVecinos:"<<minVecinos<<endl;
      if(aux < minVecinos){
        //cout <<"IF1"<<endl;
        dondePuedeVivirManuel.clear();
        minVecinos = aux;
        dondePuedeVivirManuel.push_back(i+1);
      }
      else if(aux == minVecinos){
        //cout <<"IF2"<<endl;
        dondePuedeVivirManuel.push_back(i+1);
      }

    }

  //  cout << "Lugar con menos vecinos" << endl;

    for (int i = 0; i < dondePuedeVivirManuel.size(); i++) {
        if(i != dondePuedeVivirManuel.size()-1)
          cout<< dondePuedeVivirManuel[i]<<" ";
          else
           cout<< dondePuedeVivirManuel[i];
    }
    cout<<endl;

    vecindario.clear();
    dondePuedeVivirManuel.clear();
    minVecinos= 1001;

    N--;
  }
}
