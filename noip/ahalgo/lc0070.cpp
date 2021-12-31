class Solution {
public:
    int climbStairs(int m) {
        vector <int> res;
        res.push_back(1);
        res.push_back(1);
        for (int k = 2; k <= m; ++k)
            res.push_back(res[k - 2] + res[k - 1]);
        return res.back();
    }
};
