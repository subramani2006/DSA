class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int j = 0; j < n; j++) {
                if (isConnected[node][j] == 1 && !visited[j]) {
                    dfs(j);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i);
            }
        }

        return count;
    }
};
