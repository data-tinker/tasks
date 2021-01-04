class Solution {
private:
    string decodeStringOneStack(const string& s) {
        stack<char> charStack;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ']') {
                charStack.push(s[i]);
                continue;
            }

            string tmp;

            while (charStack.top() != '[') {
                tmp += charStack.top();
                charStack.pop();
            }

            charStack.pop();

            string digitString;
            while (!charStack.empty() && isdigit(charStack.top())) {
                digitString += charStack.top();
                charStack.pop();
            }

            reverse(digitString.begin(), digitString.end());
            int numberOfRepeats = stoi(digitString);

            for (size_t i = 0; i < numberOfRepeats; ++i) {
                for (int j = tmp.size() - 1; j >= 0; --j) {
                    charStack.push(tmp[j]);
                }
            }
        }

        string result;
        while (!charStack.empty()) {
            result += charStack.top();
            charStack.pop();
        }

        reverse(begin(result), end(result));

        return result;
    }

    string decodeStringTwoStacks(const string& s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString;
        int k = 0;

        for (const auto ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + ch - '0';
            } else if (ch == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();

                for (int i = countStack.top(); i > 0; --i) {
                    decodedString += currentString;
                }
                countStack.pop();
                currentString = decodedString;
            } else {
                currentString = currentString + ch;
            }
        }

        return currentString;
    }
public:
    string decodeString(string s) {
        return decodeStringTwoStacks(s);
    }
};
