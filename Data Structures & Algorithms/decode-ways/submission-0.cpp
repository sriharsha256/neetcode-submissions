class Solution {
public:
    int numDecodings(string s) {
         int n = s.size();
         vector<int> dp(n+1,0);
         dp[0] = 1;
         for(int i=1;i<=n;i++)
         {
            if(s[i-1]-'0'!=0)
            dp[i] = dp[i-1];
            if(i>=2)
            {
             int twodigit = (s[i-1]-'0') + (s[i-2]-'0')*10;
            if(twodigit>=10 && twodigit<=26)
            dp[i] = dp[i]+dp[i-2];
            }
         }
         return dp[n];
    }
};
