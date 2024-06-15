#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string str) {
    int n = str.length();
    stack<char> stack;
    // Swap character starting from two
    // corners
    int flag=0;
    // for (int i = 0; i < n / 2; i++){
    //     swap(str[i], str[n - i - 1]);}
        // cout<<"after reversing-"<<str<<endl;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='('||str[i]=='['||str[i]=='{')
            {
                cout<<"pushed-"<<str[i]<<endl;
                stack.push(str[i]);
            }
            if((str[i]==')'||str[i]==']'||str[i]=='}'))
            {
                if(stack.empty())
                {return "NO";}
                char ch=stack.top();
                cout<<"ch-"<<ch<<endl;
                cout<<"str[i]-"<<str[i]<<endl;
                stack.pop();
                if((ch=='('&&str[i]==')')||(ch=='{'&&str[i]=='}')||(ch=='['&&str[i]==']'))
                {
                    cout<<"matched"<<endl;
                    continue;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            
        }
        if(flag==1||!stack.empty())
        return "NO";
        return "YES";
        
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
