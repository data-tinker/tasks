#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;

    if (nums.empty()) {
        permutations.emplace_back();
        return permutations;
    }

    auto val = nums.back();
    nums.pop_back();
    auto recurisvePermutations = permute(nums);

    for (const auto& perm: recurisvePermutations) {
        for (size_t i = 0; i <= perm.size(); ++i) {
            permutations.push_back(perm);
            permutations.back().insert(permutations.back().begin() + i, val);
        }
    }

    return permutations;
}

bool nextPermutation(vector<int>& nums) {
    int l = nums.size() - 1;
    int r = nums.size() - 1;

    while (l > 0 && nums[l - 1] >= nums[l]) {
        --l;
    }

    if (l <= 0) {
        return false;
    }

    while (nums[r] < nums[l - 1]) {
        --r;
    }

    swap(nums[l - 1], nums[r]);

    r = nums.size() - 1;

    while (l < r) {
        swap(nums[l++], nums[r--]);
    }

    return true;
}

int main() {
    vector<int> nums{2, 4, 5, 6};

    sort(begin(nums), end(nums));

    do {
        for (auto n :nums) {
            cout << n << ' ';
        }
        cout << endl;
    } while (nextPermutation(nums));

    return 0;
}
