class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0,current_sum=0,MaxSum= nums[0],current_min=0,MinSum=nums[0],circular_sum=0;
        for(int i=0;i<nums.size();i++)
        { 
             // if start and end are not included
            total += nums[i];
            current_sum += nums[i];
            MaxSum = max(MaxSum,current_sum);
            if(current_sum<0) current_sum=0;

            // if start and end include find min middle part
            current_min += nums[i];
            MinSum = min(MinSum,current_min);
            if(current_min>0) current_min=0;
        }
        if(MaxSum<0) return MaxSum;
        circular_sum = total - MinSum;
        return max(MaxSum,circular_sum);
    }
};