#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int q;
    cin >> q;
    int c, ele;
    stack<int> s1, s2;

    while (q > 0) {
        cin >> c;
        switch (c) {
            case 1: { // Enqueue operation
                cin >> ele;
                s1.push(ele);
                break;
            }
            case 2: { // Dequeue operation
                if (s2.empty()) {
                    while (!s1.empty()) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
                if (!s2.empty()) {
                    s2.pop();
                }
                break;
            }
            case 3: { // Print front operation
                if (s2.empty()) {
                    while (!s1.empty()) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
                if (!s2.empty()) {
                    cout << s2.top() << endl;
                }
                break;
            }
            default:
                break;
        }
        q--;
    }
    return 0;
}
