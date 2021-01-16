#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicatesIterator( const vector<int>& arr1, const vector<int>& arr2)
{
    vector<int> duplicates;

    size_t p1 = 0;
    size_t p2 = 0;

    while (p1 < arr1.size() && p2 < arr2.size()) {
        if (arr1[p1] == arr2[p2]) {
            duplicates.push_back(arr1[p1]);
            ++p1;
            ++p2;
        } else if (arr1[p1] < arr2[p2]) {
            ++p1;
        } else {
            ++p2;
        }
    }

    return duplicates;
}

vector<int> findDuplicates( const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> duplicates;

    for (const auto arr1Number : arr1) {
        size_t l = 0;
        size_t r = arr2.size();

        while (l < r) {
            size_t m = l + (r - l) / 2;

            if (arr2[m] == arr1Number) {
                duplicates.push_back(arr1Number);
                break;
            } else if (arr2[m] < arr1Number) {
                l = m + 1;
            } else {
                r = m;
            }
        }
    }

    return duplicates;
}

int main() {
    cout << findDuplicates({1, 2, 3}, {1, 2}).size() << endl;
    return 0;
}
