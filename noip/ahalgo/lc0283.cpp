class Solution {
public:
    void moveZeroes(vector <int> & nums) {
        /**
         * `itr`负责寻找下一个非零值
         * `non0`遇到零值会停下，直到`itr`找到下一个非零值
         */
        auto non0 = nums.begin();
        for (auto itr = nums.begin(); itr != nums.end(); ++itr)
            if (*itr != 0)
                swap(*itr, *(non0++));
    }
};
