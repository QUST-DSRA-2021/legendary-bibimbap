class Solution {
public:
    double fastmul(double x, long long M) {
        if (M != 0) {
            double y = fastmul(x, M / 2);
            return M % 2 == 0 ? y * y : y * y * x;
        } else
            return 1.;
    }
    double myPow(double x, int m) {
        long long M = (long long)m;
        return M >= 0 ? fastmul(x, M) : 1. / fastmul(x, -M);
    }
};
