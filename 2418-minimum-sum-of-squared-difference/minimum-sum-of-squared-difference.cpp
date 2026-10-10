class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> diff(nums1.size());

        long long sum = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if (sum <= k) return 0;

        vector<long long> freq(mx + 1, 0);

        for (int d : diff)
            freq[d]++;

        for (int d = mx; d > 0 && k > 0; d--) {
            long long cnt = freq[d];
            long long take = min(k, cnt);

            freq[d] -= take;
            freq[d - 1] += take;
            k -= take;
        }

        long long ans = 0;

        for (int d = 1; d <= mx; d++)
            ans += freq[d] * d * d;

        return ans;
    }
};