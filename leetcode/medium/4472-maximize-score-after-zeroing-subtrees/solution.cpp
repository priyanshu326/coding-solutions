
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& parent,
                       vector<int>& op,
                       vector<int>& score) {

        int n = parent.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        // Build traversal order
        vector<int> order;
        order.reserve(n);

        vector<int> st;
        st.push_back(0);

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            order.push_back(u);

            for (int v : children[u]) {
                st.push_back(v);
            }
        }

        // DP
        vector<long long> dp(n, 0);

        // Process children before parents
        for (int i = n - 1; i >= 0; i--) {

            int u = order[i];

            long long sum = 0;
            long long minVal = LLONG_MAX;

            for (int v : children[u]) {
                sum += dp[v];
                minVal = min(minVal, dp[v]);
            }

            // Leaf node
            if (children[u].empty()) {
                dp[u] = score[u];
                continue;
            }

            // Mandatory operation
            if (op[u] == 1) {
                dp[u] = score[u] + sum - minVal;
            }

            // Optional operation
            else {
                dp[u] = score[u] + sum - min(0LL, minVal);
            }
        }

        return dp[0];
    }
};
