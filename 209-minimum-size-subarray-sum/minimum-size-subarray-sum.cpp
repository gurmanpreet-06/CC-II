class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int l = 0;
        int size = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            while (sum >= target) {
                sum -= nums[l];
                size = min(size, i - l + 1);
                l++;
            }   
        }
        if (size == INT_MAX)
            size = 0;
        return size;
    }
};