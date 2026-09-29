class Solution {
public:

    int timer = 0;

    void dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& tin,
             vector<int>& low,
             vector<vector<int>>& bridges) {

        vis[node] = 1;

        tin[node] = low[node] = timer++;

        for(int adjNode : adj[node]) {

            if(adjNode == parent)
                continue;

            if(!vis[adjNode]) {

                dfs(adjNode, node, adj,
                    vis, tin, low, bridges);

                low[node] = min(low[node], low[adjNode]);

                // Bridge condition
                if(low[adjNode] > tin[node]) {
                    bridges.push_back({node, adjNode});
                }
            }
            else {
                // Back edge
                low[node] = min(low[node], tin[adjNode]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for(auto edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);

        vector<vector<int>> bridges;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, bridges);
            }
        }

        return bridges;
    }
};