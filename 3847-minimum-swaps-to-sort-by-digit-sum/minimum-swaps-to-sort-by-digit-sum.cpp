
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto digitSum = [](int x) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        vector<int> sortedNums = nums;

        sort(sortedNums.begin(), sortedNums.end(),
             [&](int a, int b) {
                 int sa = digitSum(a);
                 int sb = digitSum(b);

                 if (sa != sb)
                     return sa < sb;

                 return a < b;
             });

        unordered_map<int, int> target;
        for (int i = 0; i < n; i++) {
            target[sortedNums[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = target[nums[j]];
                cycleSize++;
            }

            if (cycleSize > 1)
                swaps += cycleSize - 1;
        }

        return swaps;
    }
};
