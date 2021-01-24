class Solution {
public:
    int minDeletions(string inputString) {
      if (inputString.empty()) {
        return 0;
      }

        unordered_map<char, int> charToOccurrences;

      for (const auto c : inputString) {
        ++charToOccurrences[c];
      }

      vector<int> occurrences;

      for (const auto& keyValue : charToOccurrences) {
        occurrences.push_back(keyValue.second);
      }

      sort(begin(occurrences), end(occurrences));

      priority_queue<int> pq;

        int occurrencesIdx = 0;

      for (int i = 1; i <= occurrences.back(); ++i) {
        int newIndex = occurrencesIdx;
        while (newIndex < occurrences.size() && occurrences[newIndex] == i) {
          ++newIndex;
        }
        if (newIndex == occurrencesIdx) {
            pq.push(i);
        }
        occurrencesIdx = newIndex;
      }

      int minDeletions = 0;

      for (int i = occurrences.size() - 1; i >= 0; --i) {
        if (i > 0 && occurrences[i - 1] == occurrences[i]) {
            if (pq.empty()) {
            minDeletions += occurrences[i];
          } else {
            bool added = false;
            while (!pq.empty()) {
                int top = pq.top();
                pq.pop();

                if (top < occurrences[i]) {
                    minDeletions += occurrences[i] - top;
                    added = true;
                    break;
                }
            }

            if (!added) {
                minDeletions += occurrences[i];
            }
          }
        }
      }

      return minDeletions;
    }
};
