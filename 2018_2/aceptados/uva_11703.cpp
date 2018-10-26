#include <bits/stdc++.h>

using namespace std;

 int sqrtlogsin(int x , vector< int> & dptable) {
  //cout << "X_" << x << endl;
  if(x== 0) return 1 % 1000000;

  if(dptable[x] != -998545){
    //cout << "Se encontro en la tabla"<< endl;
    return dptable[x];
  }

   int t1,t2,t3;
  t1 = floor(x - sqrt(x));
  t2 = floor(log(x));
  t3 = floor(x*(pow(sin(x),2.0)));


  //cout <<"t1: " << t1 <<" t2: " << t2 <<" t3: " << t3 << endl;
  int result = (sqrtlogsin(t1, dptable) + sqrtlogsin(t2, dptable) + sqrtlogsin(t3,dptable))%1000000;
//cout << " # X_" << x <<" = " << result << endl;
  dptable[x] = result;
  return result;
}

int main (){
  vector<int> dptable(1000001);
  //cout << "Size: " << dptable.size() << endl;

  for (int i = 0; i < dptable.size(); i++) {
    dptable[i] = -998545;
  }

  float N;

  while (true) {
    cin >> N;
    if(N==-1) break;
    else{
      cout << sqrtlogsin(N,dptable) << endl;
    }
  }



  return 0;
}
