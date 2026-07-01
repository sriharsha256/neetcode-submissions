class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> last(26,0);
        int n  = s.size();
        for(int i=0;i<n;i++)
        last[s[i]-'a'] = i;
        int j=0;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx = max(mx,last[s[i]-'a']);
            if(i==mx)
            {
                ans.push_back(i-j+1);
                j = i+1;
            }
        }
        return ans;
    }
};
