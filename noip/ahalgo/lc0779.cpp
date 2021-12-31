class Solution {
public:
    int kthGrammar(int m, int k) {
        return ((m != 1) ? ((1 - k % 2) ^ kthGrammar(m - 1, (k + 1) >> 1)) : (0));
    }
};
