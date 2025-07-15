class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> result;
        dfs("JFK", graph, result);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(string airport, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& result) {
        auto& dests = graph[airport];
        while (!dests.empty()) {
            string next = dests.top();
            dests.pop();
            dfs(next, graph, result);
        }
        result.push_back(airport);
    }
};
