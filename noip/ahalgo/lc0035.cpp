class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int m = nums.size();
        int lbound = 0, rbound = m - 1, res = m;
        while (lbound <= rbound) {
            int mid = (lbound + rbound) >> 1;
            if (target <= nums[mid]) {
                res = mid;
                rbound = res - 1;
            } else
                lbound = ++mid;
        }
        return res;
    }
};
