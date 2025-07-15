class Solution {
public:
    unordered_map<string, pair<int, int>> memo;

    pair<int, int> dfs(vector<int> players, int a, int b, int round) {
        if (a > b) swap(a, b);

        if (players[a - 1] == players[players.size() - b]) {
            return {round, round}; // they meet now
        }

        string key = to_string(players.size()) + "-" + to_string(a) + "-" + to_string(b);
        if (memo.count(key)) return memo[key];

        int minRound = INT_MAX, maxRound = INT_MIN;
        int n = players.size();

        function<void(int, vector<int>&)> backtrack = [&](int i, vector<int>& next) {
            if (i >= (n + 1) / 2) {
                vector<int> sortedNext = next;
                sort(sortedNext.begin(), sortedNext.end());

                int newA = -1, newB = -1;
                for (int j = 0; j < sortedNext.size(); j++) {
                    if (sortedNext[j] == players[a - 1]) newA = j + 1;
                    if (sortedNext[j] == players[b - 1]) newB = j + 1;
                }

                auto [low, high] = dfs(sortedNext, newA, newB, round + 1);
                minRound = min(minRound, low);
                maxRound = max(maxRound, high);
                return;
            }

            int j = n - 1 - i;

            int p1 = players[i];
            int p2 = players[j];

            if ((p1 == players[a - 1] && p2 == players[b - 1]) || 
                (p2 == players[a - 1] && p1 == players[b - 1])) {
                minRound = min(minRound, round);
                maxRound = max(maxRound, round);
                return;
            }

            if (p1 == players[a - 1] || p1 == players[b - 1]) {
                next.push_back(p1);
                backtrack(i + 1, next);
                next.pop_back();
            } else if (p2 == players[a - 1] || p2 == players[b - 1]) {
                next.push_back(p2);
                backtrack(i + 1, next);
                next.pop_back();
            } else {
                next.push_back(p1);
                backtrack(i + 1, next);
                next.pop_back();

                next.push_back(p2);
                backtrack(i + 1, next);
                next.pop_back();
            }
        };

        vector<int> next;
        backtrack(0, next);
        return memo[key] = {minRound, maxRound};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> players(n);
        iota(players.begin(), players.end(), 1);
        auto [earliest, latest] = dfs(players, firstPlayer, secondPlayer, 1);
        return {earliest, latest};
    }
};
