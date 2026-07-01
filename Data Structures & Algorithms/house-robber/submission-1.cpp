class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prev1 = nums[0];
        int prev2 = max(nums[0],nums[1]);
        if(nums.size()==2)
        return prev2;
        int cur=0;
        for(int i=2;i<nums.size();i++)
        {
            cur  = max(prev1+nums[i],prev2);
            prev1 = prev2;
            prev2 = cur;  
        }
        return cur;
    }
};
