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

    string decodeStringTwoStacks(string s) {
        stack<string> stringStack;
        stack<int> numberStack;

        string currentString;
        int currentNumber = 0;

        for (const auto c : s) {
            if (c == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();

                for (size_t i = 0; i < numberStack.top(); ++i) {
                    decodedString += currentString;
                }
                numberStack.pop();

                currentString = decodedString;
            } else if (c == '[') {
                stringStack.push(currentString);
                numberStack.push(currentNumber);

                currentString = "";
                currentNumber = 0;
            } else if (isdigit(c)) {
                currentNumber = currentNumber * 10 + c - '0';
            } else {
                currentString += c;
            }
        }

        return currentString;
    }
public:
    string decodeString(string s) {
        return decodeStringTwoStacks(s);
    }
};
