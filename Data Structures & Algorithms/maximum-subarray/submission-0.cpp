class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n = nums.size();
       int mx=INT_MIN;
       int currsum=0;
       for(int i=0;i<n;i++)
       {
          currsum += nums[i];
          mx = max(mx,currsum);
          if(currsum<0) currsum=0; 
       }
       return mx;
    }
};
