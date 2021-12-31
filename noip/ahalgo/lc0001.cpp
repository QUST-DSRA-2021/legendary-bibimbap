class Solution {
public:
    vector<int> twoSum(vector <int> & arr, int target) {
        unordered_map <int, int> hashtable;
        for (int k = 0; k != arr.size(); ++k) {
            auto itr = hashtable.find(target - arr[k]);
            if (itr != hashtable.end())
                return {itr->second, k};
            hashtable[arr[k]] = k;
        }
        return {};
    }
};
