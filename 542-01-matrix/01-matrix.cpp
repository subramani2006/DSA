class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>>q;

        vector<vector<int>>dist(n,vector<int>(m,-1));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int delrow[] = {-1,+1,0,0};
        int delcol[] = {0,0,-1,+1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i =0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && dist[nrow][ncol]==-1){
                    dist[nrow][ncol] = dist[row][col]+1;
                    q.push({nrow,ncol});
                }


            }

        }
    return dist;
        
    }
};