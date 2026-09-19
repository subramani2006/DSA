class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       queue<pair<int,int>>q;

       int fresh = 0;

       for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)
             fresh++;
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
       }
       int mins = 0;
       int delrow[] = {-1,0,+1,0};
       int delcol[]= {0,+1,0,-1};
       while(!q.empty()&&fresh>0){

        int size = q.size();

        for(int i = 0;i<size;i++){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int j = 0;j<4;j++){
                int nrow = row+delrow[j];
                int ncol = col + delcol[j];

                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    fresh--;
                    q.push({nrow,ncol});
                }
            }
        
            
        }
        mins++;

       }
       if(fresh>0)
          return -1;
        return mins;
        
    }
};
