class Solution {
public:
    void solve(int i,vector<int> &temp,vector<vector<int>> &ans,vector<int> nums)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,temp,ans,nums);
        temp.pop_back();
        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        solve(idx,temp,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(0,temp,ans,nums);
        return ans;
    }
};
