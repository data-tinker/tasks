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

    long long n, result = 0;
    cin >> n;
    vector<long long> a(n);
    unordered_set<long long> usedNumbers;
    vector<long long> uniqueNumbersSuffix;
    unordered_set<long long> uniqueNumbers;

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (long long i = a.size() - 1; i >= 0; --i) {
        uniqueNumbers.insert(a[i]);
        uniqueNumbersSuffix.push_back(uniqueNumbers.size());
    }

    reverse(uniqueNumbersSuffix.begin(), uniqueNumbersSuffix.end());

    for (size_t i = 0; i < a.size() - 1; ++i) {
        if (usedNumbers.find(a[i]) == usedNumbers.end()) {
            result += uniqueNumbersSuffix[i + 1];
            usedNumbers.insert(a[i]);
        }
    }

    cout << result << endl;

    return 0;
}
