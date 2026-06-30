class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> adj;
        unordered_map<char,int> indegree;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                indegree[words[i][j]]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++)
        {
            string s1 = words[i];
            string s2 = words[i+1];
            if(s1.size()>s2.size() && s1.substr(0,s2.size())==s2)
            return "";
            int len  = min(s1.size(),s2.size());
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                adj[s1[j]].push_back(s2[j]);
                indegree[s2[j]]++;
                break;
                }
            }
        }
        queue<char> q;
        for(auto it = indegree.begin();it!=indegree.end();it++)
        {
            if(it->second==0)
            q.push(it->first);
        }
        string ans = "";
        while(!q.empty())
        {
            char node = q.front();
            q.pop();
            ans  += node;
                        for(int i=0;i<adj[node].size();i++)
            {
                char nei = adj[node][i];

                indegree[nei]--;

                if(indegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        if(ans.size() != indegree.size())
        {
            return "";
        }

        return ans;

    }
};
