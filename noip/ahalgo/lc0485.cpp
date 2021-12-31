class Solution {
public:
    int findMaxConsecutiveOnes(vector <int> & arr) {
        int res = 0, cur = 0;
        for (auto psi = arr.begin(), phi = arr.begin(); psi != arr.end(); ++psi) {
            while (*psi == 0 && *phi == 0) {
                ++psi;
                ++phi;
            } //TODO
        }
    }
};
