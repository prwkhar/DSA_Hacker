#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) {
    stack<int> mainStack;
    stack<int> maxStack;
    vector<int> result;

    for (const string& op : operations) {
        if (op.substr(0, 2) == "1 ") {
            int num = stoi(op.substr(2));
            mainStack.push(num);
            if (maxStack.empty() || num >= maxStack.top()) {
                maxStack.push(num);
            }
        } else if (op == "2") {
            if (!mainStack.empty()) {
                if (mainStack.top() == maxStack.top()) {
                    maxStack.pop();
                }
                mainStack.pop();
            }
        } else if (op == "3") {
            if (!maxStack.empty()) {
                result.push_back(maxStack.top());
            }
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
