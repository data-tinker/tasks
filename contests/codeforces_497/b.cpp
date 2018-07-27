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

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, w, h, pw, ph;
    cin >> n;

    cin >> pw >> ph;

    if (pw > ph) {
        swap(pw, ph);
    }

    for (int i = 1; i < n; ++i) {
        cin >> w >> h;

        if (w >= h) {
            if (ph >= w) {
                ph = w;
            } else if (ph >= h) {
                ph = h;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            if (ph >= h) {
                ph = h;
            }  else if (ph >= w) {
                ph = w;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
