class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream iss(text);
        string word;
        deque<string> wordQueue;
        vector<string> occurences;

        bool foundFirst = false;
        bool foundSecond = false;

        while (iss >> word) {
            wordQueue.push_back(word);

            if (wordQueue.size() == 3) {
                if (wordQueue[0] == first && wordQueue[1] == second) {
                    occurences.push_back(wordQueue[2]);
                }
                wordQueue.pop_front();
            }
        }

        return occurences;
    }
};
