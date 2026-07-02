class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++)
        total += nums[i];
        int sum = 0;
        if(total%2==1) return false;
        else sum = total/2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++)
        dp[i][0] = true;
        for(int i=1;i<=n;i++)
        {
            for(int amt =1;amt<=sum;amt++)
            {
                if(nums[i-1]>amt)
                dp[i][amt] = dp[i-1][amt];
                else
                dp[i][amt] = dp[i-1][amt] || dp[i-1][amt-nums[i-1]]; 
            }
        }
        return dp[n][sum];
    }
};
