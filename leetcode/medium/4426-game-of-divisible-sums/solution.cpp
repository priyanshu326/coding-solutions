
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long long> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Option 1: Take one element
            long long sum1 = nums[i];

            long long takeOne;

            if (sum1 % 3 == 0) {
                takeOne = sum1 - dp[i + 1];
            } else {
                takeOne = sum1 + dp[i + 1];
            }

            // Option 2: Take two elements
            long long takeTwo = LLONG_MIN;

            if (i + 1 < n) {
                long long sum2 = (long long)nums[i] + nums[i + 1];

                if (sum2 % 3 == 0) {
                    takeTwo = sum2 - dp[i + 2];
                } else {
                    takeTwo = sum2 + dp[i + 2];
                }
            }

            dp[i] = max(takeOne, takeTwo);
        }

        return dp[0];
    }
};
