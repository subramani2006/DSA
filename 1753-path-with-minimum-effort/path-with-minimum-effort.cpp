class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        // dist[row][col] = minimum effort needed to reach this cell
        vector<vector<int>> dist(
            n, vector<int>(m, INT_MAX)
        );

        // {effort, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()) {

            int effort = pq.top().first;

            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            
            if(row == n-1 && col == m-1)
                return effort;

            // Check 4 directions
            for(int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m) {

                    int edgeEffort =
                        abs(heights[row][col] -
                            heights[nrow][ncol]);

                    int newEffort =
                        max(effort, edgeEffort);

                    if(newEffort < dist[nrow][ncol]) {

                        dist[nrow][ncol] = newEffort;

                        pq.push({
                            newEffort,
                            {nrow, ncol}
                        });
                    }
                }
            }
        }

        return 0;
    }
};