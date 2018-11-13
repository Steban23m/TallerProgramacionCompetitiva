#include <bits/stdc++.h>

using namespace std;

class Routes{
  public:
    int firstStop;
    int lastStop;
    int numStops;

    Routes(int p1, int p2, int n){
      firstStop=p1;
      lastStop = p2;
      numStops = n;
    };
};


void calculateLongestHappyRoute(int route, vector<int> & stopsValues, vector<int> & happyValue){
  int max_sum = 0;
  bool flagReset = 0;
  happyValue.push_back(stopsValues[0]);
  if(happyValue[0] < 0)
    flagReset =1;
  for (int i = 1; i < stopsValues.size(); i++) {

    if(flagReset){
      happyValue.push_back(stopsValues[i]);
      flagReset = 0;
    }

    else{
      int auxResult = stopsValues[i] + happyValue[i-1];
      if(auxResult < 0){
        //Reset
        flagReset = 1;

      }

        happyValue.push_back(auxResult);
    }

  }

cout << "     ";

for (int i = 0; i < happyValue.size(); i++) {
    cout << "|" << happyValue[i] << "| ";
}

cout << endl;

//Encontrar el valor de suma menor

max_sum = *(max_element(happyValue.begin(),happyValue.end()));
cout <<"   maxSum:"<<max_sum<<endl;

if(max_sum < 0) {
    cout <<"Route "<< route << " has no nice parts" << endl;
}

else{
//calcular todas las rutas que tienen valor maximo
  vector<Routes> routeswMaxSum;

  int firstStop,lastStop, stops =0, sum=0;
  firstStop=1;
  for(int i=0; i < happyValue.size();i++){
    int aux = happyValue[i];
    if(aux < 1){
      firstStop = i+2;
      lastStop++;
      sum = 0;
    }
    else{
    stops++;
    lastStop = i+2;
    sum = aux;
    if(sum == max_sum){
      Routes r1(firstStop,lastStop,stops);
      cout << "Ruta con valor max entre : "<< firstStop<< " y" << lastStop << endl;
      routeswMaxSum.push_back(r1);
    }
    }
  }

}




happyValue.clear();
}

int main (){

  vector<int> stopsValues;
  vector<int> auxDP;
  int currentCase;
  int numRoutes=0;
  int numStops;

  cin >> numRoutes;

  currentCase=1;
  while(numRoutes != 0 && currentCase <= numRoutes){
    cout << "Route: "<< currentCase << endl;
    cin >> numStops;
    cout << "  NumStops: "<< numStops << endl;

    for (int i = 0; i < numStops-1; i++) {
      int temp;
      cin >> temp;
      stopsValues.push_back(temp);
    }

    cout << "  NumStopsBetweenValues: "<< stopsValues.size() << endl;

    calculateLongestHappyRoute(currentCase,stopsValues, auxDP);
    stopsValues.clear();
    currentCase++;

  }




  return 0;


}
