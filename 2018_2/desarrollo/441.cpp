#include <iostream>
#include <string>
#include<algorithm>
#include <cmath>
#include <vector>
using namespace std;




int main (){

  int n;
  vector<int> linea;
char primero = 0;
  vector<string> combinaciones;
  while (true) {
    cin >> n;

    if(n != 0){
      if(primero == 0){
          primero =1;

        }
    else{
      cout << endl;
      cout <<endl;
  }
      for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        linea.push_back(temp);
      }
      sort(linea.begin(), linea.end());
      //obtener combinaciones
      for(int i1=0; linea.size()-i1 >=6; i1++){
        for(int i2=1+i1; linea.size()-i2 >=5; i2++){
          for(int i3=1+i2; linea.size()-i3 >=4; i3++){
            for(int i4=1+i3; linea.size()-i4 >=3; i4++){
              for(int i5=1+i4; linea.size()-i5 >=2; i5++){
                for(int i6=1+i5; linea.size()-i6 >=1; i6++){
                  string temp = to_string(linea[i1])+" "+to_string(linea[i2])+" "+to_string(linea[i3])+" "+ to_string(linea[i4])+" " + to_string(linea[i5]) +" "+to_string(linea[i6]);
                  combinaciones.push_back(temp);
                }
              }
            }
          }

        }
      }

      for (int i = 0; i < combinaciones.size(); i++) {
        if(i+1 == combinaciones.size()){
          cout << combinaciones[i];
        }
      else{
        cout << combinaciones[i]<< endl;
      }

      }
      combinaciones.clear();



      linea.clear();

    }
    else{
      break;
    }

  }
cout <<endl;
  return 0;
}
#include <iostream>
#include <string>
#include<algorithm>
#include <cmath>
#include <vector>
using namespace std;


void obtenerCombinaciones(string s, vector<int> & vec, int index, vector<string>& combinaciones){

  if(s.size()==6){
    combinacions.push_back(s);
    cout << s << endl;
  }
  else{
    for (index; index < vec.size()-s.size()-; i++) {
      /* code */
    }
  }

}

int main (){

  int n;
  vector<int> linea;

  while (true) {
    cin >> n;

    if(n != 0){
      for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        linea.push_back(temp);
      }
    int i = 0;
    for(int i=0; i + 6 <= n; i++){
      for (j = 0; j+5 < t; i++) {
        /* code */
      }
    }


      linea.clear();
      cout << endl;
    }
    else{
      break;
    }
  }
  return 0;
}
