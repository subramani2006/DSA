class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);

        for(auto road : roads) {

            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);

        vector<int> ways(n, 0);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {

            long long distance = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(distance > dist[node])
                continue;

            for(auto it : adj[node]) {

                int adjacentNode = it.first;
                int edgeWeight = it.second;

                long long newDistance =
                    distance + edgeWeight;

                if(newDistance < dist[adjacentNode]) {

                    dist[adjacentNode] = newDistance;

                    ways[adjacentNode] =
                        ways[node];

                    pq.push({
                        newDistance,
                        adjacentNode
                    });
                }

                else if(newDistance == dist[adjacentNode]) {

                    ways[adjacentNode] =
                        (ways[adjacentNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};