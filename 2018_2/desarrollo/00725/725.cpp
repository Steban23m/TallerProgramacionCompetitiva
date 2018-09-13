#include <iostream>
#include <string>
#include<algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;
/*Por cada N valido
-generar todas las permutaciones
*/


void generateAllPairs(vector<tuple<string, string>> & pairs){

  int digitos[] = {0,1,2,3,4,5,6,7,8,9};
  for(int i = 0 ; i < pow(2,10) ; i++){
    string p1="", p2="";
    for(int j=0; j < 10; j++){

      if(i & 1 << j){
        //    cout << 1;
        p1+=to_string(j);
      }
      else{
        p2+=to_string(j);
        //  cout <<0;
      }

    }


    if(p1.length()==5 && p2.length()==5){

      sort(p1.begin(), p1.end());
      sort(p2.begin(), p2.end());
      do {
        do {
        //cout << "<" << p1 <<", "<< p2<<">"<<endl;
        int aux1 = stoi(p1);
        int aux2 = stoi(p2);
          pairs.push_back(make_tuple(p1, p2));
         } while(std::next_permutation(p2.begin(), p2.end()));
 } while(std::next_permutation(p1.begin(), p1.end()));


  }
  p1="";
  p2="";
}

    }

bool checkDivision(int num, int den, int N){
  if(num / den == N && num % den == 0){
return true;
  }
  else{
    return false;
  }

}

void checkPairs(int N, vector<tuple<string, string>>& results,   vector<tuple<string, string>>& pairs){
  for(auto i:pairs){
    if(checkDivision(stoi(get<0>(i)), stoi(get<1>(i)), N)){
      results.push_back(i);
    }
  }
}


int main (){

  int N;
  vector<tuple<string, string>> pairs;
  vector<tuple<string, string>> results;
  bool flag_first = true;
  generateAllPairs(pairs);
  while (true) {
    cin >> N;

    if(N!=0){
      if(flag_first){
        flag_first = false;
      }
      else{
        cout <<endl;
      }
      checkPairs(N, results, pairs);
      sort(results.begin(),results.end());

      for (auto i:results) {
        cout << get<0>(i) << " / "<<get<1>(i) <<" = "<<N<<endl;
      }
      if(results.size()==0){
        cout << "There are no solutions for "<<N<<"."<<endl;
      }
      results.clear();
    }

    else {
      return 0;
    }


  }
}
