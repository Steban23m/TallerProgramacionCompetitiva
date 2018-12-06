#include <bits/stdc++.h>

using namespace std;

float tripCost(int pos, float defaultCost){

  if(pos == 1){
    return defaultCost;
  }
  else if(pos==2){
    return defaultCost*0.5;
  }
  else if(pos >=3 && pos <= 6){
    return defaultCost*0.25;
  }
  else{
    return defaultCost;
  }


}

float calculateBestCostTrip(vector<pair<int,float>> & trips, int tripIndex, int positionTripDcto, int time){
  pair<int,float> currentTrip = trips[tripIndex-1];

//  cout << "Calculating Trip "<< tripIndex << ", Time Counting: "<<time<< " , Trip amount " << positionTripDcto << endl;
  //cout <<"Current trip: "<< currentTrip.first<<" |  " <<currentTrip.second << endl;
  if(tripIndex==1){
  //  cout << "First Trip"<<endl;
    return currentTrip.second + calculateBestCostTrip(trips,tripIndex+1,positionTripDcto+1, time+currentTrip.first);
  }
   if(trips.size() == tripIndex){
  //  cout << "Last Trip"<<endl;
  //  cout << "Costo Ultimo Viaje ";
    if (time >=120) {
    //    cout <<  currentTrip.second<<endl;
        return currentTrip.second;
    }
    else{
    //  cout << tripCost(positionTripDcto, currentTrip.second)<<endl;
      return tripCost(positionTripDcto, currentTrip.second);
    }

  }

  else{

    if (time >= 120) {
  //      cout << "Resetting Time"<<endl;
        return tripCost(1, currentTrip.second) + calculateBestCostTrip(trips, tripIndex+1, 1, 0);
    }
    else{
      float viajeaux1 = tripCost(positionTripDcto, currentTrip.second);
      float aux1 =  + calculateBestCostTrip(trips,tripIndex+1,positionTripDcto+1, time+currentTrip.first);
  //    cout << "Costo de realizar viaje " << tripIndex << " inmediatamente : " << viajeaux1<<" +"<< aux1<<endl;

      float viajeaux2 = tripCost(1, currentTrip.second);
      float aux2 = calculateBestCostTrip(trips,tripIndex+1,2, currentTrip.first);
  //    cout << "Costo viaje " << tripIndex << " si se espera: "<< viajeaux2<<" +" << aux2 <<endl;
      //Minimo Costo entre realizar viaje altiro o esperar al nuevo ciclo de descuentos
      return fmin(viajeaux1 + aux1, viajeaux2 + aux2);

    }
  }

}

int main(){

  int N=0;
  int distanceTime;
  float cost;
  vector<pair<int,float>> trips;

  while (cin >> N) {


    for (int i = 0; i < N; i++) {
      cin >> distanceTime;
      cin >> cost;
    trips.push_back(make_pair(distanceTime, cost));
    }

  //  cout << "Size: "<< trips.size() << endl;
    //cout <<"Time | Cost" <<endl;

    float result = calculateBestCostTrip(trips,1,1,0);

    cout <<fixed <<setprecision(2)<< result  <<endl;

    trips.clear();

  }





return 0;
}
