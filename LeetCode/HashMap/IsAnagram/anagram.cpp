class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        map<char,int> m;
        map<char,int> mt;
        for(auto i : s)
        {
            m[i]++;
        }
        for(auto i : t)
        {
            mt[i]++;
        }
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(mt.find(i->first)!=mt.end())
            {
                if(mt[i->first]==i->second)
                {

                    cout<<"continue"<<endl;
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};