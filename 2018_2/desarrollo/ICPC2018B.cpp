#include <bits/stdc++.h>

using namespace std;

char isPossibleRectangle(vector<int> trees,vector<float> treeAngles){


}


int main(){
  int nTrees;
  vector<int> trees;
  vector<float> treeAngles;

  while (cin >> nTrees) {
    float length =0;
    trees.push_back(0);

    for (int i = 1; i < nTrees+1; i++) {
      int auxTree;
      cin >> auxTree;
      trees.push_back(auxTree);

      length += auxTree;
    }
    float initialAngle=0;
    cout << "Total length: "<<length<<endl;
    for (int i = 0; i < nTrees+1; i++) {

      if(i==0)
      treeAngles.push_back(trees[i] * (360/length));
      else{
        treeAngles.push_back(treeAngles[i-1]+trees[i] * (360/length));
      }


      cout << "Tree "<<i<<" .Distance recorred: "<<trees[i]<<". Angle :"<<treeAngles[i]<<endl;
    }

    cout << endl;
    trees.clear();
  }



  return 0;
}
