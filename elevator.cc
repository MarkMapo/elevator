#include "ElevatorCar.hh"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

// prototypes
int stringToInt(std::string stringIn);
std::vector<int> commaStringToInts(std::string stringIn);

// static defines
const static std::string START_FLOOR_ARGUMENT="-start=";
const static std::string TRAVEL_FLOOR_ARGUMENT="-floors=";

// run this like "elevator -start=12 -floors=2,9,1,32"
int main(int argc, char** argv)
{
  // local variables
  int returnValue=0;
  int startFloor=1;
  std::vector<int> nextFloors;
  std::vector<double> travelTimes;

  // parse the args
  for (int argCounter=0; argCounter<argc; argCounter++)
  {
    std::string tempString=argv[argCounter];
    if (tempString.find(START_FLOOR_ARGUMENT)==0)
    {
      tempString.replace(0, START_FLOOR_ARGUMENT.length(), "");
      startFloor=stringToInt(tempString);
    }
    if (tempString.find(TRAVEL_FLOOR_ARGUMENT)==0)
    {
      tempString.replace(0, TRAVEL_FLOOR_ARGUMENT.length(), "");
      nextFloors=commaStringToInts(tempString);
    }
  }
  
  // run ElevatorCar
  ElevatorCar elevatorCar(startFloor);
  travelTimes=elevatorCar.travel(nextFloors);

  std::cout << "times=";
  for (int iterator=0; iterator<travelTimes.size(); iterator++)
  {
    std::cout << travelTimes[iterator];
    if (iterator<travelTimes.size()-1)
      std::cout << ",";
  }
  std::cout << " floors=";
  for (int iterator=0; iterator<nextFloors.size(); iterator++)
  {
    std::cout << nextFloors[iterator];
    if (iterator<nextFloors.size()-1)
      std::cout << ",";
  }  
  std::cout << std::endl;
  
  return returnValue;
}

int stringToInt(std::string stringIn)
{
  int returnValue=0;
  std::stringstream tempStream(stringIn);
  tempStream >> returnValue;

  return returnValue;
}

std::vector<int> commaStringToInts(std::string stringIn)
{
  std::vector<int> returnValue;
  size_t commaPosition;

  do
  {
    commaPosition=stringIn.find(",");
    std::string tempString=stringIn;

    if (commaPosition!=std::string::npos)
    {
      tempString=stringIn.substr(0, commaPosition);
      stringIn.erase(0, commaPosition+1);
    }
    if (tempString.length()>0)
    {
      returnValue.push_back(stringToInt(tempString));
    }
  } while (commaPosition!=std::string::npos && stringIn.length()>0);

  return returnValue;
}
