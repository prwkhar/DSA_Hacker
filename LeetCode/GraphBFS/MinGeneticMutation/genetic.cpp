class Solution {
public:
    bool diff(string s,string j)
    {
        if(s.length()!=j.length())
        return false;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=j[i])
            count++;
        }
        if(count==1)
        return true;
        return false;
    }
    bool isthere(vector<string> b,string neighbor)
    {
        for(int i=0;i<b.size();i++)
        {
            if(b[i]==neighbor)
            return true;
        }
        return false;
    }
    int bfs(map<string,vector<string>>& mp,string start,string end,vector<string> bank)
    {
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int steps=0;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
            string s1=q.front();
            q.pop();
            if(s1==end)
            return steps;
            for(string neighbor : mp[s1])
            {
                if(visited.find(neighbor)==visited.end()&&isthere(bank,neighbor))
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }

        }
        steps++;
    }
    return -1;
}
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string,vector<string>> mp;
        bank.push_back(startGene);
        for(int i=0;i<bank.size();i++)
        {
            for(int j=i+1;j<bank.size();j++)
            {
                if(diff(bank[i],bank[j]))
                {
                    mp[bank[i]].push_back(bank[j]);
                    mp[bank[j]].push_back(bank[i]);
                }
            }
        }
        //now we have created the map
        return bfs(mp,startGene,endGene,bank);
    }
};