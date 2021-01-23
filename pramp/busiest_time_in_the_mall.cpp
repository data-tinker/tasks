#include <iostream>
#include <vector>
#include <limits>

using namespace std;
// complexity
// space O(1)
// time O(n)

inline int computePeople(int numberOfPeople, bool isEnter) {
  return isEnter ? numberOfPeople : -numberOfPeople;
}

int findBusiestPeriod( const vector<vector<int> >& data )
{
  int currentTimeStamp = 0;
  int currentNumberOfPeople = 0;
  int maxNumberOfPeople = numeric_limits<int>::min();
  int maxTimeStamp = 0;

  for (const auto& ts : data) {
    if (ts[0] != currentTimeStamp) {
      if (currentNumberOfPeople > maxNumberOfPeople) {
        maxTimeStamp = currentTimeStamp;
        maxNumberOfPeople = currentNumberOfPeople;
      }
      currentTimeStamp = ts[0];
    }

    currentNumberOfPeople += computePeople(ts[1], ts[2]);
  }

  if (currentNumberOfPeople > maxNumberOfPeople) {
    maxTimeStamp = currentTimeStamp;
    maxNumberOfPeople = currentNumberOfPeople;
  }

  return maxTimeStamp;
}

int main() {
  return 0;
}
