#include <bits/stdc++.h>

using namespace std;

#define INF 999999

int minNodosNoVisitados(vector<int> & distancia, vector<int> &visitados){
  int min = INF;
  int min_index=0;
  for (int i = 0; i < distancia.size(); i++) {
    if(distancia[i] <= min && visitados[i] ==0){
      min = distancia[i];
      min_index = i;
    }
  }
  return min_index;
}

bool allNodosVisited(vector<int>& visitados){
  bool allVisited = true;

  for (int i = 0; i < visitados.size(); i++) {
    if(visitados[i] ==0){
      allVisited = false;
      break;
    }
  }
  return allVisited;
}


int main(){
  int N; //Casos
  /*
  Servers n
  cables m
  */
  int servers, cables;

  ofstream myfile;

  myfile.open ("check.txt");
  int S;
  int T;

  cin >> N;
  int casos = 1;
  while(casos <= N){
    cin >> servers;
    cin >> cables;
    cin >>S;
    cin >>T;

    cout << "Caso:" << casos<<endl;
    cout << "servers" << servers<<endl;
    cout << "Cables" << cables<<endl;
    cout << "Desde" << S<<endl;
    cout << "Hasta" << T<<endl;

    int matrizGrafo[servers][servers];

    for (int i = 0; i < servers; i++) {
      for (int j = 0; j < servers; j++) {
        matrizGrafo[i][j] = (INF);
      }
    }

    //cout << "Creada Matriz Adjacencia" << servers<<endl;

    vector<set<int>> adjacenciaGrafo(servers);

    for (int i = 0; i < cables; i++) {
      int n1, n2, w;
      cin >> n1;
      cin >> n2;
      cin >>w;
      cout << "Arco " <<n1 << " ,"<<n2<<" peso:"<<w<<endl;

      adjacenciaGrafo[n1].insert(n2);
      adjacenciaGrafo[n2].insert(n1);

      if(w <= matrizGrafo[n1][n2]){
        matrizGrafo[n1][n2] = w;
        matrizGrafo[n2][n1] = w;
      }

    }

    //Calcular la distancia mas corta entre S y T;

    vector<int>distancia(servers);
    for (int i = 0; i < distancia.size(); i++) {
      if(i==S){
        distancia[i] =0;
      }
      else{
        distancia[i] =INF;
      }
    }

    vector<int>visitados(servers);
    for (int i = 0; i < servers; i++) {
      visitados[i] = 0;
    }




    while(!allNodosVisited(visitados)){

      int nodoActual = minNodosNoVisitados(distancia,visitados);

      cout << "Nodo "<<nodoActual<<endl;

      //Revisar las distancias de los vecinos al nodo source

      auto it = adjacenciaGrafo[nodoActual].begin();
      cout << "Cantidad de vecinos" << adjacenciaGrafo[nodoActual].size() <<endl;
      while (it != adjacenciaGrafo[nodoActual].end()) {
        cout << "Vecino "<<*it<<endl;
        int distanciaVecino = matrizGrafo[(*it)][nodoActual];
        cout << "DistVec al nodo actual "<<distanciaVecino<<endl;

        if(distanciaVecino+distancia[nodoActual] <= distancia[(*it)] && visitados[(*it)]==0){
          cout << distanciaVecino+distancia[nodoActual] << " <=" <<  distancia[(*it)] <<endl;
          distancia[(*it)] = distanciaVecino+distancia[nodoActual];
          cout << "Actualiza distancia ";

        }
        ++it;
      }
visitados[nodoActual] =1;
    cout << "No hay mas vecinos "<<nodoActual<<endl;
    }
    myfile << "Case #"<<casos<<": ";
    if(distancia[T] == INF){
      myfile<<"unreachable"<<endl;
    }
    else{
      myfile<<distancia[T]<<endl;
    }











    casos++;
  }


myfile.close();
  return 0;
}
