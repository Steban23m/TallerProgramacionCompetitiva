#include <bits/stdc++.h>
/*Idea del codigo extraida de https://codeforces.com/blog/entry/63157*/

using namespace std;

int main(){
  float r;
  while (cin >> r) {
    int i=1;
    while (true) {
      if(fmod(i*r,360)==0){
        cout << i << endl;
        break;
      }
      else{
        i++;
      }
    }
  }



  return 0;
}
