#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            graph[A][B] = values[i];
            graph[B][A] = 1.0 / values[i];
        }

        // Evaluate queries
        vector<double> result;
        for (const auto& query : queries) {
            const string& A = query[0];
            const string& B = query[1];
            if (graph.find(A) == graph.end() || graph.find(B) == graph.end()) {
                result.push_back(-1.0);
            } else {
                result.push_back(bfs(A, B, graph));
            }
        }

        return result;
    }

private:
    double bfs(const string& start, const string& end, unordered_map<string, unordered_map<string, double>>& graph) {
        if (start == end) {
            return 1.0;
        }

        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty()) {
            auto [node, value] = q.front();
            q.pop();

            for (const auto& neighbor : graph[node]) {
                const string& nextNode = neighbor.first;
                double edgeValue = neighbor.second;

                if (visited.find(nextNode) != visited.end()) {
                    continue;
                }

                double nextValue = value * edgeValue;
                if (nextNode == end) {
                    return nextValue;
                }

                q.push({nextNode, nextValue});
                visited.insert(nextNode);
            }
        }

        return -1.0;
    }
};
