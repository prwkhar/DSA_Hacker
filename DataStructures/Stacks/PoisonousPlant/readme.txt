#include <bits/stdc++.h>

using namespace std;

/**
 * Function to determine the number of days after which no plant dies.
 * @param p: vector of integers representing the pesticide levels of the plants.
 * @return: integer representing the number of days until no plants die.
 */
int poisonousPlants(vector<int> p) {
    int n = p.size();  // Get the number of plants
    vector<int> days(n, 0);  // Initialize days vector with 0 for all plants
    stack<int> st;  // Stack to keep track of plant indices
    int max_days = 0;  // Variable to track the maximum days survived

    // Loop through each plant
    for (int i = 0; i < n; ++i) {
        int max_survive = 0;  // Variable to track the maximum survival days for current plant

        // Pop elements from stack while the current plant's pesticide level is less than or equal to the top of the stack
        while (!st.empty() && p[st.top()] >= p[i]) {
            max_survive = max(max_survive, days[st.top()]);  // Update max_survive with the maximum days survived
            st.pop();  // Remove the top element from the stack
        }

        // If stack is not empty, the current plant has more pesticide than the plant on the left
        if (!st.empty()) {
            days[i] = max_survive + 1;  // Update days survived for the current plant
        } else {
            days[i] = 0;  // No surviving days if no plant on the left has more pesticide
        }

        max_days = max(max_days, days[i]);  // Update the max days survived across all plants
        st.push(i);  // Push current plant index onto the stack
    }

    return max_days;  // Return the maximum days survived
}

int main() {
    // Sample input: pesticide levels of the plants
    vector<int> pesticide_levels = {6, 5, 8, 4, 7, 10, 9};
    
    // Call the function and print the result
    cout << poisonousPlants(pesticide_levels) << endl;  // Output: 2
    
    return 0;
}
