class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> count;
        count[0] = 1; // base case
        int prefixSum = 0, result = 0;

        for (int num : nums) {
            prefixSum += num;
            if (count.find(prefixSum - goal) != count.end()) {
                result += count[prefixSum - goal];
            }
            count[prefixSum]++;
        }
        return result;
    }
};
