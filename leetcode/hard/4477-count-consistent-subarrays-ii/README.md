# Q4. Count Consistent Subarrays II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums`.

A subarray is called  **consistent**  if the  **bitwise AND**  of all its elements is equal to the  **minimum**  value of the subarray.

Return the number of  **consistent subarrays**  in `nums`.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [5,3,1,2]

 **Output:**  6

 **Explanation:** 

The following subarrays are consistent:

Subarray	Values	Bitwise AND	Minimum Value
nums[0..0]	[5]	5	5
nums[1..1]	[3]	3	3
nums[2..2]	[1]	1	1
nums[3..3]	[2]	2	2
nums[1..2]	[3, 1]	3 AND 1 = 1	1
nums[0..2]	[5, 3, 1]	5 AND 3 AND 1 = 1	1

Therefore, the number of consistent subarrays is 6.

 **Example 2:** 

 **Input:**  nums = [1,1,1]

 **Output:**  6

 **Explanation:** 

For every subarray, both the bitwise AND and the minimum value are equal to 1. Therefore, the answer is 6.

 **Example 3:** 

 **Input:**  nums = [0]

 **Output:**  1

 **Explanation:** 

The only subarray is `[0]`, whose bitwise AND and minimum value are both 0. Therefore, the answer is 1.

 

 **Constraints:** 

- 1 <= nums.length <= 2 * 10​​​​​​​5
- 0 <= nums[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 536 ms (beats 50.11%)  
**Memory:** 410.6 MB (beats 24.35%)  
**Submitted:** 2026-11-15T18:42:18.420Z  

```cpp

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

```

---

[View on LeetCode](https://leetcode.com/problems/count-consistent-subarrays-ii/)