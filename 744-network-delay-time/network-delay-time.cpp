class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto [nextNode, wt] : adj[node]) {

                if(d + wt < dist[nextNode]) {

                    dist[nextNode] = d + wt;

                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};