// 两次二分查找
// 执行用时 : 0 ms, 在所有 cpp 提交中击败了 100.00% 的用户
// 内存消耗 : 8.7 MB, 在所有 cpp 提交中击败了 82.85% 的用户
class Solution
{
public:
    vector<int>::iterator findIndex(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int mid = 0;

        if (nums[left] < nums[right]) return nums.begin();
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[left] < nums[mid]) left = mid;
            else right = mid;
        }
        return nums.begin() + mid + 1;
    }

    int search(vector<int> &nums, int target)
    {
        if (nums.empty()) return -1;
        vector<int>::iterator mid, idx;
        mid = findIndex(nums);
        // 查左边
        idx = lower_bound(nums.begin(), mid, target);
        if (idx == nums.end()) return -1;
        if (*idx == target) return idx - nums.begin();

        // 查右边
        idx = lower_bound(mid, nums.end(), target);
        if (idx == nums.end()) return -1;
        if (*idx == target) return idx - nums.begin();

        // 都没有
        return -1;
    }
};