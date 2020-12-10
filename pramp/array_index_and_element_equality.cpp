#include <iostream>
#include <vector>

using namespace std;

int indexEqualsValueSearch(const vector<int> &arr) {
  size_t l = 0;
  size_t r = arr.size();
  size_t m;
  int resultIdx = -1;

  while (l < r) {
    m = (l + r) / 2;

    if (arr[m] < m) {
      l = m + 1;
    } else {
      if (arr[m] == m) {
        resultIdx = m;
      }
      r = m;
    }
  }

  return resultIdx;
}

int main() {
  return 0;
}

