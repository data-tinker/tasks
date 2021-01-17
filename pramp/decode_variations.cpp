#import <iostream>
#import <string>
#import <unordered_map>

using namespace std;

int decodeVariationsHelper(const string& S, unordered_map<size_t, int> memorization, size_t idx) {
    if (idx < S.length() && S[idx] == '0') {
        return 0;
    }

    if (idx >= S.length() - 1) {
        return 1;
    }

    auto found = memorization.find(idx);
    if (found != memorization.end()) {
        return found->second;
    }

    int variationsSum = decodeVariationsHelper(S, memorization, idx + 1);
    if ((S[idx] - '0') * 10 + (S[idx + 1] - '0') <= 26) {
        variationsSum += decodeVariationsHelper(S, memorization, idx + 2);
    }

    memorization[idx] = variationsSum;
    return variationsSum;
}

int decodeVariations(const string& S) {
    unordered_map<size_t, int> memorization;
    return decodeVariationsHelper(S, memorization, 0);
}

int main() {
    return 0;
}
