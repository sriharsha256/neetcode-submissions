class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left=0;
        int right=n-1;
        int mx = INT_MIN;
        while(left<right)
        {
            int height = min(heights[left],heights[right]);
            int width = right-left;
            mx = max(mx,height*width);
            if(heights[left]>heights[right]) right--;
            else left++;
        }
        return mx;
    }
};
