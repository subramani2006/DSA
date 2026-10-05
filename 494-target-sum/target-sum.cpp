class Solution {
private :
    int solve(int i , int sum , vector<int>& nums, int target){
        if(i==nums.size()){
            if(sum==target)
               return 1;
            return 0;
        }
        int add = solve(i+1,sum+nums[i],nums,target);
        int sub = solve(i+1,sum-nums[i],nums,target);

        return add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(0,0,nums,target);
        
    }
};