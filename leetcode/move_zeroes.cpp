#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    size_t l = 0;
    size_t r = 0;

    while (r < nums.size()) {
        if (nums[r] == 0) {
            ++r;
            continue;
        }

        nums[l] = nums[r];
        ++l;
        ++r;
    }

    for (size_t i = l; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> v{0,1,0,3,12};

    moveZeroes(v);

    for (const auto & i : v) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
