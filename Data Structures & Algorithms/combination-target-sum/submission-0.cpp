class Solution {
public:
    void solve(int i, int sum, int target,
               vector<int>& temp,
               vector<vector<int>>& ans,
               vector<int>& nums)
    {
        if(sum>target)
        return;
        if(i == nums.size())
        {
            if(sum == target)
                ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i,sum+nums[i],target,temp,ans,nums);
        temp.pop_back();
        solve(i+1,sum,target,temp,ans,nums);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
         solve(0, 0, target, temp, ans, nums);
        return ans;

    }
};
