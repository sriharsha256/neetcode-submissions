class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        int left=0;
        int right=n-1;
        int leftmax=0;
        int rightmax=0;
        int water=0;
        while(left<right)
        {
           if(heights[left]<=heights[right])
           {
             if(leftmax<heights[left]) leftmax = heights[left];
             else water+= leftmax-heights[left];
             left++;
           } 
           else
           {
            if(rightmax<heights[right]) rightmax = heights[right];
            else water+= rightmax-heights[right];
            right--;
           }
        }
        return water;
    }
};
