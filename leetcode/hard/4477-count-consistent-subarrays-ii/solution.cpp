
class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n = nums.size();
        const int B = 20;

        vector<vector<int>> prevZero(B, vector<int>(n));
        vector<vector<int>> nextZero(B, vector<int>(n));

        // Find the nearest previous and next positions
        // where each bit is absent.
        for (int b = 0; b < B; b++) {
            int last = -1;

            for (int i = 0; i < n; i++) {
                prevZero[b][i] = last;

                if ((nums[i] & (1 << b)) == 0) {
                    last = i;
                }
            }

            int next = n;

            for (int i = n - 1; i >= 0; i--) {
                nextZero[b][i] = next;

                if ((nums[i] & (1 << b)) == 0) {
                    next = i;
                }
            }
        }

        // Find the next position having value <= nums[i].
        // This ensures duplicate minimum values are counted once.
        vector<int> nextLE(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nextLE[i] = st.top();
            }

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int L = -1;
            int R = nextLE[i];

            // Every element must contain all set bits of nums[i].
            for (int b = 0; b < B; b++) {
                if (nums[i] & (1 << b)) {
                    L = max(L, prevZero[b][i]);
                    R = min(R, nextZero[b][i]);
                }
            }

            // Number of valid choices for left and right endpoints.
            ans += 1LL * (i - L) * (R - i);
        }

        return ans;
    }
};
