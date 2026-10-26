class Solution {
public:

    int dfs(int city, int parent, vector<vector<pair<int, int>>> &adj){
        int changes = 0;
        for(auto [neighbour, cost]: adj[city]){
            if(neighbour == parent){
                continue;
            }

            changes += cost;
            changes += dfs(neighbour, city, adj);
        }
        return changes;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>>adj(n);

        for(auto& road : connections){
            int a = road[0];
            int b = road[1];

            adj[a].push_back({b,1});
            adj[b].push_back({a, 0});
        }

        return dfs(0, -1, adj);
    }
};