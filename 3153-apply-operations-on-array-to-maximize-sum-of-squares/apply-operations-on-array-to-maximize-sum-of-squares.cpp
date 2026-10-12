class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        constexpr int MOD = 1'000'000'007;
        constexpr int MAX_BIT = 30;

        vector<int> minIndex(MAX_BIT, 0);
        vector<int> optimal(nums.size(), 0);

        // Redistribute every set bit into the earliest available number.
        for (int num : nums) {
            for (int b = 0; b < MAX_BIT; ++b) {
                if (num >> b & 1) {
                    optimal[minIndex[b]++] |= 1 << b;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            ans = (ans + 1LL * optimal[i] * optimal[i]) % MOD;
        }

        return static_cast<int>(ans);
    }
};