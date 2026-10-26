
class Solution {
public:
    double dfs(string curr, string target,
               unordered_map<string, vector<pair<string, double>>>& adj,
               unordered_set<string>& visited) {

        if (curr == target) {
            return 1.0;
        }

        visited.insert(curr);

        for (auto& [neighbor, weight] : adj[curr]) {
            if (visited.count(neighbor)) {
                continue;
            }

            double result = dfs(neighbor, target, adj, visited);

            if (result != -1.0) {
                return weight * result;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string, double>>> adj;

        // Build the weighted graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            adj[a].push_back({b, value});
            adj[b].push_back({a, 1.0 / value});
        }

        vector<double> answers;

        for (auto& query : queries) {
            string start = query[0];
            string target = query[1];

            // Undefined variables
            if (!adj.count(start) || !adj.count(target)) {
                answers.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                answers.push_back(dfs(start, target, adj, visited));
            }
        }

        return answers;
    }
};
