#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> trees;

int numTrees(int n) {
    int result = 0;

    if (n == 0) {
        return 1;
    }

    for (size_t i = 0; i < n; ++i) {
        if (trees.find(i) == trees.end()) {
            trees[i] = numTrees(i);
        }

        if (trees.find(n - i - 1) == trees.end()) {
            trees[n - i - 1] = numTrees(n - i - 1);
        }

        result += trees[i] * trees[n - i -1];
    }

    return result;
}

int main() {
    cout << numTrees(3);

    return 0;
}
