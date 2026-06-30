class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        if(m>n) return false;
        vector<int> v1(26,0);
        for(int i=0;i<m;i++)
        v1[s1[i]-'a']++;
        vector<int> v2(26,0);
        int left=0;
        for(int right=0;right<n;right++)
        {
            v2[s2[right]-'a']++;
            if(right-left+1 == m)
            {
                if(v2==v1) return true;
                else
                {
                v2[s2[left]-'a']--;
                left++;
                }
            }
        }
        return false;
    }
};
