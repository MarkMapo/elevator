#include <vector>

class ElevatorCar
{
public:
  ElevatorCar(int startFloor=1);

  int getCurrentFloor();

  // returns the time to travel to the nextFloor
  double travel(int nextFloor);

  // returns total time travel and travel to each floor
  std::vector<double> travel(std::vector<int> nextFloors); 

protected:
  int currentFloor;

public:
  static const double TRAVEL_TIME_PER_FLOOR=10.0;
};

