#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num) {
    vector<int> result(num + 1);
    result[0] = 0;
    result[1] = 1;

    for (size_t i = 2; i <= num; ++i) {
        result[i] = result[i & (i - 1)] + 1;
    }
    return result;
}

int main() {
    int num = 4;

    for (auto i: countBits(num)) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
