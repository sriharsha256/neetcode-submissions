class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> open;
        stack<int> star;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else
            {
                if(open.size()==0 && star.size()==0) return false;
                else if(open.size()>0) open.pop();
                else star.pop();
            }
        }
        while(open.size()!=0 && star.size()!=0)
        {
            if(open.top()<star.top())
            {
                open.pop();
                star.pop();
            }
            else
            return false;
        }
        return open.empty();
    }
};
