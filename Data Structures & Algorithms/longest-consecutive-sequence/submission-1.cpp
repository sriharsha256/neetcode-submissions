class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            int curr = nums[i]-1;
            int length = 1;
            while(mp.find(curr)!=mp.end())
            {
                curr--;
                length++;
            }
            mx  = max(mx,length);
        }
        return mx;
    }
};
