class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int,int> mp;
        for (int card : hand) {
            mp[card]++;   
        }

        while (!mp.empty()) {
            int first = mp.begin()->first;   
            for (int i = 0; i < groupSize; i++) {
                int card = first + i;

                if (mp[card] == 0)  
                    return false;

                mp[card]--;          
                if (mp[card] == 0)  
                    mp.erase(card);
            }
        }
        return true;
    }
};
