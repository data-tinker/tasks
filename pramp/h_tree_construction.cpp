#include <iostream>
#include <utility>
#include <cmath>

// 0, 0 lenght = 2 -> (-1, 0), (1, 0)
// 0, 0 length = 2 -> (0, -1), (0, 1)
// orientation == true - horisontal
// (0, 0), 10, 1
// halfLength = 5, in:(0, 0) out:((-5, 0), (5, 0))
// -5,0 - 5, 0
// halfLength = 5, in:(-5, 0) out: ((-5, -5), (-5, 5))
// -5,-5 | -5, 5
// halfLength = 5, in:(5, 0) out: ((5, -5), (5, 5))
// 5,-5 | 5, 5
// 2 ^ n

using namespace std;

class HTreeDrawer {
private:
  double maxDepth;
  double sqrt2 =  sqrt(2);

  void drawLine(const pair<double, double>& firstPoint, const pair<double, double>& secondPoint, bool orientation) {
    string orientationArrow;
    if (orientation) {
      orientationArrow = " - ";
    } else {
      orientationArrow = " | ";
    }

    cout << firstPoint.first << ',' << firstPoint.second << orientationArrow << secondPoint.first << ',' <<  secondPoint.second << endl;
}

  pair<pair<double, double>, pair<double, double>> getEnds(const pair<double, double>& center, double length, bool orientation) {
    double halfLength = length / 2;

    if (orientation) {
      return make_pair(make_pair(center.first - halfLength, center.second), make_pair(center.first + halfLength, center.second));
    }

    return make_pair(make_pair(center.first, center.second - halfLength), make_pair(center.first, center.second + halfLength));
  }

  void drawHTreeHelper(pair<double, double> center, double length, double depth, bool orientation) {
    if (depth > maxDepth) {
      return;
    }

    auto points = getEnds(center, length, orientation);
    auto firstPoint = points.first;
    auto secondPoint = points.second;

    drawLine(firstPoint, secondPoint, orientation);

    if (orientation) {
      drawHTreeHelper(firstPoint, length, depth, !orientation);
      drawHTreeHelper(secondPoint, length, depth, !orientation);
    } else {
      drawHTreeHelper(firstPoint, length / sqrt2, ++depth, !orientation);
      drawHTreeHelper(secondPoint, length / sqrt2, ++depth, !orientation);
    }
  }
public:
  void drawHTree(pair<double, double> center, double length, double depth) {
    maxDepth = depth;

    drawHTreeHelper(center, length, 1, true);
  }
};

int main()
{
    pair<double, double> center{0, 0};
    HTreeDrawer().drawHTree(center, 10, 1);

    return 0;
}

