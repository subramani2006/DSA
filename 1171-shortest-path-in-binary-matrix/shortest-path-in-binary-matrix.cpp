class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int,int>> q;

        q.push({0, 0});

        
        grid[0][0] = 1;

        int distance = 1;

        int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                if(row == n-1 && col == n-1)
                    return distance;

                for(int j = 0; j < 8; j++) {

                    int nrow = row + drow[j];
                    int ncol = col + dcol[j];

                    if(nrow >= 0 && nrow < n &&
                       ncol >= 0 && ncol < n &&
                       grid[nrow][ncol] == 0) {

                        grid[nrow][ncol] = 1;

                        q.push({nrow, ncol});
                    }
                }
            }

            distance++;
        }

        return -1;
    }
};