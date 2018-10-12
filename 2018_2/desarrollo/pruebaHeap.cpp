#include <bits/stdc++.h>

using namespace std;

bool comparatorPairs(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main(){

  priority_queue <pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>, pair<int,int>)> > nodos(comparatorPairs);

  nodos.push(make_pair(1,10));
  nodos.push(make_pair(2,5));
  nodos.push(make_pair(3,2));
  nodos.push(make_pair(4,7));
  nodos.push(make_pair(5,15));

  while (!nodos.empty()) {
    cout << (nodos.top()).first << ","<<(nodos.top()).second<<endl;
    nodos.pop();
  }
}
