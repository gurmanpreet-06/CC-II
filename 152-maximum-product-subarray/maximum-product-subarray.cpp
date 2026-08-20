class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int best = nums[0];
        int worst = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int curr = nums[i];

            int newBest = max({curr, curr * best, curr * worst});
            int newWorst = min({curr, curr * best, curr * worst});

            best = newBest;
            worst = newWorst;

            ans = max(ans, best);
        }

        return ans;
    }
};