class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;

        for (const auto num : pushed) {
            s.push(num);
            while (!s.empty() && s.top() == popped[r]) {
                s.pop();
                ++r;
            }
        }

        if (!s.empty()) {
            return false;
        }

        return true;
    }
};
