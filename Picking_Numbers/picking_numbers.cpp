#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
sort(a.begin(),a.end());
int n=a.size();
int num=0;int flag=0;
int count=0,count1=0,num2=-1,totalcount=0;int max=0;
for(int i=0;i<n;i++)
{
    num=a[i];
    while(a[i]==num){
    count++;i++;}
    cout<<"value of i"<<endl<<i<<endl;
    if(i==n&&num2==-1)
    {
        max=count;
    break;}
    num2=a[i];
    if((num2-num)==1)
    {
        flag=1;
    }
    while(a[i]==num2){
    count1++;i++;}
    cout<<num<<"-"<<count<<endl;
    cout<<num2<<"-"<<count1<<endl;
    if(flag==1){
    totalcount=count+count1;
    if(max<totalcount)
    max=totalcount;}
    if(flag==0)
    {
        if(count1>max||count>max){
        if(count1>count)max=count1;
        if(count>count1)max=count;
        else max=count;}
    }
    i=i-count1-1;
    count=0;
    count1=0;
    flag=0;
}
return max;

}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    cout<<"enter elements";int ele;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        v.push_back(ele);
    }

    int result = pickingNumbers(v);

    cout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
