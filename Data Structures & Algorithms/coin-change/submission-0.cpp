class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
      vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
      for(int i=0;i<=n;i++)
      dp[i][0] = 0;
      for(int i=1;i<=n;i++)
      {
        for(int amt=1;amt<=amount;amt++)
        {
            dp[i][amt] = dp[i-1][amt]; 

            if(coins[i-1]<=amt)
            dp[i][amt] = min(dp[i-1][amt],1+dp[i][amt-coins[i-1]]);
        }
      }
      if (dp[n][amount] == 1e9)
            return -1;

        return dp[n][amount];

    }
};
