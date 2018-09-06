#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main () {
int N;
vector<int> libros;
int M;

while(cin >> N){
  int a=0,b=0, distancia=1000001;
  int numI,numJ;
//cout << "N:" << N<<endl;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    libros.push_back(temp);
  //  cout <<libros[i] <<",";
  }
  sort(libros.begin(), libros.end());

  cin >>M;

/*
for (int i = 0; i < count; i++) {
  if(libros[0]+M < libros[i])
    libros.remove(libros[i]);
}*/

for(int i=0;i < libros.size(); i++){
  for (int j = 0; j < libros.size(); j++) {
    if(i != j){
      if( libros[i] + libros[j] == M){
        if(libros[i] >= libros[j]){
          a = libros[j];
          b = libros[i];
        }
        else{
          b = libros[j];
          a = libros[i];
        }
          if(distancia > b-a){
            distancia = b-a;
            numI = a;
            numJ=b;
          }
      }
    }
  }
}



  cout << "Peter should buy books whose prices are " << numI<< " and "<<numJ<<"."<<endl;



  libros.clear();
  cout <<endl;
}
return 0;
}
