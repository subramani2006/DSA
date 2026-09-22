class Solution {
private:
    bool dfs(int node ,vector<vector<int>>& graph,vector<int>& state ){
        if(state[node]==1)
           return false;
        if(state[node]==2)
           return true;
        if(state[node]==3)
           return false;

        state[node]=1;

        for(auto neigh : graph[node]){
            if(dfs(neigh,graph,state)==false){
                state[node]=3;
                return false;
            }
        }
        state[node]=2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>state(V,0);
        vector<int>ans;

        for(int i=0 ; i<V;i++){
            if(dfs(i,graph,state)){;

            
              ans.push_back(i);
            }
        }
    return ans;
        
    }
};