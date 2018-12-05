#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> possibleMoves(vector<vector<int>> pileOfCards){

  vector<pair<int,int>> moves;

  for (int i = 0; i < pileOfCards.size()-1; i++) {
    vector<int> pileP,pileQ;
    pileP = pileOfCards[i];
    pileQ = pileOfCards[i+1];

    if(pileP.size()==1){
      if(pileP[0] >= pileQ[pileQ.size()-1]){
        moves.push_back(make_pair(i,i+1));
      }
    }
  }
  return moves;
}

void doMovement(pair<int,int> move, vector<vector<int>>& pileOfCards){
  pileOfCards.size();
  int from = move.first, to = move.second;
  auto itTo = pileOfCards.begin() + to;
  int card = pileOfCards[from][0];
  pileOfCards[to].push_back(card);
  pileOfCards.erase(pileOfCards.begin()+ from);
}

void printPileOfCards(vector<vector<int>> &  pileOfCards){
    cout << "------------"<<endl;
    for (int i = 0; i < pileOfCards.size(); i++) {
      cout << "Pile "<< i <<":";

      for (int j = 0; j < (pileOfCards[i]).size(); j++) {
        cout << "|" << pileOfCards[i][j] << "| ";
      }
      cout << endl;
    }
    cout << "------------"<<endl;
}


int playMountMarathon(vector<vector<int>> pilesOfCards){

  //Revisar Movimientos disponibles
//  printPileOfCards(pilesOfCards);
  auto movements = possibleMoves(pilesOfCards);

//  cout << "Movements: " << movements.size()<<endl;

  if(movements.size()== 0){
    //No quedan más movimientos por hacer;
    return pilesOfCards.size();
  }

  else{
    int minPilesOfCards = 99999999;
    for (int i = 0; i < movements.size(); i++) {
      vector<vector<int>> auxPilesOfCards;
      copy(pilesOfCards.begin(),pilesOfCards.end(),back_inserter(auxPilesOfCards));

      pair<int,int>auxMove = movements[i];
    //  cout << "Move card "<< auxMove.first << " to " << auxMove.second<< endl;
      doMovement(auxMove,auxPilesOfCards);
    //  printPileOfCards(auxPilesOfCards);
      int auxMinPiles = playMountMarathon(auxPilesOfCards);

      if(auxMinPiles <= minPilesOfCards){
        minPilesOfCards = auxMinPiles;
      //  cout << "Current min piles "<< minPilesOfCards <<endl;
      }


    }

    return minPilesOfCards;
  }



}


int main (){
  int N=0;
  vector<vector<int>> pileOfCards;


  while(cin >> N){

    //Leer Numero de las cartas
    for (int i = 0; i < N; i++) {
      int tempCarta;
      cin >> tempCarta;
      vector<int> pileCard;
      pileOfCards.push_back(pileCard);
      pileOfCards[i].push_back(tempCarta);
    }


    int piles =  playMountMarathon(pileOfCards);
    cout << piles <<endl;


    pileOfCards.clear();
  }

  return 0;
}
