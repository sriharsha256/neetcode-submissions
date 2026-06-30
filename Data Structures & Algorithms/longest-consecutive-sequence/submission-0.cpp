class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
        int ans =0;
        for(int i=0;i<nums.size();i++)
        {
            int curr  = nums[i]-1;
            int count=1;
            while(mp.find(curr)!=mp.end())
            {
                curr--;
                count++;
            }
            
           ans = max(ans,count);
        }
        return ans;

    }
};
