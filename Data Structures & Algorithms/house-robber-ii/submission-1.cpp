class Solution {
public:
    int solve(vector<int>& nums,int start,int end)
    {
        int n = end-start+1;
        if(n==1) return nums[start];
        vector<int> dp(n,0);
        dp[0] = nums[start];
        dp[1] = max(nums[start],nums[start+1]);
        for(int i=2;i<n;i++)
            dp[i] = max(dp[i-1],dp[i-2]+nums[start+i]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
         int n = nums.size();

        if(n == 1)
         return nums[0];
        int option1  = solve(nums,0,nums.size()-2);
        int option2  = solve(nums,1,nums.size()-1);
        return max(option1,option2);
    }
};
