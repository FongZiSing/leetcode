class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<double, vector<string>> result;
        vector<vector<string>> ans;
        int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        for (const auto& str : strs) {
            double key = 1;
            for_each(str.begin(), str.end(), [&](const char& c) { key *= primes[c - 'a']; });
            auto got = result.find(key);
            result[key].push_back(str);
        }

        for (const auto& res : result)
            ans.push_back(res.second);
        return ans;
    }
};