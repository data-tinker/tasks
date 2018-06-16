#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>
#include <sstream>

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s, a, d, b;
    cin >> s;
    int p;

    istringstream iss(s);
    getline(iss, a, '.');
    getline(iss, d, 'e');
    getline(iss, b);

    p = stoi(b);
    int i;
    int j;

    i = d.size() - 1;

    while (!d.empty()) {
        if (d.back() == '0') {
            d.pop_back();
        } else {
            break;
        }
    }

    for (i = 0; i < p; ++i) {
        if (i < d.size()) {
            a += d[i];
        } else {
            a += '0';
        }
    }

    if (d.size() > i) {
        a += '.';
        for (j = i; j < d.size(); ++j) {
            a += d[j];
        }
    }

    cout << a << endl;

    return 0;
}
