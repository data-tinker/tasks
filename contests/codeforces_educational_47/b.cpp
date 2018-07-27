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

    string s, result = "";

    getline(cin, s);

    int onesCount = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            ++onesCount;
        } else {
            result += s[i];
        }
    }

    int pos = -1;
    while (pos + 1 < result.size() && result[pos + 1] == '0') {
        ++pos;
    }

    result.insert(pos + 1, string(onesCount, '1'));

    cout << result << endl;

    return 0;
}
