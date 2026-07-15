class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int n = nums.size();
        int prefixsum = 0;
        for(int i=0;i<n;i++)
        {
            prefixsum += nums[i];
            int rem = prefixsum%k;
            if(mp.find(rem)==mp.end()) mp[rem] = i;
            else
            if(i-mp[rem]>=2) return true;
        }
        return false;
    }
};