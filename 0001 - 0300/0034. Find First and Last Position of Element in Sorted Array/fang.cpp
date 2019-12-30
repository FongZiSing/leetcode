// 二分查找
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty()) return {-1, -1};
        vector<int>::iterator first, last, temp;
        first = temp = lower_bound(nums.begin(), nums.end(), target);
        while (++temp < nums.end()) { if (*temp != target) break; }
        last = temp - 1;
        if (last == nums.end()) return {-1, -1};
        if (target != *last) return {-1, -1};
        return {first - nums.begin(), last - nums.begin()};
    }
};