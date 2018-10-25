#include <bits/stdc++.h>

using namespace std;


int calculateLWS(int N, vector<int> & cards){

  int maxPoints =-1;
  int sumPoints=0;

  for(int i=0; i < cards.size() ; i++ ){

  //  cout << "Puntos " << sumPoints <<endl;
  //  cout << "Carta " << cards[i] <<endl;
    sumPoints += cards[i];

  //  cout << "Score Nuevo " << sumPoints <<endl;

    if(sumPoints > 0){
  //    cout << "Sigue ganando" << endl;
      if(sumPoints > maxPoints){
    //    cout << "reemplazar maxPoints" << endl;
        maxPoints = sumPoints;
      }

    }
    else{
      sumPoints =0;
    }

  //  cout << "Max Puntos: " << maxPoints << endl;


  }
  return maxPoints;

}

int main (){

  int N;



  while (true) {
    cin >> N;
    if(N==0) break;

    else{
  //    cout << "Leer " << N <<" cartas "<< endl;
      vector<int> cards;
      int aux;
      for (int i = 0; i < N; i++) {
        cin >> aux;
        cards.push_back(aux);
        //cout << "Agregada carta "<< cards[i] << endl;
      }


      int longestWin = calculateLWS(N, cards);

      if(longestWin > 0){
        cout << "The maximum winning streak is "<<longestWin <<"."<<endl;

      }
      else{
        cout << "Losing streak." <<endl;
      }
      cards.clear();
    }






  }
  return 0;
}
