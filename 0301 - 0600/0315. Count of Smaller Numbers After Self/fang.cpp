class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> ans(nums.size(), 0);
        deque<int> order;

        for (int i = nums.size(); i--;) {
            auto got = lower_bound(order.begin(), order.end(), nums[i]);
            ans[i] = distance(order.begin(), got);
            order.insert(got, nums[i]);
        }

        return ans;
    }
};