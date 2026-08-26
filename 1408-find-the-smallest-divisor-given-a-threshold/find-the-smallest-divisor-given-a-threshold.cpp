class Solution {
public:
    int findsum(vector<int>&nums , int n )
    {
        int sum = 0;
        for(int num : nums){
            sum +=(num+n-1)/n;
        }
    return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
          
          int low = 1;
          int high = *max_element(nums.begin(),nums.end());

          while(low<=high){
            int mid = low+(high-low)/2;
            int sum = findsum(nums,mid);
            if(sum<=threshold){
                high = mid-1;
            }
            else
               low = mid+1;

          }
    return low;       
    }
};