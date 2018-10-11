#include <bits/stdc++.h>

using namespace std;
#define INF 9999



int main(){

  clock_t begin = clock();



  int E; //Nro Empleados, max 2500

  cin >> E;
  vector<set<int>> grafo(E);
  int tamanoGrafo = E;


  //Inicializar en infinito.

  for (int e= 0; e <E; e++) {
    int numeroAmigos;
    cin >> numeroAmigos;
//cout << e<<" tiene "<<numeroAmigos<<" amigos" << endl;
    while (numeroAmigos > 0 ) {
      int amigo;
      cin >> amigo;

      grafo[e].insert(amigo);
      //grafoMatriz[amigo][e] = 1;
      numeroAmigos--;
    }
  //  cout << e<<" tiene "<<grafo[e].size()<<" amigos almacenados" << endl;

  }


  int T; //casos
  cin >> T;
  while (T--) {

    int source;
    int maxDailyBoom = -1;
    int firstBoomDay = 0;
    cin >> source;
    //cout << "Caso source: "<<source<<endl;
    int SIZE = tamanoGrafo;
    vector<int> auxCalcularBoom(SIZE);


    if(grafo[source].size()==0){
    //  cout << "No habia amigos" <<endl;
      cout << 0 << endl;

    }
    else{
      vector<int> visitados(SIZE);
      vector<int> distancia(SIZE);

      for(int i=0;i <  visitados.size() ; i++){
        visitados[i] = 0;
      }
      for(int i=0;i <  distancia.size() ; i++){
        distancia[i] = INF;
      }

      visitados[source] = 1;
      distancia[source] = 0;

      queue<int> auxBFS;
      auxBFS.push(source);


      while (!auxBFS.empty()) {

        int nodo = auxBFS.front();
        auxBFS.pop();
        //cout << "Sacando nodo"<< nodo <<" de queue" <<endl;
        auto it =  grafo[nodo].begin();
        for (it; it != grafo[nodo].end(); ++it) {
          int aux = *it;
      //    cout << "Vecino"<< aux<<endl;
          if(visitados[aux] == 0){
        //    cout << "No ha sido visitado"<<endl;
            visitados[aux] =1;
            distancia[aux] = distancia[nodo] +1;
        //    cout << "Distancia "<<distancia[aux] <<" de" << source<<endl;
            auxBFS.push(aux);
          }
          else{
        //    cout << "Nodo Ya visitado"<< aux<<endl;
          }
        }


      }

      for(int i=0;i <  distancia.size() ; i++){
        if(distancia[i]!=0 && distancia[i]!=INF)
        auxCalcularBoom[distancia[i]-1]+=1;
      }

      //  cout << "Boom";
      for(int i=0;i <  distancia.size() ; i++){

      //  cout << auxCalcularBoom[i];
      }
    //  cout << endl;



      maxDailyBoom =  *(max_element(auxCalcularBoom.begin(), auxCalcularBoom.end()));

      firstBoomDay = max_element(auxCalcularBoom.begin(), auxCalcularBoom.end()) - auxCalcularBoom.begin() +1;

      cout << maxDailyBoom << " "<< firstBoomDay << endl;

    }



  }
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//  cout << elapsed_secs<<endl;

  return 0;

}
