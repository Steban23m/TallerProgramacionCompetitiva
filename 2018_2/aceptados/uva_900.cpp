#include <bits/stdc++.h>

using namespace std;


unsigned int calculteDifferentPatterns(int N, vector<unsigned int> & table){

  if(N <= 1){
    return 1;
  }

  if(table[N] != 0){
    return table[N];
  }

      return calculteDifferentPatterns(N-1,table) + calculteDifferentPatterns(N-2,table);

}

int main (){

  vector<unsigned int> tableBlocks(51);
  //cout << "Size: TableBlock" << tableBlocks.size()<<endl;
  for (int i = 0; i < tableBlocks.size(); i++) {
    tableBlocks[i] = 0;
  }

while(true){
  int N;
  cin >> N;

if(N==0){
  break;
}
else{
  unsigned int result = calculteDifferentPatterns(N, tableBlocks);
  cout << result<<endl;
}

}



  return 0;
}
