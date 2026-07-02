class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[hand[i]]++;
        for(int i=0;i<n;i++)
        {
            int curr = hand[i];
            if(mp[curr]==0) continue;
            int size = groupSize;
            while(size--)
            {
                if(mp[curr]==0) return false;
                mp[curr]--;
                curr++;
            }
        }
        return true;
    }
};
