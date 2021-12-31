// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int m) {
        int lbound = 1, rbound = m;
        while (lbound < rbound) {
            int mid = lbound + ((rbound - lbound) >> 1);
            if (isBadVersion(mid))
                rbound = mid;
            else
                lbound = ++mid;
        }
        return lbound;
    }
};
