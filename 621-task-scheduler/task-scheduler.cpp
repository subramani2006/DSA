class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int>freq(26,0);
        priority_queue<int>maxheap;
        
        for(char task:tasks){
            freq[task-'A']++;
        }

        for(int f : freq){
            if(f>0)
                maxheap.push(f);
        }

        int time = 0;
       

        while(!maxheap.empty()){
            vector<int>used;
            int count=0;

            for(int i = 0 ;i<=n;i++){

                if(maxheap.empty()){
                   break;
                }
                int frequency = maxheap.top();
                maxheap.pop();

                frequency--;

                if(frequency>0){
                    used.push_back(frequency);
                }
                time++;
                count++;
            }

            for(int frequency : used){
                maxheap.push(frequency);
            }
            if(!maxheap.empty()){
                time = time+(n+1)-count;
            }
        }

    return time;
    }
};