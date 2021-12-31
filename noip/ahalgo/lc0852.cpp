class Solution {
public:
    int peakIndexInMountainArray(vector <int> & arr) {
        auto itr = arr.begin() + 1;
        int res = 1;
        while ((*(itr - 1) >= *itr || *itr <= *(itr + 1)) && (itr + 1 != arr.end())) {
            ++itr;
            ++res;
        }
        return res;
    }
};
