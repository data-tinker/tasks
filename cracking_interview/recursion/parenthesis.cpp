#include <iostream>
#include <vector>

using namespace std;

void generateParenthesisHelper(int n, int remOpen, int remClose, string sequence, vector<string>& parenthesis) {
    if (sequence.length() == n * 2) {
        parenthesis.push_back(sequence);
        return;
    }

    if (remClose > 0) {
        generateParenthesisHelper(n, remOpen, remClose - 1, sequence + ')', parenthesis);
    }

    if (remOpen > 0) {
        generateParenthesisHelper(n, remOpen - 1, remClose + 1, sequence + '(', parenthesis);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> parenthesis;

    generateParenthesisHelper(n, n, 0, "", parenthesis);

    return parenthesis;
}

int main() {
    int n;
    cin >> n;

    auto parenthesis = generateParenthesis(n);

    for (const auto& p: parenthesis) {
        cout << p << endl;
    }

    return 0;
}
