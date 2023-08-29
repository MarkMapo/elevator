#include "ElevatorCar.hh"
#include <vector>
#include <cstdlib>

ElevatorCar::ElevatorCar(int startFloor)
{
  currentFloor=startFloor;
}

int ElevatorCar::getCurrentFloor()
{
  return currentFloor;
}

// returns the time to travel to the nextFloor
double ElevatorCar::travel(int nextFloor)
{
  // note: always take the absolute value of the time (time never goes backwards)
  double returnValue=abs((nextFloor-currentFloor)*TRAVEL_TIME_PER_FLOOR);
  currentFloor=nextFloor;
  return returnValue;
}

// returns total time travel and travel to each floor
std::vector<double> ElevatorCar::travel(std::vector<int> nextFloors)
{
  double totalTime=0.0;
  std::vector<double> returnValues;
  returnValues.push_back(totalTime); // just a place holder in the vector

  for (int floorIterator=0; floorIterator<nextFloors.size(); floorIterator++)
  {
    double tempTime=this->travel(nextFloors[floorIterator]);
    totalTime+=tempTime;
    returnValues.push_back(tempTime);
  }
      
  returnValues[0]=totalTime;

  return returnValues;
}
