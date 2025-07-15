class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].length();
        int totalLen = wordLen * words.size();
        int sLen = s.length();

        unordered_map<string, int> wordCount;
        for (const string& word : words) wordCount[word]++;

        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> window;

            while (right + wordLen <= sLen) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.find(word) != wordCount.end()) {
                    window[word]++;
                    count++;

                    while (window[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == words.size()) result.push_back(left);
                } else {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
