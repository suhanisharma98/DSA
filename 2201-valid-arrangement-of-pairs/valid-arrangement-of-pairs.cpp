class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

    
        int start = pairs[0][0]; 
        for (auto& [node, _] : graph) {
            if (outDegree[node] > inDegree[node]) {
                start = node;
                break;
            }
        }

        vector<int> path;
        dfs(graph, start, path);

        
        reverse(path.begin(), path.end());
        vector<vector<int>> result;
        for (int i = 1; i < path.size(); ++i) {
            result.push_back({path[i - 1], path[i]});
        }

        return result;
    }

private:
    void dfs(unordered_map<int, deque<int>>& graph, int node, vector<int>& path) {
        while (!graph[node].empty()) {
            int next = graph[node].front();
            graph[node].pop_front();
            dfs(graph, next, path);
        }
        path.push_back(node);
    }
};
