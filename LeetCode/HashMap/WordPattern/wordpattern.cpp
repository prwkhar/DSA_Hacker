class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        unordered_map<string,char> map2;
        int nw=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            nw++;
        }
        cout<<"nw-"<<nw<<endl<<"len-"<<pattern.length()<<endl;
        if(nw!=(pattern.length()-1))
        return false;
        string word="";int j=0;
        s=s+" ";
        for(int i=0;i<pattern.length();i++)
        {
            while(s[j]!=' ')
            {
                word=word+s[j];
                j++;
            }
            cout<<"word-"<<word<<endl;
            if(map.find(pattern[i])!=map.end())
            {
                if(map[pattern[i]]!=word)
                return false;
            }
            else
            {
                map[pattern[i]]=word;
            }
             if(map2.find(word)!=map2.end())
            {
                if(map2[word]!=pattern[i])
                return false;
            }
            else
            {
                map2[word]=pattern[i];
            }
            word="";
            j++;
        }
        return true;
    }
};