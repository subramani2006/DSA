class Solution {
public:

    bool bfs(int start, vector<vector<int>>& graph,
             vector<int>& color) {

        queue<int> q;

        q.push(start);
        color[start] = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int neighbour : graph[node]) {

                // Not colored
                if (color[neighbour] == 0) {

                    // Give opposite color
                    if (color[node] == 1)
                        color[neighbour] = 2;
                    else
                        color[neighbour] = 1;

                    q.push(neighbour);
                }

                // Same color → not bipartite
                else if (color[neighbour] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {

            if (color[i] == 0) {

                if (!bfs(i, graph, color))
                    return false;
            }
        }

        return true;
    }
};