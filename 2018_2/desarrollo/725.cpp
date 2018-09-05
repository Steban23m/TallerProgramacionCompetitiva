#include <iostream>
#include <string>
#include<algorithm>
#include <cmath>
#include <vector>
using namespace std;
/*Por cada N valido
-generar todas las permutaciones
*/


void mostrarPermutaciones(){
  vector<int> numeros;
  string temp="";
  int digitos[] = {0,1,2,3,4,5,6,7,8,9};
  sort(digitos,digitos+9);
  do{
    for (int i = 0; i < 5; i++) {
      temp += to_string(digitos[i]);
    }
    //cout << temp <<endl;
    int tempnumber = stoi(temp);
    if(find(numeros.begin(), numeros.end(), tempnumber)==numeros.end()){
      numeros.push_back(tempnumber);
    }
    temp = "";
  }while(next_permutation(digitos,digitos+10));

  for (int i = 0; i < numeros.size(); i++) {
    cout << numeros[i] << endl;
  }
}
int main (){

  int N;
  mostrarPermutaciones();
/*
  while (true) {
    cin >> N;

    if(N!=0){

      cout << "N = " << N << endl;
          //Generar todas las permutaciones de 5 numeros


    }

    else {
      return 0;
    }


  }*/
}
