class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx=nums[0],mn=nums[0];
        int res=nums[0];
        int max_element=INT_MIN;
        int min_element = INT_MAX;
        for(int i=1;i<n;i++)
        {
            max_element = max({nums[i],mx*nums[i],mn*nums[i]});
            min_element = min({nums[i],mx*nums[i],mn*nums[i]});
            res = max(res,max_element);
            mx = max_element;
            mn = min_element;
        }
        return res;
    }
};
