class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        stack<int> st;
        st.push(-1); // Base for length calculation

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // New base
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};
