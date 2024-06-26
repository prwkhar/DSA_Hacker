class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> ransom;
        map<char,int> maga;
        for(auto i:ransomNote)
        {
            ransom[i]++;
        }
        for(auto i:magazine)
        {
            maga[i]++;
        }
        for(auto i=ransom.begin();i!=ransom.end();i++)
        {
            cout<<"this is the output-"<<i->first<<"-"<<i->second<<endl;
            if(maga.find(i->first)!=maga.end())
            {
                if(maga[i->first]>=i->second)
                {
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