class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int currsum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            currsum += nums[i];
            int diff = currsum-k;
            res += mp[diff];
            mp[currsum]++; 
        }
        return res;
    }
};