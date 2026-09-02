class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>freq;
        priority_queue<pair<int,int>>maxheap;
        vector<int>result;

        for(int num : nums){
            freq[num]++;
        }
        
        for(auto x : freq){
            maxheap.push({x.second,x.first});
        }
        
        for(int i=0;i<k;i++){

            result.push_back(maxheap.top().second);
            maxheap.pop();

        }
    return result;
        
    }
};