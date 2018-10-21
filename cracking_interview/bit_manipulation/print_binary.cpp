#include <iostream>

using namespace std;

string printBinary(const string& repr) {
    int intPart = stoi(repr.substr(0, repr.find('.')));
    double decPart = stod(repr) - intPart;

    string intRepr = "";

    while (intPart > 0) {
        intRepr += (intPart % 2) ? '1' : '0';
        intPart >>= 1;
    }
    reverse(begin(intRepr), end(intRepr));

    string decRepr = "";
    while (decPart > 0) {
        if (decRepr.length() > 32) {
            return "ERROR";
        }

        if (decPart == 1) {
            decRepr += '1';
            break;
        }

        double r = decPart * 2;

        if (r >= 1) {
            decRepr += '1';
            decPart = r - 1;
        } else {
            decRepr += '0';
            decPart = r;
        }
    }

    if (intRepr.empty()) {
        intRepr = "0";
    }

    if (decRepr.empty()) {
        return intRepr;
    }

    return intRepr + '.' + decRepr;
}

int main() {
    cout << printBinary("0.75") << endl;

    return 0;
}
