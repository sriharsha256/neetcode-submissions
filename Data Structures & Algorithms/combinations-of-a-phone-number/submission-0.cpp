class Solution {
public:
    void solve(int index,string &temp,vector<string> &ans,string &digits,vector<string> &mp)
    {
        if(index==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string letters = mp[digits[index]-'0'];
        for(int i=0;i<letters.size();i++)
        {
           temp += letters[i];
           solve(index+1,temp,ans,digits,mp);
           temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> mp(10);
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        string temp="";
        vector<string> ans;
        solve(0,temp,ans,digits,mp);
        return ans;

    }
};
