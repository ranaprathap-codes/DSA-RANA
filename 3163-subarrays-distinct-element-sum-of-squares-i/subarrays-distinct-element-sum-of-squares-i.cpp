#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        
        // Loop through all possible starting positions of subarrays
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinctElements;
            
            // Expand the subarray from index i to j
            for (int j = i; j < n; ++j) {
                distinctElements.insert(nums[j]);
                
                // Count distinct elements, square it, and add to total
                int count = distinctElements.size();
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};
