class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        for (int i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
               
               
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
