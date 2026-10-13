
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       
        for (int& x : nums) {
            x *= x;
        }
sort(nums.begin(), nums.end());

        int n = nums.size();
        int m = n / 2;
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans -= nums[i];
        }
        for (int i = m; i < n; i++) {
            ans += nums[i];
        }

        return ans;
    }
};
