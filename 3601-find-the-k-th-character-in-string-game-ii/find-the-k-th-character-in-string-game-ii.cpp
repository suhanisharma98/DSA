class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> length = {1}; // Initial string is "a"

        for (int op : operations) {
            long long prev = length.back();
            long long newLen = min(k, prev * 2); // Avoid overflow
            length.push_back(newLen);
        }

        int shift = 0;

        for (int i = operations.size(); i >= 1; --i) {
            long long half = length[i - 1];

            if (k > half) {
                k -= half;
                if (operations[i - 1] == 1) {
                    shift++;
                }
            }
        }

        return (char)('a' + (shift % 26));
    }
};
