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

const unordered_set<char> Vowels {'a', 'o', 'u', 'i', 'e'};

enum CharacterType {
    Vowel,
    Consonant
};

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s;
    cin >> s;

   CharacterType previousCharacter = Vowel;

    for (const auto &c: s) {
        auto isVowel = Vowels.find(c) != Vowels.end();

        if (previousCharacter == Consonant && !isVowel) {
            cout << "NO" << endl;
            return 0;
        }

        if (isVowel || c == 'n') {
            previousCharacter = Vowel;
        } else {
            previousCharacter = Consonant;
        }
    }

    if (previousCharacter == Consonant) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}
