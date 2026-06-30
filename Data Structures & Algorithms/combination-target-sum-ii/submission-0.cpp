class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void solve(int i,vector<int> candidates,int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0 || i==candidates.size()) return;
        // take 
        temp.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i]);
        temp.pop_back();
        int idx = i+1;
        while(idx<candidates.size() && candidates[idx]==candidates[idx-1]) idx++;
        solve(idx,candidates,target);
      
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target);
        return ans;
    }
};