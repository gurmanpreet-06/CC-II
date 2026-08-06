class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> as;

        int j = 0;
        while (j < n && nums[j] < 0) //First non negative
            j++;

        int i = j - 1; //Last negative

        //Merging
        while (i >= 0 && j < n) {
            if (nums[i] * nums[i] <= nums[j] * nums[j]) {
                as.push_back(nums[i] * nums[i]);
                i--;
            }
            else {
                as.push_back(nums[j] * nums[j]);
                j++;
            }
        }

        //Remaining -ve side numbers
        while (i >= 0) {
            as.push_back(nums[i] * nums[i]);
            i--;
        }

        //Remaining +ve side numbers
        while (j < n) {
            as.push_back(nums[j] * nums[j]);
            j++;
        }

        return as;
    }
};