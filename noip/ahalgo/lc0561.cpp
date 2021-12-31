class Solution {
public:
    int arrayPairSum(vector <int> arr) {
        sort(arr.begin(), arr.end());
        int res = 0;
        for (auto itr = arr.begin(); itr != arr.end(); ++(++itr))
            res += *itr;
        return res;
    }
};
