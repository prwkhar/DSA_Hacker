#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<vector<int>>> all_magic_squares = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
};

int findthecost(vector<vector<int>> ams, vector<vector<int>> inp) {
    int cost = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cost = cost + abs(ams[i][j] - inp[i][j]);
        }
    }
    return cost;
}

int formingMagicSquare(vector<vector<int>> s) {
    int mincost = INT_MAX;
    int cost = 0;
    for (int i = 0; i < all_magic_squares.size(); i++) {
        cost = findthecost(all_magic_squares[i], s);
        if (cost < mincost)
            mincost = cost;
    }
    return mincost;
}

int main() {
    vector<vector<int>> s(3, vector<int>(3)); // Initialize the 3x3 matrix
    
    cout << "Enter the elements of the 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }
    }

    int result = formingMagicSquare(s);

    cout << result << "\n";

    return 0;
}
