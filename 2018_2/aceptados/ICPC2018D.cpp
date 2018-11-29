#include <bits/stdc++.h>

  using namespace std;


  string clearString(string input){
    string output = input;

    //Remover puntos
    //Remover todo lo que este despues del + hasta antes del @

    auto it = output.begin();

    while (it != output.end()) {
      auto currentChar = *it;

      if(currentChar == '.'){
        //cout << " Encontrado ."<<endl;
        //cout << " Output =" << output << endl;
        output.erase(it);
      }
      else if(currentChar == '+'){
        //cout << " Encontrado +"<<endl;
        auto arrobaPos =  find(output.begin(),output.end(),'@');
        //cout << "First to erase "<< it << endl;
        //cout << "Last to erase "<< arrobaPos<<endl;

        output.erase(it,arrobaPos);
        //cout << " Output =" << output << endl;
        break;
      }
else if(currentChar == '@') break;
      else{
        //cout << " Encontrado letra normal: "<<currentChar<<endl;
        ++it;
      }
    }
    return output;
}

  int main (){

  int sizeDbEmail=0;

  set <string>uniqueEmails;

  vector<string> listEmails;

  while(cin >> sizeDbEmail){
    //cout << "Db Size :"<<sizeDbEmail<<endl;
    for (int i = 0; i < sizeDbEmail; i++) {
      string temp;
      cin >> temp;
      //cout << temp <<endl;

      temp = clearString(temp);
      //cout << "Email cleared: "<< temp<<endl;
      uniqueEmails.insert(temp);
    }
   cout << uniqueEmails.size()<<endl;
  uniqueEmails.clear();

  //listEmails.clear();


  }




  return 0;
  }
