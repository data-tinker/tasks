#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

class SlidingWindowWithMax {
public:
    SlidingWindowWithMax(int k)
        : Size(k)
    {}

    int Push(int n) {
        if (SlidingWindow.size() == Size) {
            auto dumpedElement = SlidingWindow.front();
            SlidingWindow.pop();

            if (dumpedElement == MaxNums.front()) {
                MaxNums.pop_front();
            }
        }

        SlidingWindow.push(n);

        while (!MaxNums.empty() && n > MaxNums.back()) {
            MaxNums.pop_back();
        }

        MaxNums.push_back(n);

        return MaxNums.front();
    }
private:
    size_t Size;
    queue<int> SlidingWindow;
    deque<int> MaxNums;
};

vector<int> slidingWindowMax(const vector<int>& nums, int k) {
    vector<int> result;
    SlidingWindowWithMax sw(k);

    for (int i = 0; i < k - 1; ++i) {
        sw.Push(nums[i]);
    }

    for (int i = k - 1; i < nums.size(); ++i) {
        result.push_back(sw.Push(nums[i]));
    }

    return result;
}

int main() {
    vector<int> nums{1, -1};

    auto maxs = slidingWindowMax(nums, 1);

    for (auto v: maxs) {
        cout << v << ' ';
    }

    cout << endl;

    return 0;
}
