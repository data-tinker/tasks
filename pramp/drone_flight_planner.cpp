#include <iostream>
#include <vector>

using namespace std;

int calcDroneMinEnergy( const vector<vector<int>>& route ) {
  if (route.size() == 1) {
    return 0;
  }

  int minEnergy = numeric_limits<int>::max();
  int currentEnergy = 0;

  for (size_t i = 1; i < route.size(); ++i) {
    currentEnergy -= route[i][2] - route[i - 1][2];
    minEnergy = min(minEnergy, currentEnergy);
  }

  if (minEnergy < 0) {
    return -minEnergy;
  }

  return 0;
}

int main() {
  cout << calcDroneMinEnergy({
    {0, 2, 10},
    {3, 5, 0},
    {9, 20, 6},
    {10, 12, 15},
    {10, 10, 8}
  });
  return 0;
}
