class Solution {
public:
    void reverseString(vector <char> & s) {
        auto psi = s.begin(), phi = s.end();
        --phi;
        while ((psi != phi) && (psi - 1 != phi))
            swap(*(psi++), *(phi--));
    }
};
