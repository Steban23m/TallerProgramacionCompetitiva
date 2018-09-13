#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int checkIfAllCornsAreCover(string solution, int N, char * field){
  int numScarecrows = 0;
  for(int i =0 ; i < N; i++){
    //Primer elemento
    if(i==0 && field[i] == '.'){
      if(solution[i] == 'e' || solution[i+1] == 'e'){

      }
      else{
        return -99;
      }

    }
    //Cualquier elemento excepto los extremos
    if(i!=0 && i != N-1 && field[i] == '.'){
      if(solution[i] == 'e' || solution[i+1] == 'e' || solution[i-1] == 'e'){

      }
      else{
        return -99;
      }
    }
    if(i == N-1 && field[i] == '.'){
      if(solution[i] == 'e' || solution[i-1] == 'e'){

      }
      else{
        return -99;
      }
    }
    if(solution[i] == 'e' ) {
      numScarecrows++;
    }
  }
  return numScarecrows;
}

int bestDistributionScarecrow(vector<string> & solutions, int N,char * field){
  int bestCuantitySacrecrows = N;
//  cout << "Field:";
  for (int n = 0; n < N; n++) {
  //  cout << field[n];
  }
//  cout << endl;
  for(auto solution: solutions){

    int auxScarecrows = checkIfAllCornsAreCover(solution, N, field);
    if(auxScarecrows!=-99 && auxScarecrows <= bestCuantitySacrecrows){
      bestCuantitySacrecrows = auxScarecrows;
  //   cout << solution << "("<<auxScarecrows<<")" << endl;
    }
    else{
    //  cout << solution << "(FAIL)" << endl;
    }
  }
  return bestCuantitySacrecrows;
}

void generateAllDistributionsSacrecrows(vector<string> & output, int N, int corns){

  int q = N*N;
//  cout << "Q: "<< q <<endl;
  int temp = (1 << N);
  //cout << temp << endl;
  for(int i = 1 ; i < (1 << N) ; i++){
    string aux(N,'-');
    int scarecrows = 0;

    for(int j=0; j < N; j++){

      if(i & 1 << j){
        //cout <<  1;
        aux[j] = 'e';
        scarecrows++;
      }
      else{
        //cout <<  0;
      }

    }
    //  cout <<endl;
  //  if(scarecrows >= corns)
    output.push_back(aux);
  }

}


int main (){

  int T; //Numero de casos
  int N; //largo del campo
  char field[100];
  char fieldcopy[100];
  int cornCell = 0;
  vector<string> solutions;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;

    cornCell = 0;
    for (int n = 0; n < N; n++) {
      cin >> field[n];
      if(field[n]=='.')
      cornCell++;

    }
    //cout << endl;
  //  cout << cornCell<<endl;
    generateAllDistributionsSacrecrows(solutions,N,cornCell);

    //cout << "Size Solutions :" << solutions.size() << endl;
    /*    for(auto i: solutions){
    cout<< i<< endl;
  }
  */
  if(cornCell > 0)
  cout << "Case "<<t+1<<": "<< bestDistributionScarecrow(solutions, N, field);
  else{
    cout << "Case "<<t+1<<": "<< 0;
  }
  
  cout <<endl;
  solutions.clear();
}

return 0;
}
