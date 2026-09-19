class Solution {
private:
    void dfs(int row,int col,int oldcolor,int newcolor,vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size();

        if(row<0||row>=n||col<0||col>=m)
           return;
        
        if(image[row][col]!=oldcolor)
            return;
        image[row][col]=newcolor;

        dfs(row -1,col,oldcolor,newcolor,image);
        dfs(row +1,col,oldcolor,newcolor,image);
        dfs(row ,col-1,oldcolor,newcolor,image);
        dfs(row ,col+1,oldcolor,newcolor,image);



    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];

        if(oldcolor==color){
            return image;
        }

        dfs(sr,sc,oldcolor,color,image);

    return image;
        
    }
};