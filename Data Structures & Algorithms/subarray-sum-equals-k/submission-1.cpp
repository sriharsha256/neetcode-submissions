class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n = nums.size();
        int count  = 0;
        int currsum=0;
        for(int i=0;i<n;i++)
        {
            currsum += nums[i];
            int req = currsum-k;
            if(mp.find(req)!=mp.end())
            count += mp[req];
            mp[currsum]++;
        }
        return count;
    }
};