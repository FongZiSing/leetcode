class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
        auto comparer = greater<int>();
        make_heap(arr.begin(), arr.end(), comparer);
        while (k--) {
            pop_heap(arr.begin(), arr.end(), comparer);
            result.push_back(arr.back());
            arr.pop_back();
        }

        return result;
    }
};