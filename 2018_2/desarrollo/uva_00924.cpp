#include <bits/stdc++.h>

using namespace std;
#define INF 9999



int main(){

  clock_t begin = clock();



  int E; //Nro Empleados, max 2500
  cin >> E;
  vector<vector<int>> grafoMatriz(E);



  //Inicializar en infinito.
  for (int e = 0; e < E; e++) {
    for (int f= 0; f < E; f++) {
      grafoMatriz[e].push_back(INF);
      cout << grafoMatriz[e][f]<<"|";
      if(e==f)grafoMatriz[e][f] = 0;
    }
    cout << endl;
  }

  for (int e= 0; e <E; e++) {
    int numeroAmigos;
    cin >> numeroAmigos;
cout << e<<" tiene "<<numeroAmigos<<" amigos" << endl;
    while (numeroAmigos > 0 ) {
      int amigo;
      cin >> amigo;
      cout << "Amigo "<<amigo<<endl;
      grafoMatriz[e][amigo] = 1;
      //grafoMatriz[amigo][e] = 1;
      numeroAmigos--;
    }
  }


  for (int k = 0; k < E; k++) {
    for (int i = 0; i < E; i++) {
      for (int j = 0; j < E; j++) {
        int distancia = grafoMatriz[i][k]+grafoMatriz[k][j];
        if(grafoMatriz[i][j] > distancia)
        grafoMatriz[i][j] = distancia;
      }
    }
  }
 cout << "Nuevo Grafo "<< endl;
  for (int e = 0; e < E; e++) {
    for (int f= 0; f < E; f++) {
      if (grafoMatriz[e][f]!=INF) {
      cout << setfill('0') << setw(3) << grafoMatriz[e][f]<<"|";
      }

    }
  //  cout << endl;
  }

  int T; //casos
  cin >> T;
  while (T--) {
    int source;
    int maxDailyBoom = -1;
    int firstBoomDay = 0;
    cin >> source;
    int SIZE = grafoMatriz[source].size();
    vector<int> auxCalcularBoom(SIZE);

    //Revisar caso 0
    bool flagNoAmigos =true;
    for (auto i:grafoMatriz[source]) {
        if(i != 9999 && i!=0) {
          flagNoAmigos = false;
          break;
        }
    }

    if(flagNoAmigos){
      cout << 0 << endl;
    }
    else{
      for (int i = 0; i < SIZE; i++) {
        if(grafoMatriz[source][i]!= 0 && grafoMatriz[source][i]!= INF){
          auxCalcularBoom[grafoMatriz[source][i] -1] +=1;
        }
      }

      maxDailyBoom =  *(max_element(auxCalcularBoom.begin(), auxCalcularBoom.end()));

      firstBoomDay = max_element(auxCalcularBoom.begin(), auxCalcularBoom.end()) - auxCalcularBoom.begin() +1;

      cout << maxDailyBoom << " "<< firstBoomDay << endl;

    }



  }
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << elapsed_secs<<endl;

  return 0;

}
