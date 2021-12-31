class Solution {
public:
    int search(vector <int> & nums, int target) {
        int lbound = 0, rbound = nums.size() - 1;
        while (lbound <= rbound) {
            int pivot = lbound + ((rbound - lbound) >> 1);
            if (nums[pivot] == target)
                return pivot;
            else if (nums[pivot] > target)
                rbound = pivot - 1;
            else
                lbound = pivot + 1;
        }
        return (-1);
    }
};
